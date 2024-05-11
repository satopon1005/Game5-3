#pragma once
#include "../Draw2D.h"
#include "../../Animation/Animation.h"

enum BulletType
{
	fireball,
	magicbullet,
	Slashing,

	BulletTypeMaxNum
};

constexpr char BULLET_TYPE_HANDLE_PATH[BulletTypeMaxNum][64] = {
	{"data/Weapon/fireball.png"},
	{"data/Weapon/magicbullet,png"},
	{"data/Weapon/Slashing.png"},
};

//サイズ関連
constexpr int BULLET_GAZOU_SIZE[BulletTypeMaxNum] = {
	300,128,200
};

constexpr int BULLET_DISPLAY_SIZE[BulletTypeMaxNum] = {
	20,32,20
};

constexpr int BULLET_COLLISION_SIZE_R[BulletTypeMaxNum] = {
	BULLET_DISPLAY_SIZE[fireball] / 2,
	BULLET_DISPLAY_SIZE[magicbullet] / 2,
	BULLET_DISPLAY_SIZE[Slashing] / 2,
};

//アニメーション関連
constexpr int BULLET_ANIME_NUM[BulletTypeMaxNum] = {
	1,1,1
};
constexpr int BULLET_ANIME_MAX_NUM = 1;

constexpr float BULLET_ANIME_TYPE[BulletTypeMaxNum] = {
	20,0,0
};

//弾のスピード
constexpr int BULLET_MOVE_SPEED[BulletTypeMaxNum] = {
	10,10,10
};

class Bullet :public Draw2D
{
private:
	int m_bullet_type;
	Animation m_anime_index;

	float m_angle;
	float m_move_angle;

public:
	void Init();
	void Step();
	void Draw(int handle);

	bool Spawn(VECTOR player_pos, int bullet_type);

	int GetBulletType() { return m_bullet_type; }
	int GetAnimeIndex() { return m_anime_index.GetCurrentAnimeIndex(); }
};