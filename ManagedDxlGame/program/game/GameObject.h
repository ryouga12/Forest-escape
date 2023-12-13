#pragma once
#include <time.h>
#include <string>
#include "../dxlib_ext/dxlib_ext.h"

class GameObject {
public:
	virtual void Update(float delta_time);
	virtual void Draw(float delta_time);
};