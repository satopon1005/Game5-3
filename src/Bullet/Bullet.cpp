#include "Bullet.h"

void Bullet::Init() {
	Bullet:: bulletType = BULLET_TYPE::NOTHING;

	/*bulletPos = { 0.0f,0.0f,0.0f };
	bulletRot = { 0.0f,0.0f,0.0f };
	bulletSpeed = { 0.0f,0.0f,0.0f };

	for (int i = 0; i < BULLET_NUM; i++) {
		handle = LoadGraph(bulletFilePath[i]);
	}

	Time = 0.0f;
	isUse = false;
	isHit = false;*/
}

void Bullet::Step() {
	ScreenOut();
	switch (bulletType) {
	case NOTHING:
		break;
	case RESIDUE:

		break;
	default:
		break;
	}
}

void Bullet::Draw() {

}

void Bullet::Fin() {
	for (int i = 0; i < BULLET_NUM; i++) {
		DeleteGraph(handle);
	}
}


void Bullet::ScreenOut() {
	if (SCREEN_SIZE_X < bulletPos.x) {
		isUse = false;
	}
	if (SCREEN_SIZE_Y < bulletPos.y) {
		isUse = false;
	}
}

int ScopeRand(int min, int max) {
	int rand;

	rand = GetRand(max);

	if (rand <= min) {
		return ScopeRand(min, max);
	}
	else
		return rand;
}