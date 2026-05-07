#pragma once
#include<vector>
#include<string>
#include<algorithm>
using std::vector;
using std::string;

struct AsciiObjs
{
	vector<string> plane;
	vector<string> cloud;
};


void InitAscii(AsciiObjs& objs);
void UpdateAscii(AsciiObjs& objs);
void RenderAscii(const AsciiObjs& objs);