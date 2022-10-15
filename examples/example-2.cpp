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

#include <scn/scn.h>
#include <iostream>
#include <string>

// 在 Windows 系统之下：输入 ctrl + z 后按下回车，就代表标准输入流的结束
// 在 Unix / Linux / MacOS 系统之下：输入 ctrl + D，就表示输入流结束了

int main()
{
    std::cout << "Hi there! What's your first name?\n";

    std::string name;
    scn::input("{}", name);
    std::cout << "Welcome, " << name << '\n';
}
