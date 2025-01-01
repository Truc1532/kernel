---DEPENDENCIES---
NASM - (Netwide assembler)
GCC - (GNU C Compiler)
xorriso
GRUB - (make sure you have the grub-mkrescue or grub2-mkrescue command avaible)
Virtualbox or qemu

---EMULATING---
If you decide to use qemu to run the kernel, enter this command:
qemu-system-i386 -cdrom kernel.iso
---ABOUT---
This is not a final release. For now this is just an example of how the system will look like.
I don't know yet when the official 1.0 version will be released since there is some stuff to improve/add. Like improving the code, adding features like a filesystem which will allow to read and write data.
