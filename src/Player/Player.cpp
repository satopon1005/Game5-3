#include "DxLib.h"
#include "Player.h"
#include "../Input/Input.h"
#include "../Screen/Screen.h"


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

	GetMousePoint(&MousePosX, &MousePosY);

}

void Player::Draw()
{
	DrawCircle((int)(PlayerPos.x - Screen::m_screen_pos.x + PLAYER_SIZE / 2),
		(int)(PlayerPos.y - Screen::m_screen_pos.y + PLAYER_SIZE / 2),
		PLAYER_SIZE / 2,
		GetColor(0, 0, 255), true);

	DrawExtendGraph((int)(PlayerPos.x - Screen::m_screen_pos.x),
		(int)(PlayerPos.y - Screen::m_screen_pos.y),
		(int)(PlayerPos.x + PLAYER_SIZE - Screen::m_screen_pos.x),
		(int)(PlayerPos.y + PLAYER_SIZE - Screen::m_screen_pos.y),
		handle,
		true);
	DrawFormatString(0, 15, GetColor(255, 255, 255), "マウス座標X:%d,座標Y:%d", MousePosX, MousePosY);
	DrawFormatString(0, 30, GetColor(255, 255, 255), "プレイヤー座標X:%d,座標Y:%d", (int)PlayerPos.x, (int)PlayerPos.y);
}

void Player::Fin()
{

}

bool Player::IsShot()
{
	if (GetMouseInput() && MOUSE_INPUT_LEFT != 0)
	{
		return true;
	}

	return false;
}

//弾の移動関数?
//void Player::Move(VECTOR playerPos, VECTOR BulletPos)
//{
//	//二点間の距離
//	float TwoPoint = 0.0f;
//
//	//X,Yベクトルを計算
//	BulletPos.x = MousePosX - playerPos.x;
//	BulletPos.y = MousePosY - playerPos.y;
//
//	//二点間の距離を取得
//	TwoPoint = (BulletPos.x * BulletPos.x) + (BulletPos.y * BulletPos.y);
//
//	//平方根を求める
//	TwoPoint = sqrtf(TwoPoint);
//
//	//正規化した値を足す
//	bulletPos.x += BulletPos.x / TwoPoint;
//	bulletPos.y += BulletPos.y / TwoPoint;
//}