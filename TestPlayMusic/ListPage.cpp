#include "ListPage.h"
using namespace std;

MediaNodePtr g_headPtr = createList();
MediaNodePtr g_temp_headPtr = createList();

char szPathBuffer[1024];

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
			if (loadPathInFolder(g_temp_headPtr) == 0)
			{
				printList(g_temp_headPtr);
				printf("%s", "输入你想添加的音乐编号：");
				scanf("%d", &num);
				CLEAR_BUF
				if (0 == appendNode(g_headPtr, getNodePathByNumber(g_temp_headPtr, num)))
				{
					puts("添加成功");
				}
				else
				{
					puts("添加失败");
				}
				clearList(g_temp_headPtr);
				system("pause");
			}

			break;
		case '6':
			switch (loadPathInFolder(g_headPtr))
			{
			case 0:
				puts("读取成功");
				system("pause");
				break;
			default:
				puts("读取失败");
				system("pause");
				break;
			}
			break;
		case '2': // print
			printList(g_headPtr);

			system("pause");
			break;
		case '4':
			storeList(FILE_NAME, g_headPtr);
			exit = 1;
			break;
		case '5':
			printList(g_headPtr);
			printf("%s", "请输入你想要删除的文件编号：");
			scanf("%d", &num);
			CLEAR_BUF
			if(0==deleteNode(g_headPtr, num))
			{
				puts("删除成功");
			}
			else
			{
				puts("删除失败，请检查编号是否填写正确");
			}
			system("pause");
			break;
		case '7':
			clearList(g_headPtr);
			puts("请检查链表是否清空");
			system("pause");
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
		"1. 从选择的文件夹中添加一个文件到播放列表\n"
		"6. 导入一个文件夹下的音乐文件\n"
		"2. 打印链表节点\n"
		"5. 删除一个节点\n"
		"7. 清空节点\n"
		"4. exit"
	);
}


// Function name    : GetFolder
// Description      : Open and get Folder Dialog.
// Return type      : true means click ok, false mean no select and cancel.
// Argument         : folder path reference
// Argument         : dialog window caption
// Argument         : parent window handle
bool GetFolder(std::string& folderpath, const char* szCaption, HWND hOwner)
{
	bool retVal = false;

	// The BROWSEINFO struct tells the shell
	// how it should display the dialog.
	BROWSEINFO bi;
	memset(&bi, 0, sizeof(bi));
	bi.ulFlags = BIF_USENEWUI;
	bi.hwndOwner = hOwner;
	bi.lpszTitle = szCaption;

	// must call this if using BIF_USENEWUI
	::OleInitialize(NULL);

	// Show the dialog and get the itemIDList for the selected folder.
	LPITEMIDLIST pIDL = ::SHBrowseForFolder(&bi);

	if (pIDL != NULL)
	{
		// Create a buffer to store the path, then get the path.
		char buffer[_MAX_PATH] = {'\0'};
		if (::SHGetPathFromIDList(pIDL, buffer) != 0)
		{
			// Set the string value.
			folderpath = buffer;
			retVal = true;
		}

		// free the item id list
		CoTaskMemFree(pIDL);
	}

	::OleUninitialize();

	return retVal;
}

int loadPathInFolder(MediaNodePtr sPtr)
{
	long handle; //用于查找的句柄
	std::string szPath("");

	if (GetFolder(szPath, "请选择你想打开的文件夹", NULL) == true)
	{
		char* cc;
		int length = strlen(szPath.c_str());
		cc = new char[length + 1];
		strcpy(cc, szPath.c_str());
		const char* to_search = strcat(cc, "\\*");
		struct _finddata_t fileinfo; //文件信息的结构体
		handle = _findfirst(to_search, &fileinfo); //第一次查找
		if (-1 == handle) return -1;
		sprintf(szPathBuffer, "%s\\%s", szPath.c_str(), fileinfo.name); //打印出找到的文件的文件名这个不能并入while
		appendNode(sPtr, szPathBuffer);
		while (!_findnext(handle, &fileinfo)) //循环查找其他符合的文件，知道找不到其他的为止
		{
			sprintf(szPathBuffer, "%s\\%s", szPath.c_str(), fileinfo.name);
			appendNode(sPtr, szPathBuffer);
		}
	}
	else // no folder selected
	{
		return -1;
	}
	_findclose(handle); //别忘了关闭句柄
	return 0;
}
