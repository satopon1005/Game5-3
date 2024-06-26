#include "DxLib.h"
#include "CountTime.h"
#include "../Font/Font.h"

void CountTime::Init()
{
	m_start_time = 0;
	m_elapsed_time = 0;
	m_checkpoint_time = 0;

	m_minutes = 0;
	m_seconds = 0;

	m_count_flag = false;
}
bool CountTime::Step()
{
	if (m_count_flag) {
		m_elapsed_time = GetNowCount();
		//タイマーが終了したら
		if (m_minutes == 0 && m_seconds == 0 && m_elapsed_time - m_checkpoint_time >= 500) {
			m_count_flag = false;
			return true;
		}
		//１秒経過したら
		else if (m_elapsed_time - m_checkpoint_time >= 1000) {
			m_checkpoint_time += 1000;
			m_seconds--;
			//秒数が０を下回ったら
			if (m_seconds < 0) {
				m_minutes--;
				m_seconds = 59;
			}
		}
	}

	return false;
}
void CountTime::Draw(VECTOR pos)
{
	float string_width = (float)GetDrawFormatStringWidthToHandle(Font::m_font_handle[HGP創英角ﾎﾟｯﾌﾟ体],
														"%2d：%02d", m_minutes, m_seconds);

	DrawFormatStringToHandle((int)(pos.x - string_width / 2),
							(int)pos.y,
							GetColor(255, 255, 255),
							Font::m_font_handle[HGP創英角ﾎﾟｯﾌﾟ体],
							"%2d：%02d", m_minutes, m_seconds);
}

void CountTime::StartCountTime(int minutes, int seconds)
{
	m_minutes = minutes;
	m_seconds = seconds;

	m_start_time = GetNowCount();
	m_elapsed_time = m_start_time;
	m_checkpoint_time = m_start_time;

	m_count_flag = true;
}