#pragma once
#include <time.h>
#include <string>
#include "../dxlib_ext/dxlib_ext.h"
#include"Camera.h"

enum {
	ENEMY_LEFT,
	ENEMY_RIGHT,
	ENEMY_MAX
};



class Enemy_Manager {
public:
	Enemy_Manager(tnl::Vector3 pos);
	~Enemy_Manager();

	void update(float deltatime);
	void draw(const Camera_& camera);
	tnl::Vector3 pos_ = {};								   //“G‚ÌÀ•W
	const int ENEMY_HEIGHT = 63;						   //“G‚Ì‚‚³
	const int ENEMY_WIDTH =  63;						   //“G‚Ì•
	TNL_CO_SEQUENCE(Enemy_Manager, &Enemy_Manager::seq1);  //“G‚Ì“®‚«

	

private:
	int enemy_ghdl = 0;						//“G‚Ì‰æ‘œ
	
	
	bool seq1(const float delta_time);
	bool seq2(const float delta_time);

};