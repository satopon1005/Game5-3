#include "DxLib.h"
#include "UI.h"
#include "../Player/Player.h"

void UI_Info::Init()
{
	m_pos[0] = { 10,10,0 };
	m_pos[1] = { 10,(float)(DRAW_UI_Y[0] + 15),0 };
}
void UI_Info::Step()
{

}
void UI_Info::Draw(int player_hp, int player_keikenchi, int player_level)
{
	DrawBox((int)(m_pos[0].x),
		(int)(m_pos[0].y),
		(int)(DRAW_UI_X + m_pos[0].x),
		(int)(DRAW_UI_Y[0] + m_pos[0].y),
		GetColor(10, 10, 10), true);
	DrawBox((int)(m_pos[0].x),
		(int)(m_pos[0].y),
		(int)(((float)player_hp / (float)PLAYER_DEFAULT_HP) * DRAW_UI_X + m_pos[0].x),
		(int)(DRAW_UI_Y[0] + m_pos[0].y),
		GetColor(0, 255, 0), true);

	DrawBox((int)(m_pos[1].x),
		(int)(m_pos[1].y),
		(int)(DRAW_UI_X + m_pos[1].x),
		(int)(DRAW_UI_Y[1] + m_pos[1].y),
		GetColor(10, 10, 10), true);

	DrawBox((int)(m_pos[1].x),
		(int)(m_pos[1].y),
		(int)(((float)player_keikenchi / (float)(DEFAULT_LEVELUP_NECESSARY_KEIKENCHI + (player_level * 5))) * DRAW_UI_X + m_pos[1].x),
		(int)(DRAW_UI_Y[1] + m_pos[1].y),
		GetColor(0, 120, 255), true);
}