#pragma once

class CSwordSlash
{
	private:
		int Handle;			//�摜�n���h��
		float PosX, PosY;	//���W

	public:
		//�R���X�g���N�^�E�f�X�g���N�^
		CSwordSlash();
		~CSwordSlash();

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