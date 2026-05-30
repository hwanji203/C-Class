//#include <iostream>	
//#include "GameState.h"
//using namespace std;
//// c++ struct vs class => 0.01%
//// => 접근 제한자
//// struct(public), class(private)
//class IDamageable
//{
//public:
//	virtual void TakeDamage() abstract;
//};
//class Object
//{
//public:
//	static int m_id;
//public:
//	Object(int pos) : m_pos(1)
//	{
//		m_pos = 2;
//		cout << "Object 생성" << endl; 
//	}
//	virtual ~Object() { cout << "Object 소멸" << endl; }
//	// 추상클래스 => 순수가상함수
//	virtual void Update() = 0;
//public:
//	int m_pos = 3;
//};
//int Object::m_id = 0;
//class Enemy : public Object
//{
//public:
//	Enemy(int pos) : Object(pos) { cout << "Enemy 생성" << endl; }
//	~Enemy() { cout << "Enemy 소멸" << endl; }
//public:
//	virtual void Update() override;
//};
//int main()
//{
//	Object obj;
//	Object::m_pos = 0;
//	Object::m_id = 0;
//	Enemy enemy;
//	Object* pObj = new Enemy;
//	//Enemy* pEnemy = new Object;
//	delete pObj;
//}
//class Scene
//{
//	Object* pObj[10];
//};