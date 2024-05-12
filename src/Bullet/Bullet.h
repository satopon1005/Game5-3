#pragma once
#include "DxLib.h"
#include "../Common.h"
#include "../Frame/Frame.h"
#include "../MyMath/MyMath.h"
#include "SwordSlash/SwordSlash.h"
#include "Normal/Normal.h"

const int NORM_SHOT_NUM = 100;

class CBulletMaster
{
	protected:
		bool isDraw;	//描画フラグ

	private:
		int Frame;		//フレームカウント

		//通常の弾のクラス
		NormalShot normal[NORM_SHOT_NUM];

	public:
		//コンストラクタ・デストラクタ
		CBulletMaster();
		~CBulletMaster();

		//初期化
		void Init();
		//ロード
		void Load();
		//通常処理
		void Step();
		//描画
		void Draw();
		//後処理
		void Fin();

		//弾の要求
		void RequestNormalShot(const VECTOR& vpos, const float& vspeed);
};
