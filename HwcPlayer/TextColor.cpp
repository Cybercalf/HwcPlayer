#include "TextColor.h"

void setConsoleTextColor(WORD fore_color)
{
    HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);    //获得标准输出设备句柄  
    CONSOLE_SCREEN_BUFFER_INFO csbi;                        //定义窗口缓冲区信息结构体  
    GetConsoleScreenBufferInfo(handle_out, &csbi);          //获得窗口缓冲区信息  
    SetConsoleTextAttribute(handle_out, fore_color);
}