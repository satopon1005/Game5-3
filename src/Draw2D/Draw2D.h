#pragma once
#include "DxLib.h"

//重力
constexpr float GRAVITY_POWER = 0.9f;
//最大落下スピード
constexpr float MAX_FILLING_SPEED = GRAVITY_POWER * 30;

class Draw2D
{
protected:
	int* m_handle;

	VECTOR m_pos;
	bool m_isUse;
	VECTOR m_coliision_size;
	float m_coliision_size_r;
public:
	Draw2D();
	~Draw2D();

	void LoadHandle(char* handle_path, int ANum, int Xnum, int Ynum, int Xsize, int Ysize);
	void FinHandle();

	VECTOR GetPos() { return m_pos; }
	void SetPos(VECTOR pos) { m_pos = pos; }

	bool GetIsUse() { return m_isUse; }
	void SetIsUse(bool flag) { m_isUse = flag; }

	VECTOR GetCollisionSize() { return m_coliision_size; }
	float GetCollisionSizeR() { return m_coliision_size_r; }

	void SetCollisionSize(VECTOR size) { m_coliision_size = size; }
	void SetCollisionSizeR(float size) { m_coliision_size_r = size; }
};