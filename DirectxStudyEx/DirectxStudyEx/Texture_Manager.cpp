#include "Texture_Manager.h"
#include "Global.h"

void Texture_Manager::LoadTexture(const TCHAR* name, int id, int left, int right, int top, int bottom) {
	TextureObject* newObject = new TextureObject;
	
	//id setting
	newObject->id = id;

	//texture setting
	D3DXCreateTextureFromFile(g_pd3dDevice, name, &newObject->texture);

	//sprite setting
	D3DXCreateSprite(g_pd3dDevice, &newObject->sprite);

	newObject->rect.top = top;
	newObject->rect.bottom = bottom;
	newObject->rect.left = left;
	newObject->rect.right = right;


	textureObjects.push_back(newObject);
}

TextureObject* Texture_Manager::GetTexture(const int id)
{
	for (int i = 0; i < textureObjects.size(); ++i)
	{
		if (textureObjects[i]->id == id)
		{
			return textureObjects[i];
		}
	}

	return nullptr;
}

