#pragma once
#include "Bullet.h"

class PlayerBulletA : public Bullet
{
public:
	PlayerBulletA(int x, int y, float vx, float vy);
	void Update() override;
	void Render() override;
	bool IsDead() override;
	void SetDead(bool flag) override;

	D3DXVECTOR2 GetPosition() override;

	float posX;
	float posY;
	float velX;
	float velY;
	bool isDead;
};

