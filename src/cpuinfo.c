#include "include/variables.h"

void cpuid(int code, unsigned int *a, unsigned int *b, unsigned int *c, unsigned int *d) {
	asm volatile("cpuid"
			: "=a"(*a), "=b"(*b), "=c"(*c), "=d"(*d)
			: "a"(code));
}

void print_cpuinfo() {
	unsigned int eax, ebx, ecx, edx;
	char vendor[13];

	cpuid(0, &eax, &ebx, &ecx, &edx);
	*((unsigned int *)vendor) = ebx;
	*((unsigned int *)(vendor + 4)) = edx;
	*((unsigned int *)(vendor + 8)) = ecx;
	vendor[12] = '\0';

	print("CPU Vendor: ");
	print(vendor);
	end_line();

	cpuid(1, &eax, &ebx, &ecx, &edx);

	int family = ((eax >> 8) & 0xF) + ((eax >> 20) & 0xFF);
	int model = ((eax >> 4) & 0xF) + ((eax >> 12) & 0xF0);
	int stepping = eax & 0xF;

	char buffer[10];
	print("CPU Family: ");
	itoa(family, buffer);
	print(buffer);
	end_line();

	print("CPU Model: ");
	itoa(model, buffer);
	print(buffer);
	end_line();

	print("CPU Stepping: ");
	itoa(stepping, buffer);
	print(buffer);
	end_line();
}
