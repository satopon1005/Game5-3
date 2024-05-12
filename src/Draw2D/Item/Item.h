#pragma once
#include "../Draw2D.h"
#include "../Bullet/Bullet.h"

enum ItemType
{
	Potion,
	Keikenchi,

	ItemTypeMaxNum
};

constexpr int ITEM_SIZE[BulletTypeMaxNum + ItemTypeMaxNum] = {
	32,
	32,
	32,
	32,
	32,

	15,		//Potion
	30,		//Keikenchi
};

constexpr char ITEM_HANDLE_PATH[ItemTypeMaxNum][64] = { 
	{"data/item/回復ポーション.png"},
	{"data/item/経験値.png"},
};
constexpr char WEAPON_ITEM_HANDLE_PATH[] = { "data/武器の見た目/weapon.png" };

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