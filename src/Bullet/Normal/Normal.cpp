#include "Normal.h"

void NormalShot::Init() {
	memset(&Pos, 0, sizeof(VECTOR));
	memset(&Spd, 0, sizeof(VECTOR));
	handle = LoadGraph("");
	isActive = false;

	count = Time;
}

void NormalShot::Step() {
	if (!isActive)return;

	if (count < 0) {
		count = Time;
	}

	//À•W‚É‘¬“x‚ð‰ÁŽZ
	UpData();
	//ˆê’è”ÍˆÍ‚ð’´‚¦‚½‚çÁ‚·
	if (Pos.x > SCREEN_SIZE_X * 2 || Pos.x < 0
		|| Pos.z > SCREEN_SIZE_Y * 2 || Pos.z < 0
		||count < 0.0f) {
		isActive = false;
	}
}

void NormalShot::Draw() {
	if (isActive) {
		DrawRotaGraph((int)Pos.x, (int)Pos.y, 1.0f, 0.0f, handle, true);
		DrawBox((int)(Pos.x - Screen::m_screen_pos.x), (int)(Pos.y - Screen::m_screen_pos.y), (int)(Pos.x + 12 - Screen::m_screen_pos.x), (int)(Pos.y + 12 - Screen::m_screen_pos.y), GetColor(255, 255, 255), true);
	}
}

void NormalShot::Fin() {
	DeleteGraph(handle);
}

bool NormalShot::RequestShot(const VECTOR& vpos, const float& vspeed) {
	if (isActive)return false;

	Pos = vpos;
	Spd = vspeed;
	isActive = true;

	return true;
}

void NormalShot::UpData() {
	GetMousePoint(&MouseX, &MouseY);

	MousePos.x = (float)MouseX;
	MousePos.y = (float)MouseY;

	count--;

	VECTOR direction = VSub(MousePos, Pos);
	VECTOR vPos = VScale(VNorm(direction), Spd);

	Pos = VAdd(Pos, vPos);
}