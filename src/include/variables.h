// global variables
extern char *video_mem;
extern int cursor_x;
extern int cursor_y;
extern const unsigned int screenWidth;
extern const unsigned int screenHeight;

// colors
extern const unsigned char blue;
extern const unsigned char green;
extern const unsigned char red;
extern const unsigned char yellow;
extern const unsigned char gray;
extern unsigned char color;

// functions
extern void update_cursor();
extern void clear();
extern void delay();
extern void end_line();
extern void print();
extern void itoa();
extern void execute_command();

// time/date functions
extern void print_date();
extern void print_time();

// cpuinfo functions
extern void cpuid();
extern void print_cpuinfo();
