#pragma once
#include "Global.h"

class Bullet
{
public:
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual bool IsDead() = 0;
	//virtual float GetRadius() = 0;
	virtual D3DXVECTOR2 GetPosition() = 0;
	virtual void SetDead(bool flag) = 0;
	//virtual void Hit() = 0;
};

