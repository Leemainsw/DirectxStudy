#include "Global.h"

void TitleStage::Update()
{
	if (inputManager.prevKeyBuffer[VK_LBUTTON] == 1 &&
		inputManager.keyBuffer[VK_LBUTTON] == 0)
	{
		// game start...
		stageManager.MakeGameStage();
	}

}

void TitleStage::Render()
{
	TextureObject* object = textureManager.GetTexture(GAME_BACKGROUND);
	object->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	D3DXVECTOR3 pos(0, 0, 0);

	object->sprite->Draw(object->texture, &object->rect, nullptr,&pos,
		D3DCOLOR_XRGB(255, 255, 255));

	object->sprite->End();
}
