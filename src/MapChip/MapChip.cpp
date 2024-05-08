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
			m_mapchip_handle_index[i][j] = Floor;

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
	Init();
	LoadMapChip(index);
}
//�v���C�V�[���ł̃X�e�b�v����
void MapChip::Step()
{

}
//�G�f�B�b�g�V�[���ł̃X�e�b�v����
void MapChip::StepEdit()
{
	int x_index = (int)((Input::GetMousePosX() + Screen::m_screen_pos.x) / MAPCHIP_SIZE);
	int y_index = (int)((Input::GetMousePosY() + Screen::m_screen_pos.y) / MAPCHIP_SIZE);

	if (Input::GetMousePosX() > 0 && Input::GetMousePosX() < SCREEN_SIZE_X &&
		Input::GetMousePosY() > 0 && Input::GetMousePosY() < SCREEN_SIZE_Y) {

		if (Input::IsKeyDown(KEY_INPUT_1)) {
			m_mapchip_handle_index[y_index][x_index] = Wall;
		}
		if (Input::IsKeyDown(KEY_INPUT_2)) {
			m_mapchip_handle_index[y_index][x_index] = Floor;
		}
	}

	//�}�b�v�̒[��ǂɂ���
	for (int y_index = 0; y_index < MAPCHIP_NUM_Y; y_index++) {
		m_mapchip_handle_index[y_index][0] = Wall;
		m_mapchip_handle_index[y_index][MAPCHIP_NUM_X - 1] = Wall;
	}
	for (int x_index = 0; x_index < MAPCHIP_NUM_X; x_index++) {
		m_mapchip_handle_index[0][x_index] = Wall;
		m_mapchip_handle_index[MAPCHIP_NUM_Y - 1][x_index] = Wall;
	}
}

//�G�f�B�b�g�V�[���ł̕`�揈��
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

	DrawFormatString(0, 15, GetColor(255, 255, 255), "�P�F��\n�Q�F��");
}
//�v���C�V�[���ł̕`�揈��
void MapChip::Draw()
{
	for (int y_index = 0; y_index < MAPCHIP_NUM_Y; y_index++) {
		for (int x_index = 0; x_index < MAPCHIP_NUM_X; x_index++) {
			int color = GetColor(255, 255, 255);

			switch (m_mapchip_handle_index[y_index][x_index]) {
			case Wall: {
				color = GetColor(255, 0, 0);
				break;
			}
			case Floor: {
				color = GetColor(0, 0, 0);
				break;
			}
			}

			
			DrawBox((int)(x_index * MAPCHIP_SIZE - Screen::m_screen_pos.x), (int)(y_index * MAPCHIP_SIZE - Screen::m_screen_pos.y),
					(int)((x_index + 1) * MAPCHIP_SIZE - Screen::m_screen_pos.x), (int)((y_index + 1) * MAPCHIP_SIZE - Screen::m_screen_pos.y),
					color, true);
		}
	}
}

//�}�b�v�`�b�v�f�[�^���ۑ�����Ă���t�@�C���̖��O���擾
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

//�}�b�v�`�b�v�f�[�^���ۑ�����Ă���t�@�C���̌����擾
void MapChip::LoadMapNum()
{
	if (file_info.OpenFile(MAPCHIP_NUM_FILE_PATH, "r")) {
		int a = fscanf_s(file_info.fp, "%d", &m_mapchip_file_num);

		file_info.CloseFile();
	}
}
//�}�b�v�`�b�v�f�[�^���擾
void MapChip::LoadMapChip(int index)
{
	if (file_info.OpenFile(m_mapchip_file_name[index],"r")) {

		int mapIndexX = 0;
		int mapIndexY = 0;

		while (true) {

			char work = fgetc(file_info.fp);

			// EOF�̏ꍇ�͓ǂݍ��ݏI��
			if (work == EOF)
				break;

			if (work == '\n') {
				mapIndexX = 0;
				mapIndexY++;
			}
			else if (work == ',') {
				mapIndexX++;
			}
			//�����̏ꍇ�͑������
			else if (work - '0' >= 0 && work - '0' <= 9) {

				int num = work - '0';
				m_mapchip_handle_index[mapIndexY][mapIndexX] = m_mapchip_handle_index[mapIndexY][mapIndexX] * 10 + num;
			}
		}

		file_info.CloseFile();
	}
}
//�}�b�v�`�b�v�f�[�^��ۑ�
void MapChip::SaveMapChip()
{
	//�ۑ�����t�@�C���̖��O�����
	//==================================================================================
	string s_mapchip_name = "data/MapChipData/";
	char name[17];
	for (int i = 0; i < 17; i++)
		name[i] = 0;

	DrawFormatString(0, 0, GetColor(0, 0, 0), "�ۑ�����t�@�C���̖��O����͂��Ă�������");
	KeyInputSingleCharString(0, 15, 16, name, false);

	s_mapchip_name += name;
	s_mapchip_name += ".csv";

	for (int i = 0; i < 64; i++)
		m_mapchip_file_name[0] = 0;

	m_mapchip_file_name[0] = (char*)s_mapchip_name.c_str();
	//==================================================================================

	//�t�@�C���̖��O��ۑ�����
	//==================================================================================

	SaveMapChipNum(m_mapchip_file_num + 1);
	SaveMapChipName(s_mapchip_name);

	//==================================================================================

	if (file_info.OpenFile(m_mapchip_file_name[0], "w")) {
		//�ۑ���̃t�@�C�����J��
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