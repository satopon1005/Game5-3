#pragma once
#include "../Common.h"
#include "../File/File.h"

constexpr int MAPCHIP_SIZE = 40;

constexpr int MAP_SIZE_X = SCREEN_SIZE_X * 2;
constexpr int MAP_SIZE_Y = SCREEN_SIZE_Y * 2;

constexpr int MAPCHIP_NUM_X = MAP_SIZE_X / MAPCHIP_SIZE;
constexpr int MAPCHIP_NUM_Y = MAP_SIZE_Y / MAPCHIP_SIZE;

constexpr char MAPCHIP_NUM_FILE_PATH[] = { "data/MapChipData/MapChip_Num.txt" };
constexpr char MAPCHIP_NAME_FILE_PATH[] = { "data/MapChipData/MapChip_Name.txt" };

enum MapChipContent
{
	Wall,
	Floor,
};

class MapChip
{
private:
	int m_mapchip_file_num;
	int m_mapchip_handle_index[MAPCHIP_NUM_Y][MAPCHIP_NUM_X];
	char** m_mapchip_file_name;

	File file_info;

public:
	static int m_mapchip_index;

	MapChip();
	~MapChip();

	void InitEdit();
	void Init();
	void Init(int index);

	void Step();
	void StepEdit();

	void Draw();
	void DrawEdit();

	void LoadMapNum();
	void LoadFileName();

	void LoadMapChip(int index);

	void SaveMapChip();
	void SaveMapChipNum(int num);
	void SaveMapChipName(string name);

	int GetMapNum() { return m_mapchip_file_num; }
	char* GetFileName(int index) { return m_mapchip_file_name[index]; }

	int GetMapChipHandleIndex(int y_index, int x_index) { return m_mapchip_handle_index[y_index][x_index]; }
};