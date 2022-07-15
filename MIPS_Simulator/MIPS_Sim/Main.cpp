#include <iostream>
#include <string>
#include <sstream>
#include <chrono>
#include "Assembler.h"
#include "RegisterBank.h"
#include "ALU.h"
#include "Memory.h"
#include "Control.h"
#include <cstdlib>
#include <thread>
#include <fstream>

// Send Boolean arrays as integers to demonstrate register interactions
//Will hard code opcode test to add
using namespace std;
void SchedulerThread(int state) {

}

bool compareArray(bool array1[], size_t size1, bool array2[], size_t size2);
int main() {
	string rawInput;
	//ALU alu;
	Control control;
	bool* programCounter[32] = { 0 };
	int PC = 0x00400000;
	cout << "MIPS Processor Simulator";
	ifstream inputFile;
	inputFile.open("testProgram1.txt");
	while (!inputFile.eof()) {
		getline(inputFile, rawInput);

		cout << rawInput;
	}
	inputFile.close();
	Memory memory;
	Assembler(rawInput);
	bool aluOut[32];
	bool instruction[32];
	enum State { s0, s1, s2, s3, s4, s5, s6, s7, s8, s9 };
	State present_state = s0;
	State next_state = s0;
	bool opcode[6];
	bool regloc1[5];
	bool regloc2[5];
	bool IConstant[15];
	bool RConstant[5];
	bool address[26];
	int iNum = 0;
	bool regA[32] = { 0 };
	bool regB[32] = { 0 };
	bool funct[6] = { 0 };
	bool aluOp[] = { 0, 1 };
	RegisterBank registers;
	ALU alu(aluOp, 2, funct, 6);

	while (iNum<32)
	{

	} {
		switch (present_state) {
			present_state = next_state;
		s0:
			memory.getAddress(control.getIorD() ? programCounter[iNum] : 0);
			/*	for (int m = 0; m < 32; m++)
					instruction[m] = memory[m / 4];*/
			for (int i = 26; i < 32; i++)
				opcode[i - 26] = instruction[i];

			for (int j = 21; j < 25; j++)
				regloc1[j - 21] = instruction[j];

			for (int k = 16; k < 20; k++)

				control.s0(opcode, 6);

			//
			next_state = s1;

		s1:
			control.s1();
			bool jump[6] = { 0, 0, 0, 0, 1, 0 };
			bool beq[6] = { 0, 0, 0, 1, 0, 0 };
			bool bne[6] = { 0, 0, 0, 1, 0, 1 };
			bool lw[6] = { 1, 0, 0, 0, 1, 1 };
			bool sw[6] = { 1, 0, 1, 0, 1, 1 };
			bool Rop[6] = {0};

			if (compareArray(jump, 6, opcode, 6)) {
				next_state = s9;
			}
			else if((compareArray(beq, 6, opcode, 6) || (compareArray(bne, 6, opcode, 6)))){
				next_state = s8;
			}
			else if (compareArray(opcode, 6, lw, 6) || compareArray(opcode, 6, sw, 6))
			{
				next_state = s2;
			}
			
			else if(compareArray(opcode, 6, Rop, 6))
			{
				bool* arrPointer1 = registers.read1(regloc1, sizeof(regloc1) / sizeof(regloc1[0]));
				for (int m = 0; m < 32; m++)
					regA[m] = *(arrPointer1 + m);
				bool* arrPointer2 = registers.read2(regloc1, sizeof(regloc1) / sizeof(regloc1[0]));
				for (int m = 0; m < 32; m++)
					regB[m] = *(arrPointer1 + m);
			}
			else {

				bool* arrPointer1 = registers.read1(regloc1, sizeof(regloc1) / sizeof(regloc1[0]));
				for (int m = 0; m < 32; m++)
					regA[m] = *(arrPointer1 + m);
			}
		s2:
			control.s2();
			for (int a = 0; a < 2; a++)
				aluOp[a] = control.getaluOp()[a];
			ALU memAddCalc(aluOp, 2 );
			next_state = s3;
		s3:
			control.s3();

			next_state = s4;
		s4:
			control.s4();
			iNum++;
			next_state = s0;
		s5:
			control.s5();
			next_state = s4;
		s6:
			control.s6();
			next_state = s7;
			
		
		s7:
			control.s7();
			next_state = s4;
		s8:
			control.s8();
			next_state = s4;
		s9:
			control.s9();

			next_state = s4;




			/*enum mux2 { op1, op2, op3, op4 };
			mux2 pcSource = op1;
			switch (pcSource) {
			case op1:

			case op2:

			case op3:

			case op4:

			}
			cout << "Input: " << rawInput;*/

		}

}
bool compareArray(bool array1[], size_t size1, bool array2[], size_t size2) {
		int z = 0;
		if (size1 == size2) {
			for (int i = 0; i < size1; i++) {
				if (array1[i] == array2[i])
					z++;
			}
			if (z == size1)
				return 1;
			else
			{
				return 0;
			}
		}
		else {
			return 0;
		}
	}
