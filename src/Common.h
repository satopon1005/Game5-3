#pragma once
#include <string>

using namespace std;

constexpr int SCREEN_SIZE_X = 1280;		// X方向の画面サイズを指定
constexpr int SCREEN_SIZE_Y = 720;		// Y方向の画面サイズを指定

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