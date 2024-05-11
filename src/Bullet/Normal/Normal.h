#pragma once

const float Time = 180.0f;

#include "DxLib.h"
#include "../../Common.h"
#include "../../Screen/Screen.h"

#include "../../Input/Input.h"

class NormalShot {
private:
	//�N���X�̐錾
	Input input;

	//�摜�n���h��
	int    handle;
	//�ړ��X�s�[�h
	float  Spd;
	//���W
	VECTOR Pos;

	//�e�������Ă��邩
	bool isActive;

	//�}�E�X�̍��W
	int MouseX, MouseY;
	VECTOR MousePos;

	//���˂���Ă���̎���
	float count;
public:

	void Init();
	void Step();
	void Draw();
	void Fin();

	//�e�𔭎�
	bool RequestShot(const VECTOR& vpos, const float& vspeed);

	//�e�̓����̊֐�
	void UpData();

	//������Ԃ�
	bool IsActive() { return isActive; }
};