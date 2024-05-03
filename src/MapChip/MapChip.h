#pragma once
#include "../Common.h"
#include "../File/File.h"

constexpr int MAPCHIP_SIZE_X = SCREEN_SIZE_X / 32;

constexpr int MAP_SIZE_X = SCREEN_SIZE_X * 2;
constexpr int MAP_SIZE_Y = SCREEN_SIZE_Y * 2;

constexpr int MAPCHIP_NUM_X = MAP_SIZE_X / MAPCHIP_SIZE_X;
constexpr int MAPCHIP_NUM_Y = MAP_SIZE_Y / MAPCHIP_SIZE_X;

constexpr char MAPCHIP_NUM_FILE_PATH[] = { "data/MapChip/MapChip_Num.txt" };
constexpr char MAPCHIP_NAME_FILE_PATH[] = { "data/MapChip/MapChip_Name.txt" };

enum MapChipContent
{
	FrontWall,
	BackWall,
	LeftWall,
	RightWall,

	LeftUpWall,
	RightUpWall,
	LeftDownWall,
	RightDownWall,

	LeftUpSharpWall,
	RightUpSharpWall,
	LeftDownSharpWall,
	RightDownSharpWall,

	Floor,
};

class MapChip
{
private:
	static int m_mapchip_index;

	int m_mapchip_file_num;
	int m_mapchip_handle_index[MAPCHIP_NUM_Y][MAPCHIP_NUM_X];
	char** m_mapchip_file_name;

	File file_info;

public:
	MapChip();
	~MapChip();

	void Init();
	void Init(int index);
	void Step();
	void Draw();

	void LoadMapNum();
	void LoadFileName();

	void LoadMapChip(int index);
};