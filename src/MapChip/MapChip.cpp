#include "DxLib.h"
#include "MapChip.h"
#include "../Screen/Screen.h"
#include "../Input/Input.h"

int MapChip::m_mapchip_index;

MapChip::MapChip()
{
	m_mapchip_file_num = 0;
	for (int i = 0; i < MAPCHIP_NUM_Y; i++)
		for (int j = 0; j < MAPCHIP_NUM_X; j++)
			m_mapchip_handle_index[i][j] = 0;
	m_mapchip_file_name = nullptr;
}
MapChip::~MapChip()
{
	if (m_mapchip_file_name != nullptr) {
		for (int i = 0; i < m_mapchip_file_num; i++)
			delete[] m_mapchip_file_name[i];
		delete[] m_mapchip_file_name;

		m_mapchip_file_name = nullptr;
	}
}

void MapChip::InitEdit()
{
	LoadMapNum();
	for (int i = 0; i < MAPCHIP_NUM_Y; i++)
		for (int j = 0; j < MAPCHIP_NUM_X; j++)
			m_mapchip_handle_index[i][j] = 0;

	m_mapchip_file_name = new char*;
	m_mapchip_file_name[0] = new char[64];
	m_mapchip_file_name[0] = { (char*)"data/MapChipData/Map3_edit.csv" };
}
void MapChip::Init()
{
	m_mapchip_index = 0;
	LoadFileName();
}
void MapChip::Init(int index)
{
	Init();
	LoadMapChip(index);
}
//プレイシーンでのステップ処理
void MapChip::Step()
{

}
//エディットシーンでのステップ処理
void MapChip::StepEdit()
{
	int x_index = (int)((Input::GetMousePosX() + Screen::m_screen_pos.x) / MAPCHIP_SIZE);
	int y_index = (int)((Input::GetMousePosY() + Screen::m_screen_pos.y) / MAPCHIP_SIZE);

	if (Input::IsKeyDown(KEY_INPUT_0)) {
		m_mapchip_handle_index[y_index][x_index] = 0;
	}
	if (Input::IsKeyDown(KEY_INPUT_1)) {
		m_mapchip_handle_index[y_index][x_index] = 1;
	}
	if (Input::IsKeyDown(KEY_INPUT_2)) {
		m_mapchip_handle_index[y_index][x_index] = 2;
	}
	if (Input::IsKeyDown(KEY_INPUT_3)) {
		m_mapchip_handle_index[y_index][x_index] = 3;
	}
}

//エディットシーンでの描画処理
void MapChip::DrawEdit()
{
	for (int y_index = 0; y_index < MAPCHIP_NUM_Y; y_index++) {
		DrawLine((int)(-Screen::m_screen_pos.x),
			(int)(y_index * MAPCHIP_SIZE - Screen::m_screen_pos.y),
			(int)(MAP_SIZE_X - Screen::m_screen_pos.x),
			(int)(y_index * MAPCHIP_SIZE - Screen::m_screen_pos.y),
			GetColor(255, 255, 255), 2);

		for (int x_index = 0; x_index < MAPCHIP_NUM_X; x_index++) {
			if (y_index == 0) {
				DrawLine((int)(x_index * MAPCHIP_SIZE - Screen::m_screen_pos.x),
					(int)(-Screen::m_screen_pos.y),
					(int)(x_index * MAPCHIP_SIZE - Screen::m_screen_pos.x),
					(int)(MAP_SIZE_Y - Screen::m_screen_pos.y),
					GetColor(255, 255, 255), 2);
			}
		}
	}
}
//プレイシーンでの描画処理
void MapChip::Draw()
{
	for (int y_index = 0; y_index < MAPCHIP_NUM_Y; y_index++) {
		for (int x_index = 0; x_index < MAPCHIP_NUM_X; x_index++) {
			if (m_mapchip_handle_index[y_index][x_index] == 1)
				DrawBox((int)(x_index * MAPCHIP_SIZE - Screen::m_screen_pos.x), (int)(y_index * MAPCHIP_SIZE - Screen::m_screen_pos.y),
					(int)((x_index + 1) * MAPCHIP_SIZE - Screen::m_screen_pos.x), (int)((y_index + 1) * MAPCHIP_SIZE - Screen::m_screen_pos.y),
					GetColor(255, 0, 0), true);
			if (m_mapchip_handle_index[y_index][x_index] == 2)
				DrawBox((int)(x_index * MAPCHIP_SIZE - Screen::m_screen_pos.x), (int)(y_index * MAPCHIP_SIZE - Screen::m_screen_pos.y),
					(int)((x_index + 1) * MAPCHIP_SIZE - Screen::m_screen_pos.x), (int)((y_index + 1) * MAPCHIP_SIZE - Screen::m_screen_pos.y),
					GetColor(0, 255, 0), true);
			if (m_mapchip_handle_index[y_index][x_index] == 3)
				DrawBox((int)(x_index * MAPCHIP_SIZE - Screen::m_screen_pos.x), (int)(y_index * MAPCHIP_SIZE - Screen::m_screen_pos.y),
					(int)((x_index + 1) * MAPCHIP_SIZE - Screen::m_screen_pos.x), (int)((y_index + 1) * MAPCHIP_SIZE - Screen::m_screen_pos.y),
					GetColor(0, 0, 255), true);
		}
	}
}

//マップチップデータが保存されているファイルの名前を取得
void MapChip::LoadFileName()
{
	LoadMapNum();
	m_mapchip_file_name = new char* [m_mapchip_file_num];
	for (int i = 0; i < m_mapchip_file_num; i++)
		m_mapchip_file_name[i] = new char[64];

	if (file_info.OpenFile(MAPCHIP_NAME_FILE_PATH, "r")) {
		int file_index = 0;

		while (file_index < m_mapchip_file_num) {
			int a = fscanf_s(file_info.fp, "%s", m_mapchip_file_name[file_index], 64);
			file_index++;
		}

		file_info.CloseFile();
	}
}

//マップチップデータが保存されているファイルの個数を取得
void MapChip::LoadMapNum()
{
	if (file_info.OpenFile(MAPCHIP_NUM_FILE_PATH, "r")) {
		int a = fscanf_s(file_info.fp, "%d", &m_mapchip_file_num);

		file_info.CloseFile();
	}
}
//マップチップデータを取得
void MapChip::LoadMapChip(int index)
{
	if (file_info.OpenFile(m_mapchip_file_name[index],"r")) {

		int mapIndexX = 0;
		int mapIndexY = 0;

		while (true) {

			char work = fgetc(file_info.fp);

			// EOFの場合は読み込み終了
			if (work == EOF)
				break;

			if (work == '\n') {
				mapIndexX = 0;
				mapIndexY++;
			}
			else if (work == ',') {
				mapIndexX++;
			}
			//数字の場合は代入する
			else if (work - '0' >= 0 && work - '0' <= 9) {

				int num = work - '0';
				m_mapchip_handle_index[mapIndexY][mapIndexX] = m_mapchip_handle_index[mapIndexY][mapIndexX] * 10 + num;
			}
		}

		file_info.CloseFile();
	}
}
//マップチップデータを保存
void MapChip::SaveMapChip()
{
	if (file_info.OpenFile(m_mapchip_file_name[0], "w")) {
		//保存先のファイルを開く
		for (int y_index = 0; y_index < MAPCHIP_NUM_Y; y_index++) {
			for (int x_index = 0; x_index < MAPCHIP_NUM_X; x_index++) {
				fprintf(file_info.fp, "%d,", m_mapchip_handle_index[y_index][x_index]);
			}
			fprintf(file_info.fp, "\n");
		}

		file_info.CloseFile();
	}
}