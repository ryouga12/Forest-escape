#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include"Camera.h"

class item {
public:
    item(tnl::Vector3 item_pos);
    ~item();

    void update();
    void draw(const Camera_& camera );


    const int ITEM_HEIGHT = 48;				//item�̍���
    const int ITEM_WIDTH  = 63;				//item�̕�
    int item_get_se = 0;                    //item���莞��se
    

    tnl::Vector3 item_pos_ ;                //item�̍��W
    int item_ghdl = 0;                      //item�̉摜

private:

    
   

};