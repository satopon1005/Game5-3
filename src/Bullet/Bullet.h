#pragma once
#include "DxLib.h"
#include "../Common.h"
#include "../Frame/Frame.h"
#include "../MyMath/MyMath.h"
#include "SwordSlash/SwordSlash.h"

class CBulletMaster
{
	protected:
		bool isDraw;	//描画フラグ

	private:
		int Frame;		//フレームカウント

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
};
