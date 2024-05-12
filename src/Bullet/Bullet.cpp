#include "Bullet.h"

//コンストラクタ
CBulletMaster::CBulletMaster()
{
	Frame = 0;
}

//デストラクタ
CBulletMaster::~CBulletMaster()
{

}

//初期化
void CBulletMaster::Init()
{
	//フレームを初期化
	Frame = 0;

	//通常弾
	for (int i = 0; i < NORM_SHOT_NUM; i++) {
		normal[i].Init();
	}
}

//ロード
void CBulletMaster::Load()
{

}

//通常処理
void CBulletMaster::Step()
{
	//フレームをカウント
	Frame++;
	if (Frame >= FRAME_RATE)
	{
		//フレームカウントをリセット
		Frame = 0;
	}
	//通常弾
	for (int i = 0; i < NORM_SHOT_NUM; i++) {
		normal[i].Step();
	}
}

//描画
void CBulletMaster::Draw()
{
	//通常弾
	for (int i = 0; i < NORM_SHOT_NUM; i++) {
		normal[i].Draw();
	}
}

//後処理
void CBulletMaster::Fin()
{
	for (int i = 0; i < NORM_SHOT_NUM; i++) {
		normal[i].Fin();
	}
}


void CBulletMaster::RequestNormalShot(const VECTOR& vpos, const float& vspeed) {
	for (int i = 0; i < NORM_SHOT_NUM; i++) {
		if (normal[i].RequestShot(vpos, vspeed)) {
			break;
		}
	}
}