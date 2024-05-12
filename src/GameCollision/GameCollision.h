#pragma once
#include "../MapChip/MapChip.h"
#include "../Player/Player.h"
#include "../Draw2D/Enemy/EnemyManager.h"
#include "../Draw2D/Bullet/BulletManager.h"
#include "../Draw2D/Item/ItemManager.h"

void CollisionObjectsToWall(MapChip& mapchip_info, VECTOR& pos);

bool CollisionObjectsCircle(VECTOR objects_1, int collision_size1, VECTOR objects_2, int collision_size2);

void CollisionPlayerToEnemy(Player& player_info, EnemyManager& enemy_info);

void CollisionEnemyToBullet(EnemyManager& enemy_info, BulletManager& bullet_info, ItemManager& item_info);

int CollisionItemToPlayer(ItemManager& item_info, VECTOR player_pos);