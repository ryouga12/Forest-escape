#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "gm_Manager.h"
#include"Camera.h"

class Player {
public:
	Player();
	~Player();
	void Update(float deltatime);
	void Draw(const Camera_& camera);
	void PlyMove( float deltatime);
	tnl::Vector3 pos_ = {};
	int Total_Frame = 4;						//プレイヤーの総フレーム(4)
	int Horizontal_frame = 4;					//プレイヤーの横フレーム(4)
	int Vertical_frame = 1;						//プレイヤーの縦フレーム(1)
	int Horizontal_oneframe = 32;				//横方向へ 1フレームあたりの幅(32)
	int Vertical_oneframe = 48;					//縦方向へ 1フレームあたりの幅(48)
	tnl::Vector3 prev_pos = {};					//移動前の座標
	float gravity = 0;							//重力
	int jumpCount = 0;							//ジャンプのカウント
	int dblJump = 2;							//ダブルジャンプ
	int jumpMax = 1;							//ジャンプの上限回数
	bool jumpEf_flag = false;					//ジャンプエフェクトのフラグ
	int  jump_se = 0;							//ジャンプのse
	bool play_move_flag = true;					//プレイヤーの動きの制御
	const int CHARA_HEIGHT = 96;				//キャラクターの高さ
	const int CHARA_WIDTH = 64;					//キャラクターの幅
	float ply_stop_count = 0;					//プレイヤーが止まっている間の時間
	bool ply_ghdl_flag = true;					//プレイヤーの画像を表示する
	bool ply_damage_flag = true;				//プレイヤーがダメージフラグ
	float ply_damage_count = 0;					//プレイヤーが止まっている時間
	float ply_count = 0;						//プレイヤーが止まっている時間

	

private:
	
	enum {
		DIR_LEFT,
		DIR_RIGHT,
		DIR_MAX
	};
	
	float anim_time_count = 0;
	int anim_ctrl_dir = DIR_RIGHT;
	int anim_ctrl_frame = 0;
	int anim_hdls[DIR_MAX][4];
	const float initialX = (DXE_WINDOW_WIDTH - CHARA_WIDTH) / 2;	  // 画面中央に配置
	const float initialY = DXE_WINDOW_HEIGHT - CHARA_HEIGHT / 2;      // 画面下部に配置
	const float initialZ = 0;                                         // Z座標は通常使用しないので0

	
	float EFFCT_TIME = 0;											  //エフェクトの秒数
    int JUMPEFFCT_SIZE = 10;									      //エフェクトの総数
	int jumpef[10];													  //エフェクトの数
	
	float ply_stop_count_max = 2;										//同上

	float force_ = 0.98;											  //力
	
};

