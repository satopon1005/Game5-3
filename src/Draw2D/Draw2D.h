#pragma once
#include "DxLib.h"

//重力
constexpr float GRAVITY_POWER = 0.9f;
//最大落下スピード
constexpr float MAX_FILLING_SPEED = GRAVITY_POWER * 30;

constexpr int DAMAGE_EFFECT_TIME = 10;

class Draw2D
{
protected:
	int* m_handle;

	int m_hp;

	VECTOR m_pos;
	bool m_isUse;

	int m_damage_effect_count;
	int m_damage_effect_alpha;

public:
	Draw2D();
	~Draw2D();

	int GetHp() { return m_hp; }
	void SetHp(int hp) { m_hp = hp; }

	void IsDamage(int damage);

	void LoadHandle(char* handle_path);
	void LoadDivHandle(char* handle_path, int ANum, int Xnum, int Ynum, int Xsize, int Ysize);
	void FinHandle();

	VECTOR GetPos() { return m_pos; }
	VECTOR& GetPosReference() { return m_pos; }
	void SetPos(VECTOR pos) { m_pos = pos; }

	bool GetIsUse() { return m_isUse; }
	void SetIsUse(bool flag) { m_isUse = flag; }
};