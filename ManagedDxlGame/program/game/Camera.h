#pragma once
#include "../dxlib_ext/dxlib_ext.h"

class Camera_ {
public:
	Camera_();
	~Camera_();

	void update(tnl::Vector3 target_pos);
	void draw();

	tnl::Vector3 target_ = { 0, 0, 0 };
private:

	int MAP_HEIGHT = 5000;

};

