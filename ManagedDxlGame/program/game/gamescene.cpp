#include "../dxlib_ext/dxlib_ext.h"
#include "gm_main.h"
#include"MapChip.h"
#include "gm_Manager.h"
#include "gamescene.h"
#include "gm_scene_result.h"
#include"Enemy_Manager.h"
#include"Player.h"
#include"item.h"



// コンストラクタ
ScenePlay::ScenePlay() {

	back_gph_hdl_ = LoadGraph("graphics/back.png");				//背景の読み込み
	goal_ghdl_ = LoadGraph("graphics/22061545.png");			//ゴールの画像の読み込み
	myPlayer = new Player();
	system_manager = new SystemManager();
	camera = new Camera_();

	//敵のクラスの複製して読み込む
	enemy_manager[0] = new Enemy_Manager(enemypos);
	enemy_manager[1] = new Enemy_Manager(enemypos2);
	enemy_manager[2] = new Enemy_Manager(enemypos3);
	enemy_manager[3] = new Enemy_Manager(enemypos4);

	//アイテムクラスの複製して読み込む
	Item[0] = new item(item_pos);
	Item[1] = new item(item_pos2);
	Item[2] = new item(item_pos3);
	Item[3] = new item(item_pos4);
	Item[4] = new item(item_pos5);


	// マップチップの画像のロード
	gpc_map_chip_hdls_pass_ = "graphics/BrightForest-A.png";

	map_chip_width_  = 32;
	map_chip_height_ = 32;
	map_chip_x_size_ = 8;
	map_chip_y_size_ = 21;
	map_chip_all_size_ = map_chip_x_size_ * map_chip_y_size_;
	gpc_map_chip_hdls_ = new int[map_chip_all_size_];

	LoadDivGraph(gpc_map_chip_hdls_pass_.c_str(),
		map_chip_all_size_,
		map_chip_x_size_,
		map_chip_y_size_,
		map_chip_width_,
		map_chip_height_,
		gpc_map_chip_hdls_);


	// マップデータのロード
	map_data_csv_pass_ = "map_chips.csv";
	map_csv = tnl::LoadCsv<int>(map_data_csv_pass_);
	


	//map_csv = tnl::LoadCsv<int>("map_chip.csv");

	//マップチップ読み込み
	for (int i = 0; i < map_csv.size(); ++i) {
		for (int k = 0; k < map_csv[i].size(); ++k) {
			if (-1 == map_csv[i][k]) continue;
			tnl::Vector3 pos;
			int gpc_hdl;
			pos.x = { MapChip::CHIP_SIZE / 2 + k * MapChip::CHIP_SIZE};
			pos.y = { map_chip_bottom + DXE_WINDOW_HEIGHT + MapChip::CHIP_SIZE / 2 + i * MapChip::CHIP_SIZE };
			gpc_hdl = gpc_map_chip_hdls_[map_csv[i][k]];
			/*DrawGraph(pos.x, pos.y, gpc_hdl, true);*/
			MapChips.emplace_back(new MapChip(pos , gpc_hdl));
		}
	}
	//BGMの読み込み&再生
	back_bgm = LoadSoundMem("sound/ks001.wav");
	PlaySoundMem(back_bgm, DX_PLAYTYPE_LOOP, true);
	 
	//アイテムカウントの初期化
	item_count = 0;
}
// デストラクタ
ScenePlay::~ScenePlay() {
	delete myPlayer;
	delete camera;
	DeleteGraph(back_gph_hdl_);				//  画像のデリートを実行（デリートしないとメモリ内にデータが残る）
	DeleteGraph(goal_ghdl_);				//  画像のデリートを実行（デリートしないとメモリ内にデータが残る）
}

// プレイシーン内の処理
void ScenePlay::update(float delta_time) {

	//プレイヤーの動き
	myPlayer->PlyMove(delta_time);
	//敵の動き
	for (int i = 0; i < 4; i++) {
		if (enemy_manager[i]) {
			enemy_manager[i]->tnl_sequence_.update(delta_time);
		}
	}
	//カメラの動き
	camera->update(myPlayer->pos_);
	//マップチップ
	mapChip->Update();
	//シーンマネージャー（スコア、タイムなど）
	system_manager->update(delta_time);
	int score = system_manager->getScore();
	int time =  system_manager->getTime();


	

	// ブロックと衝突判定 & 補正
	// ゲームループ内での当たり判定のチェック]
	for (auto mapChip : MapChips) {
		if (int n = tnl::IsIntersectRectToCorrectPosition(
			myPlayer->pos_,
			myPlayer->prev_pos,
			myPlayer->CHARA_WIDTH,
			myPlayer->CHARA_HEIGHT,
			mapChip->pos_,
			map_chip_width_,
			map_chip_height_)) {

			myPlayer->jumpCount = 0;
			myPlayer->gravity = 0;
			myPlayer->jumpEf_flag = false;
			tnl::DebugTrace("n = %d\n", n);
		}
	}

	//itemとプレイヤーのあたり判定
	for (int i = 0; i < 5; i++) {
		if (Item[i]) {
			if (tnl::IsIntersectRectToCorrectPosition(
				myPlayer->pos_,
				myPlayer->prev_pos,
				myPlayer->CHARA_WIDTH,
				myPlayer->CHARA_HEIGHT,
				Item[i]->item_pos_,
				Item[i]->ITEM_WIDTH,
				Item[i]->ITEM_HEIGHT)) {

				item_count++;
				PlaySoundMem(Item[i]->item_get_se, DX_PLAYTYPE_BACK); 
				delete Item[i];
				Item[i] = nullptr;
			}
		}
	}
	
	//アイテムがMaxになるとフラグをtrueにする
	if (item_count == item_count_max) {
		item_count_flag = true;
	}

	//プレイヤーと敵のあたり判定
	for (int i = 0; i < 4; i++) {
		if (enemy_manager[i]) {
			if (tnl::IsIntersectRectToCorrectPosition(
				myPlayer->pos_,
				myPlayer->prev_pos,
				myPlayer->CHARA_WIDTH,
				myPlayer->CHARA_HEIGHT,
				enemy_manager[i]->pos_,
				enemy_manager[i]->ENEMY_WIDTH,
				enemy_manager[i]->ENEMY_HEIGHT)) {

				myPlayer->gravity = 0;
				//プレイヤーの動きを止める
				myPlayer->play_move_flag = false;
				myPlayer->jumpEf_flag = false;
				myPlayer->ply_damage_flag = false;

			}
		}
	}

	
	
		/*if (checkCollision) {
			DrawString(500, 100, "当たった", -1);
		}*/
	
	
	
	//シーン遷移(スコアと時間をリザルト画面に持っていく)
	if (tnl::Input::IsKeyDown(eKeys::KB_W) || tnl::Input::IsPadDownTrigger(ePad::KEY_UP)) {
		if ((myPlayer->pos_.x == goal_pos_.x && myPlayer->pos_.y == goal_pos_.y && item_count == item_count_max)) {
			auto mgr = GameManager::GetInstance();
			StopSoundMem(back_bgm);
			mgr->changeScene(new SceneResult(score, time));
		}
	}

}



// プレイシーンの描画
void ScenePlay::draw() {

	DrawStringEx(10, 10, -1, "プレイ画面");
	//背景
	DrawRotaGraph(700, 100, 3,0, back_gph_hdl_, true);							

	//ゴールの描画
	tnl::Vector3 draw_pos = goal_pos_ - camera->target_ + tnl::Vector3(DXE_WINDOW_WIDTH >> 1, DXE_WINDOW_HEIGHT >> 1, 0);
	DrawRotaGraph(draw_pos.x, draw_pos.y, 0.1f, 0, goal_ghdl_, true);

	//プレイヤーの描画
	myPlayer->Draw(*camera);

	/*for (int y = 0; y < map_csv.size(); ++y) {
		for (int x = 0; x < map_csv[y].size(); ++x) {
			DrawGraph(x * map_chip_width_ , DXE_WINDOW_HEIGHT + y * map_chip_height_, gpc_map_chip_hdls_[map_csv[y][x]], true);
		}
	}*/

	//// マップの表示
	//for (int y = 0; y < map_data_.size(); ++y) {
	//	for (int x = 0; x < map_data_[y].size(); ++x) {
	//		DrawGraph( x * map_chip_width_, (-3200) + DXE_WINDOW_HEIGHT + y * map_chip_height_, gpc_map_chip_hdls_[map_data_[y][x]], true);
	//	}
	//}
	// 描画時にカメラの位置をオフセットとして適用


	//Mapchipの描画
	for (auto mapChip : MapChips) {
		mapChip->draw(*camera);
	}

	//DrawStringEx(10, 50, -1, "プレイヤーの座標x　: %f", myPlayer->pos_.x);
	/*DrawStringEx(500, 50, -1, "プレイヤーの座標y　: %f", myPlayer->pos_.y);
	DrawStringEx(1000, 50, -1, "gravity : %f", myPlayer->gravity);*/
	SetFontSize(22);
	DrawStringEx(1000, 50, -1, "アイテム : %d / 5", item_count);
	DrawStringEx(430, 50, -1, "クリア条件 : アイテムを5個揃えて\n             ゴールを目指せ！");
	
	
	if (goal_pos_.x == myPlayer->pos_.x && goal_pos_.y == myPlayer->pos_.y) {
		if (item_count_flag) {
			DrawStringEx(400, 200, -1, "Ｗキー又は十字キーの上を押してください");
		}
		else {
			DrawStringEx(500, 200, -1, "アイテムが足りません");
		}
	}
	
	//アイテムの描画
	for (int i = 0; i < 5; i++) {
		if(Item[i])Item[i]->draw(*camera);
	}
	//システムマネージャーの描画
	system_manager->draw();

	//敵の描画
	for (int i = 0; i < 4; i++) {
		if (enemy_manager[i])enemy_manager[i]->draw(*camera);
	}


	SetFontSize(18);
}

