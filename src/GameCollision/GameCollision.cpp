#include "DxLib.h"
#include "GameCollision.h"
#include "../Collision/Collision.h"
#include "../Player/Player.h"

void GameCollision::PlayerToWall(MapChip& mapchip_info, VECTOR& player_pos)
{
	for (int y_index = 0; y_index < MAPCHIP_NUM_Y; y_index++) {
		for (int x_index = 0; x_index < MAPCHIP_NUM_X; x_index++) {
			if (Collision::IsHitRect(x_index * MAPCHIP_SIZE,
									y_index * MAPCHIP_SIZE,
									(x_index + 1) * MAPCHIP_SIZE,
									(y_index + 1) * MAPCHIP_SIZE,
									player_pos.x,
									player_pos.y,
									PLAYER_SIZE,
									PLAYER_SIZE)) {
				float overlap_x = 0;
				float overlap_y = 0;

				int direction_x = 0;
				int direction_y = 0;

				direction_x = Collision::GetHitDirectionX2D(x_index * MAPCHIP_SIZE, MAPCHIP_SIZE, player_pos.x, (int)PLAYER_SIZE, overlap_x);
				direction_y = Collision::GetHitDirectionX2D(y_index * MAPCHIP_SIZE, MAPCHIP_SIZE, player_pos.y, (int)PLAYER_SIZE, overlap_y);

				//右下から当たったとき
				if (direction_x == 0, direction_y == 0) {
					int right_wall_index = mapchip_info.GetMapChipHandleIndex(y_index, x_index + 1);
					int down_wall_index = mapchip_info.GetMapChipHandleIndex(y_index + 1, x_index);

					//その壁の右と下両方が壁のとき
					if (right_wall_index == MapChipContent::Wall &&
						down_wall_index == MapChipContent::Wall) {
						player_pos.x += overlap_x;
						player_pos.y += overlap_y;
					}
					//その壁の右が壁のとき
					else if (right_wall_index == MapChipContent::Wall) {
						player_pos.y += overlap_y;
					}
					//その壁の下が壁のとき
					else if (down_wall_index == MapChipContent::Wall) {
						player_pos.x += overlap_x;
					}
					//その壁の右と下両方に壁がないとき
					else {
						player_pos.y += overlap_y;
					}
				}
				//左下から当たったとき
				if (direction_x == 1, direction_y == 0) {
					int left_wall_index = mapchip_info.GetMapChipHandleIndex(y_index, x_index - 1);
					int down_wall_index = mapchip_info.GetMapChipHandleIndex(y_index + 1, x_index);

					//その壁の左と下両方が壁のとき
					if (left_wall_index == MapChipContent::Wall &&
						down_wall_index == MapChipContent::Wall) {
						player_pos.x -= overlap_x;
						player_pos.y += overlap_y;
					}
					//その壁の左が壁のとき
					else if (left_wall_index == MapChipContent::Wall) {
						player_pos.y += overlap_y;
					}
					//その壁の下が壁のとき
					else if (down_wall_index == MapChipContent::Wall) {
						player_pos.x -= overlap_x;
					}
					//その壁の左と下両方に壁がないとき
					else {
						player_pos.y += overlap_y;
					}
				}
				//左上から当たったとき
				if (direction_x == 1, direction_y == 1) {
					int left_wall_index = mapchip_info.GetMapChipHandleIndex(y_index, x_index - 1);
					int up_wall_index = mapchip_info.GetMapChipHandleIndex(y_index - 1, x_index);

					//その壁の左と上両方が壁のとき
					if (left_wall_index == MapChipContent::Wall &&
						up_wall_index == MapChipContent::Wall) {
						player_pos.x -= overlap_x;
						player_pos.y -= overlap_y;
					}
					//その壁の左が壁のとき
					else if (left_wall_index == MapChipContent::Wall) {
						player_pos.y -= overlap_y;
					}
					//その壁の上が壁のとき
					else if (up_wall_index == MapChipContent::Wall) {
						player_pos.x -= overlap_x;
					}
					//その壁の右と上両方に壁がないとき
					else {
						player_pos.y -= overlap_y;
					}
				}
				//右上から当たったとき
				if (direction_x == 0, direction_y == 1) {
					int right_wall_index = mapchip_info.GetMapChipHandleIndex(y_index, x_index + 1);
					int up_wall_index = mapchip_info.GetMapChipHandleIndex(y_index - 1, x_index);

					//その壁の右と上両方が壁のとき
					if (right_wall_index == MapChipContent::Wall &&
						up_wall_index == MapChipContent::Wall) {
						player_pos.x += overlap_x;
						player_pos.y -= overlap_y;
					}
					//その壁の右が壁のとき
					else if (right_wall_index == MapChipContent::Wall) {
						player_pos.y -= overlap_y;
					}
					//その壁の上が壁のとき
					else if (up_wall_index == MapChipContent::Wall) {
						player_pos.x += overlap_x;
					}
					//その壁の右と上両方に壁がないとき
					else {
						player_pos.y -= overlap_y;
					}
				}
			}
		}
	}
}

