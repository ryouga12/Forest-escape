#include <time.h>
#include <string>
#include <numbers>
#include "Enemy_Manager.h"
#include "../dxlib_ext/dxlib_ext.h"
#include"Camera.h"

//コンストラクタ
Enemy_Manager::Enemy_Manager(tnl::Vector3 pos)
{
	//敵の画像の読み込み
	enemy_ghdl = LoadGraph("graphics/dekakabocha.png");
	
	
	pos_ = pos;
	
	 
}

//デストラクタ
Enemy_Manager::~Enemy_Manager()
{


}

//毎フレーム実行
void Enemy_Manager::update(float deltatime)
{



	
}

//描画
void Enemy_Manager::draw(const Camera_& camera)
{
	tnl::Vector3 draw_pos = pos_ - camera.target_ + tnl::Vector3(DXE_WINDOW_WIDTH >> 1, DXE_WINDOW_HEIGHT >> 1, 0);
	DrawRotaGraph(draw_pos.x, draw_pos.y, 1, 0, enemy_ghdl, true);
	
}

//敵の動き
bool Enemy_Manager::seq1(const float delta_time)
{
	DrawStringEx(0, 0, -1, "seq1");

	TNL_SEQ_CO_TIM_YIELD_RETURN(5, delta_time, [&]() {
		pos_.x += 1;
		});

	


	tnl_sequence_.change(&Enemy_Manager::seq2);

	TNL_SEQ_CO_END;
}

bool Enemy_Manager::seq2(const float delta_time)
{
	DrawStringEx(0, 0, -1, "seq2");

	TNL_SEQ_CO_TIM_YIELD_RETURN(5, delta_time, [&]() {
		pos_.x -= 1;
		});
	

	tnl_sequence_.change(&Enemy_Manager::seq1);

	TNL_SEQ_CO_END;
}
