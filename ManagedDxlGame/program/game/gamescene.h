#pragma once

#include "gm_scene_base.h"
#include "Player.h"
#include"MapChip.h"
#include"System_Manager.h"
#include"Camera.h"
#include "../dxlib_ext/dxlib_ext.h"
#include"Enemy_Manager.h"
#include"item.h"

class ScenePlay : public SceneBase {
private:
	 
	int back_gph_hdl_ = 0;												// 背景画像  
	int goal_ghdl_ = 0;													// ゴールの画像
	int chip_gpc_hdl = 0;												// マップチップの画像
	Player* myPlayer = nullptr;											// プレイヤーのポインタ変数
	MapChip* mapChip = nullptr;											// マップチップのポインタ変数
	SystemManager* system_manager = nullptr;							// システムマネージャーのポインタ変数
	Enemy_Manager* enemy_manager[4];								    // エネミーマネージャーのポインタ変数
	item* Item[5];														// アイテムクラスのポインタ変数
	Camera_* camera = nullptr;											// カメラクラスのポインタ変数
	int GRAVITY = 5;													// 重力
	int FORCE = 0;														// 力

	std::string gpc_map_chip_hdls_pass_;								// 画像パス
	int map_chip_width_;												// マップチップの幅
	int map_chip_height_;												// マップチップの高さ
	int map_chip_all_size_;												// マップチップの総フレーム数
	int map_chip_x_size_;												// マップチップの横フレーム数
	int map_chip_y_size_;												// マップチップの縦フレーム数
	int map_chip_bottom = -5500;										// マップチップの底
	int* gpc_map_chip_hdls_;											// 画像データ格納
	int back_bgm = 0;													// 常に流れているBGM

	std::string map_data_csv_pass_;										// マップCSVデータのパス
	tnl::Vector3 pos_ = { 0, 0, 0 };
	tnl::Vector3 goal_pos_ = { 609 , -4093 , 0};						// ゴールの座標
	
	tnl::Vector3 item_pos  = {65 , 643 , 0};							// アイテムの座標1
	tnl::Vector3 item_pos2 = {1215 , -93 , 0};							// アイテムの座標2					
	tnl::Vector3 item_pos3 = {673 , -1563 , 0};							// アイテムの座標3
	tnl::Vector3 item_pos4 = {65 , -2043 , 0};							// アイテムの座標4
	tnl::Vector3 item_pos5 = {1045 , -4500 , 0};						// アイテムの座標5

	tnl::Vector3 enemypos  = {261 , -573 ,  0};							//敵の座標1
	tnl::Vector3 enemypos2 = {795 , -1149 ,  0 };						//敵の座標2
	tnl::Vector3 enemypos3 = {385 , -1566 , 0};							//敵の座標3
	tnl::Vector3 enemypos4 = {65 , -3869 ,  0};							//敵の座標4
	


	int  item_count;												    // アイテムカウント
	int  item_count_max = 5;											// アイテムの最大カウント数
	bool item_count_flag = false;										// アイテムフラグ


public:
	ScenePlay();
	~ScenePlay();

	void update(float delta_time) override;
	void draw() override;
	
	

	std::vector<std::vector<int>> map_csv;
	std::list<MapChip*> MapChips;
};
