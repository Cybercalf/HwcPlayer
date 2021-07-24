#include "ListPage.h"
using namespace std;

void listPage()
{
	int exit = 0;
	while (!exit)
	{
		showListPage();
		switch (_getch())
		{
			break;
		case '2': // print
			system("pause");
			break;
		case '3': // swap
			system("pause");
			break;
		case '4':
			printf("%s", "即将退出此界面!\n");
			system("pause");
			exit = 1;
			break;
		default:
			break;
		}
	}
}

void showListPage()
{
	system("cls");
	puts("这里是播放列表页面！\n"
		"1. 为链表中添加一个节点\n"
		"2. 打印链表节点\n"
		"3. 交换两个节点的位置\n"
		"4. exit"
	);
}
