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
	int Total_Frame = 4;						//�v���C���[�̑��t���[��(4)
	int Horizontal_frame = 4;					//�v���C���[�̉��t���[��(4)
	int Vertical_frame = 1;						//�v���C���[�̏c�t���[��(1)
	int Horizontal_oneframe = 32;				//�������� 1�t���[��������̕�(32)
	int Vertical_oneframe = 48;					//�c������ 1�t���[��������̕�(48)
	tnl::Vector3 prev_pos = {};					//�ړ��O�̍��W
	float gravity = 0;							//�d��
	int jumpCount = 0;							//�W�����v�̃J�E���g
	int dblJump = 2;							//�_�u���W�����v
	int jumpMax = 1;							//�W�����v�̏����
	bool jumpEf_flag = false;					//�W�����v�G�t�F�N�g�̃t���O
	int  jump_se = 0;							//�W�����v��se
	bool play_move_flag = true;					//�v���C���[�̓����̐���
	const int CHARA_HEIGHT = 96;				//�L�����N�^�[�̍���
	const int CHARA_WIDTH = 64;					//�L�����N�^�[�̕�
	float ply_stop_count = 0;					//�v���C���[���~�܂��Ă���Ԃ̎���
	bool ply_ghdl_flag = true;					//�v���C���[�̉摜��\������
	bool ply_damage_flag = true;				//�v���C���[���_���[�W�t���O
	float ply_damage_count = 0;					//�v���C���[���~�܂��Ă��鎞��
	float ply_count = 0;						//�v���C���[���~�܂��Ă��鎞��

	

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
	const float initialX = (DXE_WINDOW_WIDTH - CHARA_WIDTH) / 2;	  // ��ʒ����ɔz�u
	const float initialY = DXE_WINDOW_HEIGHT - CHARA_HEIGHT / 2;      // ��ʉ����ɔz�u
	const float initialZ = 0;                                         // Z���W�͒ʏ�g�p���Ȃ��̂�0

	
	float EFFCT_TIME = 0;											  //�G�t�F�N�g�̕b��
    int JUMPEFFCT_SIZE = 10;									      //�G�t�F�N�g�̑���
	int jumpef[10];													  //�G�t�F�N�g�̐�
	
	float ply_stop_count_max = 2;										//����

	float force_ = 0.98;											  //��
	
};

