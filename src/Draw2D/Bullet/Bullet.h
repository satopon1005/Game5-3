#pragma once
#include "../Draw2D.h"
#include "../../Animation/Animation.h"

enum BulletType
{
	fireball,
	magicbullet,
	Slashing,
	Holywater,
	Ninniku,

	BulletTypeMaxNum
};

constexpr char BULLET_TYPE_HANDLE_PATH[BulletTypeMaxNum][64] = {
	{"data/Weapon/fireball.png"},
	{"data/Weapon/magicbullet.png"},
	{"data/Weapon/Slashing.png"},
	{"data/Weapon/holywater.png"},
};

//�T�C�Y�֘A
constexpr int BULLET_GAZOU_SIZE_X[BulletTypeMaxNum] = {
	100,128,42,64
};

constexpr int BULLET_GAZOU_SIZE_Y[BulletTypeMaxNum] = {
	100,69,126,64
};

constexpr int BULLET_DISPLAY_SIZE_Y[BulletTypeMaxNum] = {
	100,50,200,64
};

constexpr int BULLET_COLLISION_SIZE_R[BulletTypeMaxNum] = {
	10,10,15,32
};

//�A�j���[�V�����֘A
constexpr int BULLET_ANIME_NUM[BulletTypeMaxNum] = {
	3,3,3,3
};
constexpr int BULLET_ANIME_MAX_NUM = 3;

constexpr int BULLET_ANIME_TIME[BulletTypeMaxNum] = {
	20,20,20,20
};

//�e�̃X�s�[�h
constexpr int BULLET_MOVE_SPEED[BulletTypeMaxNum] = {
	10,10,10,0
};

//�A���Ŕ��˂���e�̐�
constexpr int BULLET_CONTINUATION_SHOT_NUM[BulletTypeMaxNum] = {
	3,3,1,1
};

constexpr int BULLET_DAMAGE_NUM[BulletTypeMaxNum] = {
	1000,700,300,30
};

class Bullet :public Draw2D
{
private:
	int m_bullet_type;
	Animation m_anime_index;

	float m_angle;
	float m_move_angle;

	int m_display_count;

public:
	void Init();
	void Step();
	void Draw(int handle);

	bool Spawn(VECTOR player_pos, int bullet_type);

	int GetBulletType() { return m_bullet_type; }
	int GetAnimeIndex() { return m_anime_index.GetCurrentAnimeIndex(); }
};