#include "Control.h"
// Will add timings in main
//Boolean Arrays are used to better simulate registers, plus avoids the values ending up in unknown states as can only be true or false
void Control::recieveInstruction(bool* opcode, bool* instruction) {
	
	pcWrite = 1;
	bool compare[5] = { 0, 0, 0, 0, 0 };
	

	if (compareArrayx6(opcode, compare)) { // Compare Opcode to 000000
		if (compareArrayx6(instruction, add)) {
			aluOp[0] = 0;
			aluOp[1] = 0;
			pcSource[0] = 0;
			pcSource[0] = 0;
			pcWriteControl = 1;
		}
		if (compareArrayx6(instruction, sub)) {
			aluOp[0] = 0;
			aluOp[1] = 1;
		}
		if (compareArrayx6(instruction, andInstruction)) { 
			aluOp[0] = 1; //Alu Op = 10
			aluSrcA = 1;
			aluSrcB[1] = 0;// Alu Src B = 00

		}
		if (compareArrayx6(instruction, nor)) {
			aluOp[0] = 1; // ALU Op is 10 Op determined by funct
			aluSrcA = 1;
			aluSrcB[1] = 0; // ALU Src B = 00 R-type
			
		}
		
		if (compareArrayx6(instruction, orInstruction)) {
			aluOp[0] = 1; // Alu Op = 10, determined by funct
			aluSrcA = 1;
			aluSrcB[1] = 0; // Alu Src B  = 00, R type Instruction
		}
		if (compareArrayx6(instruction, slt)) {
			aluOp[0] = 1;
			aluSrcA = 1;
			aluSrcB[1] = 0;// Alu Src B = 00, R-type Instruction

		}
		if (compareArrayx6(instruction, sll)) {
			aluOp[0] = 1;
			aluSrcA = 1;
			aluSrcB[1] = 0; // Alu Src B = 00, R-type

		}
		if (compareArrayx6(instruction, srl)) {
			aluOp[0] = 1;
			aluSrcA = 1;
			aluSrcB[1] = 0; // Alu Src B = 00, R-type
		}
		
	}
	
	if (compareArrayx6(opcode, addi)) { // Add Immediate
		aluOp[0] = 1;
		aluSrcA = 1;

	}
	if (compareArrayx6(opcode, ori)) {
		aluOp[0] = 1; // Alu Op = 10 determined by funct
		aluSrcA = 1;
		// Alu Src B = 01, I -type instruction
	}
	
	if (compareArrayx6(opcode, andi)) { // And Immediate
		aluOp[0] = 1;
		aluSrcA = 1;
	}
	if (compareArrayx6(opcode, beq)) { // branch if Equal
		aluOp[1] = 1;
		aluSrcA = 1;
		aluSrcB[0] = 1; // Alu Src B = 11 sign extend signal
		pcSource[0] = 0;
		pcSource[1] = 1;

	}
	if (compareArrayx6(opcode, bne)) { // Branch if not equal
		aluOp[1] = 1;
		aluSrcA = 1;
		aluSrcB[0] = 1; // Alu Src B = 11 sign extend signal

	}
	
	if (compareArrayx6(opcode, j)) {
		
		pcSource[0] = 1;
		
	}
	if (compareArrayx6(opcode, lw)) {
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
	if (compareArrayx6(opcode, slti)) {
		aluOp[1] = 1;
		aluSrcA = 1;
		aluSrcB[1] = 0;

		regDst = 1;
		memToReg = 0;
		regWrite = 1;

	}
	
	
	if (compareArrayx6(opcode, sw)) {
		aluSrcA = 1;
		aluSrcB[1] = 0;
		aluSrcB[0] = 1;

		memWrite = true;
		iorD = 1;

			
	}
	

}

bool Control::compareArrayx6(bool* opcode, bool* array) {
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
bool Control::getMemRead() {
	return memRead;
}
bool Control::getMemToReg() {
	return memToReg;
}
bool* Control::getPCSource() {
	return pcSource;
}
bool Control::getPCWrite() {
	return pcWrite;
}
bool Control::getPCWriteControl() {
	return pcWriteControl;
}
bool Control::getregDst() {
	return regDst;
}
bool* Control::getaluOp() {
	return aluOp;
}