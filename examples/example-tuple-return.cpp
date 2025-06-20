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

#include "scn/scn.h"
#include "scn/tuple_return.h"
#include <iostream>
#include <regex>

int main()
{
#if defined(__cpp_structured_bindings) && __cpp_structured_bindings >= 201606
    auto [result, proto, url, port] =
        scn::scan_tuple<std::string, std::string, std::string>("https baidu 8080",
                                                               "{} {} {}");
    if (result) {
        std::cout << "Read " << proto << "://" << url << ":" << port <<  '\n';
    }
#else
    std::cout << "Compile with structured bindings support (C++17) for this "
                 "example to work\n";
#endif
}
