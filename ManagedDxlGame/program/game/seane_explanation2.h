#pragma once
#include "gm_scene_base.h"

class seane_explanation2 : public SceneBase {
public:
	seane_explanation2();
	~seane_explanation2();

	void update(float delta_time) override;
	void draw() override;

private:
	int enemy_explanation_ghdl = 0;				//�����p�̓G�̉摜
	int item_explanation_ghdl = 0;				//�����p�̃A�C�e���̉摜

};