#pragma once
#include "../SceneBace/SceneBace.h"
#include "../../MapChip/MapChip.h"

class SceneSelect :public SceneBace
{
private:
	MapChip mapchip_info;
	int m_select_num;

public:
	void Init();
	void Step();
	void Draw();
};