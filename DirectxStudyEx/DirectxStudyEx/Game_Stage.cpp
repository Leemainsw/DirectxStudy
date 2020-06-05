#include "Global.h"
#include "Game_Stage.h"

void Game_Stage::Update()
{

}

void Game_Stage::Render()
{
	TextureObject* object = textureManager.GetTexture(GAME_BACKGROUND);
	object->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	D3DXVECTOR3 pos(0, 0, 0);

	object->sprite->Draw(object->texture, &object->rect, nullptr, &pos,
		D3DCOLOR_XRGB(255, 255, 255));

	object->sprite->End();
}
