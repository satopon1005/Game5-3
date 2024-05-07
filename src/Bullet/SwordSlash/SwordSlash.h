#pragma once

class CSwordSlash
{
	private:
		int Handle;			//画像ハンドル
		float PosX, PosY;	//座標

	public:
		//コンストラクタ・デストラクタ
		CSwordSlash();
		~CSwordSlash();

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