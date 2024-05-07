#pragma once
#include "DxLib.h"
#include "../Bullet/Residue/Residue.h"

const char PLAYER_PATH[] = { "data/Player/knight.png" };
const float PLAYER_SIZE = 384.0f;

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
	void Move(VECTOR playerPos, VECTOR bulletPos);

	void Draw();
	void Fin();

	float GetPosX(){return PlayerPos.x;}
	float GetPosY(){return PlayerPos.y;}

	bool IsShot();
};