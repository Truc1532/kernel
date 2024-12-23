---DEPENDENCIES---
NASM - (Netwide assembler)
GCC - (GNU C Compiler)
xorriso
GRUB - (make sure you have the grub-mkrescue or grub2-mkrescue command avaible)
Virtualbox or qemu

---BUILDING---
First assemble the loader.asm file:
  nasm -f elf32 -o loader.o src/assembly/loader.asm
Then compile the main.c file:
  gcc -m32 -o kernel.o -c src/main.c -nostdlib -nostartfiles -nodefaultlibs
After that link the two .o files you just have created.
  ld -T linker.ld -m elf_i386 -o kernel.efi loader.o kernel.o
Now run this command to create the required directories:
  mkdir -p isodir/boot/grub/
Now move some files over to these directories
  mv kernel.efi isodir/boot/
  mv grub.cfg isodir/boot/grub/
Finally run the grub command to create an iso file:
  grub-mkrescue -o kernel.iso isodir/
To run the iso file you can either use qemu or virtualbox. If you decide to use qemu run this command:
  qemu-system-i386 -cdrom kernel.iso
