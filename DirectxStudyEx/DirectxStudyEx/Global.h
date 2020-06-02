#pragma once

#include <Windows.h>
#include <d3dx9.h>
#include <D3dx9core.h>

#include "Texture_Manager.h"
#include "TitleStage.h"
#include "Stage_Manager.h"

#pragma warning( disable : 4996 ) // disable deprecated warning 

#define WINDOW_WIDTH 680
#define WIDTH_HEIGHT 480

#define TEX_TITLE_SCREEN 1000

#define GAME_BACKGROUND 2000
#define GAME_PLAYER_BODY 2001
#define GAME_PLAYER_BULLET_1 2002

#define GAME_ENEMY_A_BODY 2003
#define GAME_ENEMY_B_BODY 2004
#define GAME_ENEMY_EXPLOSION 2005

#define GAME_ENEMY_BOSS_A_BODY 3000
#define GAME_ENEMY_BOSS_A_BULLET_1 3001

//LoadTexture
#define PLAYER 100

extern LPDIRECT3D9             g_pD3D; // Used to create the D3DDevice
extern LPDIRECT3DDEVICE9       g_pd3dDevice; // Our rendering device
extern DWORD deltaTime;

extern Texture_Manager textureManager;
extern TitleStage titleStage;
extern Stage_Manager stageManager;