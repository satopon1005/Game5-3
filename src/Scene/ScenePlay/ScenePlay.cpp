#include "DxLib.h"
#include "ScenePlay.h"
#include "../../Common.h"
#include "../../Input/Input.h"
#include "../../Screen/Screen.h"
#include "../../GameCollision/GameCollision.h"

void ScenePlay::Init()
{
	mapchip_info.Init(MapChip::m_mapchip_index);
	player_info.Init();
	enemy_info.Init();
	item_info.Init();

	bullet_info.Init();

	ui_info.Init();

	Screen::Init();
}
void ScenePlay::Step()
{
	if (Input::IsKeyPush(KEY_INPUT_RETURN)) {
		SceneBace::g_scene_ID = Title_Scene;
	}
	player_info.Step();

	bullet_info.Step();
	bullet_info.SpawnBullet(player_info.GetPos());

	CollisionObjectsToWall(mapchip_info, player_info.GetPos());

	Screen::Step(VGet(player_info.GetPosX(), player_info.GetPosY(), 0.0f));

	enemy_info.Step(player_info.GetPos());
	enemy_info.Spawn();

	item_info.Step(player_info.GetPos());

	CollisionPlayerToEnemy(player_info, enemy_info);
	CollisionEnemyToBullet(enemy_info, bullet_info, item_info);

	int item_type = CollisionItemToPlayer(item_info, bullet_info, player_info.GetPos());
	if (item_type != -1) {
		player_info.IsGetItem(item_type);
	}
}
void ScenePlay::Draw()
{
	mapchip_info.Draw();

	bullet_info.Draw();

	player_info.Draw();
	enemy_info.Draw();

	item_info.Draw();


	ui_info.Draw(player_info.GetHP(), player_info.GetKeikenchi(), player_info.GetLevel());
}
void ScenePlay::Fin()
{
	enemy_info.Fin();
	bullet_info.Fin();
}