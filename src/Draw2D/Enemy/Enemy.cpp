#include "DxLib.h"
#include "Enemy.h"
#include "../../Common.h"
#include "../../Screen/Screen.h"
#include "../../MyMath/MyMath.h"

void Enemy_Info::Init()
{
	m_pos = { 0 };
	m_isUse = false;

	m_distination_pos = { 0 };
	m_enemy_type = 0;

	LoadHandle((char*)ENEMY_HANDLE_PATH);
}
void Enemy_Info::Step(VECTOR player_pos)
{
	if (m_isUse) {
		m_distination_pos = GetVector(m_pos, player_pos, ENEMY_SPEED);

		m_pos.x += m_distination_pos.x;
		m_pos.y += m_distination_pos.y;
	}
}
void Enemy_Info::Draw()
{
	if (m_isUse) {
		DrawCircle((int)(m_pos.x - Screen::m_screen_pos.x + ENEMY_COLLISION_SIZE / 2),
			(int)(m_pos.y - Screen::m_screen_pos.y + ENEMY_COLLISION_SIZE / 2),
			ENEMY_COLLISION_SIZE / 2,
			GetColor(0, 255, 0), true);

		DrawExtendGraph((int)(m_pos.x - Screen::m_screen_pos.x),
			(int)(m_pos.y - Screen::m_screen_pos.y),
			(int)(m_pos.x - Screen::m_screen_pos.x + ENEMY_COLLISION_SIZE),
			(int)(m_pos.y - Screen::m_screen_pos.y + ENEMY_COLLISION_SIZE),
			m_handle[0], true);
	}
}
void Enemy_Info::Fin()
{
	FinHandle();
}

bool Enemy_Info::Spawn()
{
	if (m_isUse)return false;

	m_enemy_type = GetRand(EnemyTypeMaxNum - 1);
	m_isUse = true;

	int spawn_pos_rand = GetRand(3);

	switch (spawn_pos_rand) {
	case 0: {
		//âE
		m_pos.x = Screen::m_screen_pos.x + SCREEN_SIZE_X + ENEMY_COLLISION_SIZE;
		m_pos.y = GetRand(SCREEN_SIZE_Y) + Screen::m_screen_pos.y;
		break;
	}
	case 1: {
		//ç∂
		m_pos.x = Screen::m_screen_pos.x - ENEMY_COLLISION_SIZE;
		m_pos.y = GetRand(SCREEN_SIZE_Y) + Screen::m_screen_pos.y;
		break;
	}
	case 2: {
		//è„
		m_pos.y = Screen::m_screen_pos.y - ENEMY_COLLISION_SIZE;
		m_pos.x = GetRand(SCREEN_SIZE_X) + Screen::m_screen_pos.x;
		break;
	}
	case 3: {
		//â∫
		m_pos.y = Screen::m_screen_pos.y + SCREEN_SIZE_Y + ENEMY_COLLISION_SIZE;
		m_pos.x = GetRand(SCREEN_SIZE_X) + Screen::m_screen_pos.x;
		break;
	}
	}

	return true;
}