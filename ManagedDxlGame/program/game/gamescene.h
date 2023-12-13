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
	 
	int back_gph_hdl_ = 0;												// �w�i�摜  
	int goal_ghdl_ = 0;													// �S�[���̉摜
	int chip_gpc_hdl = 0;												// �}�b�v�`�b�v�̉摜
	Player* myPlayer = nullptr;											// �v���C���[�̃|�C���^�ϐ�
	MapChip* mapChip = nullptr;											// �}�b�v�`�b�v�̃|�C���^�ϐ�
	SystemManager* system_manager = nullptr;							// �V�X�e���}�l�[�W���[�̃|�C���^�ϐ�
	Enemy_Manager* enemy_manager[4];								    // �G�l�~�[�}�l�[�W���[�̃|�C���^�ϐ�
	item* Item[5];														// �A�C�e���N���X�̃|�C���^�ϐ�
	Camera_* camera = nullptr;											// �J�����N���X�̃|�C���^�ϐ�
	int GRAVITY = 5;													// �d��
	int FORCE = 0;														// ��

	std::string gpc_map_chip_hdls_pass_;								// �摜�p�X
	int map_chip_width_;												// �}�b�v�`�b�v�̕�
	int map_chip_height_;												// �}�b�v�`�b�v�̍���
	int map_chip_all_size_;												// �}�b�v�`�b�v�̑��t���[����
	int map_chip_x_size_;												// �}�b�v�`�b�v�̉��t���[����
	int map_chip_y_size_;												// �}�b�v�`�b�v�̏c�t���[����
	int map_chip_bottom = -5500;										// �}�b�v�`�b�v�̒�
	int* gpc_map_chip_hdls_;											// �摜�f�[�^�i�[
	int back_bgm = 0;													// ��ɗ���Ă���BGM

	std::string map_data_csv_pass_;										// �}�b�vCSV�f�[�^�̃p�X
	tnl::Vector3 pos_ = { 0, 0, 0 };
	tnl::Vector3 goal_pos_ = { 609 , -4093 , 0};						// �S�[���̍��W
	
	tnl::Vector3 item_pos  = {65 , 643 , 0};							// �A�C�e���̍��W1
	tnl::Vector3 item_pos2 = {1215 , -93 , 0};							// �A�C�e���̍��W2					
	tnl::Vector3 item_pos3 = {673 , -1563 , 0};							// �A�C�e���̍��W3
	tnl::Vector3 item_pos4 = {65 , -2043 , 0};							// �A�C�e���̍��W4
	tnl::Vector3 item_pos5 = {1045 , -4500 , 0};						// �A�C�e���̍��W5

	tnl::Vector3 enemypos  = {261 , -573 ,  0};							//�G�̍��W1
	tnl::Vector3 enemypos2 = {795 , -1149 ,  0 };						//�G�̍��W2
	tnl::Vector3 enemypos3 = {385 , -1566 , 0};							//�G�̍��W3
	tnl::Vector3 enemypos4 = {65 , -3869 ,  0};							//�G�̍��W4
	


	int  item_count;												    // �A�C�e���J�E���g
	int  item_count_max = 5;											// �A�C�e���̍ő�J�E���g��
	bool item_count_flag = false;										// �A�C�e���t���O


public:
	ScenePlay();
	~ScenePlay();

	void update(float delta_time) override;
	void draw() override;
	
	

	std::vector<std::vector<int>> map_csv;
	std::list<MapChip*> MapChips;
};
