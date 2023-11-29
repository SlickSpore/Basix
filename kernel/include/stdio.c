// Basic Implementation of STDIO.h from posix c

typedef unsigned char u8_t;

#define VMEM (u8_t*) 0xb8000

/* (T)erminal (COLORS) Enum*/
typedef enum {
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    DEFAULT,
    DGRAY,
    LBLUE,
    LGREEN,
    LCYAN,
    LRED,
    LMAGENTA,
    YELLOW,
    WHITE
}TCOLORS;


/* Print String Function with Color to vmem */
void pprintsColor(char *__str, TCOLORS __clr, int x, int y){
    u8_t *vmem =  VMEM;
    char *_c =__str;
    vmem += x*2+y*80*2;
    while (*_c != 0){
        *vmem = *_c; 
        vmem++;
        *vmem = __clr;
        vmem++;
        _c++;
    }

    *vmem = 0;
}

/* Puts a Character in vmem*/
void puts(char __chr, int x, int y){
    u8_t *vmem =  VMEM;
    vmem += x*2+y*80*2;
    *vmem = __chr;
    vmem++;
    *vmem = DEFAULT;
}

/* Clear vmem buffer */
void clearScreen(){
    u8_t *vmem = VMEM;
    int i = 0;

    for (i = 0; i < 80*25*2; i += 2){
        vmem[i]   = 0x0;
        vmem[i+1] = BLACK; 
    }   
}

/* Reads from the Specified port in Memory*/
u8_t inp(unsigned short port){
    u8_t result;
    __asm__("in %%dx,%%ax" : "=a"(result) : "d"(port));
    return result;
}

/* Writes to the Specified port in Memory*/
void outp(unsigned short port, u8_t data){
    __asm__("out %%ax,%%dx" : : "a"(port) , "d"(data));
}