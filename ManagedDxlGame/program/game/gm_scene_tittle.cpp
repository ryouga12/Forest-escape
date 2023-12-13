#include "../dxlib_ext/dxlib_ext.h"
#include "gm_main.h"
#include "gm_Manager.h"
#include "gm_scene_tittle.h"
#include "gm_scene_result.h"
#include "gamescene.h"
#include"Player.h"
#include "seane_explanation.h"


// コンストラクタ
SceneTitle::SceneTitle() {
	//画像の読み込み
	test_back_ground_gfx_ = LoadGraph("graphics/2501060.png");
	//サウンドの読み込み&流す
	title_bgm = LoadSoundMem("sound/ks036.wav");
	PlaySoundMem(title_bgm, DX_PLAYTYPE_LOOP, true);
	
}
// デストラクタ
SceneTitle::~SceneTitle() {
	DeleteGraph(test_back_ground_gfx_);  //  画像のデリートを実行（デリートしないとメモリ内にデータが残る）
}

// タイトルシーン内の処理
void SceneTitle::update(float delta_time) {
	
	//点滅処理
	string_flashing = string_flashing + 1;
	if (string_flashing == 30) {
		string_flashing = 0;
		flashing_flag = !flashing_flag;
	}


	
	//シーン遷移
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)|| tnl::Input::IsPadDownTrigger(ePad::KEY_1)) {
		auto mgr = GameManager::GetInstance();
		StopSoundMem(title_bgm);//音楽を止める
		mgr->changeScene(new seane_explanation());
	}
}

// タイトルシーンの描画
void SceneTitle::draw() {
	DrawRotaGraph(DXE_WINDOW_WIDTH / 2, DXE_WINDOW_HEIGHT / 2, 1.0f, 0, test_back_ground_gfx_, true);
	SetFontSize(50);
	DrawStringEx(430, 200, -1, "forest　escape");
	SetFontSize(18);
	if (flashing_flag) {
		DrawStringEx(550, 300, -1, "press Enter\n\n   or\n\nRound button");
	}
	
	
}

