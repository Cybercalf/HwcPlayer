#include "ListPage.h"
using namespace std;



MediaNodePtr g_headPtr = createList();

void listPage()
{
	int exit = 0; // 页面退出的标志
	int num = 0; // 用户输入的节点编号
	char path[PATH_LENGTH] = "";

	while (!exit)
	{
		showListPage();
		switch (_getch())
		{
		case '1':
			strcpy_s(path, "");
			printf("请输入您要添加的mp3文件的路径:\n");
			scanf("%s", path);
			CLEAR_BUF
			switch (appendNode(g_headPtr, path))
			{
			case 0:
				puts("添加成功");
				break;
			case -1:
				puts("新建节点失败");
				break;
			case -2:
				puts("列表中已有该曲目，不能重复添加");
				break;
			}
			system("pause");

			break;
		case '2': // print
			printList(g_headPtr);

			system("pause");
			break;
		case '4':
			exit = 1;
			break;
		case '5':
			printf("%s", "删除编号：");
			scanf("%d", &num);
			switch (deleteNode(g_headPtr, num))
			{
			case 0:
				puts("删除成功");
				system("pause");
				break;
			default:
				puts("删除不成功");
				system("pause");
				break;
			}
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
		"5. 删除一个节点\n"
		"4. exit"
	);
}
