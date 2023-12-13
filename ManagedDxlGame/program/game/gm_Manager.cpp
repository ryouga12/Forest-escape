#include "../dxlib_ext/dxlib_ext.h"
#include "gm_Manager.h"
#include "../game/gm_scene_base.h"
#include"gm_scene_tittle.h"



GameManager::GameManager(SceneBase* start_scene) : now_scene_(start_scene) {
	
}

// シングルトンのアドレスを取得
GameManager* GameManager::GetInstance(SceneBase* start_scene) {
	static GameManager* instance = nullptr;
	if (!instance) {
		instance = new GameManager(start_scene);
	}
	return instance;
}

//  ゲームマネージャー内の処理
void GameManager::update(float delta_time) {
	if (now_scene_) now_scene_->update(delta_time);
	if (now_scene_) now_scene_->draw();
}
void GameManager::changeScene(SceneBase* next_scene, float trans_time) {
	delete now_scene_;
	now_scene_ = nullptr;
	now_scene_ = next_scene;
}