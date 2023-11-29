/*

    Basix OS Functions Libraries

*/

/* Clears the Interrupt Vector */
void clearInterrupts(){
    __asm__("cli");
}

/* Memory Setter Implementation*/
void mset(byte* addr, int lenght, int value){
    int i; 
    for (i = 0; i < lenght; i++){
        *addr = value;
        addr++;
    }
}


