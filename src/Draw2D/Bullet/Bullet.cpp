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

	m_anime_index.Init();

	m_display_count = 0;
}
void Bullet::Step()
{
	if (m_isUse) {
		switch (m_bullet_type) {
		//炎の杖
		case fireball: {
			m_pos.x += cosf(m_angle) * BULLET_MOVE_SPEED[m_bullet_type];
			m_pos.y += sinf(m_angle) * BULLET_MOVE_SPEED[m_bullet_type];
			break;
		}
		//魔弾
		case magicbullet: {
			m_pos.x += cosf(m_angle) * BULLET_MOVE_SPEED[m_bullet_type];
			m_pos.y += sinf(m_angle) * BULLET_MOVE_SPEED[m_bullet_type];
			break;
		}
		//斬撃
		case Slashing: {
			m_pos.x += cosf(m_angle) * BULLET_MOVE_SPEED[m_bullet_type];
			m_pos.y += sinf(m_angle) * BULLET_MOVE_SPEED[m_bullet_type];
			break;
		}
		//聖水
		case Holywater: {
			m_display_count++;

			if (m_display_count > 3 * 60) {
				m_isUse = false;
			}
		}
		//ニンニク
		}

		m_anime_index.PlayAnimation(BULLET_ANIME_NUM[m_bullet_type], BULLET_ANIME_TIME[m_bullet_type]);

		if (m_pos.x - Screen::m_screen_pos.x < -BULLET_DISPLAY_SIZE_Y[m_bullet_type] ||
			m_pos.y - Screen::m_screen_pos.y < -BULLET_DISPLAY_SIZE_Y[m_bullet_type] ||
			m_pos.x - Screen::m_screen_pos.x  > SCREEN_SIZE_X + BULLET_DISPLAY_SIZE_Y[m_bullet_type] ||
			m_pos.y - Screen::m_screen_pos.y  > SCREEN_SIZE_Y + BULLET_DISPLAY_SIZE_Y[m_bullet_type]) {
			m_isUse = false;
		}
	}
}
void Bullet::Draw(int handle)
{
	if (m_isUse) {
		switch (m_bullet_type) {
		//炎の杖
		case fireball: {
			/*DrawCircle((int)(m_pos.x + BULLET_COLLISION_SIZE_R[m_bullet_type] - Screen::m_screen_pos.x),
				(int)(m_pos.y + BULLET_COLLISION_SIZE_R[m_bullet_type] - Screen::m_screen_pos.y),
				BULLET_COLLISION_SIZE_R[m_bullet_type],
				GetColor(255, 255, 0), true);*/

			DrawRotaGraph2((int)(m_pos.x + BULLET_COLLISION_SIZE_R[m_bullet_type] - Screen::m_screen_pos.x),
				(int)(m_pos.y + BULLET_COLLISION_SIZE_R[m_bullet_type] - Screen::m_screen_pos.y),
				70,
				50,
				((double)BULLET_DISPLAY_SIZE_Y[m_bullet_type] / (double)BULLET_GAZOU_SIZE_Y[m_bullet_type]),
				(double)m_move_angle,
				handle,
				true);
			break;
		}
		//魔弾
		case magicbullet: {
			/*DrawCircle((int)(m_pos.x + BULLET_COLLISION_SIZE_R[m_bullet_type] - Screen::m_screen_pos.x),
				(int)(m_pos.y + BULLET_COLLISION_SIZE_R[m_bullet_type] - Screen::m_screen_pos.y),
				BULLET_COLLISION_SIZE_R[m_bullet_type],
				GetColor(255, 0, 255), true);*/

			DrawRotaGraph2((int)(m_pos.x + BULLET_COLLISION_SIZE_R[m_bullet_type] - Screen::m_screen_pos.x),
				(int)(m_pos.y + BULLET_COLLISION_SIZE_R[m_bullet_type] - Screen::m_screen_pos.y),
				110,
				35,
				((double)BULLET_DISPLAY_SIZE_Y[m_bullet_type] / (double)BULLET_GAZOU_SIZE_Y[m_bullet_type]),
				(double)m_move_angle,
				handle,
				true);
			break;
		}
		//斬撃
		case Slashing: {
			/*DrawCircle((int)(m_pos.x + BULLET_COLLISION_SIZE_R[m_bullet_type] - Screen::m_screen_pos.x),
				(int)(m_pos.y + BULLET_COLLISION_SIZE_R[m_bullet_type] - Screen::m_screen_pos.y),
				BULLET_COLLISION_SIZE_R[m_bullet_type],
				GetColor(255, 0, 0), true);*/

			DrawRotaGraph((int)(m_pos.x + BULLET_COLLISION_SIZE_R[m_bullet_type] - Screen::m_screen_pos.x),
				(int)(m_pos.y + BULLET_COLLISION_SIZE_R[m_bullet_type] - Screen::m_screen_pos.y),
				((double)BULLET_DISPLAY_SIZE_Y[m_bullet_type] / (double)BULLET_GAZOU_SIZE_Y[m_bullet_type]),
				(double)m_move_angle,
				handle,
				true);
			break;
		}
		//聖水
		case Holywater: {
			/*DrawCircle((int)(m_pos.x + BULLET_COLLISION_SIZE_R[m_bullet_type] - Screen::m_screen_pos.x),
				(int)(m_pos.y + BULLET_COLLISION_SIZE_R[m_bullet_type] - Screen::m_screen_pos.y),
				BULLET_COLLISION_SIZE_R[m_bullet_type],
				GetColor(255, 0, 0), true);*/

			DrawRotaGraph((int)(m_pos.x + BULLET_COLLISION_SIZE_R[m_bullet_type] - Screen::m_screen_pos.x),
				(int)(m_pos.y + BULLET_COLLISION_SIZE_R[m_bullet_type] - Screen::m_screen_pos.y),
				((double)BULLET_DISPLAY_SIZE_Y[m_bullet_type] / (double)BULLET_GAZOU_SIZE_Y[m_bullet_type]),
				0.0,
				handle,
				true);
		}
		//ニンニク
		}
	}
}

bool Bullet::Spawn(VECTOR player_pos, int bullet_type)
{
	if (m_isUse) return false;

	m_bullet_type = bullet_type;

	switch (m_bullet_type) {
	//炎の杖
	case fireball: {
		float angle = (float)GetRand((int)(DX_PI * 2 * 100)) / 100;

		//弾発射時の座標はプレイヤーの座標
		m_pos = VGet(player_pos.x - BULLET_COLLISION_SIZE_R[m_bullet_type] + cosf(angle) * (BULLET_DISPLAY_SIZE_Y[m_bullet_type] / 2),
			player_pos.y - BULLET_COLLISION_SIZE_R[m_bullet_type] + sinf(angle) * (BULLET_DISPLAY_SIZE_Y[m_bullet_type] / 2),
			0);

		m_angle = angle;
		m_move_angle = angle;
		break;
	}
	//魔弾
	case magicbullet: {
		//プレイヤーからマウスへのベクトルのなす角
		float angle = AngleOf2Vector(VGet(1.0f, 0.0f, 0.0f),
			GetVector(VGet(player_pos.x, player_pos.y, 0),
				VGet((float)Input::GetMousePosX() + Screen::m_screen_pos.x,
					(float)Input::GetMousePosY() + Screen::m_screen_pos.y,
					0.0f)));
		if (player_pos.y > Input::GetMousePosY() + Screen::m_screen_pos.y)
			angle = (float)(DX_PI * 2 - angle);
		//出した角度から＋－３０°
		angle += (float)(GetRand((int)(DX_PI * 100 / 3 * 2)) - (DX_PI * 100 / 3)) / 100;

		//弾発射時の座標はプレイヤーの座標
		m_pos = VGet(player_pos.x - BULLET_COLLISION_SIZE_R[m_bullet_type] + cosf(angle) * (BULLET_DISPLAY_SIZE_Y[m_bullet_type] / 2),
			player_pos.y - BULLET_COLLISION_SIZE_R[m_bullet_type] + sinf(angle) * (BULLET_DISPLAY_SIZE_Y[m_bullet_type] / 2),
			0);

		m_angle = angle;
		m_move_angle = angle;

		break;
	}
	//斬撃
	case Slashing: {
		//プレイヤーからマウスへのベクトルのなす角
		float angle = AngleOf2Vector(VGet(1.0f, 0.0f, 0.0f),
			GetVector(VGet(player_pos.x, player_pos.y, 0),
				VGet((float)Input::GetMousePosX() + Screen::m_screen_pos.x,
					(float)Input::GetMousePosY() + Screen::m_screen_pos.y,
					0.0f)));
		if (player_pos.y > Input::GetMousePosY() + Screen::m_screen_pos.y)
			angle = (float)(DX_PI * 2 - angle);

		//弾発射時の座標はプレイヤーの座標
		m_pos = VGet(player_pos.x - BULLET_COLLISION_SIZE_R[m_bullet_type] + cosf(angle) * (BULLET_DISPLAY_SIZE_Y[m_bullet_type] / 2),
			player_pos.y - BULLET_COLLISION_SIZE_R[m_bullet_type] + sinf(angle) * (BULLET_DISPLAY_SIZE_Y[m_bullet_type] / 2),
			0);

		m_angle = angle;
		m_move_angle = angle;
		break;
	}
	//聖水
	case Holywater: {
		float angle = (float)GetRand((int)(DX_PI * 2 * 100)) / 100;

		m_pos = VGet(player_pos.x - BULLET_COLLISION_SIZE_R[m_bullet_type] + sinf(angle) * BULLET_DISPLAY_SIZE_Y[m_bullet_type],
			player_pos.y - BULLET_COLLISION_SIZE_R[m_bullet_type] + cosf(angle) * BULLET_DISPLAY_SIZE_Y[m_bullet_type],
			0);

		m_display_count = 0;
	}
	//ニンニク
	}

	m_isUse = true;
	m_anime_index.Init();

	return true;
}