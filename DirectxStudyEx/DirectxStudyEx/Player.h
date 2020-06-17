#pragma once
#include "Global.h"

#define PLAYER_BODY_WIDTH 31
#define PLAYER_BODY_WIDTH_HALF 15

#define PLAYER_BODY_HEIGHT 48
#define PLAYER_BODY_HEIGHT_HALF 24

class Player
{
	public:
		Player();

		void Update();
		void Render();

		D3DXVECTOR2 GetPosition();
	
		float playerX;
		float playerY;
		float speed;
		float hp;
};

