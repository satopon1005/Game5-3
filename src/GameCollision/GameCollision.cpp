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

				//�E�����瓖�������Ƃ�
				if (direction_x == 0, direction_y == 0) {
					int right_wall_index = mapchip_info.GetMapChipHandleIndex(y_index, x_index + 1);
					int down_wall_index = mapchip_info.GetMapChipHandleIndex(y_index + 1, x_index);

					//���̕ǂ̉E�Ɖ��������ǂ̂Ƃ�
					if (right_wall_index == MapChipContent::Wall &&
						down_wall_index == MapChipContent::Wall) {
						player_pos.x += overlap_x;
						player_pos.y += overlap_y;
					}
					//���̕ǂ̉E���ǂ̂Ƃ�
					else if (right_wall_index == MapChipContent::Wall) {
						player_pos.y += overlap_y;
					}
					//���̕ǂ̉����ǂ̂Ƃ�
					else if (down_wall_index == MapChipContent::Wall) {
						player_pos.x += overlap_x;
					}
					//���̕ǂ̉E�Ɖ������ɕǂ��Ȃ��Ƃ�
					else {
						player_pos.y += overlap_y;
					}
				}
				//�������瓖�������Ƃ�
				if (direction_x == 1, direction_y == 0) {
					int left_wall_index = mapchip_info.GetMapChipHandleIndex(y_index, x_index - 1);
					int down_wall_index = mapchip_info.GetMapChipHandleIndex(y_index + 1, x_index);

					//���̕ǂ̍��Ɖ��������ǂ̂Ƃ�
					if (left_wall_index == MapChipContent::Wall &&
						down_wall_index == MapChipContent::Wall) {
						player_pos.x -= overlap_x;
						player_pos.y += overlap_y;
					}
					//���̕ǂ̍����ǂ̂Ƃ�
					else if (left_wall_index == MapChipContent::Wall) {
						player_pos.y += overlap_y;
					}
					//���̕ǂ̉����ǂ̂Ƃ�
					else if (down_wall_index == MapChipContent::Wall) {
						player_pos.x -= overlap_x;
					}
					//���̕ǂ̍��Ɖ������ɕǂ��Ȃ��Ƃ�
					else {
						player_pos.y += overlap_y;
					}
				}
				//���ォ�瓖�������Ƃ�
				if (direction_x == 1, direction_y == 1) {
					int left_wall_index = mapchip_info.GetMapChipHandleIndex(y_index, x_index - 1);
					int up_wall_index = mapchip_info.GetMapChipHandleIndex(y_index - 1, x_index);

					//���̕ǂ̍��Ə㗼�����ǂ̂Ƃ�
					if (left_wall_index == MapChipContent::Wall &&
						up_wall_index == MapChipContent::Wall) {
						player_pos.x -= overlap_x;
						player_pos.y -= overlap_y;
					}
					//���̕ǂ̍����ǂ̂Ƃ�
					else if (left_wall_index == MapChipContent::Wall) {
						player_pos.y -= overlap_y;
					}
					//���̕ǂ̏オ�ǂ̂Ƃ�
					else if (up_wall_index == MapChipContent::Wall) {
						player_pos.x -= overlap_x;
					}
					//���̕ǂ̉E�Ə㗼���ɕǂ��Ȃ��Ƃ�
					else {
						player_pos.y -= overlap_y;
					}
				}
				//�E�ォ�瓖�������Ƃ�
				if (direction_x == 0, direction_y == 1) {
					int right_wall_index = mapchip_info.GetMapChipHandleIndex(y_index, x_index + 1);
					int up_wall_index = mapchip_info.GetMapChipHandleIndex(y_index - 1, x_index);

					//���̕ǂ̉E�Ə㗼�����ǂ̂Ƃ�
					if (right_wall_index == MapChipContent::Wall &&
						up_wall_index == MapChipContent::Wall) {
						player_pos.x += overlap_x;
						player_pos.y -= overlap_y;
					}
					//���̕ǂ̉E���ǂ̂Ƃ�
					else if (right_wall_index == MapChipContent::Wall) {
						player_pos.y -= overlap_y;
					}
					//���̕ǂ̏オ�ǂ̂Ƃ�
					else if (up_wall_index == MapChipContent::Wall) {
						player_pos.x += overlap_x;
					}
					//���̕ǂ̉E�Ə㗼���ɕǂ��Ȃ��Ƃ�
					else {
						player_pos.y -= overlap_y;
					}
				}
			}
		}
	}
}

