EVERYTHING IS ON THE master BRANCH.

First assemble the boot.s file with this command:
'as --32 boot.s -o boot.o'
This is going to creat a boot.o file which you'll have to use later. Now for the kernel.c, compile it into an .o file with this command:
'gcc -m32 -c kernel.c -o kernel.o'
 After this link the two .o files into a single binary file:
 'ld -m elf_i386 -T linker.ld kernel.o boot.o -o start.bin'
 This will create a start.bin file. Now use this command to create folders:
 'mkdir -p isodir/boot/grub/'
 Now copy the start.bin file to the boot folder. You can also use this command:
 'cp start.bin isodir/boot/start.bin'
 And also copy the grub.cfg into the grub folder. You can also use this command:
 'cp grub.cfg isodir/boot/grub/grub.cfg'
 Now create the iso with this command:
'grub-mkrescue -o Boot.iso isodir'
If this isn't working try:
'grub2-mkrescue -o Boot.iso isodir'
Now you can start it using qemu:
'qemu-system-x86_64 -cdrom Boot.iso'
