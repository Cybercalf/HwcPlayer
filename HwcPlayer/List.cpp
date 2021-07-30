﻿#include "List.h"

Media *createMedia(const char *path)
{
	struct _finddata_t *musicInfo = (struct _finddata_t *)malloc(sizeof(struct _finddata_t));
	long handle = _findfirst(path, musicInfo);
	if (handle == -1)
	{
		return NULL; //未找到文件则返回NULL
	}
	else
	{
		// 为新建的Media结构体分配一块内存
		Media *newMedia = (Media *)malloc(sizeof(Media));
		// 初始化Media结构体中的参数
		strcpy_s(newMedia->name, sizeof(newMedia->name), musicInfo->name);
		strcpy_s(newMedia->path, sizeof(newMedia->path), path);
		
		GetShortPathName(newMedia->path, newMedia->short_path, sizeof(newMedia->short_path));

		// 通过在windows中打开对应的文件，来获取对应音频文件的有关信息
		char lengthOfTime[1024] = "";
		char cmd[1000] = "";
		strcpy_s(cmd, "open ");
		strcat_s(cmd, newMedia->short_path);
		strcat_s(cmd, " alias song");

		//打开文件
		mciSendString(cmd, NULL, 0, NULL);
		//获取音频时长，单位秒
		mciSendString("status song length", lengthOfTime, 1024, NULL);
		newMedia->length = atoi(lengthOfTime) / 1000;
		// 如果找到的音频文件时长为0，则不能创建它，直接返回NULL
		if (newMedia->length == 0)
		{
			free(newMedia);
			return NULL;
		}
		// 关闭文件
		mciSendString("close song", NULL, 0, NULL);

		_findclose(handle);

		return newMedia;
	}
}

MediaNodePtr createNode(const char *path)
{
	MediaNodePtr newNodePtr = (MediaNodePtr)malloc(sizeof(MediaNode));
	Media *tempMediaPtr = createMedia(path);
	// 新建的节点不指向任何节点，next赋值NULL
	newNodePtr->next = NULL;
	// 如果Media信息创建成功并且节点创建成功
	if (tempMediaPtr != NULL && newNodePtr != NULL)
	{
		newNodePtr->media = *tempMediaPtr; // 把Media信息传给新建的节点
		return newNodePtr;
	}
	else
	{
		if (newNodePtr != NULL)
			free(newNodePtr);
		if (tempMediaPtr != NULL)
			free(tempMediaPtr);
		return NULL;
	}
}

MediaNodePtr createList()
{
	// 创建一个链表的头，虽然具有一个节点的完整的样子，却不存储任何媒体信息
	MediaNodePtr head = (MediaNodePtr)malloc(sizeof(MediaNode));
	// 给这个头编号为0
	head->number = 0;
	// 这个头目前没有下一个节点，即链表是空的
	head->next = NULL;

	return head;
}

int isListEmpty(MediaNodePtr startPtr)
{
	return startPtr->next == NULL;
}

const char *getNodeShortPathByNumber(MediaNodePtr startPtr, unsigned int number)
{
	if (number <= 0)
		return "\0";
	char *tempPath = (char *)malloc(sizeof(char) * PATH_LENGTH);
	memset(tempPath, '\0', sizeof(tempPath));
	MediaNodePtr pMove = startPtr->next;
	// 寻找对应节点
	while (pMove != NULL && pMove->number != number)
	{
		pMove = pMove->next;
	}
	// 如果没找到
	if (pMove == NULL)
		return "\0";
	// 如果找到了
	else
	{
		strcpy_s(tempPath, sizeof(char) * PATH_LENGTH, pMove->media.short_path);
	}
	return (const char *)tempPath;
}

const char* getNodePathByNumber(MediaNodePtr startPtr, unsigned int number)
{
	if (number <= 0)
		return "\0";
	char* tempPath = (char*)malloc(sizeof(char) * PATH_LENGTH);
	memset(tempPath, '\0', sizeof(tempPath));
	MediaNodePtr pMove = startPtr->next;
	// 寻找对应节点
	while (pMove != NULL && pMove->number != number)
	{
		pMove = pMove->next;
	}
	// 如果没找到
	if (pMove == NULL)
		return "\0";
	// 如果找到了
	else
	{
		strcpy_s(tempPath, sizeof(char) * PATH_LENGTH, pMove->media.path);
	}
	return (const char*)tempPath;
}

unsigned int getNodeNumberByShortPath(MediaNodePtr startPtr, const char* short_path)
{
	MediaNodePtr pMove = startPtr->next;
	// 寻找对应节点
	while (pMove != NULL && strcmp(short_path, pMove->media.short_path) != 0)
	{
		pMove = pMove->next;
	}
	// 如果没找到
	if (pMove == NULL)
		return 0;
	// 如果找到了
	else
	{
		return pMove->number;
	}
}

unsigned int getNodeNumberByPath(MediaNodePtr startPtr, const char *path)
{
	MediaNodePtr pMove = startPtr->next;
	// 寻找对应节点
	while (pMove != NULL && strcmp(path, pMove->media.path) != 0)
	{
		pMove = pMove->next;
	}
	// 如果没找到
	if (pMove == NULL)
		return 0;
	// 如果找到了
	else
	{
		return pMove->number;
	}
}

const char * getNodePathByShortPath(MediaNodePtr startPtr, const char* short_path)
{
	MediaNodePtr pMove = startPtr->next;
	// 寻找对应节点
	while (pMove != NULL && strcmp(short_path, pMove->media.short_path) != 0)
	{
		pMove = pMove->next;
	}
	// 如果没找到
	if (pMove == NULL)
		return "\0";
	// 如果找到了
	else
	{
		return pMove->media.path;
	}
}

const char *getMediaNameByNumber(MediaNodePtr startPtr, unsigned int num)
{
	if (num <= 0)
		return "\0";
	char *tempName = (char *)malloc(sizeof(char) * NAME_LENGTH);
	memset(tempName, '\0', sizeof(tempName));
	MediaNodePtr pMove = startPtr->next;
	// 寻找对应节点
	while (pMove != NULL && pMove->number != num)
	{
		pMove = pMove->next;
	}
	// 如果没找到
	if (pMove == NULL)
		return "\0";
	// 如果找到了
	else
	{
		strcpy_s(tempName, sizeof(char) * NAME_LENGTH, pMove->media.name);
	}
	return (const char *)tempName;
}

int appendNode(MediaNodePtr &startPtr, const char *path)
{
	// 先创建一个新的节点，以便追加到链表中
	MediaNodePtr newPtr = createNode(path);
	// 如果新建节点不成功
	if (newPtr == NULL)
	{
		return -1;
	}
	// 如果新建节点成功
	else
	{
		// 寻找链表之前的节点中有没有与新建节点相同的节点
		MediaNodePtr searchPMove = startPtr->next;
		while (searchPMove != NULL)
		{
			// 如果找到，那么新建的节点不能插入
			if (strcmp(searchPMove->media.path, path) == 0)
			{
				free(newPtr);
				return -2;
			}
			else
			{
				searchPMove = searchPMove->next;
			}
		}

		MediaNodePtr pMoveFront = NULL;
		MediaNodePtr pMove = startPtr; // 现在pMove指向的是链表的头，里面没有媒体信息，需要不断向后移动来找到链表的末尾
		while (pMove != NULL)
		{
			pMoveFront = pMove;
			pMove = pMove->next;
		}
		// 经过移动两个指针，已经找到了链表的末尾，此时pMove是NULL，pMoveFront指向链表中的最后一个节点
		pMoveFront->next = newPtr;				 // 让链表原先的最后一个节点连接新建的节点，从而把新建的节点追加到链表的尾部
		newPtr->number = pMoveFront->number + 1; // 新建节点的编号比它上一个节点的编号要大1
		return 0;
	}
}

// 根据编号删除一个链表的节点
// return 0 if success, not 0 if fail
int deleteNode(MediaNodePtr &startPtr, unsigned int num)
{
	if (num <= 0)
		return -1;
	MediaNodePtr pMoveFront = startPtr;
	MediaNodePtr pMove = startPtr->next;
	// 寻找对应节点
	while (pMove != NULL && pMove->number != num)
	{
		pMoveFront = pMove;
		pMove = pMove->next;
	}
	// 如果没找到
	if (pMove == NULL)
		return -1;
	// 如果找到了
	else
	{
		pMoveFront->next = pMove->next; // 让节点脱节
		free(pMove);
		// 让后续节点的编号改变
		pMove = pMoveFront->next;
		while (pMove != NULL)
		{
			pMove->number = pMoveFront->number + 1;
			pMoveFront = pMove;
			pMove = pMove->next;
		}
		return 0;
	}
}

void clearList(MediaNodePtr &startPtr)
{
	if (isListEmpty(startPtr))
		return;
	while (0 == deleteNode(startPtr, 1))
		;
	return;
}

void printList(MediaNodePtr &startPtr)
{
	if (isListEmpty(startPtr))
	{
		puts("\t\t    音乐列表为空");
	}
	else
	{
		printf("\t\t    %-8s%-30s%-10s%-40s\n", "编号", "歌名", "时长", "路径");
		// 打印要从第一个有意义的节点开始，链表的头不存储媒体信息，所以打印要从头后面连接的第一个节点开始
		MediaNodePtr pMove = startPtr->next;
		int minutes = 0, seconds = 0;
		while (pMove != NULL)
		{
			// 把Media的时长信息转换为适合打印的字符串length
			minutes = pMove->media.length / 60;
			seconds = pMove->media.length % 60;

			char length[100] = "";
			sprintf_s(length, "%d分%d秒", minutes, seconds);
			// 打印
			printf("\t\t    %-8d%-30s%-10s%-40s\n",
				   pMove->number, pMove->media.name, length, pMove->media.path);
			// 去打印下一个节点
			pMove = pMove->next;
		}
	}
}

unsigned int getLength(MediaNodePtr startPtr)
{
	if (startPtr == NULL)
		return 0;
	else
	{
		MediaNodePtr pMoveFront = startPtr;
		MediaNodePtr pMove = startPtr->next;
		while (pMove != NULL)
		{
			pMoveFront = pMove;
			pMove = pMove->next;
		}
		return pMoveFront->number;
	}
}
