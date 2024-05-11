#pragma once
#include "../Draw2D.h"

enum ItemType
{
	Potion,
	Keikenchi,

	ItemTypeMaxNum
};

constexpr int ITEM_SIZE_R[ItemTypeMaxNum] = {
	15,		//Potion
	30,		//Keikenchi
};

constexpr char ITEM_HANDLE_PATH[] = { "data/item/item.png" };

class Item :public Draw2D
{
private:
	int m_item_type;

public:
	void Init();
	void Step();
	void Draw(int handle);

	bool Spawn(VECTOR pos, int item_type);

	int GetItemType() { return m_item_type; }
};