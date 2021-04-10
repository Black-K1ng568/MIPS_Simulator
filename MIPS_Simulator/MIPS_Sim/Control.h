#pragma once
class Control
{
public:
	void recieveInstruction(bool* opcode);
	void sendData();
	int add(); // Opcode = 000000, Funct = 
	int addi(); // Opcode = 001000
	int andInstruction(); // Opcode =  000000
	int andi(); // Opcode  = 001100
	int beq(); // Opcode = 000100 Branch If Equal
	int bne(); // Opcode = 000101 Branch If not equal
	int lbu(); // Opcode = 100100 Load Byte Unsigned
	int lhu(); // Opcode = 100101 Load Half Word Unsigned
	int ll(); // Opcode  = 110000 Load Linked
	int lw(); // Opcode = 100011 Load Word
	int nor(); // Opcode = 000000
	int orInstruction(); // Opcode = 000000
	int ori(); // Opcode = 001101
	int slt(); // Opcode = 000000
	int slti(); // Opcode = 001010
	int sll(); // Opcode = 000000 Shift Left Logical
	int srl(); // Opcode = 000000 Shift Right Logical
	int sb(); // Opcode = 001011
	int sc(); // Opcode = 111000 Store Conditional
	int sh(); // Opcode = 101001
	int sw(); // Opcode = 101011
	int sub(); // Opcode = 100010

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
	bool aluSrcA;
	bool aluSrcB;


};

