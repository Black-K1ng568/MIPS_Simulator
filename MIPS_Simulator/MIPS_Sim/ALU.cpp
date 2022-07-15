#include "ALU.h"

ALU::ALU(bool AluOP[], size_t size1, bool function[], size_t size2) {
	for (int i = 0; i < size1; i++) {
		aluOp[i] = AluOP[i];
	}
	for (int j = 0; j < size2; j++) {
		funct[j] = function[j];
	}
	if ((funct[3]) == (1)) {
		aluControl[0] = 0;
		aluControl[1] = 1;
		aluControl[2] = 1;
		aluControl[3] = 1;
	}
	else if ((funct[1]) == 1) {
		aluControl[0] = 0;
		aluControl[1] = 1;
		aluControl[2] = 1;
		aluControl[3] = 0;
	}
	else if (funct[2] == 1)
	{
		aluControl[0] = 0;
		aluControl[1] = 0;
		aluControl[2] = 0;
		aluControl[3] = 0;
	}
	else if ((funct[0] == 1) && (funct[3] = 1)) {
		aluControl[0] = 1;
		aluControl[1] = 0;
		aluControl[2] = 0;
		aluControl[3] = 0;
	}
	else
	{
		aluControl[0] = 0;
		aluControl[1] = 0;
		aluControl[2] = 1;
		aluControl[3] = 0;
	}
	
}
ALU::ALU(bool AluOP[], size_t size) {
	for (int i = 0; i < size; i++) {
		aluOp[i] = AluOP[i];
	}

	if ((booltoInteger(aluOp, 2)) == (0)) {
		aluControl[0] = 0;
		aluControl[1] = 1;
		aluControl[2] = 0;
		aluControl[3] = 0;
			
	}
	else if ((booltoInteger(aluOp, 2)) == (1)) {
		aluControl[0] = 0;
		aluControl[1] = 1;
		aluControl[2] = 1;
		aluControl[3] = 0;
	}
}

ALU::ALU(bool AluOP[], size_t size1, bool function[], size_t size2, bool regA[], size_t size3, bool regB[], size_t size4) {
	for (int i = 0; i < size1; i++) {
		aluOp[i] = AluOP[i];
	}
	for (int j = 0; j < size2; j++) {
		funct[j] = function[j];
	}
	for (int k = 0; k < size3; k++)
		dataA[k] = regA[k];
	for (int l = 0; l < size4; l++)
		dataB[l] = regB[l];
}

void ALU::setdataA(bool A[], size_t size) {
	for (int i = 0; i < size; i++)
		dataA[i] = A[i];
}

void ALU::setdata(bool A[], size_t size1, bool B[], size_t size2) {
	for (int i = 0; i < size1; i++)
		dataA[i] = A[i];

	for (int j = 0; j < size2; j++)
		dataB[j] = B[j];
}

void ALU::readALU() { //Reads data to ALU And Performs operation
	 //initialise output to zero
	for (int i = 0; i < 16; i++)
		output[i] = 0;

	if (compareArray(aluOp, 2, add, 2)) {
		ADD();
	}
	if (compareArray(aluOp, 2, sub, 2)) {
		SUB();
	}
	if (compareArray(aluOp, 2,  extend, 2)) {
		if (compareArray(funct, 6,  andInstruction, 6)) {
			AND();
		}
		if (compareArray(funct, 6, nor, 6)) {
			NOR();
		}
		if (compareArray(funct, 6, orInstruction, 6)) {
			OR();
		}
		if (compareArray(funct, 6, slt, sizeof(slt))) {
			SLT();
		}
		if (compareArray(funct, 6, sll, sizeof(sll))) {
			SLL();
		}
		if (compareArray(funct, 6, srl , sizeof(srl))) {
			SRL();
		}
	}

}
bool* ALU::getdataA() {
	bool* dataAlocation = { nullptr };
	dataAlocation = dataA;

	return dataAlocation;

}


bool* ALU::outputResult() {
	bool* outputPointer;
	outputPointer = output;
	return outputPointer;
}


void ALU::ADD() {
	bool carryin = 0;
	for (int i = 0; i < 16;i++) {
		output[i] = (dataA[i] xor dataB[i]) xor carryin;
		carryin = (dataA[i] & dataB[i]) | (dataA[i] & carryin) | (dataB[i] & carryin);
	}
		overflow = carryin;
}
void ALU::AND() {
	for (int i = 0; i < 32; i++) {
		output[i] = dataA[i] & dataB[i];
	}

}
void ALU::NOR() {
	for (int i = 0; i < 32; i++) {
		output[i] = !(dataA[i] | dataB[i]);
	}
	
}

void ALU::OR() {
	for (int i = 0; i < 32; i++) {
		output[i] = dataA[i] | dataB[i];
	}
}

void ALU::ORI() {
	for (int i = 0; i < 32; i++) {
		output[i] = dataA[i] & dataB[i];
	}
}

void ALU::SLL() { //shift left logical
	for (int i = 0; i < 16; i++) {
		if (i + shamt >= 15) {
			break;
		}
		else {
			output[i + shamt] = dataB[i];
		}
	}
}

void ALU::SLT() { // set less than
	int intdataA, intdataB;
	intdataA = booltoInteger(dataA, sizeof(dataA));
	intdataB = booltoInteger(dataB, sizeof(dataB));

	if (intdataA < intdataB) {
		for (int i = 0; i < 16; i++)
			output[i] = 1;
	}
	else {
		for (int i = 0; i < 16; i++)
			output[i] = 0;
	}
	
}


void ALU::SRL() {
	for (int i = 15; i >=0; i--) {
		if (i - shamt >= 0) {
			break;
		}
		else {
			output[i - shamt] = dataB[i];
		}
	}
	
}

void ALU::SUB() {
	bool borrow=0;
	for (int i = 0; i < 32; i++) {
		output[i] = dataA[i] | dataB[i] | borrow;
		borrow = (dataA[i] & !borrow) | (dataA[i] & !dataB) | (dataB[i] & borrow);
	}

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


/*bool compareArrayx2(bool* opcode, bool* array) { // Compares input arrays 
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
*/
bool compareArray(bool array1[], size_t size1, bool array2[], size_t size2 ) {
	int z = 0;
	if (size1 == size2) {
		for (int i = 0; i < size1; i++) {
			if (array1[i] == array2[i])
				z++;
		}
		if (z == size1)
			return 1;
		else
		{
			return 0;
		}
	}
	else {
		return 0;
	}
}

 int booltoInteger(bool array[], size_t size) {
	 int value = 0;

	 for (int i = 0; i < size; i++) {
		 if (array[i]) {
			 value |= 1 << (size - i - 1);
		 }
		 //cout << "\nValue in Progress Number" << i << " : " << value << endl;

	 }
	 return value;
}
