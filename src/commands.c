void execute_command(char *command) {
    if (string_equals(command, "clear")) {
        clear();
    } else if (string_equals(command, "time")) {
        print("Time: ");
        print_time();
        end_line();
    } else if (string_equals(command, "reboot")) {
	    print("Rebooting...");
	    delay(100000000);
	    outb(0x64, 0xFE);
    } else if (string_equals(command, "help")) {
	    print("clear - clear the screen\n");
	    print("time - displays the current time\n");
	    print("date - displays the current date\n");
	    print("reboot - reboot your device\n");
	    print("shutdown - shutdown your device\n");
    } else if (string_equals(command, "date")) {
	    print("Date: ");
	    print_date();
	    end_line();
    } else if (string_equals(command, "shutdown")) {
	    print("Shuting down...");
	    delay(100000000);
	    asm volatile("int $0x15" : : "a"(0x5307));
	   
	   print("System failed to shutdown\n"); 
    } else {
        print("Unknown command: ");
        print(command);
        end_line();
    }
}

