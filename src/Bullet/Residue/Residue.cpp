#include "Residue.h"

void Residue::Init() {
	handle = LoadGraph(bulletFilePath[RESIDUE]);

	bulletPos = { 0.0f,0.0f,0.0f };
	bulletRot = { 0.0f,0.0f,0.0f };
	bulletSpeed = { 0.0f,0.0f,0.0f };

	handle = LoadGraph(bulletFilePath[RESIDUE]);

	Time = 0.0f;
	isUse = false;
	isHit = false;
}

void Residue::Step() {

}

void Residue::Draw() {
	DrawRotaGraph(bulletPos.x, bulletPos.y, 1.0f, bulletRot.y, handle, true);
}

void Residue::Fin() {
	DeleteGraph(handle);
}