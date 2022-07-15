#include "Control.h"
// Will add timings in main
//Boolean Arrays are used to better simulate registers, plus avoids the values ending up in unknown states as can only be true or false
Control::Control() {
	pcSource[0] = 0;
	pcSource[1] = 0;
	pcWriteCond = 0;
	memRead = 1;
	aluSrcA = 0;
	iorD = 0;
	irWrite = 1;
	aluSrcB[0] = 1;
	aluSrcB[1] = 0;
	pcWrite = 1;
}

void Control::s0(bool input[], size_t size) {
	pcSource[0] = 0;
	pcSource[1] = 0;
	pcWriteCond = 0;
	memRead = 1;
	aluSrcA = 0;
	iorD = 0;
	irWrite = 1;
	aluSrcB[0] = 1;
	aluSrcB[1] = 0;
	pcWrite = 1;
}
void Control::s1() {
	
	aluSrcA = 0;
	aluSrcB[1];
	aluSrcB[1];
	
	//bool compare[6] = { 0, 0, 0, 0, 0, 0 };
	
	/* The If statement is unnecessary can just have different function*/

	/*if (compareArray(opcode, sizeof(opcode), rInstruct, 6)) { // Compare Opcode to 000000
			aluOp[0] = 0;
			aluOp[1] = 1;
			aluSrcA = 1;
			aluSrcB[0] = 0;
			aluSrcB[1] = 0;
			pcWriteCond = 1;
		}
		
	if (compareArray(opcode, sizeof(opcode), addi, sizeof(addi))) { // Add Immediate
		aluOp[1] = 1;
		aluOp[0] = 0;
		aluSrcA = 1;

	}
	if (compareArray(opcode, sizeof(opcode),  ori, 6)) { //or immediate
		aluOp[0] = 1; // Alu Op = 10 determined by funct
		aluSrcA = 1;
		// Alu Src B = 01, I -type instruction
	}
	
	if (compareArray(opcode, 6, addi, 6)) { // And Immediate
		aluOp[0] = 1;
		aluSrcA = 1;
	}
	if (compareArray(opcode, 6, beq, 6)) { // branch if Equal
		aluOp[1] = 1;
		aluSrcA = 1;
		aluSrcB[0] = 1; // Alu Src B = 11 sign extend signal
		pcSource[0] = 0;
		pcSource[1] = 1;

	}
	if (compareArray(opcode, 6, bne, 6)) { // Branch if not equal
		aluOp[1] = 1;
		aluSrcA = 1;
		aluSrcB[0] = 1; // Alu Src B = 11 sign extend signal

	}
	
	if (compareArray(opcode, 6,  j, 6)) { //jump
		
		pcSource[0] = 1;
		
	}
	if (compareArray(opcode, 6, lw, 6)) { //load word
		//Alu Op is 00
		aluSrcA = 1;
		aluSrcB[1] = 0;
		aluSrcB[0] = 1; // Alu Src B = 10 load word

		regWrite = 1;
		memRead = 1;
		iorD = 1;

		memToReg = 1;
		regDst = 0;

	}
	if (compareArray(opcode, 6, slti, 6)) { //Set less than immediate
		aluOp[1] = 1;
		aluSrcA = 1;
		aluSrcB[1] = 0;

		regDst = 1;
		memToReg = 0;
		regWrite = 1;

	}
	
	
	if (compareArray(opcode, 6, sw, 6)) { // Store Word
		aluSrcA = 1;
		aluSrcB[1] = 0;
		aluSrcB[0] = 1;

		memWrite = true;
		iorD = 1;

			
	}*/
	

}
void Control::s2() {
	aluOp[0] = 0;
	aluOp[1] = 0;
	aluSrcA = 1;
	aluSrcB[0] = 0;
	aluSrcB[1] = 1;
	
}
void Control::s3() {
	memRead = 1;
	iorD = 1;
}
void Control::s4() {
	regDst = 0;
	regWrite = 1;
	memToReg = 1;
}
void Control::s5() {
	memWrite = 1;
	iorD = 1;
}

void Control::s6() {
	aluSrcA = 1;
	aluSrcB[0] = 0;
	aluSrcB[1] = 0;
	aluOp[0] = 0;
	aluOp[1] = 1;
}
void Control::s7() {
	regDst = 1;
	regWrite = 1;
	memToReg = 0;
}
void Control::s8() {
	aluSrcA = 1;
	aluSrcB[0] = 0;
	aluSrcB[1] = 0;
	aluOp[0] = 1;
	aluOp[1] = 0;
	pcWriteCond = 1;
	pcSource[0] = 1;
	pcSource[1] = 0;
}
void Control::s9() {
	pcWrite = 1;
	pcSource[0] = 0;
	pcSource[1] = 1;
}
bool compareArray(bool array1[], size_t size1, bool array2[], size_t size2) {
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

bool Control::getAluSrcA() {
	return aluSrcA;
}
bool* Control::getAluSrcB() {
	return aluSrcB;
}
bool Control::getIorD() {
	return iorD;
}
bool Control::getIRWrite() {
	return irWrite;
}
bool Control::getMemRead() { //Obtains mem read confirmation bit
	return memRead;
}
bool Control::getMemToReg() {
	return memToReg;
}
bool Control::getMemWrite() {
	return memWrite;
}

bool* Control::getPCSource() {
	return pcSource;
}
bool Control::getPCWrite() {
	return pcWrite;
}
bool Control::getPCWriteControl() {
	return pcWriteCond;
}
bool Control::getregDst() {
	return regDst;
}
bool* Control::getaluOp() {
	return aluOp;
}
bool Control::checkaluOp(const bool comp[], size_t size) {
	int z = 0;
	for (int i = 0; i < size; i++) {
		if (aluOp[i] == comp[i])
			z++;
	}
	if (z == 2)
		return 1;// True if arrays are equal
	else {
		return 0;
	}
}

bool Control::checkpcSource(const bool comp[], size_t size ) {
	int z = 0;
	for (int i = 0; i < size; i++) {
		if (pcSource[i] == comp[i])
			z++;
	}
	if (z == 2)
		return 1;// True if arrays are equal
	else {
		return 0;
	}
}

bool Control::checkAluSrcB(const bool comp[], size_t size) {
	int z = 0;
	for (int i = 0; i < size; i++) {
		if (aluSrcB[i] == comp[i])
			z++;
	}
	if (z == 2)
		return 1;// True if arrays are equal
	else {
		return 0;
	}
}
