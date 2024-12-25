echo "Compiling..."
nasm -f elf32 -o loader.o src/assembly/loader.asm
gcc -m32 -o main.o -c src/main.c -nostdlib -nostartfiles -nodefaultlibs
gcc -m32 -o globals.o -c src/globals.c -nostdlib -nostartfiles -nodefaultlibs
gcc -m32 -o commands.o -c src/commands.c -nostdlib -nostartfiles -nodefaultlibs
gcc -m32 -o date\&time.o -c src/date\&time.c -nostdlib -nostartfiles -nodefaultlibs
gcc -m32 -o cpuinfo.o -c src/cpuinfo.c -nostdlib -nostartfiles -nodefaultlibs

echo "Linking..."
gcc -m32 -r globals.o date\&time.o cpuinfo.o commands.o main.o -o kernel.o -nostdlib -nostartfiles -nodefaultlibs
ld -T linker.ld -m elf_i386 -o kernel.efi loader.o kernel.o

echo "Done, you can create the iso with the instruction in the README.txt file"
