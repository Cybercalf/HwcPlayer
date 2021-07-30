#include "Media.h"
using namespace std;

int MymciSendString(const char* szCommand, char* szbuffer)
{
	if (NULL == szbuffer)
	{
		if (0 != mciSendString(szCommand, NULL, 0, NULL)) return -1;
		else return 0;
	}
	else
	{
		if (0 != mciSendString(szCommand, szbuffer, 1024, NULL)) return -2;
		else return 0;
	}
}

int openMusicByShortPath(const char* short_path)
{
	if (short_path != NULL)
	{
		char cmd[1000] = "";
		strcpy_s(cmd, "open ");
		strcat_s(cmd, short_path);
		strcat_s(cmd, " alias BackMusic");
		if (0 == MymciSendString(cmd, NULL)) // 如果打开音乐成功，就可以尝试加载歌词文件了
		{
			clearLrcList(); // 清空歌词链表，为之后加载做准备
			char lrcpath[PATH_LENGTH] = ""; // 要打开的歌词文件路径
			// 先根据传入的短路径转换成路径，然后用它来初始化歌词文件路径
			int pos = sprintf(lrcpath, "%s",
			                  getNodePathByShortPath(g_headPtr, short_path)) - 4; // pos用于确定字符串写入的起始位置
			pos += sprintf(lrcpath + pos, "%s", ".lrc");
			// 到此，lrcpath应存储着一个和音乐文件同名的、只有后缀名改为".lrc"的绝对路径（长路径而非短路径）
			loadIrcList(lrcpath); // 利用这个路径加载歌词文件

			return 0; // 如果打开音乐成功，无论加载歌词成功与否，都要返回0。歌词加载成功与否，可以通过检查歌词链表是否为空实现
		}
	}
	return -1;
}

int closeMusic()
{
	char cmd[1000] = "close BackMusic";
	return MymciSendString(cmd, NULL);
}

int playMusic()
{
	char cmd[1000] = "";
	sprintf(cmd, "%s", "play BackMusic");
	return MymciSendString(cmd, NULL);
}

int playMusicRepeat()
{
	char cmd[1000] = "play BackMusic repeat";
	return MymciSendString(cmd, NULL);
}

int stopMusic()
{
	char cmd[1000] = "stop BackMusic";
	return MymciSendString(cmd, NULL);
}

int pauseMusic()
{
	char cmd[1000] = "pause BackMusic";
	return MymciSendString(cmd, NULL);
}

int resumeMusic()
{
	char cmd[1000] = "resume BackMusic";
	return MymciSendString(cmd, NULL);
}

int getMusicCurrentPosition()
{
	char szTimeBuffer[1024];
	MymciSendString("status BackMusic position", szTimeBuffer);
	return atoi(szTimeBuffer);
}

int getMusicLength()
{
	char szTimeBuffer[1024];
	MymciSendString("status BackMusic length", szTimeBuffer);
	return atoi(szTimeBuffer);
}

int seekToPosition(int position)
{
	char cmd[1000] = "";
	sprintf(cmd, "seek BackMusic to %d", position);
	return MymciSendString(cmd, NULL);
}

int getMusicSpeed()
{
	char szSpeedBuffer[1024];
	MymciSendString("status BackMusic speed", szSpeedBuffer);
	return atoi(szSpeedBuffer);
}

void setMusicSpeed(int speed)
{
	char cmd[1000] = "";
	sprintf(cmd, "set BackMusic speed %d", speed);
	MymciSendString(cmd, NULL);
}
