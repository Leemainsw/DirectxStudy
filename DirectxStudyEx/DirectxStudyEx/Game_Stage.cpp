#include "Global.h"
#include "Game_Stage.h"
#include "Player.h"

void Game_Stage::Update()
{
	background.Update();
	player.Update();
	gameSystem.Update();
}

void Game_Stage::Render()
{
	background.Render();
	player.Render();
	gameSystem.Render();
}
