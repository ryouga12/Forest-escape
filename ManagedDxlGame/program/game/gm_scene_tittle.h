#pragma once
#include "gm_scene_base.h"



class SceneTitle : public SceneBase {
private:

	int test_back_ground_gfx_ = 0;			//タイトル画面
	
	int string_flashing = 0;				//文字を点滅させる
	bool flashing_flag = true;				//点滅させるためのフラグ
	int title_bgm = 0;

	

public:
	SceneTitle();
	~SceneTitle();

	void update(float delta_time) override;
	void draw() override;
};