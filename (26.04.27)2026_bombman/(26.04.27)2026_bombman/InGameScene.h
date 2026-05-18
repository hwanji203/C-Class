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
void ExplodeBomb(GameState& state, Bomb& bomb);
void BlastFlame(GameState& state, Position pos
				, int dx, int dy, int power);
void RemoveDeadBombs(std::vector<Bomb>& bombs);
void AddFlame(GameState& state, int x, int y);
void RemoveDeadFlames(std::vector<Flame>& flames);
void Dash(GameState& state, Position dir);
void UpdateDashTrails(GameState& state);

// render
void RenderInGame(const GameState& state);
void DrawMap(const GameState& state);
void DrawUI(const GameState& state);
void DrawBlock(const GameState& state, int x, int y);
bool TryDrawPlayer(const GameState& state, int x, int y);
bool TryDrawFlame(const GameState& state, int x, int y);
bool TryDrawTrail(const GameState& state, int x, int y);