#pragma once
#include "Glue.h"

extern HANDLE hOutput, hOutBuf;
//两个句柄，这里可以就理解为我们等会需要用的两个缓冲区
extern COORD coord;  //位置坐标，用到的时候解释
extern DWORD bytes;        //这个主要是要配合下面的一个函数
void initconsoleScreenBuffer();     //初始化我们的缓存区
