#include "DxLib.h"
#include "SceneManager.h"
#include "../Common.h"
#include "../Sound/Sound.h"

int SceneBace::g_scene_ID;

SceneManager::SceneManager()
{
	scene = nullptr;
	SceneBace::g_scene_ID = Title;
}

void SceneManager::Main()
{
	switch (g_current_scene_ID) {
	case Title: {
		if (scene != nullptr) {
			delete scene;
		}
		g_current_scene_ID = LOOP;
		break;
	}
	case Play: {
		if (scene != nullptr) {
			delete scene;
		}
		g_current_scene_ID = LOOP;
		break;
	}
	case Result: {
		if (scene != nullptr) {
			delete scene;
		}
		g_current_scene_ID = LOOP;
		break;
	}
	}
	if (scene != nullptr) {
		scene->Step();
		scene->Draw();
	}
}