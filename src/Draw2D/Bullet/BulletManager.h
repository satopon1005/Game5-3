#pragma once
#include "Bullet.h"

constexpr int BULLET_MAX_NUM = 300;
constexpr int BULLET_SPAWN_INTERVAL_COUNT[BulletTypeMaxNum] = { 20,20,20,90 };

class BulletManager
{
private:
	Bullet bullet_info[BULLET_MAX_NUM];

	int m_handle[BulletTypeMaxNum][BULLET_ANIME_MAX_NUM];

	bool m_bullet_usable_flag[BulletTypeMaxNum];

	int m_spawn_interval_count[BulletTypeMaxNum];

public:
	void Init();
	void Step();
	void Draw();
	void Fin();

	bool Spawn(VECTOR player_pos, int player_level, int bullet_type);
	void SpawnBullet(VECTOR player_pos, int player_level);

	bool SetUsableFlag(int index, bool flag) { return m_bullet_usable_flag[index] = flag; }

	Bullet& GetBulletInfo(int index) { return bullet_info[index]; }
};