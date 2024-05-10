#include "DxLib.h"
#include "GameCollision.h"
#include "../Collision/Collision.h"
#include "../Player/Player.h"
#include "../Draw2D/Enemy/Enemy.h"

bool ChackWallIndex(int wall_index) {
	if (wall_index < MapChipType::WallMaxNum ||
		wall_index == MapChipType::Tsuta)
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

bool CollisionPlayerToEnemy(VECTOR player_pos, VECTOR enemy_pos)
{
	if (Collision::IsHitCircle((player_pos.x + (float)PLAYER_SIZE_R),
		(player_pos.y + (float)PLAYER_SIZE_R),
		((float)PLAYER_SIZE_R),
		(enemy_pos.x + (float)ENEMY_COLLISION_SIZE_R),
		(enemy_pos.y + (float)ENEMY_COLLISION_SIZE_R),
		((float)ENEMY_COLLISION_SIZE_R)))
	{
		return true;
	}

	return false;
}