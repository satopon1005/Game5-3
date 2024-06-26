#include "DxLib.h"
#include "GameCollision.h"
#include "../Collision/Collision.h"
#include "../Sound/Sound.h"

bool ChackWallIndex(int wall_index) {
	if (wall_index < MapChipType::WallMaxNum ||
		wall_index == MapChipType::Tsuta ||
		wall_index == MapChipType::Stump)
		return true;
	return false;
}

void CollisionObjectsToWall(MapChip& mapchip_info, VECTOR& pos)
{
	for (int y_index = 0; y_index < MAPCHIP_NUM_Y; y_index++) {
		for (int x_index = 0; x_index < MAPCHIP_NUM_X; x_index++) {
			if (mapchip_info.GetMapChipHandleIndex(y_index, x_index) == MapChipType::Floor1 ||
				mapchip_info.GetMapChipHandleIndex(y_index, x_index) == MapChipType::Floor2)
				continue;

			if (Collision::IsHitRect((float)(x_index * MAPCHIP_SIZE),
									(float)(y_index * MAPCHIP_SIZE),
									(float)(MAPCHIP_SIZE),
									(float)(MAPCHIP_SIZE),
									pos.x - PLAYER_SIZE_R,
									pos.y - PLAYER_SIZE_R,
									(float)PLAYER_SIZE_R * 2,
									(float)PLAYER_SIZE_R * 2)) {
				float overlap_x = 0;
				float overlap_y = 0;

				int direction_x = 0;
				int direction_y = 0;

				direction_x = Collision::GetHitDirectionX2D((float)(x_index * MAPCHIP_SIZE),
															MAPCHIP_SIZE,
															pos.x - PLAYER_SIZE_R,
															(int)PLAYER_SIZE_R * 2,
															overlap_x);
				direction_y = Collision::GetHitDirectionX2D((float)(y_index * MAPCHIP_SIZE),
															MAPCHIP_SIZE,
															pos.y - PLAYER_SIZE_R,
															(int)PLAYER_SIZE_R * 2,
															overlap_y);

				//右下から当たったとき
				if (direction_x == 0 && direction_y == 0) {
					int right_wall_index = mapchip_info.GetMapChipHandleIndex(y_index, x_index + 1);
					int down_wall_index = mapchip_info.GetMapChipHandleIndex(y_index + 1, x_index);

					//その壁の右と下両方が壁のとき
					if (ChackWallIndex(right_wall_index) &&
						ChackWallIndex(down_wall_index)) {
						pos.x += overlap_x;
						pos.y += overlap_y;
					}
					//その壁の右が壁のとき
					else if (ChackWallIndex(right_wall_index)) {
						pos.y += overlap_y;
					}
					//その壁の下が壁のとき
					else if (ChackWallIndex(down_wall_index)) {
						pos.x += overlap_x;
					}
					//その壁の右と下両方に壁がないとき
					else {
						if (overlap_x > overlap_y)
							pos.y += overlap_y;
						else
							pos.x += overlap_x;
					}
				}
				//左下から当たったとき
				if (direction_x == 1 && direction_y == 0) {
					int left_wall_index = mapchip_info.GetMapChipHandleIndex(y_index, x_index - 1);
					int down_wall_index = mapchip_info.GetMapChipHandleIndex(y_index + 1, x_index);

					//その壁の左と下両方が壁のとき
					if (ChackWallIndex(left_wall_index) &&
						ChackWallIndex(down_wall_index)) {
						pos.x -= overlap_x;
						pos.y += overlap_y;
					}
					//その壁の左が壁のとき
					else if (ChackWallIndex(left_wall_index)) {
						pos.y += overlap_y;
					}
					//その壁の下が壁のとき
					else if (ChackWallIndex(down_wall_index)) {
						pos.x -= overlap_x;
					}
					//その壁の左と下両方に壁がないとき
					else {
						if (overlap_x > overlap_y)
							pos.y += overlap_y;
						else
							pos.x -= overlap_x;
					}
				}
				//左上から当たったとき
				if (direction_x == 1 && direction_y == 1) {
					int left_wall_index = mapchip_info.GetMapChipHandleIndex(y_index, x_index - 1);
					int up_wall_index = mapchip_info.GetMapChipHandleIndex(y_index - 1, x_index);

					//その壁の左と上両方が壁のとき
					if (ChackWallIndex(left_wall_index) &&
						ChackWallIndex(up_wall_index)) {
						pos.x -= overlap_x;
						pos.y -= overlap_y;
					}
					//その壁の左が壁のとき
					else if (ChackWallIndex(left_wall_index)) {
						pos.y -= overlap_y;
					}
					//その壁の上が壁のとき
					else if (ChackWallIndex(up_wall_index)) {
						pos.x -= overlap_x;
					}
					//その壁の右と上両方に壁がないとき
					else {
						if (overlap_x > overlap_y)
							pos.y -= overlap_y;
						else
							pos.x -= overlap_x;
					}
				}
				//右上から当たったとき
				if (direction_x == 0 && direction_y == 1) {
					int right_wall_index = mapchip_info.GetMapChipHandleIndex(y_index, x_index + 1);
					int up_wall_index = mapchip_info.GetMapChipHandleIndex(y_index - 1, x_index);

					//その壁の右と上両方が壁のとき
					if (ChackWallIndex(right_wall_index) &&
						ChackWallIndex(up_wall_index)) {
						pos.x += overlap_x;
						pos.y -= overlap_y;
					}
					//その壁の右が壁のとき
					else if (ChackWallIndex(right_wall_index)) {
						pos.y -= overlap_y;
					}
					//その壁の上が壁のとき
					else if (ChackWallIndex(up_wall_index)) {
						pos.x += overlap_x;
					}
					//その壁の右と上両方に壁がないとき
					else {
						if (overlap_x > overlap_y)
							pos.y -= overlap_y;
						else
							pos.x += overlap_x;
					}
				}
			}
		}
	}
}

bool CollisionObjectsCircle(VECTOR objects_1, int collision_size1, VECTOR objects_2, int collision_size2)
{
	if (Collision::IsHitCircle((objects_1.x),
		(objects_1.y),
		((float)collision_size1),
		(objects_2.x),
		(objects_2.y),
		((float)collision_size2)))
	{
		return true;
	}

	return false;
}

void CollisionPlayerToEnemy(Player& player_info, EnemyManager& enemy_info)
{
	for (int enemy_index = 0; enemy_index < ENEMY_NUM; enemy_index++) {
		if (!enemy_info.GetEnemyInfo(enemy_index).GetIsUse()) continue;

		if (CollisionObjectsCircle(player_info.GetPos(),
									PLAYER_SIZE_R,
									enemy_info.GetEnemyInfo(enemy_index).GetPos(),
									ENEMY_COLLISION_SIZE_R))
		{
			player_info.IsDamage(ENEMY_ATTACK_POWER[enemy_info.GetEnemyInfo(enemy_index).GetEnemyType()]);
		}
	}
}

void CollisionEnemyToBullet(EnemyManager& enemy_info, BulletManager& bullet_info, ItemManager& item_info)
{
	for (int enemy_index = 0; enemy_index < ENEMY_NUM; enemy_index++) {
		if (!enemy_info.GetEnemyInfo(enemy_index).GetIsUse()) continue;

		for (int bullet_index = 0; bullet_index < BULLET_MAX_NUM; bullet_index++) {
			if (!bullet_info.GetBulletInfo(bullet_index).GetIsUse()) continue;
			if (bullet_info.GetBulletInfo(bullet_index).GetBulletType() == BulletType::Holywater) continue;

			if(CollisionObjectsCircle(enemy_info.GetEnemyInfo(enemy_index).GetPos(),
									ENEMY_COLLISION_SIZE_R,
									bullet_info.GetBulletInfo(bullet_index).GetPos(),
									BULLET_COLLISION_SIZE_R[bullet_info.GetBulletInfo(bullet_index).GetBulletType()]))
			{
				enemy_info.GetEnemyInfo(enemy_index).IsDamage(BULLET_DAMAGE_NUM[bullet_info.GetBulletInfo(bullet_index).GetBulletType()]);

				bullet_info.GetBulletInfo(bullet_index).SetHitCount(bullet_info.GetBulletInfo(bullet_index).GetHitCount() + 1);

				if (bullet_info.GetBulletInfo(bullet_index).GetBulletType() != BulletType::fireball ||
					bullet_info.GetBulletInfo(bullet_index).GetHitCount() >= 3)
					bullet_info.GetBulletInfo(bullet_index).SetIsUse(false);

				if (!enemy_info.GetEnemyInfo(enemy_index).GetIsUse()) {
					int spawn_item_index = GetRand(BulletTypeMaxNum * 3);

					if (spawn_item_index > BulletTypeMaxNum + 1) {
						if (GetRand(3) == 0)
							spawn_item_index = BulletTypeMaxNum + 1;
						else
							spawn_item_index = BulletTypeMaxNum;
					}

					item_info.Spawn(enemy_info.GetEnemyInfo(enemy_index).GetPos(), spawn_item_index);
					Sound::PlaySE(SEtype::Enemy_Death_SE);
				}
			}
		}
	}
}

int CollisionItemToPlayer(ItemManager& item_info, BulletManager& bullet_info, VECTOR player_pos)
{
	for (int item_index = 0; item_index < ITEM_MAX_NUM; item_index++) {
		if (!item_info.GetItemInfo(item_index).GetIsUse()) continue;

		if (CollisionObjectsCircle(player_pos,
			PLAYER_SIZE_R,
			item_info.GetItemInfo(item_index).GetPos(),
			ITEM_SIZE[item_info.GetItemInfo(item_index).GetItemType()]))
		{
			item_info.GetItemInfo(item_index).SetIsUse(false);

			int index = item_info.GetItemInfo(item_index).GetItemType();

			bullet_info.SetUsableFlag(index, true);

			return index;
		}
	}
	return -1;
}