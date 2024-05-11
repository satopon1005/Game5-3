#include "DxLib.h"
#include "BulletManager.h"

void BulletManager::Init()
{
	for (int bullet_type_index = 0; bullet_type_index < BulletTypeMaxNum; bullet_type_index++) {
		LoadDivGraph(BULLET_TYPE_HANDLE_PATH[bullet_type_index],
			BULLET_ANIME_NUM[bullet_type_index],
			1,
			BULLET_ANIME_NUM[bullet_type_index],
			BULLET_GAZOU_SIZE[bullet_type_index],
			BULLET_GAZOU_SIZE[bullet_type_index],
			m_handle[bullet_type_index]);
	}
	m_spawn_interval_count = 0;
}
void BulletManager::Step()
{
	for (int bullet_index = 0; bullet_index < BULLET_MAX_NUM; bullet_index++) {
		bullet_info[bullet_index].Step();
	}
	m_spawn_interval_count++;
}
void BulletManager::Draw()
{
	for (int bullet_index = 0; bullet_index < BULLET_MAX_NUM; bullet_index++) {
		bullet_info[bullet_index].Draw(m_handle[bullet_info[bullet_index].GetBulletType()][bullet_info[bullet_index].GetAnimeIndex()]);
	}
}
void BulletManager::Fin()
{
	for (int bullet_index = 0; bullet_index < BulletTypeMaxNum; bullet_index++) {
		for (int anime_index = 0; anime_index < BULLET_ANIME_MAX_NUM; anime_index++) {
			DeleteGraph(m_handle[bullet_index][anime_index]);
		}
	}
}

void BulletManager::Spawn(VECTOR player_pos)
{
	if (m_spawn_interval_count < BULLET_SPAWN_INTERVAL_COUNT)
		return;

	for (int bullet_index = 0; bullet_index < BULLET_MAX_NUM; bullet_index++) {
		if (bullet_info[bullet_index].Spawn(player_pos, Slashing)) {
			m_spawn_interval_count = 0;
			break;
		}
	}
}