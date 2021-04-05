#include "Control.h"
// Will add timings in main

void Control::recieveInstruction(bool* opcode, bool* instruction) {
	
	pcWrite = 1;
	bool compare[5] = { 0, 0, 0, 0, 0 };
	if (compareArray(opcode, compare)) { // Compare Opcode to 000000
		if (compareArray(instruction, add)) {
			aluOp[0] = 0;
			aluOp[1] = 0;
			pcSource[0] = 0;
			pcSource[0] = 0;
			pcWriteControl = 1;
		}
		if (compareArray(instruction, sub)) {
			aluOp[0] = 0;
			aluOp[1] = 1;
		}
		if (compareArray(instruction, andInstruction)) { 
			aluOp[0] = 1; //Alu Op = 10
			aluSrcA = 1;
			aluSrcB[1] = 0;// Alu Src B = 00

		}
		if (compareArray(instruction, nor)) {
			aluOp[0] = 1; // ALU Op is 10 Op determined by funct
			aluSrcA = 1;
			aluSrcB[1] = 0; // ALU Src B = 00 R-type
			
		}
		
		if (compareArray(instruction, orInstruction)) {
			aluOp[0] = 1; // Alu Op = 10, determined by funct
			aluSrcA = 1;
			aluSrcB[1] = 0; // Alu Src B  = 00, R type Instruction
		}
		if (compareArray(instruction, slt)) {
			aluOp[0] = 1;
			aluSrcA = 1;
			aluSrcB[1] = 0;// Alu Src B = 00, R-type Instruction

		}
		if (compareArray(instruction, sll)) {
			aluOp[0] = 1;
			aluSrcA = 1;
			aluSrcB[1] = 0; // Alu Src B = 00, R-type

		}
		if (compareArray(instruction, srl)) {
			aluOp[0] = 1;
			aluSrcA = 1;
			aluSrcB[1] = 0; // Alu Src B = 00, R-type
		}
		
	}
	
	if (compareArray(opcode, addi)) { // Add Immediate
		aluOp[0] = 1;
		aluSrcA = 1;

	}
	if (compareArray(opcode, ori)) {
		aluOp[0] = 1; // Alu Op = 10 determined by funct
		aluSrcA = 1;
		// Alu Src B = 01, I -type instruction
	}
	
	if (compareArray(opcode, andi)) { // And Immediate
		aluOp[0] = 1;
		aluSrcA = 1;
	}
	if (compareArray(opcode, beq)) { // branch if Equal
		aluOp[1] = 1;
		aluSrcA = 1;
		aluSrcB[0] = 1; // Alu Src B = 11 sign extend signal
		pcSource[0] = 0;
		pcSource[1] = 1;

	}
	if (compareArray(opcode, bne)) { // Branch if not equal
		aluOp[1] = 1;
		aluSrcA = 1;
		aluSrcB[0] = 1; // Alu Src B = 11 sign extend signal

	}
	
	if (compareArray(opcode, j)) {
		
		pcSource[0] = 1;
		
	}
	if (compareArray(opcode, lw)) {
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
	if (compareArray(opcode, slti)) {
		aluOp[1] = 1;
		aluSrcA = 1;
		aluSrcB[1] = 0;

		regDst = 1;
		memToReg = 0;
		regWrite = 1;

	}
	
	
	if (compareArray(opcode, sw)) {
		aluSrcA = 1;
		aluSrcB[1] = 0;
		aluSrcB[0] = 1;

		memWrite = true;
		iorD = 1;

			
	}
	

}
void Control::sendData() { // Returns Data

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


