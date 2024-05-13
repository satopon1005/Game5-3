#include "DxLib.h"
#include "SceneSelect.h"
#include "../../Common.h"
#include "../../Input/Input.h"
#include "../../Font/Font.h"

void SceneSelect::Init()
{
	mapchip_info.Init();
	m_select_num = 0;

	for (int i = 0; i < 5; i++) {
		m_select_pos[i] = { (float)(-SCREEN_SIZE_X / 10 * 3 + SCREEN_SIZE_X / 10 * 4 * i),
							(float)(SCREEN_SIZE_Y / 2),
							0.0f };
		m_select_size[i] = SELECT_IMAGE_SIZE[1];
	}
}
void SceneSelect::Step()
{
	if (m_select_pos[2].x == SCREEN_SIZE_X / 2) {
		if (Input::IsKeyPush(KEY_INPUT_RETURN)) {
			SceneBace::g_scene_ID = Play_Scene;
			MapChip::m_mapchip_index = m_select_num;
		}

		if (Input::IsKeyPush(KEY_INPUT_LEFT)) {
			m_select_num--;
			if (m_select_num < 0)
				m_select_num = mapchip_info.GetMapNum() - 1;

			for (int i = 0; i < 5; i++)
				m_select_pos[i].x += SCREEN_SIZE_X / 10 * 4;
		}
		if (Input::IsKeyPush(KEY_INPUT_RIGHT)) {
			m_select_num++;
			if (m_select_num >= mapchip_info.GetMapNum())
				m_select_num = 0;

			for (int i = 0; i < 5; i++)
				m_select_pos[i].x -= SCREEN_SIZE_X / 10 * 4;
		}
	}
	else if (m_select_pos[2].x < SCREEN_SIZE_X / 2) {
		for (int i = 0; i < 5; i++)
			m_select_pos[i].x += 8;
	}
	else {
		for (int i = 0; i < 5; i++)
			m_select_pos[i].x -= 8;
	}
}
void SceneSelect::Draw()
{
	for (int i = 0; i < 5; i++) {
		DrawBox(m_select_pos[i].x - m_select_size[i] / 2,
			m_select_pos[i].y - m_select_size[i] / 2,
			m_select_pos[i].x + m_select_size[i] / 2,
			m_select_pos[i].y + m_select_size[i] / 2,
			GetColor(255, 0, 0), true);

		char* str = mapchip_info.GetFileName(0);

		str += 17;

		int string_width = GetDrawFormatStringWidthToHandle(Font::GetFontHandle(HGP‘n‰pŠpÎß¯Ìß‘Ì),
			str);

		DrawFormatStringToHandle(m_select_pos[i].x - string_width / 2,
			m_select_pos[i].y - 20,
			GetColor(255, 255, 255),
			Font::GetFontHandle(HGP‘n‰pŠpÎß¯Ìß‘Ì),
			str);
	}

	DrawFormatString(0, 0, GetColor(255, 255, 255), "ƒZƒŒƒNƒg");
	DrawFormatString(0, 15, GetColor(255, 255, 255), "%d", m_select_num);
	DrawFormatString(0, 30, GetColor(255, 255, 255), "%s", mapchip_info.GetFileName(m_select_num));
}
void SceneSelect::Fin()
{

}