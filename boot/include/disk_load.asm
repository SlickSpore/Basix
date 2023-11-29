[bits 16]

; Real Mode BIOS Routine to read the disk

disk_load:
    push bx
    xor bx, bx  
    mov es, bx
    xor bx, bx
    mov ds, bx
    pop bx

    push dx
    mov ah, 0x02
    mov al, dh

    mov ch, 0
    mov dh, 0
    mov cl, 0x02

    int 0x13

    jc read_failed1

    pop dx
    cmp dh , al
    jne read_failed2
    ret

read_failed1:
    mov bx, READ_ERROR1
    call print16
    jmp $
read_failed2:
    mov bx, READ_ERROR2
    call print16
    jmp $

READ_ERROR1:
    db "Unable to Read The DISK!: ERROR 1", 0
READ_ERROR2:
    db "Unable to Read The DISK!: ERROR 2", 0