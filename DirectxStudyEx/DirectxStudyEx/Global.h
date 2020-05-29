#pragma once

#include <Windows.h>
#include <d3dx9.h>
#include <D3dx9core.h>

#include "Texture_Manager.h"

#pragma warning( disable : 4996 ) // disable deprecated warning 

#define WINDOW_WIDTH 680
#define WIDTH_HEIGHT 480

//LoadTexture
#define PLAYER 100

extern LPDIRECT3D9             g_pD3D; // Used to create the D3DDevice
extern LPDIRECT3DDEVICE9       g_pd3dDevice; // Our rendering device

//extern Texture_Manager textureManager;