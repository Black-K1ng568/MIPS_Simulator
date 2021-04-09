#include "ALU.h"
void ALU::readALUop(bool* operation, bool* opcode, int constant) {
	intdataA = booltoInteger(dataA);
	intdataB = booltoInteger(dataB);
	if (compareArrayx2(operation, add)) {
		ADD()
	}
	if (compareArrayx2(operation, sub)) {

	}
	if (compareArrayx2(operation, extend)) {
		if (compareArrayx6(opcode, andInstruction)) {
			
		}
		if (compareArrayx6(opcode, nor)) {

		}
		if (compareArrayx6(opcode, orInstruction)) {

		}


	}

}

int ALU::outputResult() {
	
	return output;
}


void ALU::ADD() {
	

	output = intdataA + intdataB;
	if (output > 2147483648)
		overflow = 1;
}
void ALU::AND() {
	for (int i = 0; i < 32; i++) {
		aluResult[i] = dataA[i] & dataB[i];
	}
	output = booltoInteger(aluResult);

}
void ALU::NOR() {
	for (int i = 0; i < 32; i++) {
		aluResult[i] = !(dataA[i] | dataB[i]);
	}
	output = booltoInteger(aluResult);
}

void ALU::OR() {
	for (int i = 0; i < 32; i++) {
		aluResult[i] = dataA[i] | dataB[i];
	}
	output = booltoInteger(aluResult);
}

void ALU::ORI() {
	for (int i = 0; i < 32; i++) {
		aluResult[i] = dataA[i] & dataB[i];
	}
	output = booltoInteger(aluResult);
}

void ALU::SLL() {
	intdataA << shamt;
}

void ALU::SLT() {
	if (intdataA < intdataB) {
		aluResult[0] = 1;
	}
	output = booltoInteger(aluResult);
}

void ALU::SLTI() {
	if (intdataA < intdataB) {
		aluResult[0] = 1;
	}
	aluResult[0] = 1;
}

void ALU::SRL() {
	intdataB >> shamt;
}

void ALU::SUB() {
	output= intdataA - intdataB;

}
void ALU::BEQ() {
	SUB();

}
void ALU::BNE() {
	SUB();

}
void ALU::LW() {
	ADD();

}
void ALU::SW() {
	ADD(); 

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
	 int value = 0;

	 for (int i = 0; i < 32; i++) {
		 if (array[i]) {
			 value |= 1 << (32 - i - 1);
		 }
		 //cout << "\nValue in Progress Number" << i << " : " << value << endl;

	 }
	 return value;
}