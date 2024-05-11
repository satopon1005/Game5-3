#include "DxLib.h"
#include "ItemManager.h"
#include "../../Player/Player.h"
#include "../../GameCollision/GameCollision.h"

void ItemManager::Init()
{
	for (int i = 0; i < ITEM_MAX_NUM; i++){
		item_info[i].Init();
	}
	LoadDivGraph(ITEM_HANDLE_PATH, ItemTypeMaxNum, 2, 1, 64, 64, m_handle);
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
	for (int i = 0; i < ItemTypeMaxNum; i++) {
		DeleteGraph(m_handle[i]);
	}
}

void ItemManager::Spawn(VECTOR pos, int item_type)
{
	for (int i = 0; i < ITEM_MAX_NUM; i++) {
		if (item_info[i].Spawn(pos, item_type)) {
			break;
		}
	}
}