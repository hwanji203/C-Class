#include "Console.h"

int main()
{
	std::cout << "안녕" << endl;
	SetUnicodeMode();
	wcout << L" ▄▄    ▄▄            ▄▄▄▄      ▄▄▄▄                         ▄▄      ▄▄                     ▄▄▄▄            ▄▄     ▄▄" << endl;
	wcout << L" ██    ██            ▀▀██      ▀▀██                         ██      ██                     ▀▀██            ██     ██" << endl;
	wcout << L" ██    ██   ▄████▄     ██        ██       ▄████▄            ▀█▄ ██ ▄█▀  ▄████▄    ██▄████    ██       ▄███▄██     ██" << endl;
	wcout << L" ████████  ██▄▄▄▄██    ██        ██      ██▀  ▀██            ██ ██ ██  ██▀  ▀██   ██▀        ██      ██▀  ▀██     ██" << endl;
	wcout << L" ██    ██  ██▀▀▀▀▀▀    ██        ██      ██    ██            ███▀▀███  ██    ██   ██         ██      ██    ██     ▀▀" << endl;
	wcout << L" ██    ██  ▀██▄▄▄▄█    ██▄▄▄     ██▄▄▄   ▀██▄▄██▀            ███  ███  ▀██▄▄██▀   ██         ██▄▄▄   ▀██▄▄███     ▄▄" << endl;
	wcout << L" ▀▀    ▀▀    ▀▀▀▀▀      ▀▀▀▀      ▀▀▀▀     ▀▀▀▀              ▀▀▀  ▀▀▀    ▀▀▀▀     ▀▀          ▀▀▀▀     ▀▀▀ ▀▀     ▀▀" << endl;
	(void)_setmode(_fileno(stdout), _O_U16TEXT);
	SetDefaultMode();
	SetUnicodeMode();
	wcout << "☠" << endl;
}