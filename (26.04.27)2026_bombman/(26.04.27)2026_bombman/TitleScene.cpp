#include "TitleScene.h"
#include "Console.h"
#include "AsciiArt.h"
static AsciiObjs objs;
void InitTitle()
{
    InitAscii(objs);
}

void UpdateTitle(GameState& state)
{
    UpdateAscii(objs);

    if(GetKeyDown(VK_UP))
    {
        state.curMenu = (Menu)std::max(0, (int)state.curMenu - 1);
    }
    if(GetKeyDown(VK_DOWN))
    {
        state.curMenu = (Menu)std::min((int)Menu::QUIT, (int)state.curMenu + 1);
    }

    if(GetKeyDown(VK_RETURN) || GetKeyDown(VK_SPACE))
    {
        switch(state.curMenu)
        {
            case Menu::START:
                PlayTransition();
                state.curScene = Scene::INGAME;
                break;
            case Menu::INFO:
                state.curScene = Scene::INFO;
                break;
            case Menu::QUIT:
                state.isRunning = false;
                break;
        }
    }
}

void RenderTitle(const GameState& state)
{
    RenderAscii(objs);

    COORD res = GetConsoleResolution();
    int x = res.X / 2 - 4;
    int y = res.Y / 3 * 2;
    SetColor();

    const wstring title[] =
    {
        L"██████╗  ██████╗ ███╗   ███╗██████╗ ███████╗██████╗     ███╗   ███╗ █████╗ ███╗   ██╗",
        L"██╔══██╗██╔═══██╗████╗ ████║██╔══██╗██╔════╝██╔══██╗    ████╗ ████║██╔══██╗████╗  ██║",
        L"██████╔╝██║   ██║██╔████╔██║██████╔╝█████╗  ██████╔╝    ██╔████╔██║███████║██╔██╗ ██║",
        L"██╔══██╗██║   ██║██║╚██╔╝██║██╔══██╗██╔══╝  ██╔══██╗    ██║╚██╔╝██║██╔══██║██║╚██╗██║",
        L"██████╔╝╚██████╔╝██║ ╚═╝ ██║██████╔╝███████╗██║  ██║    ██║ ╚═╝ ██║██║  ██║██║ ╚████║",
        L"╚═════╝  ╚═════╝ ╚═╝     ╚═╝╚═════╝ ╚══════╝╚═╝  ╚═╝    ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝"
    };

    int titleX = (res.X - 85) / 2;
    int titleY = res.Y / 3;
    SetUnicodeMode();

    for(int i = 0; i < 6; ++i)
    {
        GotoXY(titleX, titleY + i);
        wcout << title[i];
    }
    SetDefaultMode();

    const string labels[] = { "게임 시작", "게임 정보", "게임 종료" };
    for(int i = 0; i < 3; ++i)
    {
        GotoXY(x - 2, y + i);
        cout << (i == (int)state.curMenu ? "> " : "  ") << labels[i];
    }

    /*GotoXY(x, y);
    cout << "게임 시작";
    GotoXY(x, y + 1);
    cout << "게임 정보";
    GotoXY(x, y + 2);
    cout << "게임 종료";

    GotoXY(x - 2, y + (int)state.prevMenu);
    cout << " ";
    GotoXY(x - 2, y + (int)state.curMenu);
    cout << ">";*/
}

void UpdateInfo(GameState& state)
{
    if(GetKeyDown(VK_ESCAPE))
        state.curScene = Scene::TITLE;
}

void RenderInfo(const GameState& state)
{
    COORD res = GetConsoleResolution();
    int x = res.X / 2;
    int y = res.Y / 3;
    const string infoLabel[] =
    {
        "[ 조작 방법 ]",
        "방향키 : 이동",
        "SPACE : 폭탄 설치",
        "Z     : 스킬",
        "ESC   : 돌아가기"
    };

    for(int i = 0; i < 5; ++i)
    {
        GotoXY(x, y + i);
        if(i == 0)
            SetColor(Color::LIGHT_YELLOW);
        else if(i == 4)
            SetColor(Color::LIGHT_GRAY);
        else
            SetColor();
        cout << infoLabel[i];

    }
}

void PlayTransition()
{
    COORD res = GetConsoleResolution();
    int delayMs = 30;
    int falshCount = 6;
    FlashAnim(res, falshCount, delayMs);
    CrossAnim(res, delayMs);
}

void FlashAnim(COORD res, int count, int delayMs)
{
    system("cls");
    for(int i = 0; i < count; ++i)
    {
        SetColor(Color::BLACK, Color::WHITE);
        system("cls");
        Sleep(delayMs);

        SetColor();
        system("cls");
        Sleep(delayMs);
    }
}

void CrossAnim(COORD res, int delayMs)
{
    SetColor(Color::BLACK, Color::WHITE);
    for(int x = 0; x < res.X / 2; ++x)
    {
        for(int y = 0; y < res.Y; y += 2)
        {
            GotoXY(x * 2, y);
            cout << "  ";
        }
        for(int y = 1; y < res.Y; y += 2)
        {
            GotoXY(res.X - 2 - x * 2, y);
            cout << "  ";
        }
        Sleep(delayMs);
    }
    SetColor();
}
