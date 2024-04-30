#pragma once

class Animation
{
protected:
	int m_current_anime_index;
	int m_current_anime_time;

public:
	void Init();

	void PlayAnimation(const int max_index, const int change_anime_time);

	void SetCurrentAnimationIndex(int index) { m_current_anime_index = index; }
	int GetCurrentAnimeIndex() { return m_current_anime_index; }
};