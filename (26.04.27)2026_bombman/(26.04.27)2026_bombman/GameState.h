#pragma once
// 스택, 힙, 데이터, 코드(읽기 전용 메모리)?
// char ch[] = {"HELLO"};
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
    Position pos = { 0,0 };
    int         bombMax = 1;
    int         bombPower = 1;
    bool     isAlive = true;
    int         moveInterval = 150;
    ULONGLONG lastMoveTime = 0;
    bool     isTrans = false;
};

struct GameState
{
    Scene prevScene = Scene::NONE;
    Scene curScene = Scene::TITLE;
    Menu curMenu = Menu::START;
    bool isRunning = true;
    Block map[MAP_H][MAP_W] = {};
    Player player;
    ULONGLONG curTime;
};