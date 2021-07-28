// PlaylistPage.h: 播放列表页面。
#include "File.h"
#include "Glue.h"
#include "List.h"

extern MediaNodePtr g_headPtr;

// 显示播放列表页面，同时承担交互等功能，可以被其他模块调用
// 功能：
// 从指定文件夹中导入一个音乐
// 从指定文件夹中导入所有音乐
// 删除音乐列表中的一个音乐
// 清空播放列表
// 返回主菜单界面
//
void listPage();

// 只显示播放列表界面的样子，不承担交互等功能，不可以被其他模块调用
//
void showListPage();

// Function name    : GetFolder
// Description      : Open and get Folder Dialog.
// Return type      : true means click ok, false mean no select and cancel.
// Argument         : folder path reference
// Argument         : dialog window caption
// Argument         : parent window handle
bool getFolder(std::string& folderpath, const char* szCaption, HWND hOwner);

// 将指定文件夹中的音乐文件信息存到指定链表中
// 参数：
// sPtr：指定链表的表头
// 返回值：
// 成功返回0，不成功返回非0
//
int loadPathInFolder(MediaNodePtr sPtr);
