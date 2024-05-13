#pragma once
#include "../SceneBace/SceneBace.h"
#include "../../MapChip/MapChip.h"
#include "../../Player/Player.h"
#include "../../Draw2D/Enemy/EnemyManager.h"
#include "../../Draw2D/Item/ItemManager.h"
#include "../../Draw2D/Bullet/BulletManager.h"
#include "../../UI/UI.h"
#include "../../CountTime/CountTime.h"

constexpr int PLAY_TIME[2]{ 2,30 };

class ScenePlay :public SceneBace
{
private:
	MapChip mapchip_info;
	Player player_info;
	EnemyManager enemy_info;
	ItemManager item_info;

	CountTime count_time_info;

	UI_Info ui_info;

	BulletManager bullet_info;

public:
	void Init();
	void Step();
	void Draw();
	void Fin();
};