#include "EnemyA.h"

EnemyA::EnemyA()
{
	isDead = false;
	state = kInit;
	hp = 4;

	const int centerX = WINDOW_WIDTH / 2;
	const int rangeX = 400;
	const int tempX = (rand() % rangeX) - (rangeX / 2);
	posX = centerX + tempX;
	posY = -50;

	velX = 0;
	velY = 0;
}

void EnemyA::Update()
{
	switch(state)
	{
	case kInit:
		state = kMoveToPoint;
		velY = 130;
		break;
	case kMoveToPoint:
		UpdateMoveToPoint();
		break;
	case kChooseDirection:
		UpdateChooseDirection();
		break;
	case kMoveToFinish:
		UpdateMoveToFinish();
		break;
	default:
		break;
	}

	posX += velX * deltaTime;
	posY += velY * deltaTime;

}

void EnemyA::Render()
{
	TextureObject* object = textureManager.GetTexture(GAME_ENEMY_A_BODY);
	object->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	D3DXVECTOR3 pos(posX - 20, posY - 35, 0);

	object->sprite->Draw(object->texture, &object->rect, nullptr, &pos,
		D3DCOLOR_XRGB(255, 255, 255));

	object->sprite->End();
}

void EnemyA::SetDead(bool flag)
{
	isDead = flag;
}

bool EnemyA::IsDead()
{
	return false;
}

void EnemyA::Hit(float damage)
{

}

float EnemyA::GetRadius()
{
	return 0.0f;
}

D3DXVECTOR2 EnemyA::GetPosition()
{
	return D3DXVECTOR2();
}

void EnemyA::UpdateMoveToPoint()
{
	if (posY > WINDOW_HEIGHT * 0.3f)
	{
		state = kChooseDirection;
	}
}

void EnemyA::UpdateChooseDirection()
{
	const int randValue = rand() % 100;
	if (randValue > 50)
	{
		velX = -(80 + rand() % 200);
		velY *= 3;
	}
	else
	{
		velX = 80 + rand() % 200;
		velY *= 3;
	}
}

void EnemyA::UpdateMoveToFinish()
{
	if (posX < 0 || posX > WINDOW_WIDTH ||
		posY > WINDOW_HEIGHT)
	{
		isDead = true;
	}
}