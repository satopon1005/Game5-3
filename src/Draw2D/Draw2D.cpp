#include "Draw2D.h"

Draw2D::Draw2D()
{
	m_handle = nullptr;

	m_hp = 0;
	m_pos = { 0 };
	m_isUse = 0;
}
Draw2D::~Draw2D()
{
	if (m_handle != nullptr)
		FinHandle();
}

void Draw2D::LoadHandle(char* handle_path)
{
	m_handle = new int[1];

	m_handle[0] = LoadGraph(handle_path);
}

void Draw2D::LoadDivHandle(char* handle_path,
	int ANum,
	int Xnum,
	int Ynum,
	int Xsize,
	int Ysize)
{
	m_handle = new int[ANum];

	LoadDivGraph(handle_path,
		ANum,
		Xnum,
		Ynum,
		Xsize,
		Ysize,
		m_handle,
		true);
}

void Draw2D::FinHandle()
{
	delete m_handle;
}

void Draw2D::IsDamage(int damage)
{
	m_hp -= damage;
	m_damage_effect_alpha = 120;

	if (m_hp <= 0)
		m_isUse = false;
}