#pragma once
#include "gm_scene_base.h"

class seane_explanation  : public SceneBase {
public:
	seane_explanation();
	~seane_explanation();

	void update(float delta_time) override;
	void draw() override;

private:
	int plyer_explanation_ghdl = 0;					//�������̃v���C���[�̉摜
	int plyer_left_explanation_ghdl = 0;			//�������̃v���C���[�̍��摜
	int plyer_light_explanation_ghdl = 0;			//�������̃v���C���[�̉E�摜
	int ef_explanation_ghdl = 0;					//�������̃G�t�F�N�g


};