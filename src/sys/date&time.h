unsigned char read_rtc_register(unsigned char reg) {
	outb(0x70, reg);
	return inb(0x71);
}

unsigned char bcd_to_binary(unsigned char bcd) {
	return ((bcd / 16) * 10) + (bcd & 0x0F);
}

void print_date() {
	unsigned char day = bcd_to_binary(read_rtc_register(0x07));
	unsigned char month = bcd_to_binary(read_rtc_register(0x08));
	unsigned char year = bcd_to_binary(read_rtc_register(0x09));

	char *months[] = {
		"January", "February", "March", "April", "May", "June",
		"July", "August", "September", "October", "November", "December"
	};

	char day_str[3];
	char year_str[5];

	itoa(day, day_str);
	itoa(2000 + year, year_str);

	print(day_str);
	if (day == 1 || day == 21 || day == 31) {
		print("st ");
	} else if (day == 2 || day == 22) {
		print("nd ");
	} else if (day == 3 || day == 23) {
		print("rd ");
	} else {
		print("th ");
	}

	print(months[month - 1]);
	print(" ");
	print(year_str);
}

void print_time() {
	unsigned char hours = bcd_to_binary(read_rtc_register(0x04));
	unsigned char minutes = bcd_to_binary(read_rtc_register(0x02));
	unsigned char seconds = bcd_to_binary(read_rtc_register(0x00));

	char time_buffer[9];
	time_buffer[0] = '0' + (hours / 10);
	time_buffer[1] = '0' + (hours % 10);
	time_buffer[2] = ':';
	time_buffer[3] = '0' + (minutes / 10);
	time_buffer[4] = '0' + (minutes % 10);
	time_buffer[5] = ':';
	time_buffer[6] = '0' + (seconds / 10);
	time_buffer[7] = '0' + (seconds % 10);
	time_buffer[8] = '\0';

	print(time_buffer);
}
