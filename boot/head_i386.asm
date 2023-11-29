[org 0x7c00]
[bits 16]

KERNEL_OFFSET equ 0x1000

mov [BOOT_DRIVE], dl

mov bx, 0
mov ss, bx
mov bp, 0x9000
mov sp, bp  


mov bx, start_msg
call print16

mov bx, KERNEL_OFFSET
mov dh, 0x8
mov dl, [BOOT_DRIVE]
call disk_load

; Enter Video Mode
mov al, 0x13
mov ah, 0x0
int 0x10

call switch_pm

jmp $

%include "disk_load.asm"
%include "print16.asm"
%include "print32.asm"
%include "switch_pm.asm"
%include "gdt.asm"

BEGIN_PM:

    call KERNEL_OFFSET
    jmp $

BOOT_DRIVE: db 0

start_msg:  
    db "Hello World From Basix 2", 0
read_success_msg:
    db "Disk Read: OK!", 0
pm_success_msg:
    db "CPU MODE: Protected", 0

times 510 - ($-$$) db 0
dw 0xaa55

stage2:
