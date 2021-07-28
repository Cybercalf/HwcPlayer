#include "Media.h"
using namespace std;

// 调用MCI接口对音乐文件进行操作，成功返回0，不成功返回非0
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

int openMusic(const char* path)
{
	if (path != NULL)
	{
		char cmd[1000] = "";
		strcpy_s(cmd, "open ");
		strcat_s(cmd, path);
		strcat_s(cmd, " alias BackMusic");
		// printf("cmd: %s\n", cmd);
		return MymciSendString(cmd, NULL);
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
