static inline unsigned char inb(unsigned short port) {
	unsigned char ret;
	asm volatile("inb %1, %0" : "=a"(ret) : "Nd"(port));
	return ret;
}

static inline void outb(unsigned short port, unsigned char val) {
	asm volatile("outb %0, %1" : : "a"(val), "Nd"(port));
}
