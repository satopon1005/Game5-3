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

//ÉAÉCÉeÉÄÇéÊìæÇµÇΩéûÇÃèàóù
void Player::IsGetItem(int item_type)
{
	switch (item_type) {
	case ItemType::Potion: {
		break;
	}
	case ItemType::Keikenchi: {
		break;
	}
	}
}