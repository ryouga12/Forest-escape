#include "MapChip.h"
#include "../dxlib_ext/dxlib_ext.h"
#include <string>
#include"gamescene.h"

MapChip::MapChip(const tnl::Vector3& pos , int gfx_hdl) : pos_(pos) 
{
	chip_gpc_hdl = gfx_hdl;
	pos_ = pos;
	
}

MapChip::~MapChip()
{

}

void MapChip::Update()
{

}

void MapChip::draw(const Camera_& camera)
{
	tnl::Vector3 draw_pos = pos_ - camera.target_ + tnl::Vector3(DXE_WINDOW_WIDTH >> 1, DXE_WINDOW_HEIGHT >> 1, 0);
	DrawRotaGraph(draw_pos.x, draw_pos.y, 1, 0, chip_gpc_hdl, true);
}
