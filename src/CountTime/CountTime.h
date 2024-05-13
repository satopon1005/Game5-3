#pragma once

class CountTime
{
private:
	int m_start_time;
	int m_elaosed_time;
	int m_checkpoint_time;

	int m_minutes;
	int m_seconds;

	bool m_count_flag;

public:
	void Init();
	bool Step();
	void Draw(VECTOR pos);

	void StartCountTime(int minutes, int seconds);
};