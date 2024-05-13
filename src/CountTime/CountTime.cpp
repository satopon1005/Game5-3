#include "DxLib.h"
#include "CountTime.h"
#include "../Font/Font.h"

void CountTime::Init()
{
	m_start_time = 0;
	m_elapsed_time = 0;
	m_end_time = 0;

	m_count_flag = false;
}
void CountTime::Step()
{
	if (m_count_flag) {

	}
}
void CountTime::Draw(VECTOR pos)
{

}

void CountTime::StartCountTime()
{

}