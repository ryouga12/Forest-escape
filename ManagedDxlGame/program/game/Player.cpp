#include "Player.h"
#include"MapChip.h"
#include"gamescene.h"

//player�̃R���X�g���N�^
Player::Player()
{
	//�A�j���[�V�����̃��[�h����
	std::string files[DIR_MAX] = {
		"graphics/c1_anim_left.png",
		"graphics/c1_anim_right.png"
	};

	pos_ = { initialX,initialY,initialZ };

	for (int i = 0; i < 2; i++) {
		LoadDivGraph(
			files[i].c_str(),				// �摜�̃p�X
			Total_Frame,					// ���t���[����
			Horizontal_frame,				// ���t���[����
			Vertical_frame,					// �c�t���[����
			Horizontal_oneframe,			// �������� 1�t���[��������̕�
			Vertical_oneframe,				// �c������ 1�t���[��������̕�
			anim_hdls[i]);					// �摜�n���h�����i�[����z��);
	}

	//�W�����v�G�t�F�N�g�̓ǂݍ���
	LoadDivGraph("graphics/pipo-btleffect004.png", 7, 7, 1, 120, 120, jumpef);

	//�W�����v����se�̓ǂݍ���
	jump_se = LoadSoundMem("sound/jump.mp3");

}

//player�̃f�X�g���N�^
Player::~Player()
{
	
}

//Player�̍X�V����
void Player::Update(float deltatime)
{

	
}

//Player�̕`�揈��
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

//Player�̓��쏈��
void Player::PlyMove(float deltatime)
{

	prev_pos = pos_;

	

	//�G�t�F�N�g�̏���
	EFFCT_TIME += deltatime;
	if (EFFCT_TIME > 0.1f) {
		anim_ctrl_frame++;

		EFFCT_TIME = 0;
	}
	if (JUMPEFFCT_SIZE == anim_ctrl_frame) {
		jumpEf_flag = false;
		anim_ctrl_frame = 0;
	}

	//�A�j���[�V����
	anim_time_count += deltatime;
	if (anim_time_count > 0.1f) {
		anim_ctrl_frame++;
		anim_ctrl_frame %= 4;

		anim_time_count = 0;
	}

	if (play_move_flag) {
		//player�̓���
		if (tnl::Input::IsKeyDown(eKeys::KB_A) || tnl::Input::IsPadDown(ePad::KEY_LEFT)) {
			pos_.x -= 10;
		}
		if (tnl::Input::IsKeyDown(eKeys::KB_D) || tnl::Input::IsPadDown(ePad::KEY_RIGHT)) {
			pos_.x += 10;
		}

		//2�i�W�����v�̎���
		if (tnl::Input::IsKeyDownTrigger(eKeys::KB_SPACE) || tnl::Input::IsPadDownTrigger(ePad::KEY_0)) {
			if (jumpCount <= jumpMax) {
				gravity = -17.0f;
				//�W�����v���̉��̍Đ�
				PlaySoundMem(jump_se, DX_PLAYTYPE_BACK);
				//�W�����v�J�E���g�𑝂₷
				jumpCount++;
				//2��ڂ̃W�����v��
				if (jumpCount == dblJump) {
					//�W�����v���̃G�t�F�N�g�o�����߂̃t���O��true�ɂ���
					jumpEf_flag = true;
					//2��ڂ̃W�����v�͒Ⴍ�Ȃ�
					gravity = -13.0f;
				}

			}
		}

		//�A�j���[�V�����̓���
		if (tnl::Input::IsKeyDown(eKeys::KB_A) || tnl::Input::IsPadDownTrigger(ePad::KEY_LEFT))	anim_ctrl_dir = DIR_LEFT;
		if (tnl::Input::IsKeyDown(eKeys::KB_D) || tnl::Input::IsPadDownTrigger(ePad::KEY_RIGHT)) anim_ctrl_dir = DIR_RIGHT;


	}
	/*else if(tnl::Input::IsKeyDownTrigger(eKeys::KB_SPACE)) {
		force = -50;
		jumpCount++;
	}*/
	

	//�d�͂�player��������
	gravity += force_;
	pos_.y += gravity;
	

	//�v���C���[�������Ȃ��Ȃ������A2�b�o�����瓮����悤�ɂ���
	if (play_move_flag == false) {
		ply_stop_count += deltatime;
		if (ply_stop_count > ply_stop_count_max) {
			play_move_flag = true;
			ply_stop_count = 0;
		}
	}

	//�v���C���[���G�ɓ���������_�ł�����
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

	//��ʊO�ɂ����Ȃ��悤�ɂ���

	/*if (pos_.x > DXE_WINDOW_WIDTH - CHARA_WIDTH) {
		pos_.x = DXE_WINDOW_WIDTH - CHARA_WIDTH;
	}
	else if (pos_.x < 0 + CHARA_WIDTH) {
		pos_.x = 0 + CHARA_WIDTH;
	}*/

}
