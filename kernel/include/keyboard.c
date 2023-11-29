/*

    Keyboard Driver Library
         For Basix OS

*/

#define KPORT 0x60
#define isSet(var,pos) ((var) & (1<<(pos)))

enum {
    Q=0x10,
    W=0x11,
    E=0x12,
    R=0x13,
    T=0x14,
    Y=0x15,
    U=0x16,
    I=0x17,
    O=0x18,
    P=0x19,

    A=0x1E,
    S=0x1F,
    D=0x20,
    F=0x21,
    G=0x22,
    H=0x23,
    J=0x24,
    K=0x25,
    L=0x26,
    
    Z=0x2C,
    X=0x2F,
    C=0x30,
    V=0x31,
    B=0x32,
    N=0x33,
    M=0x34,

    SPACE =0x39,
    RETURN=0x1C
    
}KEYS;


/*  This Function Gets a Scan Code
    From keyboard buffer */
u8_t getScanCode(){
    return inp(KPORT);
}

/* This Function Gets an Array of
   Characters from keyboard */
char SgetChr(){               //(S)ecure (get) (Chr)ar
    char chars[]={
        0,0,'1','2','3','4','5','6','7','8','9','0','-','=',0,
        0,'Q','W','E','R','T','Y','U','I','O','P','[',']',0,
        0,'A','S','D','F','G','H','J','K','L',';','\'',0,0,
        0,'Z','X','C','V','B','N','M',',','.'
    };

    char c;
    
    while(!isSet(getScanCode(),7));
    while(isSet(getScanCode(),7));
    c = chars[getScanCode()];
    return c;
}