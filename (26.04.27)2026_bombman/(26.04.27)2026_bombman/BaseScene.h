#pragma once
class BaseScene
{
public:
	virtual void Init() abstract;
	virtual void Update() abstract;
	virtual void Render() abstract;
};

