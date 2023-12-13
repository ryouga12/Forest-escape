#pragma once
#include "gm_scene_base.h"


class SceneResult : public SceneBase {
private:
	int result_ghdl = 0;
	int score_;														//scoreの保持変数
	int time_;													   //timerの保持変数
	int high_score;												   //highscoreの保持変数
	bool clear_message_flag = true;								   //クリアメッセージのフラグ
	float EFFCT_TIME = 0;										  //エフェクトの秒数
	int   EFFCT_SIZE = 10;									      //エフェクトの総数
	int   clearmem[10];											  //メッセージ
	int   anim_ctrl_frame = 0;

public:
	SceneResult(int score ,float time );
	~SceneResult();

	

	void update(float delta_time) override;
	void draw() override;
};

