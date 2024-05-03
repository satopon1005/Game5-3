#include "DxLib.h"
#include "Screen.h"
#include "../Input/Input.h"

VECTOR Screen::m_screen_pos;

void Screen::Init()
{
	m_screen_pos = { 0.0f,0.0f,0.0f };
}
void Screen::Step()
{
	if (Input::IsKeyDown(KEY_INPUT_UP))
		m_screen_pos.y -= 5;
	if (Input::IsKeyDown(KEY_INPUT_DOWN))
		m_screen_pos.y += 5;
	if (Input::IsKeyDown(KEY_INPUT_LEFT))
		m_screen_pos.x -= 5;
	if (Input::IsKeyDown(KEY_INPUT_RIGHT))
		m_screen_pos.x += 5;
}