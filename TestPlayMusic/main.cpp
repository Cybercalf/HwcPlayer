#include "main.h"

int main(void)
{
	readList(FILE_NAME, g_headPtr);
	mainMenuPage();
	storeList(FILE_NAME, g_headPtr);
	// system("pause");
}
