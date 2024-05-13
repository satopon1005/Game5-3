#pragma once
#include "../Draw2D.h"
#include "../Bullet/Bullet.h"

enum ItemType
{
	Keikenchi,
	Potion,

	ItemTypeMaxNum
};

constexpr int ITEM_SIZE[BulletTypeMaxNum + ItemTypeMaxNum] = {
	32,
	32,
	32,
	32,
	32,

	30,		//Keikenchi
	15,		//Potion
};

constexpr char ITEM_HANDLE_PATH[ItemTypeMaxNum][64] = {
	{"data/item/経験値.png"},
	{"data/item/回復ポーション.png"},
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