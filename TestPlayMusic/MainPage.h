// MainMenu.h: 首页（主菜单）页面
#include <cstdio>
#include <cstdlib>
#include <conio.h>
#include <cstdbool>
#include <Windows.h>
#include "PlayerPage.h"
#include "Time.h"
#include "ListPage.h"
#include "File.h"

// 显示首页，同时承担交互等功能，可以被其他模块调用
// 要求：
// 显示当前的北京时间，如果用户不敲击键盘，就每秒更新一次时间；
// 用户敲击相应的键盘后，就跳转到相应的页面
void mainMenuPage();

// 只显示首页的样子，不承担交互等功能，不可以被其他模块调用
// 要求：
// 显示当前的北京时间
// 提示用户按什么键可以做什么事情，本页面一共有2个功能，一个是显示关于界面（屁用没有，可以先不做），另一个是打开播放列表页面
void showMainMenuPage();