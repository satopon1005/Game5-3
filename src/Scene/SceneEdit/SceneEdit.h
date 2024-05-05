#pragma once
#include "../SceneBace/SceneBace.h"
#include "../../MapChip/MapChip.h"

class SceneEdit :public SceneBace
{
private:
	MapChip mapchip_info;
	bool m_edit_mapchip_flag;
	bool m_save_mapchip_flag;

public:
	void Init();
	void Step();
	void Draw();
	void Fin();
};