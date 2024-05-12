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
}
void Bullet::Step()
{
	if (m_isUse) {
		switch (m_bullet_type) {
		//���̏�
		case fireball: {
			m_pos.x += cosf(m_angle) * BULLET_MOVE_SPEED[m_bullet_type];
			m_pos.y += sinf(m_angle) * BULLET_MOVE_SPEED[m_bullet_type];
			break;
		}
		//���e
		case magicbullet: {
			m_pos.x += cosf(m_angle) * BULLET_MOVE_SPEED[m_bullet_type];
			m_pos.y += sinf(m_angle) * BULLET_MOVE_SPEED[m_bullet_type];
			break;
		}
		//�a��
		case Slashing: {
			m_pos.x += cosf(m_angle) * BULLET_MOVE_SPEED[m_bullet_type];
			m_pos.y += sinf(m_angle) * BULLET_MOVE_SPEED[m_bullet_type];
			break;
		}
		//����

		//�j���j�N
		}

		m_anime_index.PlayAnimation(BULLET_ANIME_NUM[m_bullet_type], BULLET_ANIME_TIME[m_bullet_type]);

		if (m_pos.x - BULLET_DISPLAY_SIZE_Y[m_bullet_type] - Screen::m_screen_pos.x < 0 ||
			m_pos.y - BULLET_DISPLAY_SIZE_Y[m_bullet_type] - Screen::m_screen_pos.y  < 0 ||
			m_pos.x + BULLET_DISPLAY_SIZE_Y[m_bullet_type] - Screen::m_screen_pos.x  > SCREEN_SIZE_X ||
			m_pos.y + BULLET_DISPLAY_SIZE_Y[m_bullet_type] - Screen::m_screen_pos.y  > SCREEN_SIZE_Y) {
			m_isUse = false;
		}
	}
}
void Bullet::Draw(int handle)
{
	if (m_isUse) {
		switch (m_bullet_type) {
		//���̏�
		case fireball: {
			DrawCircle((int)(m_pos.x + BULLET_COLLISION_SIZE_R[m_bullet_type] - Screen::m_screen_pos.x),
				(int)(m_pos.y + BULLET_COLLISION_SIZE_R[m_bullet_type] - Screen::m_screen_pos.y),
				BULLET_COLLISION_SIZE_R[m_bullet_type],
				GetColor(255, 255, 0), true);

			DrawRotaGraph((int)(m_pos.x + BULLET_COLLISION_SIZE_R[m_bullet_type] - Screen::m_screen_pos.x),
				(int)(m_pos.y + BULLET_COLLISION_SIZE_R[m_bullet_type] - Screen::m_screen_pos.y),
				((double)BULLET_DISPLAY_SIZE_Y[m_bullet_type] / (double)BULLET_GAZOU_SIZE_Y[m_bullet_type]),
				(double)m_move_angle,
				handle,
				true);
			break;
		}
		//���e
		case magicbullet: {
			DrawCircle((int)(m_pos.x + BULLET_COLLISION_SIZE_R[m_bullet_type] - Screen::m_screen_pos.x),
				(int)(m_pos.y + BULLET_COLLISION_SIZE_R[m_bullet_type] - Screen::m_screen_pos.y),
				BULLET_COLLISION_SIZE_R[m_bullet_type],
				GetColor(255, 0, 255), true);

			DrawRotaGraph((int)(m_pos.x + BULLET_COLLISION_SIZE_R[m_bullet_type] - Screen::m_screen_pos.x),
				(int)(m_pos.y + BULLET_COLLISION_SIZE_R[m_bullet_type] - Screen::m_screen_pos.y),
				((double)BULLET_DISPLAY_SIZE_Y[m_bullet_type] / (double)BULLET_GAZOU_SIZE_Y[m_bullet_type]),
				(double)m_move_angle,
				handle,
				true);
			break;
		}
		//�a��
		case Slashing: {
			DrawCircle((int)(m_pos.x + BULLET_COLLISION_SIZE_R[m_bullet_type] - Screen::m_screen_pos.x),
				(int)(m_pos.y + BULLET_COLLISION_SIZE_R[m_bullet_type] - Screen::m_screen_pos.y),
				BULLET_COLLISION_SIZE_R[m_bullet_type],
				GetColor(255, 0, 0), true);

			DrawRotaGraph((int)(m_pos.x + BULLET_COLLISION_SIZE_R[m_bullet_type] - Screen::m_screen_pos.x),
				(int)(m_pos.y + BULLET_COLLISION_SIZE_R[m_bullet_type] - Screen::m_screen_pos.y),
				((double)BULLET_DISPLAY_SIZE_Y[m_bullet_type] / (double)BULLET_GAZOU_SIZE_Y[m_bullet_type]),
				(double)m_move_angle,
				handle,
				true);
			break;
		}
		//����

		//�j���j�N
		}
	}
}

bool Bullet::Spawn(VECTOR player_pos, int bullet_type)
{
	if (m_isUse) return false;

	m_bullet_type = bullet_type;

	switch (m_bullet_type) {
	//���̏�
	case fireball: {
		//�e���ˎ��̍��W�̓v���C���[�̍��W
		m_pos = VGet(player_pos.x - BULLET_COLLISION_SIZE_R[m_bullet_type],
			player_pos.y - BULLET_COLLISION_SIZE_R[m_bullet_type],
			0);

		float angle = (float)GetRand((int)(DX_PI * 2 * 100)) / 100;

		m_angle = angle;
		m_move_angle = angle;
		break;
	}
	//���e
	case magicbullet: {
		//�e���ˎ��̍��W�̓v���C���[�̍��W
		m_pos = VGet(player_pos.x - BULLET_COLLISION_SIZE_R[m_bullet_type],
			player_pos.y - BULLET_COLLISION_SIZE_R[m_bullet_type],
			0);

		//�v���C���[����}�E�X�ւ̃x�N�g���̂Ȃ��p
		float angle = AngleOf2Vector(VGet(1.0f, 0.0f, 0.0f),
			GetVector(VGet(player_pos.x, player_pos.y, 0),
				VGet((float)Input::GetMousePosX() + Screen::m_screen_pos.x,
					(float)Input::GetMousePosY() + Screen::m_screen_pos.y,
					0.0f)));
		if (player_pos.y > Input::GetMousePosY() + Screen::m_screen_pos.y)
			angle = (float)(DX_PI * 2 - angle);
		//�o�����p�x����{�|�R�O��
		angle += (float)(GetRand((int)(DX_PI * 100 / 3)) - (DX_PI * 100 / 6)) / 100;

		m_angle = angle;
		m_move_angle = angle;

		break;
	}
	//�a��
	case Slashing: {
		//�e���ˎ��̍��W�̓v���C���[�̍��W
		m_pos = VGet(player_pos.x - BULLET_COLLISION_SIZE_R[m_bullet_type],
			player_pos.y - BULLET_COLLISION_SIZE_R[m_bullet_type],
			0);

		//�v���C���[����}�E�X�ւ̃x�N�g���̂Ȃ��p
		float angle = AngleOf2Vector(VGet(1.0f, 0.0f, 0.0f),
			GetVector(VGet(player_pos.x, player_pos.y, 0),
				VGet((float)Input::GetMousePosX() + Screen::m_screen_pos.x,
					(float)Input::GetMousePosY() + Screen::m_screen_pos.y,
					0.0f)));
		if (player_pos.y > Input::GetMousePosY() + Screen::m_screen_pos.y)
			angle = (float)(DX_PI * 2 - angle);

		m_angle = angle;
		m_move_angle = angle;
		break;
	}
	//����

	//�j���j�N
	}

	m_isUse = true;
	m_anime_index.Init();

	return true;
}