#pragma once
#include "DxLib.h"

constexpr char PLAYER_PATH[] = { "data/Player/knight.png" };
constexpr int PLAYER_SIZE_R = 20;

constexpr float Wait = 30.0f;

constexpr int DEFAULT_LEVELUP_NECESSARY_KEIKENCHI = 10;

constexpr int PLAYER_DEFAULT_HP = 1000;

class Player
{
private:
	int handle;
	int speed;

	VECTOR PlayerPos;

	int m_hp;

	int m_level;
	int m_keikenchi;

	int m_damage_effect_count;
	int m_damage_effect_alpha;
public:

	void Init();
	void Step();

	void Draw();
	void Fin();

	void IsGetItem(int item_type);

	float GetPosX(){return PlayerPos.x;}
	float GetPosY(){return PlayerPos.y;}

	VECTOR& GetPos() { return PlayerPos; }

	int GetHP() { return m_hp; }
	int GetLevel() { return m_level; }
	int GetKeikenchi() { return m_keikenchi; }

	int GetAlpha() { return m_damage_effect_alpha; }

	void IsDamage(int damage);
};