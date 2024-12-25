global loader
extern kernel_main

MAGIC equ 0x1BADB002
FLAGS equ 0x3
CHECKSUM equ -(MAGIC+FLAGS)

section .text
align 4
dd MAGIC
dd FLAGS
dd CHECKSUM

loader:
	call kernel_main
	cli 

keep_doing_shit_stupid_ahh_bitch:
	hlt
	jmp keep_doing_shit_stupid_ahh_bitch
