#include "DxLib.h"
#include "MapChip.h"
#include "../Screen/Screen.h"

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

void MapChip::Init()
{
	
}
void MapChip::Init(int index)
{
	m_mapchip_index = 0;
	LoadFileName();
	LoadMapChip(MapChip::m_mapchip_index);
}
void MapChip::Step()
{

}
void MapChip::Draw()
{
	for (int y_index = 0; y_index < MAPCHIP_NUM_Y; y_index++) {
		for (int x_index = 0; x_index < MAPCHIP_NUM_X; x_index++) {
			if (m_mapchip_handle_index[y_index][x_index] == 1)
				DrawBox((int)(x_index * MAPCHIP_SIZE - Screen::m_screen_pos.x), (int)(y_index * MAPCHIP_SIZE - Screen::m_screen_pos.y),
					(int)((x_index + 1) * MAPCHIP_SIZE - Screen::m_screen_pos.x), (int)((y_index + 1) * MAPCHIP_SIZE - Screen::m_screen_pos.y),
					GetColor(255, 0, 0), true);
		}
	}
}

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

void MapChip::LoadMapNum()
{
	if (file_info.OpenFile(MAPCHIP_NUM_FILE_PATH, "r")) {
		int a = fscanf_s(file_info.fp, "%d", &m_mapchip_file_num);

		file_info.CloseFile();
	}
}

void MapChip::LoadMapChip(int index)
{
	if (file_info.OpenFile(m_mapchip_file_name[index],"r")) {

		int mapIndexX = 0;
		int mapIndexY = 0;

		while (true) {

			char work = fgetc(file_info.fp);

			// EOF‚Ìê‡‚Í“Ç‚Ýž‚ÝI—¹
			if (work == EOF)
				break;

			if (work == '\n') {
				mapIndexX = 0;
				mapIndexY++;
			}
			else if (work == ',') {
				mapIndexX++;
			}
			//”Žš‚Ìê‡‚Í‘ã“ü‚·‚é
			else if (work - '0' >= 0 && work - '0' <= 9) {

				int num = work - '0';
				m_mapchip_handle_index[mapIndexY][mapIndexX] = m_mapchip_handle_index[mapIndexY][mapIndexX] * 10 + num;
			}
		}

		file_info.CloseFile();
	}
}