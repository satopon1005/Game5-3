#include "DxLib.h"
#include "ItemManager.h"
#include "../../Player/Player.h"
#include "../../GameCollision/GameCollision.h"
#include "../Bullet/Bullet.h"

void ItemManager::Init()
{
	for (int i = 0; i < ITEM_MAX_NUM; i++){
		item_info[i].Init();
	}
	LoadDivGraph(WEAPON_ITEM_HANDLE_PATH, BulletTypeMaxNum, 5, 1, 150, 150, m_handle);
	for (int i = 0; i < ItemTypeMaxNum; i++)
		m_handle[BulletTypeMaxNum + i] = LoadGraph(ITEM_HANDLE_PATH[i]);

	for (int i = 0; i < BulletTypeMaxNum; i++)
		m_spaen_flag[i] = false;

	m_spaen_flag[Slashing] = true;
	m_spaen_flag[Ninniku] = true;
}
void ItemManager::Step(VECTOR player_pos)
{
	for (int i = 0; i < ITEM_MAX_NUM; i++){
		item_info[i].Step();
	}
}
void ItemManager::Draw()
{
	for (int i = 0; i < ITEM_MAX_NUM; i++){
		item_info[i].Draw(m_handle[item_info[i].GetItemType()]);
	}
}
void ItemManager::Fin()
{
	for (int i = 0; i < BulletTypeMaxNum + ItemTypeMaxNum; i++) {
		DeleteGraph(m_handle[i]);
	}
}

void ItemManager::Spawn(VECTOR pos, int item_type)
{
	if (m_spaen_flag[item_type])
		item_type = BulletTypeMaxNum;

	if (item_type < BulletTypeMaxNum)
		m_spaen_flag[item_type] = true;

	for (int i = 0; i < ITEM_MAX_NUM; i++) {
		if (item_info[i].Spawn(pos, item_type)) {
			break;
		}
	}
}