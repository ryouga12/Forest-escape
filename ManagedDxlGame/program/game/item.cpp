#include "item.h"
#include "../dxlib_ext/dxlib_ext.h"
#include <string>
#include"gamescene.h"

//�R���X�g���N�^
item::item(tnl::Vector3 item_pos)
{
	item_ghdl = LoadGraph("graphics/73938911.png");      //item�̉摜
	item_pos_ = item_pos;								 //item�̍��W

	//item���莞��se�̓ǂݍ���
	item_get_se = LoadSoundMem("sound/itemGet.mp3");
	
}

item::~item()
{
}

void item::update()
{

}

void item::draw(const Camera_& camera )
{

	
		tnl::Vector3 draw_pos = item_pos_ - camera.target_ + tnl::Vector3(DXE_WINDOW_WIDTH >> 1, DXE_WINDOW_HEIGHT >> 1, 0);
		// �A�C�e���̍��W�ɉ摜��`��
		DrawRotaGraph(draw_pos.x, draw_pos.y, 1.5f, 0 ,item_ghdl, true);
	
	
}
