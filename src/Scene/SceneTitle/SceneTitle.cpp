#include "DxLib.h"
#include "SceneTitle.h"
#include "../../Common.h"
#include "../../Input/Input.h"

void SceneTitle::Init()
{

}
void SceneTitle::Step()
{
	if (Input::IsKeyPush(KEY_INPUT_RETURN)) {
		SceneBace::g_scene_ID = Play_Scene;
	}
}
void SceneTitle::Draw()
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "ƒ^ƒCƒgƒ‹");
}