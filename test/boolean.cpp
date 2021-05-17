// Copyright 2017 Elias Kosunen
//
// Licensed under the Apache License, Version 2.0 (the "License");
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

TEST_CASE_TEMPLATE("boolean", CharT, char, wchar_t)
{
    {
        bool b{};
        auto e = do_scan<CharT>("true", "{:a}", b);
        CHECK(b);
        CHECK(e);
    }
    {
        bool b{};
        auto e = do_scan<CharT>("false", "{:a}", b);
        CHECK(!b);
        CHECK(e);
    }
    {
        bool b{};
        auto e = do_scan<CharT>("bool", "{:a}", b);
        REQUIRE(!e);
        CHECK(e.error().code() == scn::error::invalid_scanned_value);
    }
    {
        bool b{};
        auto e = do_scan<CharT>("0", "{:a}", b);
        REQUIRE(!e);
        CHECK(e.error().code() == scn::error::invalid_scanned_value);
    }
    {
        bool b{};
        auto e = do_scan<CharT>("0", "{}", b);
        CHECK(!b);
        CHECK(e);
    }
    {
        bool b{};
        auto e = do_scan<CharT>("1", "{}", b);
        CHECK(b);
        CHECK(e);
    }
    {
        bool b{};
        auto e = do_scan<CharT>("2", "{}", b);
        REQUIRE(!e);
        CHECK(e.error().code() == scn::error::invalid_scanned_value);
    }
    {
        bool b{};
        auto e = do_scan<CharT>("true", "{:n}", b);
        REQUIRE(!e);
        CHECK(e.error().code() == scn::error::invalid_scanned_value);
    }
}
