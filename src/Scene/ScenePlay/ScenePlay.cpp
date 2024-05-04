#include "DxLib.h"
#include "ScenePlay.h"
#include "../../Common.h"
#include "../../Input/Input.h"
#include "../../Screen/Screen.h"

void ScenePlay::Init()
{
	mapchip_info.Init(MapChip::m_mapchip_index);
	Screen::Init();
}
void ScenePlay::Step()
{
	if (Input::IsKeyPush(KEY_INPUT_RETURN)) {
		SceneBace::g_scene_ID = Title_Scene;
	}
	Screen::Step();
}
void ScenePlay::Draw()
{
	mapchip_info.Draw();
	DrawFormatString(0, 0, GetColor(255, 255, 255), "ƒvƒŒƒC");
}