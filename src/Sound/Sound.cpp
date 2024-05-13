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
	//ƒTƒEƒ“ƒh“Ç‚Ýž‚Ý
	for (int i = 0; i < ScenetypeMaxNum; i++) {
		m_BGM_handle[i] = LoadSoundMem(BGM_HANDLE_PATH[i]);
	}
	for (int i = 0; i < SEtypeMaxNum; i++) {
		m_SE_handle[i] = LoadSoundMem(SE_HANDLE_PATH[i]);
	}

	ChangeVolumeSoundMem(100, m_BGM_handle[Title_BGM]);
	ChangeVolumeSoundMem(100, m_BGM_handle[Select_BGM]);
	ChangeVolumeSoundMem(60, m_BGM_handle[Play_BGM]);

	ChangeVolumeSoundMem(100, m_SE_handle[GameOver_BGM]);
	ChangeVolumeSoundMem(100, m_SE_handle[Clear_BGM]);
	ChangeVolumeSoundMem(100, m_SE_handle[Enemy_Death_SE]);
	ChangeVolumeSoundMem(100, m_SE_handle[LevelUp_SE]);
}

void Sound::PlaySE(int index)
{
	//ƒTƒEƒ“ƒhÄ¶
	PlaySoundMem(m_SE_handle[index], DX_PLAYTYPE_BACK, true);
}

void Sound::StopSE(int index)
{
	// SE’âŽ~
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
	// BGM’âŽ~
	if (CheckSoundMem(m_BGM_handle[index]) == 1)
	{
		StopSoundMem(m_BGM_handle[index]);
	}
}
void Sound::StopAll()
{
	// BGM’âŽ~
	for (int i = 0; i < ScenetypeMaxNum; i++)
		if (CheckSoundMem(m_BGM_handle[i]) == 1)
		{
			StopSoundMem(m_BGM_handle[i]);
		}

	// SE’âŽ~
	for (int i = 0; i < SEtypeMaxNum; i++)
		if (CheckSoundMem(m_SE_handle[i]) == 1)
		{
			StopSoundMem(m_SE_handle[i]);
		}
}

void Sound::FinSound()
{
	//ƒTƒEƒ“ƒh”jŠü
	for (int i = 0; i < ScenetypeMaxNum; i++)
		DeleteSoundMem(m_BGM_handle[i]);

	for (int i = 0; i < SEtypeMaxNum; i++)
		DeleteSoundMem(m_SE_handle[i]);
}