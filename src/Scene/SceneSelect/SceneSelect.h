#pragma once
#include "../SceneBace/SceneBace.h"
#include "../../MapChip/MapChip.h"

constexpr int SELECT_IMAGE_SIZE = 200;
constexpr char SELECT_BG_HANDLE_PATH[] = { "data/Select/stageselection.png" };

class SceneSelect :public SceneBace
{
private:
	int m_bg_handle;

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