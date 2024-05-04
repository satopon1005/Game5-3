#include "DxLib.h"
#include "Screen.h"
#include "../Input/Input.h"
#include "../MapChip/MapChip.h"

VECTOR Screen::m_screen_pos;

void Screen::Init()
{
	m_screen_pos = { 0.0f,0.0f,0.0f };
}
void Screen::Step()
{
	
}
void Screen::StepEdit()
{
	if (Input::IsKeyDown(KEY_INPUT_UP))
		m_screen_pos.y -= 10;
	if (Input::IsKeyDown(KEY_INPUT_DOWN))
		m_screen_pos.y += 10;
	if (Input::IsKeyDown(KEY_INPUT_LEFT))
		m_screen_pos.x -= 10;
	if (Input::IsKeyDown(KEY_INPUT_RIGHT))
		m_screen_pos.x += 10;

	if (m_screen_pos.x < 0)
		m_screen_pos.x = 0;
	if (m_screen_pos.x > MAP_SIZE_X - SCREEN_SIZE_X)
		m_screen_pos.x = MAP_SIZE_X - SCREEN_SIZE_X;
	if (m_screen_pos.y < 0)
		m_screen_pos.y = 0;
	if (m_screen_pos.y > MAP_SIZE_Y - SCREEN_SIZE_Y)
		m_screen_pos.y = MAP_SIZE_Y - SCREEN_SIZE_Y;
}