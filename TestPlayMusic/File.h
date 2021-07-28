#pragma once
#include "List.h"
#include <fstream>
#include <iostream>
#define LIST_FILE_NAME "test.dat"

void storeList(const char* filename, MediaNodePtr currentPtr);
void readList(const char* filename, MediaNodePtr sPtr);
void printPic();