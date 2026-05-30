#pragma once
#include "BaseScene.h"
#include<Windows.h>

class BaseTitleScene : public BaseScene
{
	// BaseScene을(를) 통해 상속됨
	void Init() override;
	void Update() override;
	void Render() override;
private:
	void PlayTransition();
	void FlashAnim(COORD res, int count, int delayMs);
	void CrossAnim(COORD res, int delayMs);
};

