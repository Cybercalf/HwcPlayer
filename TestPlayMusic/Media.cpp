#include "Media.h"
using namespace std;

void MymciSendString(const char* szCommand, char* szbuffer)
{
	if (NULL == szbuffer)
	{
		if (0 != mciSendString(szCommand, NULL, 0, NULL))
		{
			printf("%s false!\n", szCommand);
		}
		else
		{
			printf("%s success!\n", szCommand);
		}
	}
	else
	{
		if (0 != mciSendString(szCommand, szbuffer, 1024, NULL))
		{
			printf("%s false!\n", szCommand);
		}
		else
		{
			printf("%s success!\n", szCommand);
		}
	}
}

int openMusic(char* path)
{
	if (path != NULL)
	{
		char cmd[1000] = "";
		strcpy_s(cmd, "open ");
		strcat_s(cmd, path);
		strcat_s(cmd, " alias BackMusic");
		// printf("%s\n", cmd);
		MymciSendString(
			cmd,
			NULL);
		return 0;
	}
	return -1;
}
