#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include"Camera.h"

class item {
public:
    item(tnl::Vector3 item_pos);
    ~item();

    void update();
    void draw(const Camera_& camera );


    const int ITEM_HEIGHT = 48;				//itemの高さ
    const int ITEM_WIDTH  = 63;				//itemの幅
    int item_get_se = 0;                    //item入手時のse
    

    tnl::Vector3 item_pos_ ;                //itemの座標
    int item_ghdl = 0;                      //itemの画像

private:

    
   

};