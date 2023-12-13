#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include"Camera.h"

class item {
public:
    item(tnl::Vector3 item_pos);
    ~item();

    void update();
    void draw(const Camera_& camera );


    const int ITEM_HEIGHT = 48;				//item‚Ì‚‚³
    const int ITEM_WIDTH  = 63;				//item‚Ì•
    int item_get_se = 0;                    //item“üè‚Ìse
    

    tnl::Vector3 item_pos_ ;                //item‚ÌÀ•W
    int item_ghdl = 0;                      //item‚Ì‰æ‘œ

private:

    
   

};