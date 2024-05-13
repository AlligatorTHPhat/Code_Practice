#include <iostream>

using namespace std;

bool is_lower(char c) {
	return c >= 'a' && c <= 'z';
}

bool is_upper(char c) {
	return c >= 'A' && c <= 'Z';
}

bool is_alpha(char c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool is_digit(char c) {
	return (c >= '0' && c <= '9');
}

char to_lower(char c) {
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return;
}

char to_lower(char c) {
	if (c >= 'a' && c <= 'z')
		c += 32;
	return;
}
