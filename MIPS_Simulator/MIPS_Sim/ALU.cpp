#include "ALU.h"
void ALU::readALUop(bool* operation, bool* opcode) {
	if (compareArrayx2(operation, add)) {
		
	}
	if (compareArrayx2(operation, sub)) {

	}
	if (compareArrayx2(operation, extend)) {
		if (compareArrayx6(opcode, andInstruction)) {
			
		}
		if (compareArrayx6(opcode, nor))

	}

}

int ALU::outputResult() {


}
void ALU::ADD() {
	int overflow;
	int carry;
	for (int i = 0; i < 32; i++) {
		if (((dataA[i]  && dataB[i]) == 1)  &(carry == 1)) {
			aluResult[i] = 1;
			carry = 1;
		}	
		
		if (((dataA[i] && dataB[i]) == 1) & (carry == 0)) {
			aluResult[i] = 0;
			carry = 0;
		}
		if (((dataA[i] ^ dataB[i]) == 1) & (carry == 0))  {
			aluResult[i] = 1;
			carry = 0;
		}
		if (((dataA[i] ^ dataB[i]) == 1) & (carry == 1)) {
			aluResult[i] = 0;
			carry = 1;
		}
		if (())

	}

}
void ALU::AND() {


}
void ALU::NOR() {

}

void ALU::OR() {

}

void ALU::ORI() {

}

void ALU::SLL() {

}

void ALU::SLT() {

}

void ALU::SLTI() {

}

void ALU::SRL() {

}

void ALU::SUB() {


}


bool compareArrayx2(bool* opcode, bool* array) { // Compares input arrays 
	int z = 0;
	for (int i = 0; i < 2; i++) {
		if (opcode[i] == array[i])
			z++;
	}
	if (z == 2)
		return 1; //True if arrays are equal
	else {
		return 0;
	}
}
bool compareArrayx6(bool* opcode, bool* array) {
	int z = 0;
	for (int i = 0; i < 6; i++) {
		if (opcode[i] == array[i])
			z++;
	}
	if (z == 6)
		return 1;// True if arrays are equal
	else {
		return 0;
	}
}
