#pragma once

#include "Global.h"
#include <vector>
using namespace std;

class TextureObject {
public:
	int id;
	LPD3DXSPRITE sprite;
	LPDIRECT3DTEXTURE9 texture;
	RECT rect;
};

class Texture_Manager
{
public:
	vector<TextureObject*> textureObjects;
	
	void LoadTexture(const TCHAR* name, int id, int left, int right, int top, int bottom);
	TextureObject* GetTexture(const int id);
};