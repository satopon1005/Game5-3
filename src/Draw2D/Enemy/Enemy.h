#pragma once
#include "../Draw2D.h"

enum EnemyType
{
	Enemy1,

	EnemyTypeMaxNum
};

constexpr char ENEMY_HANDLE_PATH[64] = { "data/Enemy/Bat.png" };

constexpr int ENEMY_COLLISION_SIZE = 40;

constexpr float ENEMY_SPEED = 2.0f;

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