#pragma once
#include "../SceneBace/SceneBace.h"

class SceneTitle :public SceneBace
{
private:
	int ImageHandle[3];	//�摜�n���h��
	float PosX[2];		//����X���W
	float PosY[2];		//����Y���W
	bool m_isTurn;		//���]�t���O

public:
	void Init();
	void Step();
	void Draw();
	void Fin();
};