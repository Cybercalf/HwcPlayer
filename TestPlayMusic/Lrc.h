// Lrc.h: 处理有关歌词的函数和相关参数
#pragma once
#include "Glue.h"

// 一句歌词
typedef struct lrc
{
	int time; // 歌词对应的时间，单位是秒
	char buf[200]; // 歌词
} Lrc;

// 一句歌词的节点
typedef struct lrcnode
{
	Lrc lrc;
	struct lrcnode* next;
} LrcNode;

typedef LrcNode* LrcNodePtr;

extern LrcNodePtr g_lrc_head_ptr;

// 创建歌词链表，返回链表的表头
LrcNodePtr createLrcList();

// 向歌词链表中追加一个节点
void appendLrcNode(Lrc lrc);

// 打开一个.lrc文件，并将其信息加载到歌词链表中
// 参数：
// filename:对应歌词文件的文件名（绝对路径）
// 成功返回0，不成功返回非0
// 请注意，一个.mp3文件对应的歌词文件名应以.mp3.lrc为后缀
int loadIrcList(const char* filename);

// 清空歌词链表
void clearLrcList();

// 检测歌词链表是否为空
// 是，返回true；否，返回false
bool isLrcListEmpty();

// 接收一个整数作为时间(单位为秒），返回指定歌词节点的字符串，如果没找到返回"\0"
const char* getLrcByTime(int time);