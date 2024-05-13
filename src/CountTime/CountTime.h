#pragma once

class CountTime
{
private:
	int m_start_time;
	int m_elapsed_time;
	int m_end_time;

	bool m_count_flag;

public:
	void Init();
	void Step();
	void Draw(VECTOR pos);

	void StartCountTime();
};