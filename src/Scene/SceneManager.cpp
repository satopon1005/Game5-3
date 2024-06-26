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
	SceneBace::g_scene_ID = Title_Scene;
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
		Sound::StopAll();
		Sound::PlayBGM(Scenetype::Title_BGM);
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
		Sound::StopAll();
		Sound::PlayBGM(Scenetype::Select_BGM);
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
		Sound::StopAll();
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
		Sound::StopAll();
		Sound::PlayBGM(Scenetype::Play_BGM);
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
		Sound::StopAll();
		Sound::PlaySE(SEtype::Clear_BGM);
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
		Sound::StopAll();
		Sound::PlaySE(SEtype::GameOver_BGM);
		break;
	}
	}

	if (scene != nullptr) {
		scene->Step();
		scene->Draw();
	}
}