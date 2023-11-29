[bits 16]

; Real Mode Print Routine

print16:
    pusha
    mov ah, 0x0e
.loop16:
    
    mov al, [bx]
    cmp al, 0
    je .done16
    int 0x10
    inc bx
    jmp .loop16

.done16:
    mov al, 0xa
    int 0x10
    mov al, 0xd
    int 0x10

    popa
    ret