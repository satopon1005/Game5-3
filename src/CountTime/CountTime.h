#pragma once

class CountTime
{
private:
	int m_start_time;
	int m_elapsed_time;
	int m_checkpoint_time;

	int m_minutes;
	int m_seconds;

	bool m_count_flag;

public:
	void Init();
	bool Step();
	void Draw(VECTOR pos);

	void StartCountTime(int minutes, int seconds);

	int GetElapsedSecond() { return (int)((m_checkpoint_time - m_start_time) / 1000); }
};