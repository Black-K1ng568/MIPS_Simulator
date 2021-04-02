#include "Register.h"


bool* Register::getRegValueBool() {

	static bool value[32] = { 0 };
	for (int i = 0; i < 32; i++) {
		value[i] = reg[i];
	}
	return value;
}
int Register::getRegValueInt() {
	int value = 0;
	for (int i = 0; i < 32; i++) {
		int holder = reg[i];
		value |= holder << (32 - i - 1);
	}
	return value;
}
