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

	//normal.Init();

	Screen::Init();
}
void ScenePlay::Step()
{
	if (Input::IsKeyPush(KEY_INPUT_RETURN)) {
		SceneBace::g_scene_ID = Title_Scene;
	}
	player_info.Step();

	bullet_info.Step();
	bullet_info.Spawn(player_info.GetPos());

	CollisionObjectsToWall(mapchip_info, player_info.GetPos());

	Screen::Step(VGet(player_info.GetPosX(), player_info.GetPosY(), 0.0f));

	enemy_info.Step(player_info.GetPos());
	enemy_info.Spawn();

	item_info.Step(player_info.GetPos());

	CollisionEnemyToBullet(enemy_info, bullet_info, item_info);
	if (int item_type = CollisionItemToPlayer(item_info, player_info.GetPos()) != -1) {
		player_info.IsGetItem(item_type);
	}

	//normal.Step();
}
void ScenePlay::Draw()
{
	mapchip_info.Draw();

	bullet_info.Draw();

	player_info.Draw();
	enemy_info.Draw();

	item_info.Draw();

	//normal.Draw();

	DrawFormatString(0, 0, GetColor(255, 255, 255), "ƒvƒŒƒC");
}
void ScenePlay::Fin()
{
	enemy_info.Fin();
	bullet_info.Fin();
	//normal.Fin();
}