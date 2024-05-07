#include "DxLib.h"
#include "Player.h"
#include "../Input/Input.h"


void Player::Init()
{
	PlayerPos= { 0.0f,0.0f,0.0f };
	speed = 5;

}

void Player::Step()
{
	if (Input::IsKeyPush(KEY_INPUT_D))
	{
		PlayerPos.x += speed;
	}
	if (Input::IsKeyPush(KEY_INPUT_A))
	{
		PlayerPos.x -= speed;
	}
	if (Input::IsKeyPush(KEY_INPUT_W))
	{
		PlayerPos.y -= speed;
	}
	if (Input::IsKeyPush(KEY_INPUT_S))
	{
		PlayerPos.y += speed;
	}


}

void Player::Draw()
{
	DrawRotaGraph((int)(PlayerPos.x), (int)(PlayerPos.y), 1.0f, 0.0f, handle, true);
}

void Player::Fin()
{

}