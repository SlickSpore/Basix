#include "stdio.c"
#include "keyboard.c"

void __main(){
    char str[] = "Hello World From Basix OS v2";
    char str2[] = "Starting a Shell!";
    char c;
    int x = 0;

    clearScreen();
    pprintsColor(str, YELLOW, 0, 0);
    pprintsColor(str2,DEFAULT, 0, 1);
    while(1){
        c = SgetChr();
        puts(c,x,0);
        x++;
    }
}

void putpixel(int pos_x, int pos_y, unsigned char VGA_COLOR)
{
    unsigned char* location = (unsigned char*)0xA000 + 320 * pos_y + pos_x;
    *location = VGA_COLOR;
}

void main(){
    int x, y;
    //clearScreen();
    x = 0;
    y = 0;

    for (int j = 0; j < 200; j++){
        putpixel(x,y,j);
        x++;
        y++;
    }
}