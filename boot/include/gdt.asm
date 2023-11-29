; (G)lobal (D)escriptor (T)able
gdt_start:

; Null Descriptor
gdt_null:
    dd 0x0
    dd 0x0

; Code Segment
gdt_code:
    dw 0xffff
    dw 0x0
    db 0x0
    db 10011010b
    db 11001111b
    db 0x0

; Data Segment
gdt_data:
    dw 0xffff
    dw 0x0
    db 0x0
    db 10010010b
    db 11001111b
    db 0x0

gdt_end:

gdt_descriptor:
    dw gdt_end - gdt_start - 1  ; GDT Size
    dd gdt_start                ; GDT Address

; Code Segment Offset in GDT
CODE_SEG equ gdt_code - gdt_start

; Data Segment Offset in GDT
DATA_SEG equ gdt_data - gdt_start