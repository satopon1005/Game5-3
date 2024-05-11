#pragma once
#include "../SceneBace/SceneBace.h"
#include "../../MapChip/MapChip.h"
#include "../../Player/Player.h"
#include "../../Draw2D/Enemy/EnemyManagerh.h"
#include "../../Bullet/Bullet.h"

class ScenePlay :public SceneBace
{
private:
	MapChip mapchip_info;
	Player player_info;
	EnemyManager enemy_info;

	CBulletMaster normal;

public:
	void Init();
	void Step();
	void Draw();
	void Fin();
};