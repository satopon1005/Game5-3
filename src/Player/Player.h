#pragma once
#include "DxLib.h"

const char PLAYER_PATH[] = { "data/Player/仮置きプレイヤー.png" };
const float PLAYER_SIZE = 32.0f;

class Player
{
private:
	int handle;
	int speed;

	int MousePosX, MousePosY;

	VECTOR PlayerPos;

public:

	void Init();
	void Step();
	void Draw();
	void Fin();

};