#include "Console.h"

void Count()
{
	for(int i = 3; i > 0; --i)
	{
		SetColor(Color::WHITE, Color::BLACK);
		GotoXY(10, 10);
		cout << 3 - i << "...";

		cout << "°×ÇÁ´Â ²ÜÀë";
		Sleep(500);
		
		GotoXY(10, 10);
		SetColor(Color::BLACK, Color::BLACK);
		cout << "°×ÇÁ´Â ²ÜÀë";
		Sleep(500);
	}

	system("cls");
}

void Text()
{
	for(int i = 0; i < (int)Color::END; i++)
	{
		GotoXY(i, i);
		SetColor((Color)i, Color::BLACK);
		cout << "ColorNumber: ";
		SetColor(Color::WHITE, Color::BLACK);
		cout << i;
	}
}

int main()
{
	//cout << std::setw(5) << 11 << 12;
	int maxHp = 100;
	int hp = maxHp;
	ULONGLONG startTick = GetTickCount64();
	DrawBar(0, 0, "HP", hp, maxHp, 10);
	while(true)
	{
		if(_kbhit())
		{
			char ch = _getch();
			if(ch == '1')
			{
				hp = std::max(0, hp - 10);
			}
			else if(ch == '2')
			{
				hp = std::min(maxHp, hp + 10);
			}
		}
		if(GetTickCount64() - startTick >= 1000)
		{
			hp = std::max(0, hp - 10);
			startTick = GetTickCount64();
		}
		DrawBar(0, 0, "HP", hp, maxHp, 10);
		FrameSync(60);
	}
	SetColor(Color::WHITE, Color::BLACK);
	Count();
	Text();
}