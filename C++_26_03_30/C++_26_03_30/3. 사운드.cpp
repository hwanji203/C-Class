#include "Console.h"	
#include "resource.h"

int main()
{
	//Beep(900, 1000);
	//상눋 추가 2가지

	// 1. 리소스 때려박는 방법
	//PlaySound(MAKEINTRESOURCE(IDR_WAVE1), nullptr, SND_ASYNC | SND_RESOURCE);

	// 2. 파일로 가져오는 방법
	//PlaySound(L"explosion", nullptr, SND_ASYNC | SND_LOOP | SND_FILENAME);

	_getch();
}