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
	{"data/item/�񕜃|�[�V����.png"},
	{"data/item/�o���l.png"},
};
constexpr char WEAPON_ITEM_HANDLE_PATH[] = { "data/����̌�����/weapon.png" };

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