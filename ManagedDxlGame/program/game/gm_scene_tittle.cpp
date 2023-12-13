#include "../dxlib_ext/dxlib_ext.h"
#include "gm_main.h"
#include "gm_Manager.h"
#include "gm_scene_tittle.h"
#include "gm_scene_result.h"
#include "gamescene.h"
#include"Player.h"
#include "seane_explanation.h"


// �R���X�g���N�^
SceneTitle::SceneTitle() {
	//�摜�̓ǂݍ���
	test_back_ground_gfx_ = LoadGraph("graphics/2501060.png");
	//�T�E���h�̓ǂݍ���&����
	title_bgm = LoadSoundMem("sound/ks036.wav");
	PlaySoundMem(title_bgm, DX_PLAYTYPE_LOOP, true);
	
}
// �f�X�g���N�^
SceneTitle::~SceneTitle() {
	DeleteGraph(test_back_ground_gfx_);  //  �摜�̃f���[�g�����s�i�f���[�g���Ȃ��ƃ��������Ƀf�[�^���c��j
}

// �^�C�g���V�[�����̏���
void SceneTitle::update(float delta_time) {
	
	//�_�ŏ���
	string_flashing = string_flashing + 1;
	if (string_flashing == 30) {
		string_flashing = 0;
		flashing_flag = !flashing_flag;
	}


	
	//�V�[���J��
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)|| tnl::Input::IsPadDownTrigger(ePad::KEY_1)) {
		auto mgr = GameManager::GetInstance();
		StopSoundMem(title_bgm);//���y���~�߂�
		mgr->changeScene(new seane_explanation());
	}
}

// �^�C�g���V�[���̕`��
void SceneTitle::draw() {
	DrawRotaGraph(DXE_WINDOW_WIDTH / 2, DXE_WINDOW_HEIGHT / 2, 1.0f, 0, test_back_ground_gfx_, true);
	SetFontSize(50);
	DrawStringEx(430, 200, -1, "forest�@escape");
	SetFontSize(18);
	if (flashing_flag) {
		DrawStringEx(550, 300, -1, "press Enter\n\n   or\n\nRound button");
	}
	
	
}

