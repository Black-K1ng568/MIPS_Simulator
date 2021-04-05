#pragma once
#include <string>

bool* Assembler(std::string userInput) { // Assembler to convert raw string to instruction 
	istringstream ss(userInput);
	std::string word;
	std::string str[5] = { "" };
	int instructType = 0;
	bool instruction[32] = { 0 };
	int i = 0;
	
	while (ss >> word) {
		str[i] = word;
		i++;
	}
	for (int z = 0; z < 5; z++)
		cout << str[z];
	if (str[0] == "add") // Funct = 100000, Opcode = 000000
		instruction[5] = 1;
	if (str[0] == "addi") // Opcode = 001000
		instruction[29] = 1;
	
	if (str[0] == "and") { // Opcode = 000000, Funct = 100100
		instruction[4] = 1;
		instruction[3] = 1;
	}
	if (str[0] == "andi") { // Opcode = 001100
		instruction[29] = 1;
		instruction[28] = 1;
	}
	if (str[0] == "beq") // Opcode = 000100
		instruction[28] = 1;
	if (str[0] == "bne") { // Opcode = 000101
		instruction[28] = 1;
		instruction[26] = 1;
	}
	
	
	
	if (str[0] == "lw") {// Opcode = 100011
		instruction[26] = 1;
		instruction[27] = 1;
		instruction[26] = 1;
	}
	if (str[0] == "nor") { // Opcode = 000000, Funct = 100111
		instruction[4] = 1;
		instruction[3] = 1;
		instruction[1] = 1;
		instruction[0] = 1;
	}
	if (str[0] == "or") { //Opcode = 000000, Funct = 100101
		instruction[4] = 1;
		instruction[3] = 1;
		instruction[0] = 1;
	}
	if (str[0] == "ori") { // Opcode = 001101
		instruction[29] = 1;
		instruction[28] = 1;
		instruction[26] = 1;
	}
	if (str[0] == "slt") { // Opcode = 000000, Funct = 101010 Set Less Than
		instruction[5] = 1;
		instruction[3] = 1;
		instruction[1] = 1;
	}
	if (str[0] == "slti") { // Opcode = a Set Less Than Immediate
		instruction[3] = 1;
		instruction[1] = 1;
	}
	

	if (str[0] == "sll") { // Opcode = 0, Funct = 0
		instruction[31] = 1;
		instruction[29] = 1;
		instruction[27] = 1;
	}
	if (str[0] == "srl") { //Opcode = 0, Funct = 2
		instruction[29] = 1;
		instruction[27] = 1;
	}

	
	if (str[0] == "sw") {//Store Word 2b
		instruction[31] = 1;
		instruction[29] = 1;
		instruction[27] = 1;
		instruction[26] = 1;

	}
	if (str[0] == "sub") {//Subtract 22
		instruction[31] = 1;
		instruction[27] = 1;
	}
	if (str[0] == "j") {// Jump Opcode = 000010
		instruction[27] = 1;
	}
	
	else {
		cerr << "Unknown Instruction";
		return instruction;
	}


	return instruction;
}

bool* ReadInstruction(string destination, string firstSource, string secondSource) {
	bool registers[26] = { 0 };
	bool* destReg;
	bool* firSource;
	bool* secSource;

	destReg = initRegisters(destination);
	firSource = initRegisters(firstSource);
	secSource = initRegisters(secondSource);
	for (int i = 0; i < 5; i++) {
		registers[11 + i] = *(destReg + i);
		registers[16 + i] = *(secSource + i);
		registers[21 + i] = *(firSource + i);

	}
	return registers;

}

bool* ImmediateInstruction(string destination, string source, string constant) { //Constant or address
	bool registers[20];
	bool* destReg;
	bool* theSource;
	int cont = 0; //Constant

	destReg = initRegisters(destination);
	theSource = initRegisters(source);



	return registers;
}


bool* initRegisters(string reg) {
	bool instruction[5] = { 0 };
	if (reg == "$zero")
		return instruction;

	if (reg == "$at") {
		instruction[0] = 1;
		return instruction;
	}
	if (reg == "$v0") {
		instruction[1] = 1;
		return instruction;
	}
	if (reg == "$v1") {
		instruction[1] = 1;
		instruction[0] = 1;
		return instruction;
	}
	if (reg == "$a0") {
		instruction[2] = 1;
		return instruction;
	}
	if (reg == "$a1") {
		instruction[2] = 1;
		instruction[0] = 1;
		return instruction;
	}
	if (reg == "$a2") {
		instruction[2] = 1;
		instruction[1] = 1;
		return instruction;
	}
	if (reg == "$a3") {
		instruction[2] = 1;
		instruction[1] = 1;
		instruction[0] = 1;
		return instruction;
	}
	if (reg == "$t0") {
		instruction[3] = 1;
		return instruction;
	}
	if (reg == "$t1") {
		instruction[3] = 1;
		instruction[0] = 1;
		return instruction;
	}
	if (reg == "$t2") {
		instruction[3] = 1;
		instruction[1] = 1;
		return instruction;
	}
	if (reg == "$t3") {
		instruction[3] = 1;
		instruction[1] = 1;
		instruction[0] = 1;
		return instruction;
	}
	if (reg == "$t4") {
		instruction[3] = 1;
		instruction[2] = 1;
		return instruction;
	}
	if (reg == "$t5") {
		instruction[3] = 1;
		instruction[2] = 1;
		instruction[0] = 1;
		return instruction;
	}
	if (reg == "$t6") {
		instruction[3] = 1;
		instruction[2] = 1;
		instruction[1] = 1;
		return instruction;
	}
	if (reg == "$t7") {
		instruction[3] = 1;
		instruction[2] = 1;
		instruction[1] = 1;
		instruction[0] = 1;
		return instruction;
	}
	if (reg == "$s0") {
		instruction[4] = 1;
		return instruction;
	}
	if (reg == "$s1") {
		instruction[4] = 1;
		instruction[0] = 1;
		return instruction;
	}
	if (reg == "$s2") {
		instruction[4] = 1;
		instruction[1] = 1;
		return instruction;
	}
	if (reg == "$s3") {
		instruction[4] = 1;
		instruction[1] = 1;
		instruction[0] = 1;
	}
	if (reg == "$s4") {
		instruction[4] = 1;
		instruction[2] = 1;
		return instruction;
	}
	if (reg == "$s5") {
		instruction[4] = 1;
		instruction[2] = 1;
		instruction[0] = 1;
		return instruction;
	}
	if (reg == "$s6") {
		instruction[4] = 1;
		instruction[2] = 1;
		instruction[1] = 1;
		return instruction;
	}
	if (reg == "$s7") {
		instruction[4] = 1;
		instruction[2] = 1;
		instruction[1] = 1;
		instruction[0] = 1;
		return instruction;
	}
	if (reg == "$t8") {
		instruction[4] = 1;
		instruction[3] = 1;
		return instruction;
	}
	if (reg == "$t9") {
		instruction[4] = 1;
		instruction[3] = 1;
		instruction[0] = 1;
		return instruction;
	}
	if (reg == "$k0") {
		instruction[4] = 1;
		instruction[3] = 1;
		instruction[1] = 1;
		return instruction;
	}
	if (reg == "$k1") {
		instruction[4] = 1;
		instruction[3] = 1;
		instruction[1] = 1;
		instruction[0] = 1;
		return instruction;
	}
	if (reg == "$gp") {
		instruction[4] = 1;
		instruction[3] = 1;
		instruction[2] = 1;
		return instruction;
	}
	if (reg == "$sp") {
		instruction[4] = 1;
		instruction[3] = 1;
		instruction[2] = 1;
		instruction[0] = 1;
		return instruction;
	}
	if (reg == "$fp") {
		instruction[4] = 1;
		instruction[3] = 1;
		instruction[2] = 1;
		instruction[1] = 1;
		return instruction;
	}
	if (reg == "$ra") {
		instruction[4] = 1;
		instruction[3] = 1;
		instruction[2] = 1;
		instruction[1] = 1;
		instruction[0] = 1;
		return instruction;
	}
	else {
		return instruction;
	}

	return instruction;
}
bool* intToBinary(int n) {

	bool constant[32] = { 0 };


	for (int i = 0; i < 32; i++) {
		constant[i] = n % 2;
		n = n / 2;
	}
	return constant;
}


