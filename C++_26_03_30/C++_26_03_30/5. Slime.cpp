#include<iostream>
#include<Windows.h>
#include<conio.h>
using namespace std;

enum class Scene
{
    TITLE, BATTLE, RESULT
};
enum class ActionType
{
    ATTACK = 1, HEAL
};
void Init(Scene& scene, int& playerHp, int& slimeHp);
void Update(Scene& scene, int& playerHp, int& slimeHp, bool& isRunning);
void Render(Scene scene, int playerHp, int slimeHp);
int GetValidInput(int min, int max);

int main()
{
    bool isRunning = true;
    Scene scene;
    int playerHp = 0, slimeHp = 0;
    srand((unsigned int)time(nullptr));

    Init(scene, playerHp, slimeHp);
    while(isRunning)
    {
        Update(scene, playerHp, slimeHp, isRunning);
        Render(scene, playerHp, slimeHp);
    }
}

void Init(Scene& scene, int& playerHp, int& slimeHp)
{
    scene = Scene::TITLE;
    playerHp = 50;
    slimeHp = 30;
    cout << "============================" << endl;
    cout << "   < 슬라임 잡기 게임 >   " << endl;
    cout << "============================" << endl;
    cout << "아무 키나 누르면 시작합니다..." << endl;
    (void)_getch();
    scene = Scene::BATTLE;
}

void Update(Scene& scene, int& playerHp, int& slimeHp, bool& isRunning)
{
    if(scene == Scene::BATTLE)
    {
        cout << "행동 선택(1.공격 2.회복): ";
        ActionType action = (ActionType)GetValidInput(1, 2);
        if(action == ActionType::ATTACK)
        {
            int dmg = rand() % 10 + 5;
            slimeHp -= dmg;
            cout << endl << "[공격 성공] 슬라임에게" << dmg << "데미지!" << endl;
        }
        else if(action == ActionType::HEAL)
        {
            playerHp += 15;
            cout << endl << "[체력 회복] 15 증가" << endl;
        }

        if(slimeHp > 0)
        {
            if(rand() % 100 < 50)
            {
                playerHp -= 8;
                cout << endl << "[피격] 플레이어에게 8 데미지 " << endl;
            }
            else
                cout << "[MISS]" << endl;
        }

        Sleep(1000);

        if(playerHp <= 0 || slimeHp <= 0)
            scene = Scene::RESULT;
    }
    else if(scene == Scene::RESULT)
    {
        cout << "게임을 다시 시작하시겠습니까?(Y/N)" << endl;
        char ch = _getch();
        if(ch == 'y' || ch == 'Y')
        {
            Init(scene, playerHp, slimeHp);
        }
        else if(ch == 'n' || ch == 'N')
        {
            cout << endl << "프로그램 종료" << endl;
            isRunning = false;
        }
    }
}

void Render(Scene scene, int playerHp, int slimeHp)
{
    system("cls");
    if(scene == Scene::BATTLE)
    {
        cout << "--- [ 전투 진행 중 ] ---" << endl;
        cout << "플레이어 체력" << playerHp << "| 슬라임 체력:" << slimeHp << endl << endl;
    }
    else if(scene == Scene::RESULT)
    {
        cout << "--- [ 최종 결과 ] ---" << endl;
        if(playerHp > 0)
        {
            cout << "승리! 플레이어가 생존에 성공했습니다." << endl;
        }
        else
        {
            cout << "패배... 플레이어가 쓰러졌습니다." << endl;
        }
    }
}

int GetValidInput(int min, int max)
{
    int input;
    while(true)
    {
        cin >> input;
        if(cin.fail() || input < min || input > max)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "잘못된 입력입니다. " << min << "~"
                << max << "사이 숫자를 입력하세요. " << endl;
            continue;
        }
        else
            return input;
    }
    return 0;
}