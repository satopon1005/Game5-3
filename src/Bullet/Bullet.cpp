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
}

//描画
void CBulletMaster::Draw()
{

}

//後処理
void CBulletMaster::Fin()
{

}
