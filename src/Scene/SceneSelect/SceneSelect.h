#pragma once
#include "../SceneBace/SceneBace.h"
#include "../../MapChip/MapChip.h"

constexpr int SELECT_IMAGE_SIZE = 200;

class SceneSelect :public SceneBace
{
private:
	MapChip mapchip_info;
	int m_select_num;

	VECTOR m_select_pos[5];
	int m_select_size[5];

	VECTOR m_arrow_pos[2];

public:
	void Init();
	void Step();
	void Draw();
	void Fin();
};