#include "Player.h"
#include"MapChip.h"
#include"gamescene.h"

//playerのコンストラクタ
Player::Player()
{
	//アニメーションのロード処理
	std::string files[DIR_MAX] = {
		"graphics/c1_anim_left.png",
		"graphics/c1_anim_right.png"
	};

	pos_ = { initialX,initialY,initialZ };

	for (int i = 0; i < 2; i++) {
		LoadDivGraph(
			files[i].c_str(),				// 画像のパス
			Total_Frame,					// 総フレーム数
			Horizontal_frame,				// 横フレーム数
			Vertical_frame,					// 縦フレーム数
			Horizontal_oneframe,			// 横方向へ 1フレームあたりの幅
			Vertical_oneframe,				// 縦方向へ 1フレームあたりの幅
			anim_hdls[i]);					// 画像ハンドルを格納する配列名);
	}

	//ジャンプエフェクトの読み込み
	LoadDivGraph("graphics/pipo-btleffect004.png", 7, 7, 1, 120, 120, jumpef);

	//ジャンプ時のseの読み込み
	jump_se = LoadSoundMem("sound/jump.mp3");

}

//playerのデストラクタ
Player::~Player()
{
	
}

//Playerの更新処理
void Player::Update(float deltatime)
{

	
}

//Playerの描画処理
void Player::Draw(const Camera_& camera)
{
	tnl::Vector3 draw_pos = pos_ - camera.target_ + tnl::Vector3(DXE_WINDOW_WIDTH >> 1, DXE_WINDOW_HEIGHT >> 1, 0);
	if (ply_ghdl_flag) {
		DrawRotaGraph(draw_pos.x, draw_pos.y, 2.0f, 0, anim_hdls[anim_ctrl_dir][anim_ctrl_frame], true);
		if (jumpEf_flag) {
			DrawRotaGraph(draw_pos.x, draw_pos.y + CHARA_HEIGHT / 2, 0.8f, 0, jumpef[anim_ctrl_frame], true);
		}
	}
}

//Playerの動作処理
void Player::PlyMove(float deltatime)
{

	prev_pos = pos_;

	

	//エフェクトの処理
	EFFCT_TIME += deltatime;
	if (EFFCT_TIME > 0.1f) {
		anim_ctrl_frame++;

		EFFCT_TIME = 0;
	}
	if (JUMPEFFCT_SIZE == anim_ctrl_frame) {
		jumpEf_flag = false;
		anim_ctrl_frame = 0;
	}

	//アニメーション
	anim_time_count += deltatime;
	if (anim_time_count > 0.1f) {
		anim_ctrl_frame++;
		anim_ctrl_frame %= 4;

		anim_time_count = 0;
	}

	if (play_move_flag) {
		//playerの動き
		if (tnl::Input::IsKeyDown(eKeys::KB_A) || tnl::Input::IsPadDown(ePad::KEY_LEFT)) {
			pos_.x -= 10;
		}
		if (tnl::Input::IsKeyDown(eKeys::KB_D) || tnl::Input::IsPadDown(ePad::KEY_RIGHT)) {
			pos_.x += 10;
		}

		//2段ジャンプの実装
		if (tnl::Input::IsKeyDownTrigger(eKeys::KB_SPACE) || tnl::Input::IsPadDownTrigger(ePad::KEY_0)) {
			if (jumpCount <= jumpMax) {
				gravity = -17.0f;
				//ジャンプ時の音の再生
				PlaySoundMem(jump_se, DX_PLAYTYPE_BACK);
				//ジャンプカウントを増やす
				jumpCount++;
				//2回目のジャンプ時
				if (jumpCount == dblJump) {
					//ジャンプ時のエフェクト出すためのフラグをtrueにする
					jumpEf_flag = true;
					//2回目のジャンプは低くなる
					gravity = -13.0f;
				}

			}
		}

		//アニメーションの動き
		if (tnl::Input::IsKeyDown(eKeys::KB_A) || tnl::Input::IsPadDownTrigger(ePad::KEY_LEFT))	anim_ctrl_dir = DIR_LEFT;
		if (tnl::Input::IsKeyDown(eKeys::KB_D) || tnl::Input::IsPadDownTrigger(ePad::KEY_RIGHT)) anim_ctrl_dir = DIR_RIGHT;


	}
	/*else if(tnl::Input::IsKeyDownTrigger(eKeys::KB_SPACE)) {
		force = -50;
		jumpCount++;
	}*/
	

	//重力でplayerが落ちる
	gravity += force_;
	pos_.y += gravity;
	

	//プレイヤーが動けなくなった時、2秒経ったら動けるようにする
	if (play_move_flag == false) {
		ply_stop_count += deltatime;
		if (ply_stop_count > ply_stop_count_max) {
			play_move_flag = true;
			ply_stop_count = 0;
		}
	}

	//プレイヤーが敵に当たったら点滅させる
	if (!ply_damage_flag) {
		ply_damage_count = ply_damage_count + 1;
		ply_count += deltatime;
		if (ply_damage_count == 25) {
			ply_damage_count = 0;
			ply_ghdl_flag = !ply_ghdl_flag;
			if (ply_count > 2) {
				ply_count = 0;
				ply_damage_flag = true;
				ply_ghdl_flag = true;
			}
		}
		
	}

	//画面外にいかないようにする

	/*if (pos_.x > DXE_WINDOW_WIDTH - CHARA_WIDTH) {
		pos_.x = DXE_WINDOW_WIDTH - CHARA_WIDTH;
	}
	else if (pos_.x < 0 + CHARA_WIDTH) {
		pos_.x = 0 + CHARA_WIDTH;
	}*/

}
