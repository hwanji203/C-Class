#pragma once
#include "Enums.h"
#define NOMINMAX
#include<Windows.h>

constexpr int MAP_W = 21;
constexpr int MAP_H = 20;
constexpr int WIDTH = 160;
constexpr int HEIGHT = 45;
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
	Scene prevScene = Scene::NONE;
	Scene curScene = Scene::TITLE;
	Menu curMenu = Menu::START;
	bool isRunning = true;
	Block map[MAP_H][MAP_W] = {};
	Player player;
};