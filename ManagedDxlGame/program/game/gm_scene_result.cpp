#include "../dxlib_ext/dxlib_ext.h"
#include "gm_main.h"
#include "gm_Manager.h"
#include "gm_scene_result.h"
#include "gm_scene_tittle.h"
#include"gamescene.h"
#include"System_Manager.h"


// コンストラクタ
SceneResult::SceneResult (int score , float time ){
	result_ghdl = LoadGraph("graphics/1021667.jpg");
	// スコアと時間を受け取って保持する
	this->score_ = score;
	this->time_ = time;
	
	
	//アニメーションの読み込み
	LoadDivGraph("graphics/congratulations.png", 10, 1, 10, 640, 480, clearmem);
	
}
// デストラクタ
SceneResult::~SceneResult() {
	DeleteGraph(result_ghdl);  //  画像のデリートを実行（デリートしないとメモリ内にデータが残る）
}


// タイトルシーン内の処理
void SceneResult::update(float delta_time) {

	//エフェクトの処理
	EFFCT_TIME += delta_time;
	if (EFFCT_TIME > 0.1f) {
		anim_ctrl_frame++;

		EFFCT_TIME = 0;
	}
	if (EFFCT_SIZE == anim_ctrl_frame) {
		/*clear_message_flag = false;*/
		anim_ctrl_frame = 0;
	}


	
	//シーン遷移
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)|| tnl::Input::IsPadDownTrigger(ePad::KEY_1)) {
		auto mgr = GameManager::GetInstance();
		mgr->changeScene(new SceneTitle());
	}
}

// タイトルシーンの描画
void SceneResult::draw() {

	DrawRotaGraph(DXE_WINDOW_WIDTH / 2, DXE_WINDOW_HEIGHT / 2, 1.0f, 0, result_ghdl, true);
	

	// 経過時間を取得（単位を秒に変換して表示）
	int timeInSeconds = time_ / 1000;

	/*if (clear_message_flag) {
		DrawRotaGraph(DXE_WINDOW_WIDTH / 2, DXE_WINDOW_HEIGHT / 2, 0.5, 0, clearmem[anim_ctrl_frame], true);
	}*/

	// スコアと経過時間を描画
	SetFontSize(25);
	DrawStringEx(500, 300, 0, "Score: %d", score_);
	DrawStringEx(500, 360, 0, "経過した時間: %d seconds", timeInSeconds);
	SetFontSize(18);
	
}