// List.h: 存储所有对媒体信息链表操作有关的函数
#pragma once
#ifndef LIST_H
#define LIST_H
#pragma comment(lib, "winmm.lib")
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <windows.h>
#include <mmsystem.h>
#include <io.h>

#define NAME_LENGTH 200
#define PATH_LENGTH 500

typedef struct
{
	char name[NAME_LENGTH]; //歌名(文件名） 更详细的歌曲信息需要读取mp3文件的IDv2标签
	char path[PATH_LENGTH]; //绝对路径
	int length; //时长
} Media;

struct medianode
{
	unsigned int number; //编号
	Media media;
	struct medianode* next;
};

typedef struct medianode MediaNode;
typedef MediaNode* MediaNodePtr;

// 根据文件路径创建一个Media结构体，返回它的地址
Media* createMedia(const char* path);

// 根据文件路径创建一个节点，返回它的地址
MediaNodePtr createNode(const char* path);

// 创建一个空链表，返回这个链表的地址
// 请注意，虽然返回的地址理论上指向一个节点，但是这个节点不存储任何媒体信息，只有其中的next有意义
// 即这个函数只创建一个链表的头，后续的追加操作都是在这个头之后进行
MediaNodePtr createList();

// 判断链表是否为空
// return 1 if yes, 0 if no
int isListEmpty(MediaNodePtr startPtr);

// 接收一个节点编号，返回对应节点的路径
const char* getNodePathByNumber(MediaNodePtr startPtr, unsigned int number);

// 接收一个节点路径，返回对应节点的编号
unsigned int getNodeNumberByPath(MediaNodePtr startPtr, const char* path);

// 根据文件位置生成一个Media结构体和与之对应的节点，把它添加到链表末尾
// return 0 if success, not 0 if fail
int appendNode(MediaNodePtr& startPtr, const char* path);

// 根据编号删除一个链表的节点
// return 0 if success, not 0 if fail
int deleteNode(MediaNodePtr& startPtr, unsigned int num);

// 清空以传入地址为首的整个链表，将其节点依次free掉
void clearList(MediaNodePtr& startPtr);

// 打印以传入地址为首的链表的每个节点
void printList(MediaNodePtr& startPtr);

// 返回链表长度
unsigned int getLength(MediaNodePtr startPtr);

#endif



// // // 创建一个Media节点的实例。返回一个指向该新建的节点的指针。新建节点默认不与其他节点连接
// // MediaNodePtr getNewMediaNode(unsigned int id, const char* fileName, const char* songName, const char* singerName,
// //                          const char* timeLength, const char* fileType, const char* location);
//
// // 在链表中追加一个媒体节点，成功返回非0值，不成功返回0
// int appendMediaNode(MediaNodePtr* sPtr, Media value);
//
// // 在链表中根据id删除一个媒体节点，成功返回非0值，不成功返回0
// int deleteMediaNodeById(MediaNodePtr* sPtr, unsigned int id);
//
// // // 在链表中根据歌曲名查找所有符合条件的链表信息。
// // // 返回一个指向新链表头部的指针，新链表存储所有符合条件的媒体节点
// // // 不成功返回NULL
// // MediaNodePtr searchAllMediaBySongName(MediaNodePtr sPtr, const char* songName);
//
// // 从头打印链表中所有节点的信息，成功返回1，不成功返回0
// int printMediaLinkList(MediaNodePtr sPtr);
//
// // 根据id交换链表中两个媒体节点的位置，成功返回1，不成功返回0
// int swapTwoMediaNodeById(MediaNodePtr * sPtr, unsigned int firstId, unsigned int secondId);
//
// // 根据id查找链表中的一个节点，成功返回一个指向符合要求的媒体节点的指针
// // 不成功返回NULL
// MediaNodePtr searchAMediaNodeById(MediaNodePtr sPtr, unsigned int id);
