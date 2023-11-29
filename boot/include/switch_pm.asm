[bits 16]

; Routines to make the switch to (P)rotected (M)ode

switch_pm:
    cli                     ; Clear all interrupts

    lgdt[gdt_descriptor]    ; Load GDT

    mov eax, cr0
    or  eax, 0x1            ; Set (C)ontrol (R)egister's first bit
    mov cr0, eax            ; Switch

    jmp CODE_SEG:init_pm

; CPU is now in PM
[bits 32]

init_pm:

    mov ax, DATA_SEG
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    mov ebp, 0x9000
    mov esp, ebp

    jmp BEGIN_PM


