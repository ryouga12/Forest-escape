#include "../dxlib_ext/dxlib_ext.h"
#include "gm_main.h"
#include "gm_Manager.h"
#include "seane_explanation2.h"
#include "gamescene.h"

seane_explanation2::seane_explanation2()
{
	enemy_explanation_ghdl = LoadGraph("graphics/dekakabocha.png");
	item_explanation_ghdl =  LoadGraph("graphics/73938911.png");
}

seane_explanation2::~seane_explanation2()
{
}

void seane_explanation2::update(float delta_time)
{
	//シーン遷移
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN) || tnl::Input::IsPadDownTrigger(ePad::KEY_1)) {
		auto mgr = GameManager::GetInstance();
		mgr->changeScene(new ScenePlay());
	}
}

void seane_explanation2::draw()
{
	DrawStringEx(10, 10, -1, "敵の説明&アイテム説明");
	//敵の描画&説明
	DrawRotaGraph(300, 200, 2, 0, enemy_explanation_ghdl, true);
	DrawStringEx(400, 200, -1, "画面上には敵がいます\nプレイヤーが敵に当たると、2秒間動けなくなります");
	//アイテムの描画&説明
	DrawRotaGraph(300, 400, 2, 0, item_explanation_ghdl, true);
	DrawStringEx (400, 380, -1, "画面上にはアイテムが落ちています\nアイテムが無いとクリアできません\nアイテムを5個入手して、ゴールを目指してください\nゴールには扉があります");
	//クリア説明
	DrawStringEx(400, 550, -1, "クリアした時の秒数によって、スコアが変動します\n高いスコアを目指しましょう！");
	//シーン遷移の説明
	DrawStringEx(700, 660, -1, "これからゲームが始まります\n次に進む場合は、EnterKeyまたは〇ボタンを押してください");
}
