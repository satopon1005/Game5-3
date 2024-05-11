#include "DxLib.h"
#include "Bullet.h"
#include "../../Common.h"
#include "../../Input/Input.h"
#include "../../MyMath/MyMath.h"
#include "../../Screen/Screen.h"

void Bullet::Init()
{
	m_bullet_type = 0;

	m_pos = { 0 };
	m_isUse = false;

	m_angle = 0.0f;
	m_move_angle = 0.0f;
}
void Bullet::Step()
{
	if (m_isUse) {
		switch (m_bullet_type) {
		case fireball: {
			m_pos.x += cosf(m_angle) * BULLET_MOVE_SPEED[m_bullet_type];
			m_pos.y += sinf(m_angle) * BULLET_MOVE_SPEED[m_bullet_type];
			break;
		}
		case magicbullet: {
			m_pos.x += cosf(m_angle) * BULLET_MOVE_SPEED[m_bullet_type];
			m_pos.y += sinf(m_angle) * BULLET_MOVE_SPEED[m_bullet_type];
			break;
		}
		case Slashing: {
			m_pos.x += cosf(m_angle) * BULLET_MOVE_SPEED[m_bullet_type];
			m_pos.y += sinf(m_angle) * BULLET_MOVE_SPEED[m_bullet_type];

			m_move_angle += 0.3f;
			break;
		}
		}

		if (m_pos.x - BULLET_DISPLAY_SIZE[m_bullet_type] - Screen::m_screen_pos.x < 0 ||
			m_pos.y - BULLET_DISPLAY_SIZE[m_bullet_type] - Screen::m_screen_pos.y  < 0 ||
			m_pos.x + BULLET_DISPLAY_SIZE[m_bullet_type] - Screen::m_screen_pos.x  > SCREEN_SIZE_X ||
			m_pos.y + BULLET_DISPLAY_SIZE[m_bullet_type] - Screen::m_screen_pos.y  > SCREEN_SIZE_Y) {
			m_isUse = false;
		}
	}
}
void Bullet::Draw(int handle)
{
	if (m_isUse) {
		switch (m_bullet_type) {
		case fireball: {
			break;
		}
		case magicbullet: {
			break;
		}
		case Slashing: {
			DrawCircle((int)(m_pos.x + BULLET_COLLISION_SIZE_R[m_bullet_type] - Screen::m_screen_pos.x),
				(int)(m_pos.y + BULLET_COLLISION_SIZE_R[m_bullet_type] - Screen::m_screen_pos.y),
				BULLET_COLLISION_SIZE_R[m_bullet_type],
				GetColor(255, 0, 0), true);

			/*DrawRotaGraph((int)(m_pos.x + BULLET_COLLISION_SIZE_R[m_bullet_type] - Screen::m_screen_pos.x),
				(int)(m_pos.y + BULLET_COLLISION_SIZE_R[m_bullet_type] - Screen::m_screen_pos.y),
				((double)BULLET_DISPLAY_SIZE[m_bullet_type] / (double)BULLET_GAZOU_SIZE[m_bullet_type]),
				(double)m_move_angle,
				handle,
				true);*/
			break;
		}
		}
	}
}

bool Bullet::Spawn(VECTOR player_pos, int bullet_type)
{
	if (m_isUse) return false;

	m_bullet_type = bullet_type;

	m_pos = VGet(player_pos.x - BULLET_COLLISION_SIZE_R[m_bullet_type],
		player_pos.y - BULLET_COLLISION_SIZE_R[m_bullet_type],
		0);
	m_isUse = true;

	float angle = AngleOf2Vector(VGet(1.0f, 0.0f, 0.0f),
		GetVector(VGet(player_pos.x, player_pos.y, 0),
			VGet((float)Input::GetMousePosX() + Screen::m_screen_pos.x,
				(float)Input::GetMousePosY() + Screen::m_screen_pos.y,
				0.0f)));

	if (player_pos.y > Input::GetMousePosY() + Screen::m_screen_pos.y)
		angle = (float)(DX_PI * 2 - angle);

	m_angle = angle;
	m_move_angle = angle;

	return true;
}