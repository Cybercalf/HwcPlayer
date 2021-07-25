#include "ListPage.h"
using namespace std;

enum STATUS
{
	STATUS_STOP = 0,
	STATUS_PLAY,
	STATUS_PAUSE,
}; //用枚举变量限制状态的变化范围

MediaNodePtr g_headPtr = createList();

void listPage()
{
	int exit = 0; // 页面退出的标志
	char path[200] = ""; // 用户输入的文件路径
	int num = 0; // 用户输入的节点编号
	while (!exit)
	{
		showListPage();
		switch (_getch())
		{
		case '1':
			strcpy_s(path, "");
			printf("请输入您要添加的mp3文件的路径:\n");

			scanf("%s", path);
			if (appendNode(g_headPtr, path) != -1)
			{
				printf("添加成功\n");
			}
			else
			{
				printf("添加失败\n");
			}
			system("pause");
			break;
		case '2': // print
			printList(g_headPtr);
			
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
			puts("invalid choice.");
			system("pause");
			
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
		"4. exit"
	);
}
