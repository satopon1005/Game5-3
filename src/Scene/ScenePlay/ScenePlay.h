#pragma once
#include "../SceneBace/SceneBace.h"
#include "../../MapChip/MapChip.h"

class ScenePlay :public SceneBace
{
private:
	MapChip mapchip_info;

public:
	void Init();
	void Step();
	void Draw();
	void Fin();
};