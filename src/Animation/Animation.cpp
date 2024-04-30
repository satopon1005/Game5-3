#include "DxLib.h"
#include "Animation.h"

void Animation::Init()
{
	m_current_anime_index = 0;
	m_current_anime_time = 0;
}

void Animation::PlayAnimation(const int max_index, const int change_anime_time)
{
	if (m_current_anime_time >= change_anime_time) {
		m_current_anime_index++;
		if (m_current_anime_index >= max_index) {
			m_current_anime_index = 0;
		}
	}

	m_current_anime_time++;
}