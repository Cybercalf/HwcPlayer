// TextColor.h：存储有关控制台文本颜色操作的函数和相关参数
#pragma once
#include "Glue.h"
/*
基本文本属性
FOREGROUND_BLUE 蓝色
FOREGROUND_GREEN 绿色
FOREGROUND_RED 红色
FOREGROUND_INTENSITY 加强
BACKGROUND_BLUE 蓝色背景
BACKGROUND_GREEN 绿色背景
BACKGROUND_RED 红色背景
BACKGROUND_INTENSITY 背景色加强
COMMON_LVB_REVERSE_VIDEO 反色
*/

const WORD FORE_BLUE = FOREGROUND_BLUE;           //蓝色文本属性  
const WORD FORE_GREEN = FOREGROUND_GREEN;          //绿色文本属性  
const WORD FORE_RED = FOREGROUND_RED;            //红色文本属性  
const WORD FORE_PURPLE = FORE_BLUE | FORE_RED;      //紫色文本属性  
const WORD FORE_CYAN = FORE_BLUE | FORE_GREEN;    //青色文本属性  
const WORD FORE_YELLOW = FORE_RED | FORE_GREEN;     //黄色文本属性  
const WORD FORE_GRAY = FOREGROUND_INTENSITY;      //灰色文本属性


const WORD BACK_BLUE = BACKGROUND_BLUE;           //蓝色背景属性  
const WORD BACK_GREEN = BACKGROUND_GREEN;          //绿色背景属性  
const WORD BACK_RED = BACKGROUND_RED;            //绿色背景属性  
const WORD BACK_PURPLE = BACK_BLUE | BACK_RED;      //紫色背景属性  
const WORD BACK_CYAN = BACK_BLUE | BACK_GREEN;    //青色背景属性  
const WORD BACK_YELLOW = BACK_RED | BACK_GREEN;     //黄色背景属性  
const WORD BACK_GRAY = BACKGROUND_INTENSITY;      //灰色背景属性

const WORD FORE_WHITE = FORE_RED | FORE_GREEN | FORE_BLUE; // 白色文本属性
const WORD FORE_BRIGHT_CYAN = FORE_BLUE | FORE_GREEN | FOREGROUND_INTENSITY; // 天青色文本属性

// 设置控制台标准输出的字体颜色
void setConsoleTextColor(WORD fore_color);
