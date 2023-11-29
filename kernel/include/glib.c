

typedef enum{
    WHITE = 0xf,
    RED = 0x4,
    BLUE
}RGB_t;


#define VMEM (byte *) 0xA0000
#define V_SZ 0xffff

/* Screen Properties */
#define X_SCR 320
#define Y_SCR 240

/* Fills the Screen to a Color*/
#define fillScr(c) mset(VMEM,V_SZ,c)


typedef struct {
    byte* data;
    int szx;
    int szy;
}GOBJ_t;


/* Draws a Pixel in Video Memory */
void putp(int x, int y, RGB_t clr){
    byte *vmem = VMEM + (y*X_SCR) + x;
    *vmem = clr;
}

/* Draws an Object onto the Screen */
void putObj(int x, int y, GOBJ_t obj){
    int i, j, k = 0;

    for (j = 0; j < obj.szy; j++){
        for (i = 0; i < obj.szx ; i++){
            putp(i + x,j + y,obj.data[k]);
            k++;
        }
    }
}