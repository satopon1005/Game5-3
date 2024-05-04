#pragma once
#include "DxLib.h"

#include "../Common.h"
#include "../MyMath/MyMath.h"

enum BULLET_TYPE {
	NOTHING = -1,		//データなし

	RESIDUE,		//残留弾

	BULLET_NUM,		//弾タイプの総数
};

class Bullet {
protected:

	const char bulletFilePath[BULLET_NUM][256] = {
		"data/",
	};

	BULLET_TYPE bulletType;

	VECTOR bulletPos;		//座標
	VECTOR bulletRot;		//角度
	VECTOR bulletSpeed;		//移動速度

	int handle;	//画像ハンドル
	float Time;	//時間カウント用
	bool isUse;	//撃っているか(初期値false)
	bool isHit;	//当たっているか(初期値false)

	void ScreenOut(); //画面外に出たらフラグを折る
	//範囲指定乱数
	int ScopeRand(int min, int max);

public:
	void Init();
	void Step();
	void Draw();
	void Fin();
};