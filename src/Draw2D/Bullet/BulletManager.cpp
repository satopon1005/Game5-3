#include "DxLib.h"
#include "BulletManager.h"

void BulletManager::Init()
{
	for (int bullet_type_index = 0; bullet_type_index < BulletTypeMaxNum; bullet_type_index++) {
		LoadDivGraph(BULLET_TYPE_HANDLE_PATH[bullet_type_index],
			BULLET_ANIME_NUM[bullet_type_index],
			BULLET_ANIME_NUM[bullet_type_index],
			1,
			BULLET_GAZOU_SIZE_X[bullet_type_index],
			BULLET_GAZOU_SIZE_Y[bullet_type_index],
			m_handle[bullet_type_index]);

		m_spawn_interval_count[bullet_type_index] = 0;
		m_bullet_usable_flag[bullet_type_index] = false;
	}
	m_bullet_usable_flag[Slashing] = true;
	m_bullet_usable_flag[Ninniku] = true;
}
void BulletManager::Step()
{
	for (int bullet_index = 0; bullet_index < BULLET_MAX_NUM; bullet_index++) {
		bullet_info[bullet_index].Step();
	}

	for (int bullet_type_index = 0; bullet_type_index < BulletTypeMaxNum; bullet_type_index++) {
		if (m_bullet_usable_flag[bullet_type_index])
			m_spawn_interval_count[bullet_type_index]++;
	}
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

void BulletManager::SpawnBullet(VECTOR player_pos, int player_level)
{
	for (int bullet_type_index = 0; bullet_type_index < BulletTypeMaxNum; bullet_type_index++)
	{
		for (int continuation_num = 0;
			continuation_num < BULLET_CONTINUATION_SHOT_NUM[bullet_type_index];
			continuation_num++)
			Spawn(player_pos, player_level, bullet_type_index);
	}
}

bool BulletManager::Spawn(VECTOR player_pos, int player_level, int bullet_type)
{
	int interval_count = BULLET_SPAWN_INTERVAL_COUNT[bullet_type] - (int)(player_level);
	if (interval_count < 0)
		interval_count = 0;

	if (m_spawn_interval_count[bullet_type] < interval_count)
		return false;

	for (int bullet_index = 0; bullet_index < BULLET_MAX_NUM; bullet_index++) {
		if (bullet_info[bullet_index].Spawn(player_pos, bullet_type)) {
			m_spawn_interval_count[bullet_type] = 0;
			return true;
		}
	}

	return false;
}