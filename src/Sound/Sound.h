#pragma once

enum Scenetype
{
	Title_BGM,
	Select_BGM,
	Play_BGM,
	GameOver_BGM,
	Clear_BGM,

	ScenetypeMaxNum
};

enum SEtype
{
	Attack_SE,
	
	SEtypeMaxNum
};

constexpr char BGM_HANDLE_PATH[ScenetypeMaxNum][64] = {
	{"data/Sound/BGM/"},
	{"data/Sound/BGM/"},
	{"data/Sound/BGM/"},
	{"data/Sound/BGM/"},
	{"data/Sound/BGM/"},
};

constexpr char SE_HANDLE_PATH[SEtypeMaxNum][64] = {
	{},
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
	static void FinSound();
};

/*
DX_PLAYTYPE_NORMAL	�@:�@�m�[�}���Đ�
DX_PLAYTYPE_BACK	�@:�@�o�b�N�O���E���h�Đ�
DX_PLAYTYPE_LOOP	�@:�@���[�v�Đ�
*/