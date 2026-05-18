#include "Game.h"
#include "Console.h"
#include "TitleScene.h"
#include "InGameScene.h"

void Init(GameState& state)
{
    srand((unsigned int)time(nullptr));
    //±‚∫ª ªÁ¿Ã¡Ó∞° 8X12
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
    if(GetKeyDown('1'))
        SetConsoleFont(L"MS Gothic", { 10,20 });
    if(GetKeyDown('2'))
        SetConsoleFont(L"NSimSun", { 10,20 });
    if(GetKeyDown('3'))
        SetConsoleFont(L"∏º¿∫ ∞ÌµÒ", { 10,20 }, FW_BOLD);
    if(GetKeyDown('4'))
        SetConsoleFont(L"SimSun-ExtB", { 7,14 }, FW_THIN);
    if(GetKeyDown('5'))
        SetConsoleFont(L"±º∏≤√º", { 8,16 });

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
            if(sceneChanged)
                InitInGame(state);
            UpdateInGame(state);
            break;
        case Scene::GAMEOVER:
            break;
    }
}

void Render(const GameState& state)
{
    if(state.prevScene != state.curScene)
        system("cls");
    GotoXY(0, 0);
    switch(state.curScene)
    {
        case Scene::TITLE:
            RenderTitle(state);
            break;
        case Scene::INFO:
            RenderInfo(state);
            break;
        case Scene::INGAME:
            RenderInGame(state);
            break;
        case Scene::GAMEOVER:
            break;
    }
}