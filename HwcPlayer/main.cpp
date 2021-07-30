#include "main.h"


// main():程序的入口和出口
// 承担3个功能：
// 1. 在程序开始时读取存储在文件中的播放列表信息
// 2. 进入主菜单页面
// 3. 在程序结束是将播放列表信息存储在文件中
//
int main(void)
{
	readList(LIST_FILE_NAME, g_headPtr);
	mainPage();
	storeList(LIST_FILE_NAME, g_headPtr);
}
