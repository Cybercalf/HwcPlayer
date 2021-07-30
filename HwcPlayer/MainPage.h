// MainMenu.h: 首页（主菜单）页面
#include "File.h"
#include "Glue.h"
#include "ListPage.h"
#include "PlayerPage.h"
#include "Time.h"

// 显示首页，同时承担交互等功能，可以被其他模块调用
// 用户敲击相应的键盘后，就跳转到相应的页面，可跳转的页面有：
// 播放列表页面
// 播放器页面
// 关于页面
//
void mainPage();

// 只显示首页的样子，不承担交互等功能
// 显示当前的北京时间，定时更新
// 提示用户按什么键可以做什么事情
void showMainPage();

// 显示关于页面，页面内容主要为一个字符画、制作人员名单和鸣谢
void showAboutPage();