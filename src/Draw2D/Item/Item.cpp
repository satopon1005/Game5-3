#include "DxLib.h"
#include "Item.h"
#include "../../Screen/Screen.h"
#include "../../Common.h"

void Item::Init()
{
	m_pos = { 0 };
	m_isUse = false;

	m_item_type = 0;
}
void Item::Step()
{
	if (m_isUse) {
		if (m_item_type >= BulletTypeMaxNum) {
			if (m_pos.x - Screen::m_screen_pos.x + ITEM_SIZE[m_item_type] / 2 < 0 ||
				m_pos.y - Screen::m_screen_pos.y + ITEM_SIZE[m_item_type] / 2 < 0 ||
				m_pos.x - Screen::m_screen_pos.x - ITEM_SIZE[m_item_type] / 2 > SCREEN_SIZE_X ||
				m_pos.y - Screen::m_screen_pos.y - ITEM_SIZE[m_item_type] / 2 > SCREEN_SIZE_Y) {
				m_isUse = false;
			}
		}
	}
}
void Item::Draw(int handle)
{
	if (m_isUse) {
		DrawExtendGraph((int)(m_pos.x - ITEM_SIZE[m_item_type] / 2 - Screen::m_screen_pos.x),
			(int)(m_pos.y - ITEM_SIZE[m_item_type] / 2 - Screen::m_screen_pos.y),
			(int)(m_pos.x + ITEM_SIZE[m_item_type] / 2 - Screen::m_screen_pos.x),
			(int)(m_pos.y + ITEM_SIZE[m_item_type] / 2 - Screen::m_screen_pos.y),
			handle, true);
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