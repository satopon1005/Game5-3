#pragma once
#include "../MapChip/MapChip.h"

void CollisionObjectsToWall(MapChip& mapchip_info, VECTOR& pos);

bool CollisionPlayerToEnemy(VECTOR player_pos, VECTOR enemy_pos);