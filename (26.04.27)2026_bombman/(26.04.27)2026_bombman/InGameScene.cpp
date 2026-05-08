#include "InGameScene.h"
#include<algorithm>

void LoadMap(GameState& state)
{
    // 맵 찍어낼 때
    // 1. 내부 초기화
    // 2. 외부 초기화
    const string gameMap[MAP_H] =
    {
        "21111100000000000000",
        "00000111111110000000",
        "00111100000000000000",
        "00000100000000000000",
        "00000111111111100000",
        "00000100000000100000",
        "00000100000000100000",
        "00000100000000100000",
        "00000100000000100000",
        "00000100000000100000",
        "00000100000000111100",
        "00000100000000000000",
        "00000111111111111100",
        "00000100000000001100",
        "00000100000000001001",
        "00000100000000001111",
        "00000100000000000000",
        "00000100000000000100",
        "00000111111111111100",
        "00000000000000000000",
    };
    for(int y = 0; y < MAP_H; ++y)
    {
        for(int x = 0; x < MAP_W; ++x)
        {
            int data = gameMap[y][x] - '0';
            state.map[y][x] = (Block)data;
            if(state.map[y][x] == Block::START)
            {
                state.player.pos = { x,y };
                state.map[y][x] = Block::EMPTY;
            }
        }
    }
}

void InitInGame(GameState& state)
{
	LoadMap(state);
	SetConsoleSize(MAP_W * 3, MAP_H * 2);
}

void UpdateInGame(GameState& state)
{
    MovePlayer(state);

    if(GetKeyDown(VK_SPACE))
        SpawnBomb(state);
    UpdateBomb(state);
}

void MovePlayer(GameState& state)
{
    Player& p = state.player;
    if(state.curTime - p.lastMoveTime
       < p.moveInterval)
        return;
    Position dir = GetMoveDir();
    if(dir == Position{ 0, 0 })
        return;

    Position nextPos = {
        std::clamp(p.pos.x + dir.x, 0, MAP_W - 1),
        std::clamp(p.pos.y + dir.y, 0, MAP_H - 1)
    };
    if(!CanMove(state.map, nextPos.x, nextPos.y))
    {
        return;
    }

    p.pos = nextPos;
    p.lastMoveTime = state.curTime;
}

Position GetMoveDir()
{
    Position dir = { 0, 0 };
    if(GetKey(VK_UP))
        dir.y = -1;
    if(GetKey(VK_DOWN))
        dir.y = 1;
    if(GetKey(VK_LEFT))
        dir.x = -1;
    if(GetKey(VK_RIGHT))
        dir.x = 1;
    return dir;
}

bool CanMove(const Block map[][MAP_W], int x, int y)
{
    return map[y][x] == Block::EMPTY;
}

void SpawnBomb(GameState& state)
{
    Player& p = state.player;
    if(p.bombCount >= p.bombMax)
        return;
    if(state.map[p.pos.y][p.pos.x]
       == Block::BOMB)
        return;
    Bomb bomb;
    bomb.pos = p.pos;
    bomb.startTime = state.curTime;
    bomb.power = p.bombPower;
    bomb.active = true;
    state.vecBombs.push_back(bomb);

    state.map[p.pos.y][p.pos.x] = Block::BOMB;
    p.bombCount++;
}

void UpdateBomb(GameState& state)
{
}

void RenderInGame(const GameState& state)
{
    DrawMap(state);
    DrawUI(state);
}

void DrawMap(const GameState& state)
{
    for(int y = 0; y < MAP_H; ++y)
    {
        for(int x = 0; x < MAP_W; ++x)
        {
            if(state.player.pos == Position{x, y})
            {
                SetColor(Color::LIGHT_YELLOW);
                cout << "§";
                continue;
            }
            switch(state.map[y][x])
            {
                case Block::BRICK:
                    SetColor(Color::GRAY);
                    cout << "■";
                    break;
                case Block::EMPTY:
                    SetColor();
                    cout << "  "; // 특수문자라 2칸
                    break;
            }
        }
        cout << endl;
    }

}

void DrawUI(const GameState& state)
{
    const int UI_X = MAP_W * 2 + 2; // 맵 끝 + 여백 2칸
    const int UI_W = 16;            // UI 가로 너비
    const int UI_Y = MAP_H / 2 - 5; // 맵 세로 중앙쯤

    SetColor(Color::SKYBLUE);
    GotoXY(UI_X, UI_Y);
    DrawLine('=', UI_W);
    GotoXY(UI_X, UI_Y + 1);
    cout << "  [ 플레이어 ]";
    GotoXY(UI_X, UI_Y + 2);
    DrawLine('-', UI_W);

    SetColor();
    GotoXY(UI_X, UI_Y + 3);
    cout << " 파워 : " << state.player.bombPower;
    GotoXY(UI_X, UI_Y + 4);
    cout << " 개수 : " << state.player.bombMax;

    SetColor(Color::SKYBLUE);
    GotoXY(UI_X, UI_Y + 5);
    DrawLine('-', UI_W);

    // setw: 일회용이라 매번 적용
    // left: 왼쪽 정렬, setw: 고정폭 on/off 잔상 방지

    SetColor(state.player.isTrans ? Color::LIGHT_GREEN : Color::GRAY);
    GotoXY(UI_X, UI_Y + 6);
    cout << " 투명 : " << std::left << std::setw(4) <<
        (state.player.isTrans ? "ON" : "OFF");

    SetColor(Color::LIGHT_BLUE);
    GotoXY(UI_X, UI_Y + 7);
    DrawLine('=', UI_W);

    SetColor();
}
