#pragma once
#include "../MapChip/MapChip.h"

class GameCollision
{
public:
	void PlayerToWall(MapChip& mapchip_info, VECTOR& player_pos);

	void PlayerToEnemy(VECTOR player_pos, VECTOR enemy_pos);
};