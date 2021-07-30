#include "MyTime.h"
#pragma warning(disable : 4996)

time_t timeParemeter; // 处理当前时间需要用到的参数
// struct tm *timePtr;	  // 指向结构体tm的指针变量

// 获取当前年份
int getCurrentYear()
{
	time(&timeParemeter);
	return gmtime(&timeParemeter)->tm_year + 1900;
}
// 获取当前月份
int getCurrentMonth()
{
	time(&timeParemeter);
	return gmtime(&timeParemeter)->tm_mon + 1;
}
// 获取当前天数
int getCurrentDay()
{
	time(&timeParemeter);
	return gmtime(&timeParemeter)->tm_mday;
}
// 获取当前小时数
int getCurrentHour()
{
	time(&timeParemeter);
	return gmtime(&timeParemeter)->tm_hour + 8;
}
// 获取当前分钟数
int getCurrentMinute()
{
	time(&timeParemeter);
	return gmtime(&timeParemeter)->tm_min;
}
// 获取当前秒数
int getCurrentSecond()
{
	time(&timeParemeter);
	return gmtime(&timeParemeter)->tm_sec;
}