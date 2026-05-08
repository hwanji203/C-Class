#pragma once
#include "GameState.h"	
#include "Console.h"
// init
void LoadMap(GameState& state);
void InitInGame(GameState& state);

// update
void UpdateInGame(GameState& state);
void MovePlayer(GameState& state);
Position GetMoveDir();
bool CanMove(const Block map[][MAP_W], int x, int y);
void SpawnBomb(GameState& state);
void UpdateBomb(GameState& state);

// render
void RenderInGame(const GameState& state);
void DrawMap(const GameState& state);
void DrawUI(const GameState& state);