#include "vgainit.c"

uint16 vga_entry(unsigned char ch, uint8 fore_color, uint8 back_color) {
      	uint16 ax = 0;
	uint16 ah = 0, al = 0;

	ah = back_color;
	ah <<= 4;
	ah |= fore_color;
 	ax = ah;
	ax <<= 8;
	al = ch;
	ax |= al;
	
	return ax;
}

void clear_vga_buffer(uint16 **buffer, uint8 fore_color, uint8 back_color) {
	uint32 x;
	for (x = 0; x < BUFSIZE; x++) {
		(*buffer)[x] = vga_entry(NULL, fore_color, back_color);
	}
}

void init_vga(uint8 fore_color, uint8 back_color) {
	vga_buffer = (uint16*)VGA_ADDRESS;
	clear_vga_buffer(&vga_buffer, fore_color, back_color);
}

void kernel_entry() {
	init_vga(WHITE, BLACK);

	vga_buffer[0] = vga_entry('H', WHITE, BLACK);
	vga_buffer[1] = vga_entry('e', WHITE, BLACK);
  	vga_buffer[2] = vga_entry('l', WHITE, BLACK);
  	vga_buffer[3] = vga_entry('l', WHITE, BLACK);
  	vga_buffer[4] = vga_entry('o', WHITE, BLACK);
  	vga_buffer[5] = vga_entry(' ', WHITE, BLACK);
  	vga_buffer[6] = vga_entry('W', WHITE, BLACK);
  	vga_buffer[7] = vga_entry('o', WHITE, BLACK);
  	vga_buffer[8] = vga_entry('r', WHITE, BLACK);
	vga_buffer[9] = vga_entry('l', WHITE, BLACK);
  	vga_buffer[10] = vga_entry('d', WHITE, BLACK);
}
