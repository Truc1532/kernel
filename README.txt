---DEPENDENCIES---
NASM - (Netwide assembler)
GCC - (GNU C Compiler)
xorriso
GRUB - (make sure you have the grub-mkrescue or grub2-mkrescue command avaible)
Virtualbox or qemu

---CREATING_THE_ISO---
I decided the create a shell script that builds and links the files for you because it would be too much commands to put in to compile and link manually.
To creating the iso is a pretty straight forward process. First create the build directories:
mkdir -p isodir/boot/grub/
Then move the kernel.efi and grub.cfg in those directories.
mv kernel.efi isodir/boot/
mv grub.cfg isodir/boot/grub/
Finally to create the iso itself run this command:
grub-mkrescue -o kernel.iso isodir/
If you decide to use qemu to run the kernel, enter this command:
qemu-system-i386 -cdrom kernel.iso
---ABOUT---
This is not a final release. For now this is just an example of how the system will look like.
I don't know yet when the official 1.0 version will be released since there is some stuff to improve/add. Like improving the code, adding features like a filesystem which will allow to read and write data.
