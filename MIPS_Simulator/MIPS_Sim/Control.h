#pragma once
#include <chrono>
class Control
{
public:
	void recieveInstruction(bool* opcode, bool* instruction);
	
	
	bool* getPCSource();
	bool getregDst();
	bool* getAluSrcB();

	bool getMemRead();
	bool* getaluOp();
	bool getPCWriteControl();
	bool getPCWrite();
	bool getMemWrite();
	bool getMemToReg();
	bool getIRWrite();
	bool getIorD();
	bool getAluSrcA();
	bool setPCWriteTrue();
	bool compareArrayx6(bool* opcode, bool* array);

private:
	bool regDst;
	
	bool memRead;
	bool aluOp[2] = {0};
	bool pcSource[2] = { 0 };
	bool regWrite;
	bool pcWriteControl;
	bool pcWrite;
	bool iorD;
	bool memRead;
	bool memWrite;
	bool memToReg;
	bool irWrite;
	bool aluSrcA;



	//Used for comparisons
	bool aluSrcB[2] = { 0, 1 }; // Default for PC calculation
	bool add[6] = { 1,0,0,0,0,0}; // Funct = 20
	bool addi[6] = { 0,0,1,0,0,0 };
	bool andInstruction[6] = { 1,0,0,1,0,0 }; // Funct = 24
	bool andi[6] = { 0,0,1,1,0,0 };
	bool beq[6] = { 0,0,0,1,0,0 };
	bool bne[6] = { 0,0,0,1,0,1 };
	
	bool lw[6] = { 1,0,0,0,1,1 };
	bool nor[6] = { 1,0,0,1,1,1 }; // Funct = 27
	bool orInstruction[6]= { 1,0,0,1,0,1 }; // Funct = 25
	bool ori[6] = { 0,0,1,1,0,1 };
	bool slt[6] = { 1,0,1,0,1,0 }; // Funct = 2a
	bool slti[6] = { 0,0,1,0,1,0 };
	bool sll[6] = { 0,0,0,0,0,0 }; // Funct = 0
	bool srl[6] = { 0,0,0,0,1,0 }; // Funct  = 2
	
	bool sw[6] = { 1,0,1,0,1,1 };
	bool sub[6] = { 1, 0,0,0,1,0 };
	bool j[6] = { 0,0,0,0,1,0 };


};

