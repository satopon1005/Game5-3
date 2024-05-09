#pragma once
#include "../MapChip/MapChip.h"

void CollisionPlayerToWall(MapChip& mapchip_info, VECTOR& player_pos);

void CollisionPlayerToEnemy(VECTOR player_pos, VECTOR enemy_pos);