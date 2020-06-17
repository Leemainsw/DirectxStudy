#pragma once
#include <vector>

class Bullet;
class Enemy;
using namespace std;

class GameSystem
{
public:
	vector<Bullet*> bullets;
	vector<Enemy*> enemies;
	void GeneratePlayerBulletSpread(int x, int y);
	void GenerateEnemyA();
	void Update();
	void Render();
};

