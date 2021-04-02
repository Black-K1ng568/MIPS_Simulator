#include "Control.h"

void Control::recieveInstruction(bool* opcode) {
	pcWriteControl = 1;
	pcWrite = 1;
	bool compare[5] = { 0, 0, 0, 0, 0 };
	if (compareArray(opcode, compare)) { // Compare Opcode to 000000
		aluOp = 1;
		aluSrcA = 1;
		aluSrcB = 1;

	}

}
void Control::sendData() {

}
bool compareArray(bool* opcode, bool* array) {
	int z = 0;
	for (int i = 0; i < 5; i++) {
		if (opcode[i] == array[i])
			z++;
	}
	if (z == 5)
		return 0;
	else {
		return 1;
	}
}

int Control::add() {
	
}

int Control::addi() {

}
int Control::andi() {

}
int Control::andInstruction() {

}
int Control::beq() {

}
int Control::bne() {

}
int Control::lbu() {

}
int Control::lhu() {

}
int Control::ll() {

}
int Control::lw() {

}
int Control::nor() {

}
int Control::ori() {

}
int Control::orInstruction() {

}
int Control::sb() {

}
int Control::sc() {

}
int Control::sh() {

}
int Control::sll() {

}
int Control::slt() {

}
int Control::slti() {

}
int Control::srl() {

}
int Control::sub() {

}
int Control::sw() {

}







