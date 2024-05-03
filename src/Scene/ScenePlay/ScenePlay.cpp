#include "DxLib.h"
#include "ScenePlay.h"
#include "../../Common.h"
#include "../../Input/Input.h"

void ScenePlay::Init()
{
	mapchip_info.Init(0);
}
void ScenePlay::Step()
{
	if (Input::IsKeyPush(KEY_INPUT_RETURN)) {
		SceneBace::g_scene_ID = Title_Scene;
	}
}
void ScenePlay::Draw()
{
	mapchip_info.Draw();
	DrawFormatString(0, 0, GetColor(255, 255, 255), "ƒvƒŒƒC");
}