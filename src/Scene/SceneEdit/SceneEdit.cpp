#include "DxLib.h"
#include "SceneEdit.h"
#include "../../Common.h"
#include "../../Input/Input.h"
#include "../../Screen/Screen.h"

void SceneEdit::Init()
{
	mapchip_info.InitEdit();
	Screen::Init();
}
void SceneEdit::Step()
{
	if (Input::IsKeyPush(KEY_INPUT_RETURN)) {
		SceneBace::g_scene_ID = Title_Scene;
	}
	Screen::StepEdit();
	mapchip_info.StepEdit();
}
void SceneEdit::Draw()
{
	mapchip_info.DrawEdit();
	DrawFormatString(0, 0, GetColor(255, 255, 255), "エディット");
}