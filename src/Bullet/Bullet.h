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
		bool isDraw;	//�`��t���O

	private:
		int Frame;		//�t���[���J�E���g

		//�ʏ�̒e�̃N���X
		NormalShot normal[NORM_SHOT_NUM];

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

		//�e�̗v��
		void RequestNormalShot(const VECTOR& vpos, const float& vspeed);
};
