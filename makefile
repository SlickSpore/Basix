boot_dir 	= boot
out_dir  	= out
kernel_dir	= kernel
#requires root terminal

all: boot-sec kernel boot-bin boot-img run


boot-sec : $(boot_dir)/head_i386.asm 
	nasm -I $(boot_dir)/include/ $< -o $(out_dir)/boot.o 

kernel: boot-sec
	gcc -I $(kernel_dir)/include -m32 -ffreestanding -c -o $(kernel_dir)/bin/kernel.o $(kernel_dir)/kernel_i386.c -Wall   
	
	nasm $(kernel_dir)/kernel_entry_i386.asm -f elf -o $(kernel_dir)/bin/kernel_entry.o

	ld -melf_i386  -Ttext 0x1000  -o $(kernel_dir)/bin/kernel.bin \
	$(kernel_dir)/bin/kernel_entry.o \
	$(kernel_dir)/bin/kernel.o \
	--ignore-unresolved-symbol _GLOBAL_OFFSET_TABLE_ --oformat binary

boot-bin: boot-sec
	nasm -I $(boot_dir)/include $(boot_dir)/head_i386.asm -o $(out_dir)/boot.bin
	cat $(out_dir)/boot.bin $(kernel_dir)/bin/kernel.bin > $(out_dir)/boot-sec.bin
	

boot-img : kernel 

	mkfs.vfat -C $(out_dir)/boot.i 1440
	dd if=$(out_dir)/boot-sec.bin of=$(out_dir)/boot.i
	rm $(out_dir)/boot-sec.bin
	mv $(out_dir)/boot.i $(out_dir)/boot.img

run: $(out_dir)/boot.img
	qemu-system-x86_64 -drive format=raw,index=0,file=$<
