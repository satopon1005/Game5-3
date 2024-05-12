#pragma once
#include "../Draw2D.h"

enum EnemyType
{
	Bat_mini,
	Bat,
	Ghost,
	Wood,
	Eye,

	EnemyTypeMaxNum
};

constexpr char ENEMY_HANDLE_PATH[] = { "data/Enemy/monster.png" };

constexpr int ENEMY_COLLISION_SIZE_R = 20;

constexpr float ENEMY_SPEED = 2.0f;

constexpr int ENEMY_DEFAULT_HP[EnemyTypeMaxNum] = {
	500,500,700,1000,400,
};

constexpr int ENEMY_ATTACK_POWER[EnemyTypeMaxNum] = {
	20,20,50,100,40
};

class Enemy_Info :public Draw2D
{
private:
	VECTOR m_distination_pos;
	int m_enemy_type;

public:
	void Init();
	void Step(VECTOR player_pos);
	void Draw(int handle);
	void Fin();

	bool Spawn();

	int GetEnemyType() { return m_enemy_type; }
};