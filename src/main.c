char screenWidth = 80;
char screenHeight = 25;
char *video_mem = (char *)0xB8000;
int cursor_x = 0;
int cursor_y = 0;

#define KEYBOARD_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64

static inline unsigned char inb(unsigned short port) {
	unsigned char ret;
	asm volatile("inb %1, %0" : "=a"(ret) : "Nd"(port));
	return ret;
}

static inline void outb(unsigned short port, unsigned char val) {
    asm volatile("outb %0, %1" : : "a"(val), "Nd"(port));
}

void update_cursor() {
    unsigned short position = cursor_y * screenWidth + cursor_x;

    outb(0x3D4, 0x0E);
    outb(0x3D5, (unsigned char)(position >> 8));

    outb(0x3D4, 0x0F);
    outb(0x3D5, (unsigned char)(position & 0xFF));
}

void clear() {
    for (int i = 0; i < screenWidth * screenHeight * 2; i += 2) {
        video_mem[i] = ' ';
        video_mem[i + 1] = 0x07;
    }
    cursor_x = 0;
    cursor_y = 0;
    update_cursor();
}

void delay(int count) {
	for (int i = 0; i < count; i++) {
		asm volatile("nop");
	}
}

void end_line() {
    cursor_x = 0;
    cursor_y++;
    if (cursor_y >= screenHeight) {
        clear();
    }
    update_cursor();
}

void print(char *text) {
    while (*text) {
        if (*text == '\n') {
            end_line();
        } else if (*text == '\b') {
	       if (cursor_x > 0) {
	       		cursor_x--;
	       } else if (cursor_y > 0) {
		       cursor_y--;
		       cursor_x = screenWidth - 1;
	       }

	       int offset = (cursor_y * screenWidth + cursor_x) * 2;
	       video_mem[offset] = ' ';
	       video_mem[offset + 1] = 0x07;
	} else {
            int offset = (cursor_y * screenWidth + cursor_x) * 2;
            video_mem[offset] = *text;
            video_mem[offset + 1] = 0x07;
            cursor_x++;
        }

        if (cursor_x >= screenWidth) {
            end_line();
        }

        text++;
    }
    update_cursor();
}

void itoa(int value, char *buffer) {
	char temp[10];
	int i = 0;
	if (value == 0) {
		buffer[0] = '0';
		buffer[1] = '\0';
		return;
	}
	while (value > 0) {
		temp[i++] = '0' + (value % 10);
		value /= 10;
	}
	for (int j = 0; j < i; j++) {
		buffer[j] = temp[i - j - 1];
	}
	buffer[i] = '\0';
}

#include "sys/date&time.h"

char getchar() {
	unsigned char scancode;

	while ((inb(KEYBOARD_STATUS_PORT) & 0x01) == 0);

	scancode = inb(KEYBOARD_PORT);

	if (scancode & 0x80) {
		return 0;
	}

    	char ascii_map[128] = {
        	0,  27, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b', '\t',
        	'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n', 0,
        	'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`', 0, '\\', 'z', 'x',
        	'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0, '*', 0, ' ', 0, 0, 0, 0,
    	};

	return ascii_map[scancode];
}

void gets(char *buffer, int max_len) {
	int idx = 0;
	char ch;
	print(">");


	while (1) {
		ch = getchar();

		if (ch == 0) {
			continue;
		}

		if (ch == '\n') {
			buffer[idx] = '\0';
			end_line();
			break;
		} else if (ch == '\b' && idx > -1) {
			if (cursor_x > 1) {
				idx--;
				buffer[idx] = '\0';
				print("\b");
			}
		} else if (ch != 0 && idx < max_len - 1) {
			buffer[idx++] = ch;
			char str[2] = {ch, '\0'};
			print(str);
		}
	}
}

#include "strings.h"
#include "commands.c"

void kernel_main() {
    clear();
    print("Welcome\n");
    print("Date: ");
    print_date();
    end_line();
    print("Time: ");
    print_time();
	
    char input[100];
    end_line();
    while (1) {
        gets(input, sizeof(input));

        execute_command(input);
    }
}
