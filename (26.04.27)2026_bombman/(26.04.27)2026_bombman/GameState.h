#pragma once
#include "Enums.h"

constexpr int MAP_W = 21;
constexpr int MAP_H = 20;
struct Position
{
	int x; int y;
};

struct Player
{
	Position pos = { 0, 0 };
	int		bomtMax = 1;
	int		bombPower = 1;
	bool	isAllive = true;
	int		moveInterval = 150;
};

struct GameState
{
	Scene prevScene = Scene::TITLE;
	Scene curScene = Scene::TITLE;
	Menu curMenu = Menu::START;
	bool isRunning = true;
	Block map[MAP_H][MAP_W] = {};
	Player player;
};