#pragma once
#include "gm_scene_base.h"


class SceneResult : public SceneBase {
private:
	int result_ghdl = 0;
	int score_;														//score�̕ێ��ϐ�
	int time_;													   //timer�̕ێ��ϐ�
	int high_score;												   //highscore�̕ێ��ϐ�
	bool clear_message_flag = true;								   //�N���A���b�Z�[�W�̃t���O
	float EFFCT_TIME = 0;										  //�G�t�F�N�g�̕b��
	int   EFFCT_SIZE = 10;									      //�G�t�F�N�g�̑���
	int   clearmem[10];											  //���b�Z�[�W
	int   anim_ctrl_frame = 0;

public:
	SceneResult(int score ,float time );
	~SceneResult();

	

	void update(float delta_time) override;
	void draw() override;
};

