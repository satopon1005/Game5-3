#include "DxLib.h"
#include "Sound.h"

int Sound::m_BGM_handle[ScenetypeMaxNum];
int Sound::m_SE_handle[SEtypeMaxNum];

Sound::Sound()
{
	for (int i = 0; i < ScenetypeMaxNum; i++)
		m_BGM_handle[i] = 0;
	for (int i = 0; i < SEtypeMaxNum; i++)
		m_SE_handle[i] = 0;
}

Sound::~Sound()
{
	FinSound();
}

void Sound::InitSound()
{
	//TEhÇÝÝ
	for (int i = 0; i < ScenetypeMaxNum; i++) {
		m_BGM_handle[i] = LoadSoundMem(BGM_HANDLE_PATH[i]);
	}
	for (int i = 0; i < SEtypeMaxNum; i++) {
		m_SE_handle[i] = LoadSoundMem(SE_HANDLE_PATH[i]);
	}

	ChangeVolumeSoundMem(80, m_BGM_handle[Title_BGM]);
	ChangeVolumeSoundMem(70, m_BGM_handle[Select_BGM]);
	ChangeVolumeSoundMem(60, m_BGM_handle[Play_BGM]);

	ChangeVolumeSoundMem(100, m_SE_handle[GameOver_BGM]);
	ChangeVolumeSoundMem(100, m_SE_handle[Clear_BGM]);
	ChangeVolumeSoundMem(100, m_SE_handle[Enemy_Death_SE]);
	ChangeVolumeSoundMem(100, m_SE_handle[LevelUp_SE]);
}

void Sound::PlaySE(int index)
{
	//TEhÄ¶
	PlaySoundMem(m_SE_handle[index], DX_PLAYTYPE_BACK, true);
}

void Sound::StopSE(int index)
{
	// SEâ~
	if (CheckSoundMem(m_SE_handle[index]) == 1)
	{
		StopSoundMem(m_SE_handle[index]);
	}
}

void Sound::PlayBGM(int index)
{
	// BGMÄ¶
	if (CheckSoundMem(m_BGM_handle[index]) == 0)
	{
		PlaySoundMem(m_BGM_handle[index], DX_PLAYTYPE_LOOP, true);
	}
}

void Sound::StopBGM(int index)
{
	// BGMâ~
	if (CheckSoundMem(m_BGM_handle[index]) == 1)
	{
		StopSoundMem(m_BGM_handle[index]);
	}
}
void Sound::StopAll()
{
	// BGMâ~
	for (int i = 0; i < ScenetypeMaxNum; i++)
		if (CheckSoundMem(m_BGM_handle[i]) == 1)
		{
			StopSoundMem(m_BGM_handle[i]);
		}

	// SEâ~
	for (int i = 0; i < SEtypeMaxNum; i++)
		if (CheckSoundMem(m_SE_handle[i]) == 1)
		{
			StopSoundMem(m_SE_handle[i]);
		}
}

void Sound::FinSound()
{
	//TEhjü
	for (int i = 0; i < ScenetypeMaxNum; i++)
		DeleteSoundMem(m_BGM_handle[i]);

	for (int i = 0; i < SEtypeMaxNum; i++)
		DeleteSoundMem(m_SE_handle[i]);
}