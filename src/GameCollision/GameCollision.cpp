#include "DxLib.h"
#include "GameCollision.h"
#include "../Collision/Collision.h"
#include "../Player/Player.h"
#include "../Draw2D/Enemy/Enemy.h"

void CollisionObjectsToWall(MapChip& mapchip_info, VECTOR& pos)
{
	for (int y_index = 0; y_index < MAPCHIP_NUM_Y; y_index++) {
		for (int x_index = 0; x_index < MAPCHIP_NUM_X; x_index++) {
			if (mapchip_info.GetMapChipHandleIndex(y_index, x_index) == MapChipType::Floor)
				continue;

			if (Collision::IsHitRect((float)(x_index * MAPCHIP_SIZE),
									(float)(y_index * MAPCHIP_SIZE),
									(float)(MAPCHIP_SIZE),
									(float)(MAPCHIP_SIZE),
									pos.x,
									pos.y,
									(float)PLAYER_SIZE,
									(float)PLAYER_SIZE)) {
				float overlap_x = 0;
				float overlap_y = 0;

				int direction_x = 0;
				int direction_y = 0;

				direction_x = Collision::GetHitDirectionX2D((float)(x_index * MAPCHIP_SIZE),
															MAPCHIP_SIZE,
															pos.x,
															(int)PLAYER_SIZE,
															overlap_x);
				direction_y = Collision::GetHitDirectionX2D((float)(y_index * MAPCHIP_SIZE),
															MAPCHIP_SIZE,
															pos.y,
															(int)PLAYER_SIZE,
															overlap_y);

				//�E�����瓖�������Ƃ�
				if (direction_x == 0 && direction_y == 0) {
					int right_wall_index = mapchip_info.GetMapChipHandleIndex(y_index, x_index + 1);
					int down_wall_index = mapchip_info.GetMapChipHandleIndex(y_index + 1, x_index);

					//���̕ǂ̉E�Ɖ��������ǂ̂Ƃ�
					if (right_wall_index == MapChipType::Wall &&
						down_wall_index == MapChipType::Wall) {
						pos.x += overlap_x;
						pos.y += overlap_y;
					}
					//���̕ǂ̉E���ǂ̂Ƃ�
					else if (right_wall_index == MapChipType::Wall) {
						pos.y += overlap_y;
					}
					//���̕ǂ̉����ǂ̂Ƃ�
					else if (down_wall_index == MapChipType::Wall) {
						pos.x += overlap_x;
					}
					//���̕ǂ̉E�Ɖ������ɕǂ��Ȃ��Ƃ�
					else {
						if (overlap_x > overlap_y)
							pos.y += overlap_y;
						else
							pos.x += overlap_x;
					}
				}
				//�������瓖�������Ƃ�
				if (direction_x == 1 && direction_y == 0) {
					int left_wall_index = mapchip_info.GetMapChipHandleIndex(y_index, x_index - 1);
					int down_wall_index = mapchip_info.GetMapChipHandleIndex(y_index + 1, x_index);

					//���̕ǂ̍��Ɖ��������ǂ̂Ƃ�
					if (left_wall_index == MapChipType::Wall &&
						down_wall_index == MapChipType::Wall) {
						pos.x -= overlap_x;
						pos.y += overlap_y;
					}
					//���̕ǂ̍����ǂ̂Ƃ�
					else if (left_wall_index == MapChipType::Wall) {
						pos.y += overlap_y;
					}
					//���̕ǂ̉����ǂ̂Ƃ�
					else if (down_wall_index == MapChipType::Wall) {
						pos.x -= overlap_x;
					}
					//���̕ǂ̍��Ɖ������ɕǂ��Ȃ��Ƃ�
					else {
						if (overlap_x > overlap_y)
							pos.y += overlap_y;
						else
							pos.x -= overlap_x;
					}
				}
				//���ォ�瓖�������Ƃ�
				if (direction_x == 1 && direction_y == 1) {
					int left_wall_index = mapchip_info.GetMapChipHandleIndex(y_index, x_index - 1);
					int up_wall_index = mapchip_info.GetMapChipHandleIndex(y_index - 1, x_index);

					//���̕ǂ̍��Ə㗼�����ǂ̂Ƃ�
					if (left_wall_index == MapChipType::Wall &&
						up_wall_index == MapChipType::Wall) {
						pos.x -= overlap_x;
						pos.y -= overlap_y;
					}
					//���̕ǂ̍����ǂ̂Ƃ�
					else if (left_wall_index == MapChipType::Wall) {
						pos.y -= overlap_y;
					}
					//���̕ǂ̏オ�ǂ̂Ƃ�
					else if (up_wall_index == MapChipType::Wall) {
						pos.x -= overlap_x;
					}
					//���̕ǂ̉E�Ə㗼���ɕǂ��Ȃ��Ƃ�
					else {
						if (overlap_x > overlap_y)
							pos.y -= overlap_y;
						else
							pos.x -= overlap_x;
					}
				}
				//�E�ォ�瓖�������Ƃ�
				if (direction_x == 0 && direction_y == 1) {
					int right_wall_index = mapchip_info.GetMapChipHandleIndex(y_index, x_index + 1);
					int up_wall_index = mapchip_info.GetMapChipHandleIndex(y_index - 1, x_index);

					//���̕ǂ̉E�Ə㗼�����ǂ̂Ƃ�
					if (right_wall_index == MapChipType::Wall &&
						up_wall_index == MapChipType::Wall) {
						pos.x += overlap_x;
						pos.y -= overlap_y;
					}
					//���̕ǂ̉E���ǂ̂Ƃ�
					else if (right_wall_index == MapChipType::Wall) {
						pos.y -= overlap_y;
					}
					//���̕ǂ̏オ�ǂ̂Ƃ�
					else if (up_wall_index == MapChipType::Wall) {
						pos.x += overlap_x;
					}
					//���̕ǂ̉E�Ə㗼���ɕǂ��Ȃ��Ƃ�
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
	if (Collision::IsHitCircle((player_pos.x + (float)PLAYER_SIZE / 2),
		(player_pos.y + (float)PLAYER_SIZE / 2),
		((float)PLAYER_SIZE / 2),
		(enemy_pos.x + (float)ENEMY_COLLISION_SIZE / 2),
		(enemy_pos.y + (float)ENEMY_COLLISION_SIZE / 2),
		((float)ENEMY_COLLISION_SIZE / 2)))
	{
		return true;
	}

	return false;
}