// List.h: 存储所有对媒体信息链表操作有关的函数
#pragma once
#ifndef LIST_H
#define LIST_H
#include "Glue.h"

#define NAME_LENGTH 200
#define PATH_LENGTH 500

typedef struct
{
	char name[NAME_LENGTH]; //歌名(文件名） 更详细的歌曲信息需要读取mp3文件的IDv2标签
	char path[PATH_LENGTH]; //绝对路径
	char short_path[PATH_LENGTH];
	int length;				//时长
} Media;

struct medianode
{
	unsigned int number; //编号
	Media media;
	struct medianode *next;
};

typedef struct medianode MediaNode;
typedef MediaNode *MediaNodePtr;

// 根据文件路径创建一个Media结构体，返回它的地址
Media *createMedia(const char *path);

// 根据文件路径创建一个节点，返回它的地址
MediaNodePtr createNode(const char *path);

// 创建一个空链表，返回这个链表的地址
// 请注意，虽然返回的地址理论上指向一个节点，但是这个节点不存储任何媒体信息，只有其中的next有意义
// 即这个函数只创建一个链表的头，后续的追加操作都是在这个头之后进行
MediaNodePtr createList();

// 判断链表是否为空
// return 1 if yes, 0 if no
int isListEmpty(MediaNodePtr startPtr);

// 接收一个节点编号，返回对应节点的短路径
const char *getNodeShortPathByNumber(MediaNodePtr startPtr, unsigned int number);

// 接收一个节点路径，返回对应节点的编号
unsigned int getNodeNumberByPath(MediaNodePtr startPtr, const char *path);

// 根据文件位置生成一个Media结构体和与之对应的节点，把它添加到链表末尾
// return 0 if success, not 0 if fail
int appendNode(MediaNodePtr &startPtr, const char *path);

// 根据编号删除一个链表的节点
// return 0 if success, not 0 if fail
int deleteNode(MediaNodePtr &startPtr, unsigned int num);

// 清空以传入地址为首的整个链表，将其节点依次free掉
void clearList(MediaNodePtr &startPtr);

// 打印以传入地址为首的链表的每个节点
void printList(MediaNodePtr &startPtr);

// 返回链表长度（在数值上等于链表最后一个节点的编号）
unsigned int getLength(MediaNodePtr startPtr);

// 根据编号返回节点的音乐名称
const char *getMediaNameByNumber(MediaNodePtr startPtr, unsigned int num);

#endif
