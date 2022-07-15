#pragma once
#include <chrono>
class Control
{
public:
	//
	//void recieveInstruction( bool input[], size_t size);
	Control();
	void s0(bool input[], size_t size);
	void s1();
	void s2();
	void s3();
	void s4();
	void s5();
	void s6();
	void s7();
	void s8();
	void s9();

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
	//bool setPCWriteTrue();
	//bool compareArray(bool* opcode, bool* array);
	bool checkaluOp(const bool comp[], size_t size);
	bool checkpcSource(const bool comp[], size_t size);
	bool checkAluSrcB(const bool comp[], size_t size);

private:
	bool opcode[6] = { 0 };
	bool regDst;
	bool memRead;
	bool aluOp[2] = {0};
	bool pcSource[2] = { 0 };
	bool regWrite;
	bool pcWriteCond;
	bool pcWrite;
	bool iorD; 
	bool memWrite;
	bool memToReg;
	bool irWrite;
	bool aluSrcA;
	bool aluSrcB[2] = { 0 };  // Default for PC calculation



	//Used for comparisons
	
	//bool add[6] = { 1,0,0,0,0,0}; // Funct = 20
	bool addi[6] = { 0,0,1,0,0,0 };
	//bool andInstruction[6] = { 1,0,0,1,0,0 }; // Funct = 24
	bool andi[6] = { 0,0,1,1,0,0 };
	bool beq[6] = { 0,0,0,1,0,0 };
	bool bne[6] = { 0,0,0,1,0,1 };
	
	bool lw[6] = { 1,0,0,0,1,1 };
	//bool nor[6] = { 1,0,0,1,1,1 }; // Funct = 27
	//bool orInstruction[6]= { 1,0,0,1,0,1 }; // Funct = 25
	bool ori[6] = { 0,0,1,1,0,1 };
	//bool slt[6] = { 1,0,1,0,1,0 }; // Funct = 2a
	bool slti[6] = { 0,0,1,0,1,0 };
	//bool sll[6] = { 0,0,0,0,0,0 }; // Funct = 0
	//bool srl[6] = { 0,0,0,0,1,0 }; // Funct  = 2
	bool rInstruct[6] = { 0 };
	bool sw[6] = { 1,0,1,0,1,1 };
	bool sub[6] = { 1, 0,0,0,1,0 };
	bool j[6] = { 0,0,0,0,1,0 };


};

