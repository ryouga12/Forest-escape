#include "../dxlib_ext/dxlib_ext.h"
#include "gm_main.h"
#include "gm_Manager.h"
#include "seane_explanation.h"
#include "seane_explanation2.h"
#include "gamescene.h"

seane_explanation::seane_explanation()
{
	//説明用のプレイヤー画像の読み込み
	plyer_explanation_ghdl       = LoadGraph("graphics/char_test.png");
	plyer_left_explanation_ghdl  = LoadGraph("graphics/c1_test_left.png");
	plyer_light_explanation_ghdl = LoadGraph("graphics/c1_right.png");
	
	//説明用のエフェクト画像の読み込み	
	ef_explanation_ghdl = LoadGraph("graphics/pipo-btleffect005.png");
}

seane_explanation::~seane_explanation()
{
}

void seane_explanation::update(float delta_time)
{
	//シーン遷移
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN) || tnl::Input::IsPadDownTrigger(ePad::KEY_1)) {
		auto mgr = GameManager::GetInstance();
		mgr->changeScene(new seane_explanation2());
	}
}

void seane_explanation::draw()
{
	DrawStringEx(10, 10, -1, "プレイヤー説明");
	DrawStringEx(300, 50, -1, "プレイヤーの動きはキーボードのキー又はパッドの十字キーで行います");


	//描画&説明
	DrawRotaGraph(300, 200, 3, 0, plyer_left_explanation_ghdl, true);
	DrawStringEx (50, 100, -1, "キーボードの場合はA\nゲームパッドの場合は十字キーの左で\n左に動きます");
	DrawRotaGraph(600, 200, 3, 0, plyer_explanation_ghdl, true);
	DrawStringEx (510, 300, -1, "キーボードの場合はspace\nゲームパッドの場合は×ボタンで\nジャンプします");
	DrawRotaGraph(900, 200, 3, 0, plyer_light_explanation_ghdl, true);
	DrawStringEx (950, 100, -1, "キーボードの場合はD\nゲームパッドの場合は十字キーの右で\n右に動きます");
	DrawRotaGraph(300, 500, 3, 0, plyer_left_explanation_ghdl, true);
	DrawRotaGraph(300, 600, 2, 0, ef_explanation_ghdl, true);
	DrawStringEx (400, 500, -1, "プレイヤーは2回までジャンプできます");
	DrawStringEx (700,680, -1, "次に進む場合は、EnterKeyまたは〇ボタンを押してください");

}
