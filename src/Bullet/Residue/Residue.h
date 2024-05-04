#pragma once
#include "../Bullet.h"

class Residue :public Bullet {
private:

public:
	void Init();
	void Step();
	void Draw();
	void Fin();
};