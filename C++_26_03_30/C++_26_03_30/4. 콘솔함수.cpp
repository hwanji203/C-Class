#include "Console.h"

int main()
{
	//system("calc");
	//system("notepad");
	//system("ipconfig");

	SetConsoleGameTitle(L"2-2¹Ý °×ÇÁ");
	SetConsoleSize(80, 40);
	SetConsoleWindowStyle(true);

	while(true)
	{
		char ch = _getch();
		if(ch == '1')
			ShakeConsoleWindow(2, 1000, 50);
		else if(ch == '2')
			ShakeConsoleWindow(20, 500, 10);
	}
	//SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE)
		//, CONSOLE_FULLSCREEN_MODE, 0);
	(void)_getch();
}