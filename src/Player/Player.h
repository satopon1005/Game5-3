#pragma once
#include "DxLib.h"
#include "../Bullet/Bullet.h"

const char PLAYER_PATH[] = { "data/Player/knight.png" };
const int PLAYER_SIZE_R = 20;

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

	VECTOR& GetPos() { return PlayerPos; }
};