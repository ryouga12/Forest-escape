#include "../dxlib_ext/dxlib_ext.h"
#include "gm_main.h"
#include"MapChip.h"
#include "gm_Manager.h"
#include "gamescene.h"
#include "gm_scene_result.h"
#include"Enemy_Manager.h"
#include"Player.h"
#include"item.h"



// �R���X�g���N�^
ScenePlay::ScenePlay() {

	back_gph_hdl_ = LoadGraph("graphics/back.png");				//�w�i�̓ǂݍ���
	goal_ghdl_ = LoadGraph("graphics/22061545.png");			//�S�[���̉摜�̓ǂݍ���
	myPlayer = new Player();
	system_manager = new SystemManager();
	camera = new Camera_();

	//�G�̃N���X�̕������ēǂݍ���
	enemy_manager[0] = new Enemy_Manager(enemypos);
	enemy_manager[1] = new Enemy_Manager(enemypos2);
	enemy_manager[2] = new Enemy_Manager(enemypos3);
	enemy_manager[3] = new Enemy_Manager(enemypos4);

	//�A�C�e���N���X�̕������ēǂݍ���
	Item[0] = new item(item_pos);
	Item[1] = new item(item_pos2);
	Item[2] = new item(item_pos3);
	Item[3] = new item(item_pos4);
	Item[4] = new item(item_pos5);


	// �}�b�v�`�b�v�̉摜�̃��[�h
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


	// �}�b�v�f�[�^�̃��[�h
	map_data_csv_pass_ = "map_chips.csv";
	map_csv = tnl::LoadCsv<int>(map_data_csv_pass_);
	


	//map_csv = tnl::LoadCsv<int>("map_chip.csv");

	//�}�b�v�`�b�v�ǂݍ���
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
	//BGM�̓ǂݍ���&�Đ�
	back_bgm = LoadSoundMem("sound/ks001.wav");
	PlaySoundMem(back_bgm, DX_PLAYTYPE_LOOP, true);
	 
	//�A�C�e���J�E���g�̏�����
	item_count = 0;
}
// �f�X�g���N�^
ScenePlay::~ScenePlay() {
	delete myPlayer;
	delete camera;
	DeleteGraph(back_gph_hdl_);				//  �摜�̃f���[�g�����s�i�f���[�g���Ȃ��ƃ��������Ƀf�[�^���c��j
	DeleteGraph(goal_ghdl_);				//  �摜�̃f���[�g�����s�i�f���[�g���Ȃ��ƃ��������Ƀf�[�^���c��j
}

// �v���C�V�[�����̏���
void ScenePlay::update(float delta_time) {

	//�v���C���[�̓���
	myPlayer->PlyMove(delta_time);
	//�G�̓���
	for (int i = 0; i < 4; i++) {
		if (enemy_manager[i]) {
			enemy_manager[i]->tnl_sequence_.update(delta_time);
		}
	}
	//�J�����̓���
	camera->update(myPlayer->pos_);
	//�}�b�v�`�b�v
	mapChip->Update();
	//�V�[���}�l�[�W���[�i�X�R�A�A�^�C���Ȃǁj
	system_manager->update(delta_time);
	int score = system_manager->getScore();
	int time =  system_manager->getTime();


	

	// �u���b�N�ƏՓ˔��� & �␳
	// �Q�[�����[�v���ł̓����蔻��̃`�F�b�N]
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

	//item�ƃv���C���[�̂����蔻��
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
	
	//�A�C�e����Max�ɂȂ�ƃt���O��true�ɂ���
	if (item_count == item_count_max) {
		item_count_flag = true;
	}

	//�v���C���[�ƓG�̂����蔻��
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
				//�v���C���[�̓������~�߂�
				myPlayer->play_move_flag = false;
				myPlayer->jumpEf_flag = false;
				myPlayer->ply_damage_flag = false;

			}
		}
	}

	
	
		/*if (checkCollision) {
			DrawString(500, 100, "��������", -1);
		}*/
	
	
	
	//�V�[���J��(�X�R�A�Ǝ��Ԃ����U���g��ʂɎ����Ă���)
	if (tnl::Input::IsKeyDown(eKeys::KB_W) || tnl::Input::IsPadDownTrigger(ePad::KEY_UP)) {
		if ((myPlayer->pos_.x == goal_pos_.x && myPlayer->pos_.y == goal_pos_.y && item_count == item_count_max)) {
			auto mgr = GameManager::GetInstance();
			StopSoundMem(back_bgm);
			mgr->changeScene(new SceneResult(score, time));
		}
	}

}



// �v���C�V�[���̕`��
void ScenePlay::draw() {

	DrawStringEx(10, 10, -1, "�v���C���");
	//�w�i
	DrawRotaGraph(700, 100, 3,0, back_gph_hdl_, true);							

	//�S�[���̕`��
	tnl::Vector3 draw_pos = goal_pos_ - camera->target_ + tnl::Vector3(DXE_WINDOW_WIDTH >> 1, DXE_WINDOW_HEIGHT >> 1, 0);
	DrawRotaGraph(draw_pos.x, draw_pos.y, 0.1f, 0, goal_ghdl_, true);

	//�v���C���[�̕`��
	myPlayer->Draw(*camera);

	/*for (int y = 0; y < map_csv.size(); ++y) {
		for (int x = 0; x < map_csv[y].size(); ++x) {
			DrawGraph(x * map_chip_width_ , DXE_WINDOW_HEIGHT + y * map_chip_height_, gpc_map_chip_hdls_[map_csv[y][x]], true);
		}
	}*/

	//// �}�b�v�̕\��
	//for (int y = 0; y < map_data_.size(); ++y) {
	//	for (int x = 0; x < map_data_[y].size(); ++x) {
	//		DrawGraph( x * map_chip_width_, (-3200) + DXE_WINDOW_HEIGHT + y * map_chip_height_, gpc_map_chip_hdls_[map_data_[y][x]], true);
	//	}
	//}
	// �`�掞�ɃJ�����̈ʒu���I�t�Z�b�g�Ƃ��ēK�p


	//Mapchip�̕`��
	for (auto mapChip : MapChips) {
		mapChip->draw(*camera);
	}

	//DrawStringEx(10, 50, -1, "�v���C���[�̍��Wx�@: %f", myPlayer->pos_.x);
	/*DrawStringEx(500, 50, -1, "�v���C���[�̍��Wy�@: %f", myPlayer->pos_.y);
	DrawStringEx(1000, 50, -1, "gravity : %f", myPlayer->gravity);*/
	SetFontSize(22);
	DrawStringEx(1000, 50, -1, "�A�C�e�� : %d / 5", item_count);
	DrawStringEx(430, 50, -1, "�N���A���� : �A�C�e����5������\n             �S�[����ڎw���I");
	
	
	if (goal_pos_.x == myPlayer->pos_.x && goal_pos_.y == myPlayer->pos_.y) {
		if (item_count_flag) {
			DrawStringEx(400, 200, -1, "�v�L�[���͏\���L�[�̏�������Ă�������");
		}
		else {
			DrawStringEx(500, 200, -1, "�A�C�e��������܂���");
		}
	}
	
	//�A�C�e���̕`��
	for (int i = 0; i < 5; i++) {
		if(Item[i])Item[i]->draw(*camera);
	}
	//�V�X�e���}�l�[�W���[�̕`��
	system_manager->draw();

	//�G�̕`��
	for (int i = 0; i < 4; i++) {
		if (enemy_manager[i])enemy_manager[i]->draw(*camera);
	}


	SetFontSize(18);
}

