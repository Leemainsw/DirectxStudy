#include "GameSystem.h"
#include "PlayerBulletSpread.h"

void GameSystem::GeneratePlayerBulletSpread(int x, int y)
{
	float speed = 8;
	//3개의 총알을 만들어서 배치한다.
	PlayerBulletA* a = new PlayerBulletA(x, y, -speed, -speed);
	PlayerBulletA* b = new PlayerBulletA(x, y, 0, -speed);
	PlayerBulletA* c = new PlayerBulletA(x, y, speed, -speed);

	bullets.push_back(a);
	bullets.push_back(b);
	bullets.push_back(c);

}

void GameSystem::GenerateEnemyA()
{
	Enemy* enemeyA = new EnemyA();
	enemies.push_back(enemeyA);
}

void GameSystem::Update()
{
	if (rand() % 100 < 5)
	{
		GenerateEnemyA();
	}

	// 플레이어 총알 업데이트
	for (auto iter = bullets.begin(); iter != bullets.end();)
	{
		(*iter)->Update();

		if ((*iter)->IsDead())
		{
			iter = bullets.erase(iter);
		}
		else
		{
			iter++;
		}
	}

	//적 업데이트
	for (auto iter = enemies.begin(); iter != enemies.end();)
	{
		(*iter)->Update();
		iter++;
	}
}

void GameSystem::Render()
{
	for (auto iter = bullets.begin(); iter != bullets.end();)
	{
		(*iter)->Render();
		iter++;
	}

	for (auto iter = enemies.begin(); iter != enemies.end();)
	{
		(*iter)->Render();
		iter++;
	}
}
