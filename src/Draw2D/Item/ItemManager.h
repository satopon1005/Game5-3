#pragma once
#include "Item.h"

constexpr int ITEM_MAX_NUM = 100;

class ItemManager
{
private:
	Item item_info[ITEM_MAX_NUM];
	int m_handle[BulletTypeMaxNum + ItemTypeMaxNum];

	bool m_spaen_flag[BulletTypeMaxNum];

public:
	void Init();
	void Step(VECTOR player_pos);
	void Draw();
	void Fin();

	void Spawn(VECTOR pos, int item_type);

	Item& GetItemInfo(int index) { return item_info[index]; }
};