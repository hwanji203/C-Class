#include "Game.h"
#include "Console.h"
#include "TitleScene.h"

void Init(GameState& state)
{
	srand((unsigned int)time(nullptr));
	//기본 사이즈가 8*12
	SetConsoleSize(160, 45);
	SetConsoleWindowStyle(true);
	state = GameState{};
}

void Update(GameState& state)
{
	state.prevScene = state.curScene;
	UpdateInput();
	if(GetKeyDown(VK_ESCAPE))
		state.isRunning = false;
	switch(state.curScene)
	{
		case Scene::TITLE:
			UpdateTitle(state);
			break;
		case Scene::INGAME:
			break;
	}
}

void Render(const GameState& state)
{
	if(state.prevScene != state.curScene)
		system("cls");
	switch(state.curScene)
	{
		case Scene::TITLE:
			RenderTitle(state);
			break;
		case Scene::INGAME:
			break;
	}
}
