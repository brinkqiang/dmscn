// Copyright 2017 Elias Kosunen
//
// Licensed under the Apache License, Version 2.0 (the "License{");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// This file is a part of scnlib:
//     https://github.com/eliaskosunen/scnlib

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "test.h"

TEST_CASE("C locale")
{
    std::setlocale(LC_NUMERIC, "C");
    float a, b;
    auto ret = scn::scan("3.14 3,14", "{} {}", a, b);
    CHECK(ret);
    CHECK(std::string{ret.begin(), ret.end()} == ",14");
    CHECK(a == doctest::Approx(3.14));
    CHECK(b == doctest::Approx(3.0));
}

TEST_CASE("Changing C locale")
{
    std::setlocale(LC_NUMERIC, "en_US.UTF-8");
    float a, b;
    auto ret = scn::scan("3.14 3,14", "{} {}", a, b);
    CHECK(ret);
    CHECK(std::string{ret.begin(), ret.end()} == ",14");
    CHECK(a == doctest::Approx(3.14));
    CHECK(b == doctest::Approx(3.0));
    a = b = 0;

    // C locale change not affecting behavior
    std::setlocale(LC_NUMERIC, "fi_FI.UTF-8");
    ret = scn::scan("3.14 3,14", "{} {}", a, b);
    CHECK(ret);
    CHECK(std::string{ret.begin(), ret.end()} == ",14");
    CHECK(a == doctest::Approx(3.14));
    CHECK(b == doctest::Approx(3.0));

    std::setlocale(LC_NUMERIC, "C");
}

TEST_CASE("Changing global C++ locale")
{
    std::locale::global(std::locale("en_US.UTF-8"));
    float a, b;
    auto ret = scn::scan("3.14 3,14", "{} {}", a, b);
    CHECK(ret);
    CHECK(std::string{ret.begin(), ret.end()} == ",14");
    CHECK(a == doctest::Approx(3.14));
    CHECK(b == doctest::Approx(3.0));
    a = b = 0;

    // Global C++ locale change not affecting behavior
    std::locale::global(std::locale("fi_FI.UTF-8"));
    ret = scn::scan("3.14 3,14", "{} {}", a, b);
    CHECK(ret);
    CHECK(std::string{ret.begin(), ret.end()} == ",14");
    CHECK(a == doctest::Approx(3.14));
    CHECK(b == doctest::Approx(3.0));

    std::locale::global(std::locale::classic());
}

TEST_CASE("Using scan_localized without {:l}")
{
    // no {:l} -> default behavior
    float a, b;
    auto ret =
        scn::scan_localized(std::locale::classic(), "3.14 3,14", "{} {}", a, b);
    CHECK(ret);
    CHECK(std::string{ret.begin(), ret.end()} == ",14");
    CHECK(a == doctest::Approx(3.14));
    CHECK(b == doctest::Approx(3.0));
    a = b = 0;

    ret = scn::scan_localized(std::locale("en_US.UTF-8"), "3.14 3,14", "{} {}",
                              a, b);
    CHECK(ret);
    CHECK(std::string{ret.begin(), ret.end()} == ",14");
    CHECK(a == doctest::Approx(3.14));
    CHECK(b == doctest::Approx(3.0));
    a = b = 0;

    ret = scn::scan_localized(std::locale("fi_FI.UTF-8"), "3.14 3,14", "{} {}",
                              a, b);
    CHECK(ret);
    CHECK(std::string{ret.begin(), ret.end()} == ",14");
    CHECK(a == doctest::Approx(3.14));
    CHECK(b == doctest::Approx(3.0));
}

TEST_CASE("Using scan_localized with {:l}")
{
    // {:l} -> localized behavior
    float a, b;
    auto ret = scn::scan_localized(std::locale::classic(), "3.14 3,14",
                                   "{:l} {:l}", a, b);
    CHECK(ret);
    CHECK(std::string{ret.begin(), ret.end()} == ",14");
    CHECK(a == doctest::Approx(3.14));
    CHECK(b == doctest::Approx(3.0));
    a = b = 0;

    // On my machine, with en_US locale enabled, stringstreams don't allow
    // parsing '3,14' as a float by stopping at the ',' character and returning
    // '3'.
    ret = scn::scan_localized(std::locale("en_US.UTF-8"), "3.14 3", "{:l} {:l}",
                              a, b);
    CHECK(ret);
    CHECK(ret.begin() == ret.end());
    CHECK(a == doctest::Approx(3.14));
    CHECK(b == doctest::Approx(3.0));
    a = b = 0;

    ret = scn::scan_localized(std::locale("fi_FI.UTF-8"), "3,14 3.14",
                              "{:l} {:l}", a, b);
    CHECK(ret);
    CHECK(std::string{ret.begin(), ret.end()} == ".14");
    CHECK(a == doctest::Approx(3.14));
    CHECK(b == doctest::Approx(3.0));
}

TEST_CASE_TEMPLATE("bool localized", CharT, char, wchar_t)
{
    auto locale = std::locale("en_US.UTF-8");
    {
        bool b{};
        auto e = do_scan_localized<CharT>(locale, "true", "{:la}", b);
        CHECK(b);
        CHECK(e);
    }
    {
        bool b{};
        auto e = do_scan_localized<CharT>(locale, "false", "{:la}", b);
        CHECK(!b);
        CHECK(e);
    }
    {
        bool b{};
        auto e = do_scan_localized<CharT>(locale, "bool", "{:la}", b);
        REQUIRE(!e);
        CHECK(e.error().code() == scn::error::invalid_scanned_value);
    }
    {
        bool b{};
        auto e = do_scan_localized<CharT>(locale, "0", "{:la}", b);
        REQUIRE(!e);
        CHECK(e.error().code() == scn::error::invalid_scanned_value);
    }
    {
        bool b{};
        auto e = do_scan_localized<CharT>(locale, "0", "{:l}", b);
        CHECK(!b);
        CHECK(e);
    }
    {
        bool b{};
        auto e = do_scan_localized<CharT>(locale, "1", "{:l}", b);
        CHECK(b);
        CHECK(e);
    }
    {
        bool b{};
        auto e = do_scan_localized<CharT>(locale, "2", "{:l}", b);
        REQUIRE(!e);
        CHECK(e.error().code() == scn::error::invalid_scanned_value);
    }
    {
        bool b{};
        auto e = do_scan_localized<CharT>(locale, "true", "{:ln}", b);
        REQUIRE(!e);
        CHECK(e.error().code() == scn::error::invalid_format_string);
    }
}
