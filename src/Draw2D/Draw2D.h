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
public:
	Draw2D();
	~Draw2D();

	void LoadHandle(char* handle_path);
	void LoadDivHandle(char* handle_path, int ANum, int Xnum, int Ynum, int Xsize, int Ysize);
	void FinHandle();

	VECTOR GetPos() { return m_pos; }
	VECTOR& GetPosReference() { return m_pos; }
	void SetPos(VECTOR pos) { m_pos = pos; }

	bool GetIsUse() { return m_isUse; }
	void SetIsUse(bool flag) { m_isUse = flag; }
};