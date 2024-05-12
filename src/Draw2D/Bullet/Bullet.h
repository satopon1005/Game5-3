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
	{"data/Weapon/magicbullet.png"},
	{"data/Weapon/Slashing.png"},
};

//サイズ関連
constexpr int BULLET_GAZOU_SIZE_X[BulletTypeMaxNum] = {
	100,128,70
};

constexpr int BULLET_GAZOU_SIZE_Y[BulletTypeMaxNum] = {
	100,69,100
};

constexpr int BULLET_DISPLAY_SIZE_Y[BulletTypeMaxNum] = {
	50,50,50
};

constexpr int BULLET_COLLISION_SIZE_R[BulletTypeMaxNum] = {
	10,10,10,
};

//アニメーション関連
constexpr int BULLET_ANIME_NUM[BulletTypeMaxNum] = {
	3,3,3
};
constexpr int BULLET_ANIME_MAX_NUM = 3;

constexpr int BULLET_ANIME_TIME[BulletTypeMaxNum] = {
	20,20,20
};

//弾のスピード
constexpr int BULLET_MOVE_SPEED[BulletTypeMaxNum] = {
	10,10,10
};

//連続で発射する弾の数
constexpr int BULLET_CONTINUATION_SHOT_NUM[BulletTypeMaxNum] = {
	3,3,1
};

constexpr int BULLET_DAMAGE_NUM[BulletTypeMaxNum] = {
	500,700,300,
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