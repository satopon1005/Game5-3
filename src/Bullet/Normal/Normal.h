#pragma once

const float Time = 180.0f;

#include "DxLib.h"
#include "../../Common.h"
#include "../../Screen/Screen.h"

#include "../../Input/Input.h"

class NormalShot {
private:
	//クラスの宣言
	Input input;

	//画像ハンドル
	int    handle;
	//移動スピード
	float  Spd;
	//座標
	VECTOR Pos;

	//弾が生きているか
	bool isActive;

	//マウスの座標
	int MouseX, MouseY;
	VECTOR MousePos;

	//発射されてからの時間
	float count;
public:

	void Init();
	void Step();
	void Draw();
	void Fin();

	//弾を発射
	bool RequestShot(const VECTOR& vpos, const float& vspeed);

	//弾の動きの関数
	void UpData();

	//生死を返す
	bool IsActive() { return isActive; }
};