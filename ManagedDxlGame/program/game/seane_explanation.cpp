#include "../dxlib_ext/dxlib_ext.h"
#include "gm_main.h"
#include "gm_Manager.h"
#include "seane_explanation.h"
#include "seane_explanation2.h"
#include "gamescene.h"

seane_explanation::seane_explanation()
{
	//�����p�̃v���C���[�摜�̓ǂݍ���
	plyer_explanation_ghdl       = LoadGraph("graphics/char_test.png");
	plyer_left_explanation_ghdl  = LoadGraph("graphics/c1_test_left.png");
	plyer_light_explanation_ghdl = LoadGraph("graphics/c1_right.png");
	
	//�����p�̃G�t�F�N�g�摜�̓ǂݍ���	
	ef_explanation_ghdl = LoadGraph("graphics/pipo-btleffect005.png");
}

seane_explanation::~seane_explanation()
{
}

void seane_explanation::update(float delta_time)
{
	//�V�[���J��
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN) || tnl::Input::IsPadDownTrigger(ePad::KEY_1)) {
		auto mgr = GameManager::GetInstance();
		mgr->changeScene(new seane_explanation2());
	}
}

void seane_explanation::draw()
{
	DrawStringEx(10, 10, -1, "�v���C���[����");
	DrawStringEx(300, 50, -1, "�v���C���[�̓����̓L�[�{�[�h�̃L�[���̓p�b�h�̏\���L�[�ōs���܂�");


	//�`��&����
	DrawRotaGraph(300, 200, 3, 0, plyer_left_explanation_ghdl, true);
	DrawStringEx (50, 100, -1, "�L�[�{�[�h�̏ꍇ��A\n�Q�[���p�b�h�̏ꍇ�͏\���L�[�̍���\n���ɓ����܂�");
	DrawRotaGraph(600, 200, 3, 0, plyer_explanation_ghdl, true);
	DrawStringEx (510, 300, -1, "�L�[�{�[�h�̏ꍇ��space\n�Q�[���p�b�h�̏ꍇ�́~�{�^����\n�W�����v���܂�");
	DrawRotaGraph(900, 200, 3, 0, plyer_light_explanation_ghdl, true);
	DrawStringEx (950, 100, -1, "�L�[�{�[�h�̏ꍇ��D\n�Q�[���p�b�h�̏ꍇ�͏\���L�[�̉E��\n�E�ɓ����܂�");
	DrawRotaGraph(300, 500, 3, 0, plyer_left_explanation_ghdl, true);
	DrawRotaGraph(300, 600, 2, 0, ef_explanation_ghdl, true);
	DrawStringEx (400, 500, -1, "�v���C���[��2��܂ŃW�����v�ł��܂�");
	DrawStringEx (700,680, -1, "���ɐi�ޏꍇ�́AEnterKey�܂��́Z�{�^���������Ă�������");

}
