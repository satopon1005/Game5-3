#pragma once
#include "../Common.h"

constexpr int DRAW_UI_X = SCREEN_SIZE_X / 4;
constexpr int DRAW_UI_Y[2] = { 20,5 };

class UI_Info
{
private:
	VECTOR m_pos[2];

public:
	void Init();
	void Step();
	void Draw(int player_hp, int player_keikenchi, int player_level);
};