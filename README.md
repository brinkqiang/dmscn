# dmscn

Copyright (c) 2013-2018 brinkqiang (brink.qiang@gmail.com)

[![dmscn](https://img.shields.io/badge/brinkqiang-dmscn-blue.svg?style=flat-square)](https://github.com/brinkqiang/dmscn)
[![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](https://github.com/brinkqiang/dmscn/blob/master/LICENSE)
[![blog](https://img.shields.io/badge/Author-Blog-7AD6FD.svg)](https://brinkqiang.github.io/)
[![Open Source Love](https://badges.frapsoft.com/os/v3/open-source.png)](https://github.com/brinkqiang)
[![GitHub stars](https://img.shields.io/github/stars/brinkqiang/dmscn.svg?label=Stars)](https://github.com/brinkqiang/dmscn) 
[![GitHub forks](https://img.shields.io/github/forks/brinkqiang/dmscn.svg?label=Fork)](https://github.com/brinkqiang/dmscn)

## Build status
| [Linux][lin-link] | [Mac][mac-link] | [Windows][win-link] |
| :---------------: | :----------------: | :-----------------: |
| ![lin-badge]      | ![mac-badge]       | ![win-badge]        |

[lin-badge]: https://github.com/brinkqiang/dmscn/workflows/linux/badge.svg "linux build status"
[lin-link]:  https://github.com/brinkqiang/dmscn/actions/workflows/linux.yml "linux build status"
[mac-badge]: https://github.com/brinkqiang/dmscn/workflows/mac/badge.svg "mac build status"
[mac-link]:  https://github.com/brinkqiang/dmscn/actions/workflows/mac.yml "mac build status"
[win-badge]: https://github.com/brinkqiang/dmscn/workflows/win/badge.svg "win build status"
[win-link]:  https://github.com/brinkqiang/dmscn/actions/workflows/win.yml "win build status"


## Intro
dmscn


// 在 Windows 系统之下：输入 ctrl + z 后按下回车，就代表标准输入流的结束
// 在 Unix / Linux / MacOS 系统之下：输入 ctrl + D，就表示输入流结束了

```cpp
#include <scn/scn.h>
#include <iostream>
#include <string>

int main()
{
    std::cout << "Hi there! What's your first name?\n";

    std::string name;
    scn::input("{}", name);
    std::cout << "Welcome, " << name << '\n';
}

```
## Contacts
[![Join the chat](https://badges.gitter.im/brinkqiang/dmscn/Lobby.svg)](https://gitter.im/brinkqiang/dmscn)

## Thanks
