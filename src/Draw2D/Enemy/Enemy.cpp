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

	m_damage_effect_count = 0;
	m_damage_effect_alpha = 255;
}
void Enemy_Info::Step(VECTOR player_pos)
{
	if (m_isUse) {
		m_distination_pos = GetVector(m_pos, player_pos, ENEMY_SPEED);

		m_pos.x += m_distination_pos.x;
		m_pos.y += m_distination_pos.y;

		if (m_damage_effect_alpha != 255) {
			m_damage_effect_count++;

			if (m_damage_effect_count >= DAMAGE_EFFECT_TIME) {
				m_damage_effect_alpha = 255;
				m_damage_effect_count = 0;
			}
		}
	}
}
void Enemy_Info::Draw(int handle)
{
	if (m_isUse) {
		DrawCircle((int)(m_pos.x - Screen::m_screen_pos.x),
			(int)(m_pos.y - Screen::m_screen_pos.y),
			ENEMY_COLLISION_SIZE_R,
			GetColor(0, 255, 0), true);

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_damage_effect_alpha);
		DrawExtendGraph((int)(m_pos.x - Screen::m_screen_pos.x - ENEMY_COLLISION_SIZE_R),
			(int)(m_pos.y - Screen::m_screen_pos.y - ENEMY_COLLISION_SIZE_R),
			(int)(m_pos.x - Screen::m_screen_pos.x + ENEMY_COLLISION_SIZE_R),
			(int)(m_pos.y - Screen::m_screen_pos.y + ENEMY_COLLISION_SIZE_R),
			handle, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	}
}
void Enemy_Info::Fin()
{
	
}

bool Enemy_Info::Spawn()
{
	if (m_isUse)return false;

	m_enemy_type = GetRand(EnemyTypeMaxNum - 1);
	m_isUse = true;
	m_hp = ENEMY_DEFAULT_HP[m_enemy_type];

	m_damage_effect_count = 0;
	m_damage_effect_alpha = 255;

	int spawn_pos_rand = GetRand(3);

	switch (spawn_pos_rand) {
	case 0: {
		//âE
		m_pos.x = Screen::m_screen_pos.x + SCREEN_SIZE_X + ENEMY_COLLISION_SIZE_R * 2;
		m_pos.y = GetRand(SCREEN_SIZE_Y) + Screen::m_screen_pos.y;
		break;
	}
	case 1: {
		//ç∂
		m_pos.x = Screen::m_screen_pos.x - ENEMY_COLLISION_SIZE_R * 2;
		m_pos.y = GetRand(SCREEN_SIZE_Y) + Screen::m_screen_pos.y;
		break;
	}
	case 2: {
		//è„
		m_pos.y = Screen::m_screen_pos.y - ENEMY_COLLISION_SIZE_R * 2;
		m_pos.x = GetRand(SCREEN_SIZE_X) + Screen::m_screen_pos.x;
		break;
	}
	case 3: {
		//â∫
		m_pos.y = Screen::m_screen_pos.y + SCREEN_SIZE_Y + ENEMY_COLLISION_SIZE_R * 2;
		m_pos.x = GetRand(SCREEN_SIZE_X) + Screen::m_screen_pos.x;
		break;
	}
	}

	return true;
}