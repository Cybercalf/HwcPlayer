#include "main.h"

int main(void)
{
	readList(LIST_FILE_NAME, g_headPtr);
	mainMenuPage();
	storeList(LIST_FILE_NAME, g_headPtr);
	// system("pause");
}
