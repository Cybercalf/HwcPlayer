// PlaylistPage.h: 播放列表页面。
#include <cstdio>
#include <cstdlib>
#include <conio.h>
#include <cstring>
#include <cstdbool>
#include "List.h"
#define CLEAR_BUF \
    {\
    int ch; \
while ((ch = getchar()) != EOF && ch != '\n')\
        {\
        ; \
        }\
    }



// 显示播放列表页面，同时承担交互等功能，可以被其他模块调用
void listPage();

// 只显示播放列表界面的样子，不承担交互等功能，不可以被其他模块调用
// 要求：
// 加载文件中存储的媒体列表信息到链表中，并将它们依次显示出来
// 除了显示播放列表之外，还要显示一个箭头，指向其中一个音乐文件，代表它为选中状态，如果列表为空，则不显示这个箭头。
// 箭头的初始位置永远在列表最上方
// 提示用户按什么键可以做什么事情，本页面有以下功能：
// 通过键盘改变箭头的位置，要求不能出界
// 添加一个音乐文件
// 删除一个音乐文件，具体实现为链表的节点删除操作
// 查看被选中的音乐文件的详细信息
// 播放，即进入播放器页面
// 返回主菜单
//
void showListPage();

