#pragma once
#include "Global.h"
#include "Player.h"
#include "Game_Background.h"

class Game_Stage : public Stage
{
public :
	void Update() override;
	void Render() override;

	Player player;
	Game_Background background;
};

