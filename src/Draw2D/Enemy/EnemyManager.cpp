#include "DxLib.h"
#include "EnemyManagerh.h"
#include "../../GameCollision/GameCollision.h"

void EnemyManager::Init()
{
	for (int i = 0; i < ENEMY_NUM; i++) {
		enemy_info[i].Init();
	}
	m_spawn_interval_count = 0;

	LoadDivGraph(ENEMY_HANDLE_PATH, 1, 1, 1, 256, 256, m_handle);
}
void EnemyManager::Step(VECTOR player_pos)
{
	for (int i = 0; i < ENEMY_NUM; i++) {
		if (!enemy_info[i].GetIsUse())continue;

		enemy_info[i].Step(player_pos);

		if (CollisionPlayerToEnemy(player_pos, enemy_info[i].GetPos()))
			enemy_info[i].SetIsUse(false);
	}
	m_spawn_interval_count++;
}
void EnemyManager::Draw()
{
	for (int i = 0; i < ENEMY_NUM; i++) {
		enemy_info[i].Draw(m_handle[enemy_info[i].GetEnemyType()]);
	}
}
void EnemyManager::Fin()
{
	for (int i = 0; i < ENEMY_NUM; i++) {
		enemy_info[i].Fin();
	}

	for (int i = 0; i < EnemyTypeMaxNum; i++)
		DeleteGraph(m_handle[i]);
}

void EnemyManager::Spawn()
{
	if (m_spawn_interval_count >= ENEMY_SPAWN_INTERVAL_COUNT) {
		m_spawn_interval_count = 0;
		for (int i = 0; i < ENEMY_NUM; i++) {
			if (enemy_info[i].Spawn())
				break;
		}
	}
}