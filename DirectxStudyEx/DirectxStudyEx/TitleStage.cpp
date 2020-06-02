#include "Global.h"

void TitleStage::Update()
{

	//for (int i = 0; i < 256; ++i)
	//{
	//	prevKeyBuffer[i] = keyBuffer[i];
	//}
	//
	//if (prevKeyBuffer[VK_LBUTTON] == 1 && keyBuffer[VK_LBUTTON] == 0)
	//{
	//	stageManager.MakeGameStage();
	//}

}

void TitleStage::Render()
{
	TextureObject* object = textureManager.GetTexture(TEX_TITLE_SCREEN);
	object->sprite->Begin(D3DXSPRITE_ALPHABLEND);
	D3DXVECTOR3 pos(0, 0, 0);
	object->sprite->Draw(object->texture, &object->rect, nullptr,&pos,
		D3DCOLOR_XRGB(255, 255, 255));
	object->sprite->End();
}
