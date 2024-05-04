#pragma once
#include "../SceneBace/SceneBace.h"
#include "../../MapChip/MapChip.h"

class SceneEdit :public SceneBace
{
private:
	MapChip mapchip_info;

public:
	void Init();
	void Step();
	void Draw();
};