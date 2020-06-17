#pragma once
#include "Enemy.h"

class EnemyA : public Enemy{
public:
	enum State
	{
		kInit,
		kMoveToPoint,
		kChooseDirection,
		kMoveToFinish
	};

	EnemyA();

	void Update() override;
	void Render() override;

	void SetDead(bool flag) override;;
	bool IsDead() override;
	void Hit(float damage) override;

	float GetRadius() override;
	D3DXVECTOR2 GetPosition() override;

	void UpdateMoveToPoint();
	void UpdateChooseDirection();
	void UpdateMoveToFinish();

	bool isDead;
	float posX;
	float posY;
	float velX;
	float velY;

	//float speed;
	float hp;

	float hitTimer;

	State state;

};

