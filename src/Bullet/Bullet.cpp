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

	//�ʏ�e
	for (int i = 0; i < NORM_SHOT_NUM; i++) {
		normal[i].Init();
	}
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
	//�ʏ�e
	for (int i = 0; i < NORM_SHOT_NUM; i++) {
		normal[i].Step();
	}
}

//�`��
void CBulletMaster::Draw()
{
	//�ʏ�e
	for (int i = 0; i < NORM_SHOT_NUM; i++) {
		normal[i].Draw();
	}
}

//�㏈��
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