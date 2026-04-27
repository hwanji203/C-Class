#include "Console.h"
// 전역변수는 const가 붙은것만
const int SCREEN_WIDTH = 80;
const int ATTACK_COOLDOWN = 1000;
const int BULLET_SPEED_MS = 20;
struct Bullet
{
	bool isActive = false;
	int prevX = 0;
	int x = 0;
	ULONGLONG nextMoveTime = 0;
};
struct GameState
{
	bool timeStopped = false;
	ULONGLONG lastTick = 0;
	Bullet bullet;
	int playerX = 10;
	int prevPlayerX = 10;
	int nextAttackTime = 0;
	int playerHp = 100;

	int enemyX = 50;
	int enemyHp = 100;
};
void Init();
void Update(GameState& state, ULONGLONG curTick);
void UpdateBullet(Bullet& bullet, ULONGLONG curTick);
void FireBullet(Bullet& bullet, int startX, ULONGLONG curTick);
void CheckCollision(GameState& state);

void Render(const GameState& state, ULONGLONG curTick);
void RenderBullet(const Bullet& bullet);

int Test()
{
	return 0;
};
int main()
{
	//constexpr int x = 10;
	//constexpr int y = Test();
	//x = 20;
	
	// 1. 이동(양쪽 막기)
	GameState state;
	Init();
	while(true)
	{
		ULONGLONG curTick = state.timeStopped ? state.lastTick :
			GetTickCount64();
		state.lastTick = curTick;
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
	UpdateInput();
	if(GetKey('A') && state.playerX > 0)
		state.playerX -= 2;
	if(GetKey('D') && state.playerX < SCREEN_WIDTH - 2)
		state.playerX += 2;
	if(GetKeyDown('T'))
		state.timeStopped = !state.timeStopped;
	if(GetKeyDown(VK_SPACE))
	{
		if(curTick >= state.nextAttackTime && !state.bullet.isActive)
		{
			state.nextAttackTime = curTick + ATTACK_COOLDOWN;
			FireBullet(state.bullet, state.playerX, curTick);
		}
	}
	UpdateBullet(state.bullet, curTick);
	CheckCollision(state);
}

void UpdateBullet(Bullet& bullet, ULONGLONG curTick)
{
	if(!bullet.isActive || curTick < bullet.nextMoveTime)
		return;
	bullet.prevX = bullet.x;
	bullet.x += 2;
	bullet.nextMoveTime = curTick + BULLET_SPEED_MS;

	if(bullet.x >= SCREEN_WIDTH)
		bullet.isActive = false;
}

void FireBullet(Bullet& bullet, int startX, ULONGLONG curTick)
{
	if(bullet.isActive)
		return;
	bullet.isActive = true;
	bullet.x = startX + 2;
	bullet.prevX = bullet.x;
	bullet.nextMoveTime = curTick;
}

void CheckCollision(GameState& state)
{
	if(!state.bullet.isActive || state.enemyHp <= 0)
		return;
	if(state.bullet.x >= state.enemyX && state.bullet.x <= state.enemyX + 2)
	{
		state.bullet.isActive = false;
		state.enemyHp = std::max(0, state.enemyHp - 25);
		ShakeConsoleWindow(10, 300, 20);
	}
}

void Render(const GameState& state, ULONGLONG curTick)
{
	GotoXY(state.prevPlayerX, 10);
	cout << "  ";

	GotoXY(state.playerX, 10);
	SetColor(Color::LIGHT_BLUE);
	cout << "§";

	GotoXY(state.enemyX, 10);
	SetColor(Color::LIGHT_VIOLET);
	cout << "♨";
	SetColor();

	RenderBullet(state.bullet);

	DrawBar(0, 1, "Player HP: ", state.playerHp, 100, 10);
	DrawBar(0, 2, "Enemy HP: ", state.enemyHp, 100, 10);

	GotoXY(10, 11);
	SetColor();
	cout << std::left;
	if(curTick < state.nextAttackTime || state.bullet.isActive)
	{
		ULONGLONG  remaingTime = (curTick < state.nextAttackTime) ?
			state.nextAttackTime - curTick : 0;
		cout << std::setw(25) <<
			"[SPACE] 쿨타임:"
			+ std::to_string(remaingTime);
			+"ms";
	}
	else
	{
		cout << std::setw(25) << "[SPACE] 공격 준비 완료!";
	}
}

void RenderBullet(const Bullet& bullet)
{
	if(bullet.prevX != bullet.x)
	{
		GotoXY(bullet.prevX, 10);
		cout << "  ";
	}
	if(!bullet.isActive)
		return;
	GotoXY(bullet.x, 10);
	SetColor(Color::LIGHT_YELLOW);
	cout << "-";
	SetColor();
}
