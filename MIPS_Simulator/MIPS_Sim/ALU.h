#pragma once
class ALU
{
public:
	void readInstruction(bool* instruction);
	bool* add();
	bool* subtract();
	bool* addi();
	bool* andInstruction();



private:
	bool opcode[6];
	bool dataA[32];
	bool dataB[32];
	bool aluResult[32];
};

