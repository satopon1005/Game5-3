#pragma once

enum Scenetype
{
	Title_BGM,
	Select_BGM,
	Play_BGM,

	ScenetypeMaxNum
};

enum SEtype
{
	Clear_BGM,
	GameOver_BGM,
	Enemy_Death_SE,
	
	SEtypeMaxNum
};

constexpr char BGM_HANDLE_PATH[ScenetypeMaxNum][64] = {
	{"data/Sound/BGM/TitleSceneBGM3.mp3"},
	{"data/Sound/BGM/SelectSceneBGM2.mp3"},
	{"data/Sound/BGM/ScenePlayBGM2.mp3"},
};

constexpr char SE_HANDLE_PATH[SEtypeMaxNum][64] = {
	{"data/Sound/BGM/GameClearBGM1.m4a"},
	{"data/Sound/BGM/GameOverBGM2.mp3"},
	{"data/Sound/SE/HitSE2.mp3"},
};

class Sound
{
private:
	static int m_BGM_handle[ScenetypeMaxNum];
	static int m_SE_handle[SEtypeMaxNum];
public:
	Sound();
	~Sound();

	static void InitSound();
	static void PlaySE(int index);
	static void StopSE(int index);
	static void PlayBGM(int index);
	static void StopBGM(int index);
	static void StopAll();
	static void FinSound();
};

/*
DX_PLAYTYPE_NORMAL	　:　ノーマル再生
DX_PLAYTYPE_BACK	　:　バックグラウンド再生
DX_PLAYTYPE_LOOP	　:　ループ再生
*/