#pragma once
#include "Bullet.h"

constexpr int BULLET_MAX_NUM = 100;
constexpr int BULLET_SPAWN_INTERVAL_COUNT = 10;

class BulletManager
{
private:
	Bullet bullet_info[BULLET_MAX_NUM];

	int m_handle[BulletTypeMaxNum][BULLET_ANIME_MAX_NUM];

	int m_spawn_interval_count;

public:
	void Init();
	void Step();
	void Draw();
	void Fin();

	void Spawn(VECTOR player_pos);

	Bullet& GetBulletInfo(int index) { return bullet_info[index]; }
};