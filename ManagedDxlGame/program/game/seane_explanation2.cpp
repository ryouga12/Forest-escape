#include "../dxlib_ext/dxlib_ext.h"
#include "gm_main.h"
#include "gm_Manager.h"
#include "seane_explanation2.h"
#include "gamescene.h"

seane_explanation2::seane_explanation2()
{
	enemy_explanation_ghdl = LoadGraph("graphics/dekakabocha.png");
	item_explanation_ghdl =  LoadGraph("graphics/73938911.png");
}

seane_explanation2::~seane_explanation2()
{
}

void seane_explanation2::update(float delta_time)
{
	//�V�[���J��
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN) || tnl::Input::IsPadDownTrigger(ePad::KEY_1)) {
		auto mgr = GameManager::GetInstance();
		mgr->changeScene(new ScenePlay());
	}
}

void seane_explanation2::draw()
{
	DrawStringEx(10, 10, -1, "�G�̐���&�A�C�e������");
	//�G�̕`��&����
	DrawRotaGraph(300, 200, 2, 0, enemy_explanation_ghdl, true);
	DrawStringEx(400, 200, -1, "��ʏ�ɂ͓G�����܂�\n�v���C���[���G�ɓ�����ƁA2�b�ԓ����Ȃ��Ȃ�܂�");
	//�A�C�e���̕`��&����
	DrawRotaGraph(300, 400, 2, 0, item_explanation_ghdl, true);
	DrawStringEx (400, 380, -1, "��ʏ�ɂ̓A�C�e���������Ă��܂�\n�A�C�e���������ƃN���A�ł��܂���\n�A�C�e����5���肵�āA�S�[����ڎw���Ă�������\n�S�[���ɂ͔�������܂�");
	//�N���A����
	DrawStringEx(400, 550, -1, "�N���A�������̕b���ɂ���āA�X�R�A���ϓ����܂�\n�����X�R�A��ڎw���܂��傤�I");
	//�V�[���J�ڂ̐���
	DrawStringEx(700, 660, -1, "���ꂩ��Q�[�����n�܂�܂�\n���ɐi�ޏꍇ�́AEnterKey�܂��́Z�{�^���������Ă�������");
}
