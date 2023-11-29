/*
    Basix Basic Kernel
*/
#include "types.c"
#include "glib.c"
#include "basix.c"

void main(){
    int i;

    byte sprite1[] = {
        4,0,0,0,0,0,0,0,0,0,
        0,4,4,4,0,0,0,0,0,0,
        0,0,4,4,4,4,0,0,0,0,
        0,0,0,4,4,4,4,0,0,0,
        0,0,0,0,4,4,4,4,4,0,
        0,0,0,0,0,4,4,4,4,4,
        0,0,0,0,0,0,4,0,0,0,
        0,0,0,0,0,0,0,4,0,0,
        0,0,0,0,0,0,0,0,4,0,
        0,0,0,0,0,0,0,0,0,4
    };

    GOBJ_t obj1 = {sprite1, 10, 10};


    fillScr(WHITE);

    putObj(10,10,obj1);
}