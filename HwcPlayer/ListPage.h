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

// 函数名：GetFolder
// 描述 : 打开并获取文件夹对话框。
// 返回类型：true 表示点击确定，false 表示不选择和取消。
// 参数：文件夹路径引用
// 参数：对话框窗口标题
// 参数：父窗口句柄
bool getFolder(std::string& folderpath, const char* szCaption, HWND hOwner);

// 将指定文件夹中的音乐文件信息存到指定链表中
// 参数：
// sPtr：指定链表的表头
// 返回值：
// 成功返回0，不成功返回非0
//
int loadPathInFolder(MediaNodePtr sPtr);
