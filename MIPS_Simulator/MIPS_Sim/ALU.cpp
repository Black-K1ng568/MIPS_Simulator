#include "ALU.h"
void ALU::readALUop(bool* operation, bool* opcode, int constant) {
	if (compareArrayx2(operation, add)) {
		ADD()
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
	
	int carry;
	for (int i = 0; i < 32; i++) {
		if (((dataA[i]  && dataB[i]) == 1)  && (carry == 1)) {
			aluResult[i] = 1;
			carry = 1;
		}	
		
		if (((dataA[i] && dataB[i]) == 1) && (carry == 0)) {
			aluResult[i] = 0;
			carry = 0;
		}
		if (((dataA[i] ^ dataB[i]) == 1) && (carry == 0))  {
			aluResult[i] = 1;
			carry = 0;
		}
		if (((dataA[i] ^ dataB[i]) == 1) && (carry == 1)) {
			aluResult[i] = 0;
			carry = 1;
		}
		if (((dataA[i] == 0) && (dataB[i] == 0)) && (carry == 0)) {
			aluResult[i] = 0;
			carry = 0;
		}
		if (((dataA[i] == 0) && (dataB[i] == 0)) && (carry == 1)) {
			aluResult[i] = 1;
			carry = 0;
		}
	}
	overflow = carry;
}
void ALU::AND() {
	for (int i = 0; i < 32; i++) {
		aluResult[i] = dataA[i] & dataB[i];
	}


}
void ALU::NOR() {
	for (int i = 0; i < 32; i++) {
		aluResult[i] = !(dataA[i] | dataB[i]);
	}

}

void ALU::OR() {
	for (int i = 0; i < 32; i++) {
		aluResult[i] = dataA[i] | dataB[i];
	}
}

void ALU::ORI() {
	for (int i = 0; i < 32; i++) {
		aluResult[i] = dataA[i] & dataB[i];
	}
	
}

void ALU::SLL() {
	for (int i = 0; i < 32; i++) {
		aluResult[i] = dataA[i] << shamt;
	}
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
int booltoInteger(bool* array) {
	int value;

	for (int i = 31; i = 0; i--) {
		if (array[i] == 1) {
			value = 1 << i;
		}
		
	}
}