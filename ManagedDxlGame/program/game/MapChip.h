#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "gm_Manager.h"
#include"Player.h"



class MapChip {
public:
	MapChip(const tnl::Vector3& pos , int gfx_hdl );
	~MapChip();
	void Update();
	void draw(const Camera_& camera);


	static constexpr float CHIP_SIZE = 32;				//マップチップのサイズ
	int chip_gpc_hdl = 0;								//画像のhdl
	tnl::Vector3 pos_ = { 0, 0, 0 };					//マップチップのpos
	
	

};


