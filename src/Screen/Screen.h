#pragma once

class Screen
{
public:
	static VECTOR m_screen_pos;

	static void Init();
	static void Step(VECTOR player_pos);
	static void StepEdit();
};