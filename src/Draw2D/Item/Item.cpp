#include "DxLib.h"
#include "Item.h"

void Item::Init()
{
	m_pos = { 0 };
	m_isUse = false;

	m_item_type = 0;
}
void Item::Step()
{
	if (m_isUse) {

	}
}
void Item::Draw(int handle)
{
	if (m_isUse) {

	}
}

bool Item::Spawn(VECTOR pos, int item_type)
{
	if (m_isUse)return false;

	m_pos = pos;
	m_isUse = true;

	m_item_type = item_type;

	return true;
}