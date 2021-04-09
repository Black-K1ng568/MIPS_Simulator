#pragma once
class ALU
{
public:
	void readALUop(bool* operation, bool* opcode, int constant );
	int outputResult();
	void setdataA(bool* A);
	void setdataB(bool* B);
	void resetValues();
	void ADDI();
	void ANDI();
	void BEQ();
	void BNE();
	void LW();
	void SW();
	void ADD();
	void SUB();
	void AND();
	void OR();
	void NOR();
	void OR();
	void ORI();
	void SLT();
	void SLTI();
	void SLL();
	void SRL();

	bool* getdataA();//Test Purposes
	bool* getdataB(); // Test purposes
	


private:
	int funct;
	bool dataA[32]; // Input 1
	int intdataA = 0; //Integer form of input 1
	int intdataB = 0; // Integer form of input 2
	bool dataB[32]; // Input 2
	bool aluResult[32];
	int output = 0;
	bool add[2] = { 0 };
	bool sub[2] = { 0, 1 };
	bool extend[2] = { 1,0 };
	bool andInstruction[6] = { 1,0,0,1,0,0 };
	bool nor[6] = { 1,0,0,1,1,1 }; // Funct = 27
	bool orInstruction[6] = { 1,0,0,1,0,1 }; // Funct = 25
	bool ori[6] = { 0,0,1,1,0,1 };
	bool slt[6] = { 1,0,1,0,1,0 }; // Funct = 2a
	bool slti[6] = { 0,0,1,0,1,0 };
	bool sll[6] = { 0,0,0,0,0,0 }; // Funct = 0
	bool srl[6] = { 0,0,0,0,1,0 }; // Funct  = 2
	int overflow;
	int shamt;
};

