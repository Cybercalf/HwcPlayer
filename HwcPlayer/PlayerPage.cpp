﻿#include "PlayerPage.h"

using namespace std;

char processBarBuf[100];
char szStatusBuf[1024];
char szPlayStatusBuf[1024];
char szMediaNameBuf[1024];
char szMediaSpeedBuf[10];
char isSongMuteBuf[10];
char lrcBuf[200];

int temp_song_volume = 0;

unsigned int number = 1;

enum PLAY_STATUS play_mode = STATUS_PLAY_SEQUENCE;
enum STATUS status = STATUS_STOPPED;
enum SONG_MUTE_STATUS song_mute_status = NOT_MUTE;

void playerPage()
{
	// 结束程序的标志
	int exit = 0;
	openMusicByShortPath(getNodeShortPathByNumber(g_headPtr, number));
	while (exit == 0)
	{
		while (!_kbhit())
		{
			showPlayerPage();
			if (status == STATUS_STOPPED &&
				getMusicCurrentPosition() == getMusicLength())
			{
				playMusicDown();
			}
			Sleep(800);
		}

		switch (_getch())
		{
		case 'p':
		case 'P': // 播放与暂停
			if (status == STATUS_STOPPED)
			{
				playMusic();
				status = STATUS_PLAY;
			}
			else if (status == STATUS_PLAY)
			{
				pauseMusic();
				status = STATUS_PAUSE;
			}
			else if (status == STATUS_PAUSE)
			{
				resumeMusic();
				status = STATUS_PLAY;
			}
			break;

		case 'd':
		case 'D': // 切换播放模式
			switch_play_status();
			break;
		case 'j':
		case 'J': // 跳转到指定曲目
			printList(g_headPtr);
			printf("%s\n", "请输入你想跳转的音乐编号：");
			int temp_num;
			scanf("%u", &temp_num);
			CLEAR_BUF
			if (temp_num >= 1 && temp_num <= getLength(g_headPtr))
			{
				number = temp_num;
				closeMusic();
				openMusicByShortPath(getNodeShortPathByNumber(g_headPtr, number));
				playMusic();
			}
			else
			{
				puts("打开失败，请检查编号填写是否正确");
				system("pause");
			}
			break;
		case 't':
		case 'T':
			playMusicUp();
			break;
		case 'y':
		case 'Y': // 播放下一首
			// 当播放模式为单曲循环时，需要临时更改它以便播放列表的下一首
			if (play_mode == STATUS_PLAY_REPEAT)
			{
				play_mode = STATUS_PLAY_SEQUENCE;
				playMusicDown();
				play_mode = STATUS_PLAY_REPEAT;
			}
			else
			{
				playMusicDown();
			}
			break;
		case 'u':
		case 'U':
			stepBackward10Sec();
			break;
		case 'i':
		case 'I':
			stepForward10Sec();
			break;
		case 's':
		case 'S':
			switchMusicSpeed();
			break;
		case '_':
		case '-':
			audioVolumeDown();
			break;
		case '+':
		case '=':
			audioVolumeUp();
			break;
		case '*':
		case '8':
			songVolumeDown();
			break;
		case '(':
		case '9':
			songVolumeUp();
			break;
		case 'm':
		case 'M':
			switchSongMute();
			break;
		case 'q':
		case 'Q':
			exit = 1;
			break;
		default:
			break;
		}
	}
}

// 显示命令
void showPlayerPage()
{
	system("cls");
	// 把要输出的信息存储在不同的字符串中
	loadProcessBarBuf(getMusicCurrentPosition(), getMusicLength());
	loadStatusBuf();
	loadPlayStatusBuf();
	loadMediaNameBuf();
	loadMediaSpeedBuf();
	loadIsSongMuteBuf();
	loadLrcBuf();

	puts(
		"\n\n"
		"\t\t    * * * * * * * *                   * * * * * * * *\n"
		"\t\t    * * * * * *         音    乐          * * * * * *\n"
		"\t\t    * * * * * * * *                   * * * * * * * *\n");
	
	printf("\t\t    正在播放：         %-s\n"
	       "\t\t    播放状态：         %-s\n"
	       "\t\t    播放模式：         %-s\n"
	       "\t\t    播放速度：         %-s\n",
	       szMediaNameBuf, szStatusBuf,
	       szPlayStatusBuf, szMediaSpeedBuf);
	
	printf("\t\t    当前系统音量       %-5d\n"
	       "\t\t    当前播放器音量     %-.1f%%\n"
	       "\t\t    播放器是否静音     [%s]\n\n",
	       getAudioVolume(), getSongVolume() / 10.0, isSongMuteBuf);

	setConsoleTextColor(FORE_BRIGHT_CYAN);
	printf("\t\t    %s\n\n", lrcBuf);

	setConsoleTextColor(FORE_WHITE);
	printf("\t\t    %s\n\n", processBarBuf);
	
	printf("\t\t       [ P ]  播放/暂停        [ D ]  切换播放模式\n"
	       "\t\t       [ J ]  跳转到指定曲目   [ S ]  调整倍速\n"
	       "\t\t       [ T ]  上一曲           [ Y ]  下一曲\n"
	       "\t\t       [ U ]  快退10秒         [ I ]  快进10秒\n"
	       "\t\t       [ - ]  减小系统音量     [ + ]  增大系统音量\n"
	       "\t\t       [ 8 ]  减小播放器音量   [ 9 ]  增大播放器音量\n"
	       "\t\t       [ M ]  静音/取消静音    [ Q ]  返回\n"
	);
}

void loadProcessBarBuf(int nowTime, int musicTime)
{
	int pos;
	// 时间单位为毫秒，所以需要先转成秒
	pos = sprintf(processBarBuf,
	              "%02d:%02d ",
	              nowTime / 60000 % 100,
	              nowTime / 1000 % 60);
	if (musicTime == 0)
	{
		for (int i = 0; i < 50; i++)
		{
			pos += sprintf(processBarBuf + pos, "%c", '-');
		}
	}
	else
	{
		int percentage = 50 * nowTime / musicTime;
		for (int i = 0; i < percentage; i++)
		{
			pos += sprintf(processBarBuf + pos, "%c", '*');
		}
		for (int i = percentage; i < 50; i++)
		{
			pos += sprintf(processBarBuf + pos, "%c", '-');
		}
	}
	pos += sprintf(processBarBuf + pos,
	               " %02d:%02d",
	               musicTime / 60000 % 100,
	               musicTime / 1000 % 60);
}

void loadStatusBuf()
{
	MymciSendString("status BackMusic mode", szStatusBuf);
	if (strcmp(szStatusBuf, "paused") == 0)
		status = STATUS_PAUSE;
	else if (strcmp(szStatusBuf, "stopped") == 0)
		status = STATUS_STOPPED;
	else if (strcmp(szStatusBuf, "playing") == 0)
		status = STATUS_PLAY;
}

void loadPlayStatusBuf()
{
	switch (play_mode)
	{
	case STATUS_PLAY_SEQUENCE:
		sprintf(szPlayStatusBuf, "%s", "列表循环");
		break;
	case STATUS_PLAY_REPEAT:
		sprintf(szPlayStatusBuf, "%s", "单曲循环");
		break;
	case STATUS_PLAY_RANDOM:
		sprintf(szPlayStatusBuf, "%s", "随机播放");
		break;
	default:
		break;
	}
}

void loadMediaNameBuf()
{
	sprintf(szMediaNameBuf, "%s", getMediaNameByNumber(g_headPtr, number));
}

void loadMediaSpeedBuf()
{
	sprintf(szMediaSpeedBuf, "X %.2f", getMusicSpeed() * 1.0 / 1000);
}

void loadIsSongMuteBuf()
{
	if (song_mute_status == MUTE)
		sprintf(isSongMuteBuf, "%s", "是\0");
	else
		sprintf(isSongMuteBuf, "%s", "否\0");
}

void loadLrcBuf()
{
	if (isLrcListEmpty()) // 如果歌词链表为空，说明加载歌词失败
	{
		memset(lrcBuf, '\0', sizeof(lrcBuf));
		sprintf(lrcBuf, "%s", "未找到歌词，请欣赏\0");
	}
	else
	{
		const char* tempstr = getLrcByTime(getMusicCurrentPosition() / 1000); // 除以1000是为了把毫秒单位转为秒
		if (0 != strcmp(tempstr, "\0")) // 如果getLrcByTime未返回0，说明获取歌词成功
		{
			memset(lrcBuf, '\0', sizeof(lrcBuf));
			sprintf(lrcBuf, "%s", tempstr);
		}
	}
}

void switch_play_status()
{
	switch (play_mode)
	{
	case STATUS_PLAY_SEQUENCE:
		play_mode = STATUS_PLAY_REPEAT;
		break;
	case STATUS_PLAY_REPEAT:
		play_mode = STATUS_PLAY_RANDOM;
		break;
	case STATUS_PLAY_RANDOM:
		play_mode = STATUS_PLAY_SEQUENCE;
		break;
	}
}

void playMusicUp()
{
	closeMusic();
	number -= 1;
	if (number <= 0)
		number = getLength(g_headPtr);
	if (openMusicByShortPath(getNodeShortPathByNumber(g_headPtr, number)) == 0)
		playMusic();
	return;
}

void playMusicDown()
{
	closeMusic();
	switch (play_mode)
	{
	case STATUS_PLAY_SEQUENCE:
		number += 1;
		if (number > getLength(g_headPtr))
			number = 1;
		break;
	case STATUS_PLAY_REPEAT:
		break;
	case STATUS_PLAY_RANDOM:
		srand(time(0));
		number = rand() % getLength(g_headPtr) + 1;
		break;
	}
	if (openMusicByShortPath(getNodeShortPathByNumber(g_headPtr, number)) == 0)
		playMusic();
	return;
}

void stepForward10Sec()
{
	int jumpTime = getMusicCurrentPosition() + 10000;
	if (jumpTime > getMusicLength())
		jumpTime = getMusicLength();
	seekToPosition(jumpTime);
	playMusic();
}

void stepBackward10Sec()
{
	int jumpTime = getMusicCurrentPosition() - 10000;
	if (jumpTime < 0)
		jumpTime = 0;
	seekToPosition(jumpTime);
	playMusic();
}

void switchMusicSpeed()
{
	switch (getMusicSpeed())
	{
	case 1000:
		setMusicSpeed(1250);
		break;
	case 1250:
		setMusicSpeed(800);
		break;
	case 800:
		setMusicSpeed(1000);
		break;
	default:
		break;
	}
}


void switchSongMute()
{
	if (song_mute_status == NOT_MUTE)
	{
		temp_song_volume = getSongVolume();
		setSongMute(true);
		song_mute_status = MUTE;
	}
	else
	{
		setSongMute(false);
		setSongVolume(temp_song_volume);
		song_mute_status = NOT_MUTE;
	}
}

void audioVolumeUp()
{
	int audio_volume = (getAudioVolume() + 2);
	if (audio_volume > 100)
		audio_volume = 100;
	setAudioVolume(audio_volume);
}

void audioVolumeDown()
{
	int audio_volume = (getAudioVolume() - 2);
	if (audio_volume < 0)
		audio_volume = 0;
	setAudioVolume(audio_volume);
}

void songVolumeUp()
{
	int song_volume = (getSongVolume() + 50);
	if (song_volume > 1000)
		song_volume = 1000;
	setSongVolume(song_volume);
}

void songVolumeDown()
{
	int song_volume = (getSongVolume() - 50);
	if (song_volume < 0)
		song_volume = 0;
	setSongVolume(song_volume);
}
