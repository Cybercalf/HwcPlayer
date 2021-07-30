#include "Buf.h"

HANDLE hOutput, hOutBuf;
//两个句柄，这里可以就理解为我们等会需要用的两个缓冲区
COORD coord; //位置坐标，用到的时候解释
DWORD bytes = 0; //这个主要是要配合下面的一个函数
//初始化我们的缓存区
void initconsoleScreenBuffer()
{
    hOutBuf = CreateConsoleScreenBuffer(  //创建缓冲区
        GENERIC_WRITE,
        FILE_SHARE_WRITE,
        NULL,
        CONSOLE_TEXTMODE_BUFFER,
        NULL
    );
    hOutput = CreateConsoleScreenBuffer(  //创建缓冲区
        GENERIC_WRITE,
        FILE_SHARE_WRITE,
        NULL,
        CONSOLE_TEXTMODE_BUFFER,
        NULL
    );
    //以下5行是设置这两个缓冲区的光标不可见
    CONSOLE_CURSOR_INFO cci;  //创建光标
    cci.bVisible = 0;    //光标可见度为0
    cci.dwSize = 1;      //光标大小为1，可省略
    SetConsoleCursorInfo(hOutput, &cci); //设置第一个缓冲区的光标参数
    SetConsoleCursorInfo(hOutBuf, &cci); //设置第二个缓冲区的光标参数
}
