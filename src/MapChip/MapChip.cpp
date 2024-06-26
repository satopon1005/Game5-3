#include "DxLib.h"
#include "MapChip.h"
#include "../Screen/Screen.h"
#include "../Input/Input.h"

int MapChip::m_mapchip_index;

MapChip::MapChip()
{
	for (int i = 0; i < MapChipTypeMaxNum; i++) {
		m_handle[i] = 0;
	}

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
	LoadMapHandle();
	LoadMapNum();
	for (int i = 0; i < MAPCHIP_NUM_Y; i++)
		for (int j = 0; j < MAPCHIP_NUM_X; j++)
			m_mapchip_handle_index[i][j] = Floor1;

	m_mapchip_file_name = new char*;
	m_mapchip_file_name[0] = new char[64];
}
void MapChip::Init()
{
	m_mapchip_index = 0;
	LoadFileName();
}
void MapChip::Init(int index)
{
	LoadMapHandle();
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

	if (Input::GetMousePosX() > 0 && Input::GetMousePosX() < SCREEN_SIZE_X &&
		Input::GetMousePosY() > 0 && Input::GetMousePosY() < SCREEN_SIZE_Y) {

		if (Input::IsKeyDown(KEY_INPUT_1)) {
			if (m_mapchip_handle_index[y_index][x_index] >= WallMaxNum) {

				int wall_rand = GetRand(9);
				switch (wall_rand) {
				case 0: {
					m_mapchip_handle_index[y_index][x_index] = Wall2;
					break;
				}
				case 1: {
					m_mapchip_handle_index[y_index][x_index] = Wall3;
					break;
				}
				default: {
					m_mapchip_handle_index[y_index][x_index] = Wall1;
				}
				}
			}
		}
		if (Input::IsKeyDown(KEY_INPUT_2)) {
			m_mapchip_handle_index[y_index][x_index] = Tsuta;
		}
		if (Input::IsKeyDown(KEY_INPUT_3)) {
			m_mapchip_handle_index[y_index][x_index] = Floor1;
		}
		if (Input::IsKeyDown(KEY_INPUT_4)) {
			m_mapchip_handle_index[y_index][x_index] = Floor2;
		}
		if (Input::IsKeyDown(KEY_INPUT_5)) {
			m_mapchip_handle_index[y_index][x_index] = Stump;
		}
	}

	//マップの端を壁にする
	for (int y_index = 0; y_index < MAPCHIP_NUM_Y; y_index++) {
		m_mapchip_handle_index[y_index][0] = Wall1;
		m_mapchip_handle_index[y_index][MAPCHIP_NUM_X - 1] = Wall1;
	}
	for (int x_index = 0; x_index < MAPCHIP_NUM_X; x_index++) {
		m_mapchip_handle_index[0][x_index] = Wall1;
		m_mapchip_handle_index[MAPCHIP_NUM_Y - 1][x_index] = Wall1;
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

	DrawFormatString(0, 0, GetColor(0, 0, 0), "１：壁\n２：ツタ\n３：床１\n４：床２\n５：切り株");
}
//プレイシーンでの描画処理
void MapChip::Draw()
{
	for (int y_index = 0; y_index < MAPCHIP_NUM_Y; y_index++) {
		for (int x_index = 0; x_index < MAPCHIP_NUM_X; x_index++) {

			DrawExtendGraph((int)(x_index * MAPCHIP_SIZE - Screen::m_screen_pos.x),
				(int)(y_index * MAPCHIP_SIZE - Screen::m_screen_pos.y),
				(int)((x_index + 1) * MAPCHIP_SIZE - Screen::m_screen_pos.x),
				(int)((y_index + 1) * MAPCHIP_SIZE - Screen::m_screen_pos.y),
				m_handle[m_mapchip_handle_index[y_index][x_index]],
				true);
		}
	}
}

void MapChip::LoadMapHandle()
{
	LoadDivGraph(MAPCHIP_HANDLE_PATH, MapChipTypeMaxNum, 4, 4, 50, 50, m_handle);
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
	//保存するファイルの名前を入力
	//==================================================================================
	string s_mapchip_name = "data/MapChipData/";
	char name[17];
	for (int i = 0; i < 17; i++)
		name[i] = 0;

	DrawFormatString(0, 0, GetColor(0, 0, 0), "保存するファイルの名前を入力してください");
	KeyInputSingleCharString(0, 15, 6, name, false);

	s_mapchip_name += name;
	s_mapchip_name += ".csv";

	for (int i = 0; i < 64; i++)
		m_mapchip_file_name[0] = 0;

	m_mapchip_file_name[0] = (char*)s_mapchip_name.c_str();
	//==================================================================================

	//ファイルの名前を保存する
	//==================================================================================

	SaveMapChipNum(m_mapchip_file_num + 1);
	SaveMapChipName(s_mapchip_name);

	//==================================================================================

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

void MapChip::SaveMapChipNum(int num)
{
	if (file_info.OpenFile(MAPCHIP_NUM_FILE_PATH, "w")) {
		fprintf(file_info.fp, "%d", num);

		file_info.CloseFile();
	}
}
void MapChip::SaveMapChipName(string name)
{
	if (file_info.OpenFile(MAPCHIP_NAME_FILE_PATH, "a")) {
		fprintf(file_info.fp, "\n%s", name.c_str());

		file_info.CloseFile();
	}
}