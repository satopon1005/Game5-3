#include "DxLib.h"
#include "SceneSelect.h"
#include "../../Common.h"
#include "../../Input/Input.h"

void SceneSelect::Init()
{
	mapchip_info.Init();
	m_select_num = 0;
}
void SceneSelect::Step()
{
	if (Input::IsKeyPush(KEY_INPUT_RETURN)) {
		SceneBace::g_scene_ID = Play_Scene;
		MapChip::m_mapchip_index = m_select_num;
	}

	if (Input::IsKeyPush(KEY_INPUT_LEFT)) {
		m_select_num--;
		if (m_select_num < 0)
			m_select_num = mapchip_info.GetMapNum() - 1;
	}
	if (Input::IsKeyPush(KEY_INPUT_RIGHT)) {
		m_select_num++;
		if (m_select_num >= mapchip_info.GetMapNum())
			m_select_num = 0;
	}
}
void SceneSelect::Draw()
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "ÉZÉåÉNÉg");
	DrawFormatString(0, 15, GetColor(255, 255, 255), "%d", m_select_num);
	DrawFormatString(0, 30, GetColor(255, 255, 255), "%s", mapchip_info.GetFileName(m_select_num));
}
void SceneSelect::Fin()
{

}