#include "Bullet.h"

//�R���X�g���N�^
CBulletMaster::CBulletMaster()
{
	Frame = 0;
}

//�f�X�g���N�^
CBulletMaster::~CBulletMaster()
{

}

//������
void CBulletMaster::Init()
{
	//�t���[����������
	Frame = 0;
}

//���[�h
void CBulletMaster::Load()
{

}

//�ʏ폈��
void CBulletMaster::Step()
{
	//�t���[�����J�E���g
	Frame++;
	if (Frame >= FRAME_RATE)
	{
		//�t���[���J�E���g�����Z�b�g
		Frame = 0;
	}
}

//�`��
void CBulletMaster::Draw()
{

}

//�㏈��
void CBulletMaster::Fin()
{

}
