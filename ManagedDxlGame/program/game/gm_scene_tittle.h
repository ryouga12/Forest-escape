#pragma once
#include "gm_scene_base.h"



class SceneTitle : public SceneBase {
private:

	int test_back_ground_gfx_ = 0;			//�^�C�g�����
	
	int string_flashing = 0;				//������_�ł�����
	bool flashing_flag = true;				//�_�ł����邽�߂̃t���O
	int title_bgm = 0;

	

public:
	SceneTitle();
	~SceneTitle();

	void update(float delta_time) override;
	void draw() override;
};