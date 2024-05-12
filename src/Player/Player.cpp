#include "DxLib.h"
#include "Player.h"
#include "../Input/Input.h"
#include "../Screen/Screen.h"
#include "../Draw2D/Item/Item.h"


void Player::Init()
{
	PlayerPos= { 320.0f,240.0f/*,0.0f */};
	speed = 5;

	handle = LoadGraph(PLAYER_PATH);

	m_level = 0;
	m_keikenchi = 0;

	m_hp = PLAYER_DEFAULT_HP;
}

void Player::Step()
{
	if (Input::IsKeyKeep(KEY_INPUT_D))
	{
		PlayerPos.x +=speed;
	}
	if (Input::IsKeyKeep(KEY_INPUT_A))
	{
		PlayerPos.x -= speed;
	}
	if (Input::IsKeyKeep(KEY_INPUT_W))
	{
		PlayerPos.y -= speed;
	}
	if (Input::IsKeyKeep(KEY_INPUT_S))
	{
		PlayerPos.y += speed;
	}
}

void Player::Draw()
{
	DrawCircle((int)(PlayerPos.x - Screen::m_screen_pos.x),
		(int)(PlayerPos.y - Screen::m_screen_pos.y),
		PLAYER_SIZE_R,
		GetColor(0, 0, 255), true);

	DrawExtendGraph((int)(PlayerPos.x - PLAYER_SIZE_R - Screen::m_screen_pos.x),
		(int)(PlayerPos.y - PLAYER_SIZE_R - Screen::m_screen_pos.y),
		(int)(PlayerPos.x + PLAYER_SIZE_R - Screen::m_screen_pos.x),
		(int)(PlayerPos.y + PLAYER_SIZE_R - Screen::m_screen_pos.y),
		handle,
		true);
}

void Player::Fin()
{

}

//ƒAƒCƒeƒ€‚ðŽæ“¾‚µ‚½Žž‚Ìˆ—
void Player::IsGetItem(int item_type)
{
	switch (item_type) {
	case ItemType::Potion: {
		break;
	}
	case ItemType::Keikenchi: {
		m_keikenchi++;
		if (m_keikenchi >= DEFAULT_LEVELUP_NECESSARY_KEIKENCHI + (m_level * 5)) {
			m_level++;
			m_keikenchi = 0;
		}
		break;
	}
	}
}