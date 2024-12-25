int string_equals(char *str1, char *str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *str1 == *str2;
}

int starts_with(char *str, char *prefix) {
	while (*prefix) {
		if (*str != *prefix) {
			return 0;
		}

		str++;
		prefix++;
	}
	return 1;
}
