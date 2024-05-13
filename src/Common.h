#pragma once
#include <string>

using namespace std;

constexpr int SCREEN_SIZE_X = 1280;		// X�����̉�ʃT�C�Y���w��
constexpr int SCREEN_SIZE_Y = 720;		// Y�����̉�ʃT�C�Y���w��

void InitGame();
void FinGame();

enum SceneID
{
	Title_Scene,
	Select_Scene,
	Edit_Scene,
	Play_Scene,

	Loop_Scene
};