#include "Console.h"
#include "GameState.h"
#include "Game.h"
#include <fstream>
#include<string>
class Knight
{
public:
    inline void SetHp(int hp) { m_hp = hp; }
    int GetHp() const
    {
        return m_hp;
    }
    const Position& GetPos() const
    {
        return m_pos;
    }
private:
    int m_hp;
    Position m_pos;
    int attack;
};
int main()
{
    //cout << "ㅎㅇㅎ";
    //// 파일입출력 - .txt / .json
    //// 1. 쓰기(output file)
    //std::ofstream file2("file\\test2.txt", std::ios_base::app);
    //// out: 그냥 일반 모드
    //// ate: 덮어쓰기? 수정? 
    //// at the end
    //// app: 끝에 추가
    ////file2.open("test.txt");
    //char arr[] = "JunYong";
    //if(file2.is_open())
    //{
    //    file2.write(arr, strlen(arr));
    //    file2 << "하이" << endl;
    //    file2 << "2반아 ㅎ";
    //}
    //file2.close();

    //// 2. 읽기
    //std::ifstream readTest("file\\test2.txt");

    ////// 한글자씩
    ////while (!readTest.eof())
    ////{
    ////    cout << readTest.get();
    ////}
    //// 한줄씩
    //// string의 getline
    //string str;
    //while(std::getline(readTest, str))
    //{
    //    cout << str << endl;
    //}

    //// ifstream getline
    //char buf[100];
    //while(!readTest.eof())
    //{
    //    readTest.getline(buf, 100);
    //    cout << buf << endl;
    //}
    //// RAII(리소스 획득을 한 후에 초기화하세요) 


    // 클래스 - 객체지향 프로그래밍
    // 객체 => 인스턴스.
    // 1. zoqt
    // 캡슐화 -> 프로퍼티
    // 상속
    // 인터페이스, 추상클래스
    // 디자인패턴 - 싱글톤
    // SOLID


    //GameState state;
    //Init(state);
    //while (state.isRunning)
    //{
    //    state.curTime = GetTickCount64();
    //    Update(state);
    //    Render(state);
    //    FrameSync(60);
    //}
}