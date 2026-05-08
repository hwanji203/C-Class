#include "Console.h"
#include "GameState.h"
#include "Game.h"

int main()
{
	GameState state;
	Init(state);
	while(state.isRunning)
	{
		state.curTime = GetTickCount64();
		Update(state);
		Render(state);
		FrameSync(60);
	}
}