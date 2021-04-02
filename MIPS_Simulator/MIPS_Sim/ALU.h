#pragma once
class ALU
{
public:
	void readInstruction(bool* instruction);
	bool* add();
	bool* subtract();

private:
	bool opcode[2];
	bool data1[32];
	bool data2[32];
};

