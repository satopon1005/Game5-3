#include "DxLib.h"
#include "SceneManager.h"
#include "../Common.h"
#include "../Sound/Sound.h"

#include "SceneTitle/SceneTitle.h"
#include "ScenePlay/ScenePlay.h"
#include "SceneEdit/SceneEdit.h"
#include "SceneSelect/SceneSelect.h"
#include "SceneClear/SceneClear.h"
#include "SceneGameOver/SceneGameOver.h"

int SceneBace::g_scene_ID;

SceneManager::SceneManager()
{
	scene = nullptr;
	SceneBace::g_scene_ID = Clear_Scene;
}

void SceneManager::Main()
{
	switch (SceneBace::g_scene_ID) {
	case Title_Scene: {
		if (scene != nullptr) {
			scene->Fin();
			delete scene;
		}
		scene = new SceneTitle;
		scene->Init();
		SceneBace::g_scene_ID = Loop_Scene;
		break;
	}
	case Select_Scene: {
		if (scene != nullptr) {
			scene->Fin();
			delete scene;
		}
		scene = new SceneSelect;
		scene->Init();
		SceneBace::g_scene_ID = Loop_Scene;
		break;
	}
	case Edit_Scene: {
		if (scene != nullptr) {
			scene->Fin();
			delete scene;
		}
		scene = new SceneEdit;
		scene->Init();
		SceneBace::g_scene_ID = Loop_Scene;
		break;
	}
	case Play_Scene: {
		if (scene != nullptr) {
			scene->Fin();
			delete scene;
		}
		scene = new ScenePlay;
		scene->Init();
		SceneBace::g_scene_ID = Loop_Scene;
		break;
	}
	case Clear_Scene: {
		if (scene != nullptr) {
			scene->Fin();
			delete scene;
		}
		scene = new SceneClear;
		scene->Init();
		SceneBace::g_scene_ID = Loop_Scene;
		break;
	}
	case GameOver_Scene: {
		if (scene != nullptr) {
			scene->Fin();
			delete scene;
		}
		scene = new SceneGameOver;
		scene->Init();
		SceneBace::g_scene_ID = Loop_Scene;
		break;
	}
	}

	if (scene != nullptr) {
		scene->Step();
		scene->Draw();
	}
}