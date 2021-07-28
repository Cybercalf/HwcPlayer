// File.h: 与文件存储和读取有关的操作函数
#pragma once
#include "Glue.h"
#include "List.h"
#define LIST_FILE_NAME "test.dat"

// 将指定链表的信息以二进制形式存储在指定的文件中，如果文件不存在会被创建，已存在则会先删除后创建
// 参数：
// filename: 文件名
// currentPtr：指定链表的表头
//
void storeList(const char *filename, MediaNodePtr currentPtr);

// 从指定的文件中读取链表信息，并存储到指定链表中
// 参数：
// filename：文件名
// sPtr：指定链表的表头
//
void readList(const char *filename, MediaNodePtr sPtr);
