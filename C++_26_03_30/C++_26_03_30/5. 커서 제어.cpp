#include "Console.h"

enum class Key
{
	SPECIAL = 224,
	UP = 72,
	LEFT = 75,
	RIGHT = 77,
	DOWN = 80
};

bool Update(POINT& mousepos);
void Render(POINT mousepos);

int main()
{
	SetConsoleGameTitle(L"2-2반 겜프");
	SetConsoleSize(80, 40);
	SetConsoleWindowStyle(true);
	SetCursorVisible(false);
	SetConsoleMouseInputDisabled();
	POINT mousepos = {};
	while(!GetKeyDown(VK_ESCAPE))
	{
		if (!Update(mousepos))
			continue;
		Render(mousepos);
	}
}

bool Update(POINT& mousepos)
{
	static int posX, posY;
	static int beforeposX = 0, beforeposY = 0;
	UpdateInput();
	if(GetKey(VK_UP)) posY--;
	if(GetKeyDown(VK_MBUTTON))	posY++;
	if(GetKeyDown(VK_LBUTTON))
	{
		mousepos = GetMouseCellPos();
		//posX--;
	}
	if(GetKeyDown(VK_LBUTTON))
	{
		GotoXY(mousepos.x, mousepos.y);
		cout << "사운드 출력";
		//posX--;
	}
	if(GetKeyDown(VK_RBUTTON)) posX++;
	           
	Sleep(30);
	GotoXY(posX, posY);
	return true;

	//BOOL result = IsGotoXY(posX, posY);
	//if(result == false)
	//{
	//	posX = beforeposX;
	//	posY = beforeposY;
	//	return false;
	//}
	//else
	//{
	//	beforeposX = posX;
	//	beforeposY = posY;
	//	return true;
	//}
}

void Render(POINT mousepos)
{
	GotoXY(mousepos.x, mousepos.y);
	SetColor(Color::RED, Color::GREEN);
	_putch('a');
}
