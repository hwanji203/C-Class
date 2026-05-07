#include "Game.h"
#include "Console.h"
#include "TitleScene.h"

void Init(GameState& state)
{
    srand((unsigned int)time(nullptr));
    //기본 사이즈가 8X12
    SetConsoleSize(WIDTH, HEIGHT);
    SetConsoleWindowStyle(true);
    state = GameState{};
}

void Update(GameState& state)
{
    bool sceneChanged
        = state.prevScene != state.curScene;
    state.prevScene = state.curScene;
    UpdateInput();
    if(GetKeyDown(VK_ESCAPE))
        state.isRunning = false;
    switch(state.curScene)
    {
        case Scene::TITLE:
            if(sceneChanged)
                InitTitle();
            UpdateTitle(state);
            break;
        case Scene::INFO:
            UpdateInfo(state);
            break;
        case Scene::INGAME:
            break;
        case Scene::GAMEOVER:
            break;
    }
}

void Render(const GameState& state)
{
    if(state.prevScene != state.curScene)
        system("cls");

    switch(state.curScene)
    {
        case Scene::TITLE:
            RenderTitle(state);
            break;
        case Scene::INFO:
            RenderInfo(state);
            break;
        case Scene::INGAME:
            break;
        case Scene::GAMEOVER:
            break;
    }
}