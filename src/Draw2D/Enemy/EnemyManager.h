#pragma once
#include "Enemy.h"
#include "../../Draw2D/Item/ItemManager.h"

constexpr int ENEMY_NUM = 100;
constexpr int ENEMY_SPAWN_INTERVAL_COUNT = 30;

class EnemyManager
{
private:
	Enemy_Info enemy_info[ENEMY_NUM];
	int m_spawn_interval_count;

	int m_handle[EnemyTypeMaxNum];

public:
	void Init();
	void Step(VECTOR player_pos);
	void Draw();
	void Fin();

	void Spawn(int elapsed_second);

	Enemy_Info& GetEnemyInfo(int index) { return enemy_info[index]; }
};