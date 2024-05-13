#include "DxLib.h"
#include "EnemyManager.h"
#include "../../GameCollision/GameCollision.h"
#include "../../Player/Player.h"

void EnemyManager::Init()
{
	for (int i = 0; i < ENEMY_NUM; i++) {
		enemy_info[i].Init();
	}
	m_spawn_interval_count = 0;

	LoadDivGraph(ENEMY_HANDLE_PATH, EnemyTypeMaxNum, EnemyTypeMaxNum, 1, 150, 150, m_handle);
}
void EnemyManager::Step(VECTOR player_pos)
{
	for (int i = 0; i < ENEMY_NUM; i++) {
		if (!enemy_info[i].GetIsUse())continue;

		enemy_info[i].Step(player_pos);
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

void EnemyManager::Spawn(int elapsed_second)
{
	if (m_spawn_interval_count >= ENEMY_SPAWN_INTERVAL_COUNT - (int)(elapsed_second / 10)) {
		m_spawn_interval_count = 0;
		for (int i = 0; i < ENEMY_NUM; i++) {
			if (enemy_info[i].Spawn())
				break;
		}
	}
}