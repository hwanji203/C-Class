#include "TitleScene.h"
#include "Console.h"

void UpdateTitle(GameState& state)
{
	if(GetKeyDown(VK_UP))
	{
		state.curMenu = (Menu)std::max(0, (int)state.curMenu - 1);
	}
	if(GetKeyDown(VK_DOWN))
	{
		state.curMenu = (Menu)std::min((int)Menu::QUIT, (int)state.curMenu + 1);
	}

	if(GetKeyDown(VK_RETURN) || GetKeyDown(VK_SPACE))
	{
		switch(state.curMenu)
		{
			case Menu::START:
				state.curScene = Scene::INGAME;
				break;
			case Menu::INFO:
				break;
			case Menu::QUIT:
				state.isRunning = false;
				break;
		}
	}
}

void RenderTitle(const GameState& state)
{
	COORD res = GetConsoleResolution();
	int x = res.X / 2 - 4;
	int y = res.Y / 3 * 2;
	SetColor();
	for(int i = 0; i < 3; ++i)
	{
		GotoXY(x - 1, y + i);
		cout << " ";
	}
	GotoXY(x - 1, y + (int)state.curMenu);
	cout << '>';
	GotoXY(x, y);
	cout << "게임 시작";
	GotoXY(x, y + 1);
	cout << "게임 정보";
	GotoXY(x, y + 2);
	cout << "게임 종료";
}

void UpdateInfo(GameState& state)
{
}

void RenderInfo(const GameState& state)
{
}
