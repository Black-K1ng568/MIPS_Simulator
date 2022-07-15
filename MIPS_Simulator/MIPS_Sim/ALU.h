#pragma once
class ALU
{
public:
	ALU(bool aluOp[], size_t size1, bool funct[], size_t size2);
	ALU(bool AluOp[], size_t size);
	ALU(bool aluOp[], size_t size1, bool funct[], size_t size2, bool regA[], size_t size3, bool regB[], size_t size4);
	void readALU();
	bool* outputResult();
	void setdataA(bool A[], size_t size );
	void setdata(bool A[], size_t size1, bool B[], size_t size2 );
	void resetValues();
	

	bool* getdataA();//Test Purposes
	bool* getdataB(); // Test purposes
	
protected:
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

private:
	bool funct[6] = { 0 };
	bool aluOp[2] = { 0 };
	bool zeroOp[2] = { 0 };
	bool beqOp[2] = { 0, 1 };
	bool rOp[2] = { 1, 0 };

	bool dataA[32] = { 0 }; // Input 1
	bool dataB[32] = { 0 }; // Input 2
	bool output[32] = { 0 }; //If not extended
	bool outputAddress[32] = { 0 }; //If extended i.e. address
	bool add[4] = { 0, 0, 1, 0 };
	bool sub[4] = { 0, 1, 1, 0 };
	bool andControl[4] = { 0, 0, 0, 0 };
	bool orControl[4] = {0,0,0, 1};
	bool setllt[4] = { 0, 1,1,1 };
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
	bool aluControl[4];

};

