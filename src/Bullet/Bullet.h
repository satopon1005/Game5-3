#pragma once
#include "DxLib.h"
#include "../Common.h"
#include "../Frame/Frame.h"
#include "../MyMath/MyMath.h"
#include "SwordSlash/SwordSlash.h"

class CBulletMaster
{
	protected:
		bool isDraw;	//�`��t���O

	private:
		int Frame;		//�t���[���J�E���g

	public:
		//�R���X�g���N�^�E�f�X�g���N�^
		CBulletMaster();
		~CBulletMaster();

		//������
		void Init();
		//���[�h
		void Load();
		//�ʏ폈��
		void Step();
		//�`��
		void Draw();
		//�㏈��
		void Fin();
};
