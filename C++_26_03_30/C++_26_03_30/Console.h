#pragma once
#include<iostream>
#define NOMINMAX
#include<io.h>
#include<fcntl.h>
#include<Windows.h>
#include<conio.h>
#include<iomanip>
#include<string>
#pragma comment(lib, "winmm.lib")

using std::cout;
using std::endl;
using std::wcout;
using std::string;
using std::wstring;

void SetUnicodeMode();
void SetDefaultMode();

void RenderDialogue(const string& text, int delayTime);
void RenderChar(char ch, int delayTime, bool isSkip);

void SetConsoleGameTitle(const wstring& title);
void SetConsoleSize(int width, int height);
void SetConsoleFullScreen();
void SetConsoleWindowStyle(bool showTitieBar);
void ShakeConsoleWindow(int intensity, int duration, int interval);
void SetConsoleMouseInputDisabled();
POINT GetMouseCellPos();

void GotoXY(int x, int y);
BOOL IsGotoXY(int x, int y);
void SetCursorVisible(bool visible, DWORD size = 1);

enum class Color
{
    BLACK, BLUE, GREEN, SKYBLUE, RED,
    VIOLET, YELLOW, LIGHT_GRAY, GRAY, LIGHT_BLUE,
    LIGHT_GREEN, CYAN, LIGHT_RED, LIGHT_VIOLET,
    LIGHT_YELLOW, WHITE, END
};

void SetColor(Color textColor=Color::WHITE, Color bgColor=Color::BLACK);
void DrawBar(int x, int y, const string& label,
             int value, int maxValue, int barWidth,
             const string& fillChar = "бс", const string& emptyChar = "бр");

bool GetKey(int vKey);
bool GetKeyDown(int vKey);
void UpdateInput();

void FrameSync(int fps);