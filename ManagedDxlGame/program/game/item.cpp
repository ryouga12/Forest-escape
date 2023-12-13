#include "item.h"
#include "../dxlib_ext/dxlib_ext.h"
#include <string>
#include"gamescene.h"

//コンストラクタ
item::item(tnl::Vector3 item_pos)
{
	item_ghdl = LoadGraph("graphics/73938911.png");      //itemの画像
	item_pos_ = item_pos;								 //itemの座標

	//item入手時のseの読み込み
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
		// アイテムの座標に画像を描画
		DrawRotaGraph(draw_pos.x, draw_pos.y, 1.5f, 0 ,item_ghdl, true);
	
	
}
