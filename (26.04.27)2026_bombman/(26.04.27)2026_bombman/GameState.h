#pragma once
// 스택, 힙, 데이터, 코드(읽기 전용 메모리)?
// char ch[] = {"HELLO"};
#include "Enums.h"
#define NOMINMAX
#include<Windows.h>
#include<vector>
constexpr int MAP_W = 21;
constexpr int MAP_H = 20;
constexpr int WIDTH = 160;
constexpr int HEIGHT = 45;
constexpr int BOMB_TIMBER_MS = 3000; // 3초 기다렸다가
constexpr int FLAME_TIMER_MS = 500; // 이펙트 시간
constexpr int BOMB_BLICK_INTERVAL_MS = 200; // 블링크 간격

struct Position
{
    int x; int y;

    // 연산자 오버로딩
    // 오퍼레이터 오버로딩
    bool operator ==(const Position& other) const
    {
        return x == other.x && y == other.y;
    }
};
struct Flame
{
    Position pos;
    ULONGLONG startTime = 0;
    bool    active = false;
};
struct Bomb
{
    Position pos;
    ULONGLONG startTime = 0;
    bool   active = false;
    int power = 1;
};

struct Player
{
    Position pos = { 0,0 };
    int         bombMax = 1;
    int         bombCount = 0; // 현재 폭탄
    int         bombPower = 1;
    bool     isAlive = true;
    int         moveInterval = 150;
    ULONGLONG lastMoveTime = 0;
    bool     isTrans = false;
};

struct GameState
{
    Scene prevScene = Scene::NONE;
    Scene curScene = Scene::INGAME;
    Menu curMenu = Menu::START;
    bool isRunning = true;
    Block map[MAP_H][MAP_W] = {};
    Player player;
    ULONGLONG curTime;
    std::vector<Bomb> vecBombs;
    std::vector<Flame> vecFlames;
};