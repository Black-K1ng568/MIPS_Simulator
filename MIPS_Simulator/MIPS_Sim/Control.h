#pragma once
class Control
{
public:
	void recieveInstruction(bool* opcode);
	int add(); // Opcode = 0
	int addi(); // Opcode = 8
	int andInstruction(); // Opcode =  0
	int andi(); // Opcode  = c
	int beq(); // Opcode = 4 Branch If Equal
	int bne(); // Opcode = 5 Branch If not equal
	int lbu(); // Opcode = 24 Load Byte Unsigned
	int lhu(); // Opcode = 25 Load Half Word Unsigned
	int ll(); // Opcode  = 30 Load Linked
	int lw(); // Opcode = 23 Load Word
	int nor(); 
	int orInstruction();
	int ori();
	int slt();
	int slti();
	int sll();
	int srl();
	int sb();
	int sc();
	int sh();
	int sw();
	int sub();

private:
	bool regDst;
	bool branch;
	bool memRead;
	bool aluOp;
	bool pcSource;
	bool regWrite;
	bool pcWriteControl;
	bool pcWrite;
	bool iorD;
	bool memRead;
	bool memWrite;
	bool memToReg;
	bool irWrite;

};

