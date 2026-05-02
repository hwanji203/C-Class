#include "Console.h"
#include "GameState.h"
#include "Game.h"

int main()
{
	GameState state;
	Init(state);
	while(state.isRunning)
	{
		Update(state);
		Render(state);
		FrameSync(60);
	}
}