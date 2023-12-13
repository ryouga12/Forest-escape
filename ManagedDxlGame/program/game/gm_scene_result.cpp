#include "../dxlib_ext/dxlib_ext.h"
#include "gm_main.h"
#include "gm_Manager.h"
#include "gm_scene_result.h"
#include "gm_scene_tittle.h"
#include"gamescene.h"
#include"System_Manager.h"


// �R���X�g���N�^
SceneResult::SceneResult (int score , float time ){
	result_ghdl = LoadGraph("graphics/1021667.jpg");
	// �X�R�A�Ǝ��Ԃ��󂯎���ĕێ�����
	this->score_ = score;
	this->time_ = time;
	
	
	//�A�j���[�V�����̓ǂݍ���
	LoadDivGraph("graphics/congratulations.png", 10, 1, 10, 640, 480, clearmem);
	
}
// �f�X�g���N�^
SceneResult::~SceneResult() {
	DeleteGraph(result_ghdl);  //  �摜�̃f���[�g�����s�i�f���[�g���Ȃ��ƃ��������Ƀf�[�^���c��j
}


// �^�C�g���V�[�����̏���
void SceneResult::update(float delta_time) {

	//�G�t�F�N�g�̏���
	EFFCT_TIME += delta_time;
	if (EFFCT_TIME > 0.1f) {
		anim_ctrl_frame++;

		EFFCT_TIME = 0;
	}
	if (EFFCT_SIZE == anim_ctrl_frame) {
		/*clear_message_flag = false;*/
		anim_ctrl_frame = 0;
	}


	
	//�V�[���J��
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)|| tnl::Input::IsPadDownTrigger(ePad::KEY_1)) {
		auto mgr = GameManager::GetInstance();
		mgr->changeScene(new SceneTitle());
	}
}

// �^�C�g���V�[���̕`��
void SceneResult::draw() {

	DrawRotaGraph(DXE_WINDOW_WIDTH / 2, DXE_WINDOW_HEIGHT / 2, 1.0f, 0, result_ghdl, true);
	

	// �o�ߎ��Ԃ��擾�i�P�ʂ�b�ɕϊ����ĕ\���j
	int timeInSeconds = time_ / 1000;

	/*if (clear_message_flag) {
		DrawRotaGraph(DXE_WINDOW_WIDTH / 2, DXE_WINDOW_HEIGHT / 2, 0.5, 0, clearmem[anim_ctrl_frame], true);
	}*/

	// �X�R�A�ƌo�ߎ��Ԃ�`��
	SetFontSize(25);
	DrawStringEx(500, 300, 0, "Score: %d", score_);
	DrawStringEx(500, 360, 0, "�o�߂�������: %d seconds", timeInSeconds);
	SetFontSize(18);
	
}