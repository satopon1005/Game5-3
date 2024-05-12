#pragma once
#include "DxLib.h"

constexpr char PLAYER_PATH[] = { "data/Player/knight.png" };
constexpr int PLAYER_SIZE_R = 20;

constexpr float Wait = 30.0f;

class Player
{
private:
	int handle;
	int speed;

	VECTOR PlayerPos;
public:

	void Init();
	void Step();

	void Draw();
	void Fin();

	void IsGetItem(int item_type);

	float GetPosX(){return PlayerPos.x;}
	float GetPosY(){return PlayerPos.y;}

	VECTOR& GetPos() { return PlayerPos; }
};