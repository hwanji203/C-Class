#include "Console.h"
// 전역변수는 const가 붙은것만
const int SCREEN_WIDTH = 80;
const int ATTACK_COOLDOWN = 1000;
struct GameState
{
	int playerX = 10;
	int prevPlayerX = 10;
	int nextAttackTime = 0;
};
void Init();
void Update(GameState& state, ULONGLONG curTick);
void Render(GameState state, ULONGLONG curTick);
int Test() {};
int main()
{
	constexpr int x = 10;
	constexpr int y = Test();
	// 1. 이동(양쪽 막기)
	GameState state;
	Init();
	while(true)
	{
		ULONGLONG curTick = GetTickCount64();
		Update(state, curTick);
		Render(state, curTick);
		FrameSync(60);
	}
}

void Init()
{
	SetCursorVisible(false);
	SetConsoleSize(80, 40);
	SetConsoleWindowStyle(true);
}

void Update(GameState& state, ULONGLONG curTick)
{
	state.prevPlayerX = state.playerX;
	if(GetKey('A') && state.playerX > 0)
		state.playerX -= 2;
	if(GetKey('D') && state.playerX < SCREEN_WIDTH - 2)
		state.playerX += 2;
	if(GetKeyDown(VK_SPACE))
	{
		if(curTick >= state.nextAttackTime)
			state.nextAttackTime = curTick + ATTACK_COOLDOWN;
	}
}

void Render(GameState state, ULONGLONG curTick)
{
	GotoXY(state.prevPlayerX, 10);
	cout << "  ";
	GotoXY(state.playerX, 10);
	SetColor(Color::LIGHT_BLUE);
	cout << "§";

	GotoXY(10, 11);
	SetColor();
	cout << std::left;
	if(curTick < state.nextAttackTime)
	{
		cout << std::setw(25) <<
			"[SPACE] 쿨타임:"
			+ std::to_string(state.nextAttackTime - curTick);
			+"ms";
	}
	else
	{
		cout << std::setw(25) << "[SPACE] 공격 준비 완료!";
	}
}
