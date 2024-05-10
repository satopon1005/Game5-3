#pragma once
#include "../Draw2D.h"

enum ItemType
{
	Potion,
	Keikenchi,

	ItemTypeMaxNum
};

class Item :public Draw2D
{
private:
	int m_item_type;

public:
	void Init();
	void Step();
	void Draw(int handle);

	bool Spawn(VECTOR pos, int item_type);
};