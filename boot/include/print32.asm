[bits 32]
VMEM    equ 0xb8000
BW      equ 0xf

print32:
    pusha
    mov edx, VMEM

.loop32:
    mov al, [ebx]
    mov ah, BW

    cmp al, 0
    je .done32
    
    mov [edx], ax
    add ebx, 1
    add edx, 2

    jmp .loop32

.done32:
    popa
    ret