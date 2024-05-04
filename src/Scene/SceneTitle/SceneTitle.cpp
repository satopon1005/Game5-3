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
		SceneBace::g_scene_ID = Edit_Scene;
	}
	if (Input::IsKeyDown(KEY_INPUT_RETURN) && Input::IsKeyDown(KEY_INPUT_LSHIFT)) {
		SceneBace::g_scene_ID = Select_Scene;
	}
}
void SceneTitle::Draw()
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "ƒ^ƒCƒgƒ‹");
}