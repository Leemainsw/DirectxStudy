#include "Game_Background.h"
#include "Global.h"

Game_Background::Game_Background()
{
	backgroundY = 0;
}

void Game_Background::Update()
{
	backgroundY += 0.05f;
}

void Game_Background::Render()
{
	TextureObject* object = textureManager.GetTexture(GAME_BACKGROUND);

	object->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	D3DXVECTOR3 pos(0, backgroundY, 0);

	object->sprite->Draw(object->texture, &object->rect, nullptr, &pos,
		D3DCOLOR_XRGB(255, 255, 255));

	pos = D3DXVECTOR3(0, backgroundY - 640, 0);
	object->sprite->Draw(object->texture, &object->rect, nullptr, &pos,
		D3DCOLOR_XRGB(255, 255, 255));

	object->sprite->End();

}
