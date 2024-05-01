#include "DxLib.h"
#include "SceneManager.h"
#include "../Common.h"
#include "../Sound/Sound.h"

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
			delete scene;
		}
		SceneBace::g_scene_ID = LOOP_Scene;
		break;
	}
	case Edit_Scene: {
		if (scene != nullptr) {
			delete scene;
		}
		SceneBace::g_scene_ID = LOOP_Scene;
		break;
	}
	case Play_Scene: {
		if (scene != nullptr) {
			delete scene;
		}
		SceneBace::g_scene_ID = LOOP_Scene;
		break;
	}
	case Result_Scene: {
		if (scene != nullptr) {
			delete scene;
		}
		SceneBace::g_scene_ID = LOOP_Scene;
		break;
	}
	}

	if (scene != nullptr) {
		scene->Step();
		scene->Draw();
	}
}