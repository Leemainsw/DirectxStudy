#include "PlayerBulletSpread.h"
#include "Global.h"

PlayerBulletA::PlayerBulletA(int x, int y, float vx, float vy)
{
	posX = x;
	posY = y;
	velX = vx;
	velY = vy;

	isDead = false;
}

void PlayerBulletA::Update()
{
	posX += velX;
	posY += velY;

	// 화면 밖 처리
	if (posX < 0 || posX > WINDOW_WIDTH ||
		posY < 0 || posY > WINDOW_HEIGHT)
	{
		isDead = true;
	}
}

void PlayerBulletA::Render()
{
	TextureObject* object = textureManager.GetTexture(GAME_PLAYER_BULLET_1);
	object->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	D3DXVECTOR3 pos(posX - 5, posY - 5, 0);

	object->sprite->Draw(object->texture, &object->rect, nullptr, &pos,
		D3DCOLOR_XRGB(255, 255, 255));

	object->sprite->End();
}

bool PlayerBulletA::IsDead()
{
	return isDead;
}

void PlayerBulletA::SetDead(bool flag)
{
	isDead = flag;
}

D3DXVECTOR2 PlayerBulletA::GetPosition()
{
	return D3DXVECTOR2(posX, posY);
}
