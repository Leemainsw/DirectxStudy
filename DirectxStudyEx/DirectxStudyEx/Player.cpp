#include "Global.h"
#include "Player.h"

#define PLAYER_WIDTH_HALF 15
#define PLAYER_HEIGHT_HALF 24

Player::Player()
{
	//초기 설정
	playerX = 640 / 2;
	playerY = 420;
	speed = 10.f;
	hp = 3;

}

void Player::Update()
{

	//input manager
	if (inputManager.keyBuffer[VK_LEFT] == 1)
		playerX -= speed;
	
	if (inputManager.keyBuffer[VK_RIGHT] == 1)
		playerX += speed;

	if (inputManager.keyBuffer[VK_UP] == 1)
		playerY -= speed;
	
	if (inputManager.keyBuffer[VK_DOWN] == 1)
		playerY += speed;

	//플레이어 총알 처리
	if (inputManager.keyBuffer['Z'] == 0 && inputManager.prevKeyBuffer['Z'] == 1)
	{
		gameSystem.GeneratePlayerBulletSpread(playerX, playerY - 30);
	}

	// 화면 밖 나감 처리
	if (playerX < 0)
		playerX = 0;

	if (playerX > WINDOW_WIDTH)
		playerX = WINDOW_WIDTH;

	if (playerY < 0)
		playerY = 0;

	if (playerY > WINDOW_HEIGHT)
		playerY = WINDOW_HEIGHT;
}

void Player::Render()
{
	TextureObject* object = textureManager.GetTexture(GAME_PLAYER_BODY);
	object->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	D3DXVECTOR3 pos(playerX - PLAYER_WIDTH_HALF, playerY - PLAYER_HEIGHT_HALF, 0);

	object->sprite->Draw(object->texture, &object->rect, nullptr, &pos,
		D3DCOLOR_XRGB(255, 255, 255));

	object->sprite->End();
}
