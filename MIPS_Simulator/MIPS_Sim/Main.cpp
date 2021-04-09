#include <iostream>
#include <string>
#include <sstream>
#include <chrono>
#include "Assembler.h"
#include "RegisterBank.h"
#include "ALU.h"
#include "Control.h"
#include <cstdlib>
#include <thread>
#include <fstream>

// Send Boolean arrays as integers to demonstrate register interactions
using namespace std;
void SchedulerThread(int state) {

}


int main() {
	string rawInput;
	ALU alu;
	Control control;
	bool programCounter[32] = { 0 };
	int PC = 0x00400000;
	cout << "MIPS Processor Simulator";
	ifstream inputFile;
	inputFile.open("testProgram1.txt");
	while (!inputFile.eof()) {
		getline(inputFile, rawInput);

		cout << rawInput;
	}
	inputFile.close();
	Assembler(rawInput);
	bool aluOut[32];

	enum State { s0, s1, s2, s3, s4, s5, s6, s7, s8, s9 };
	State present_state = s0;
	State next_state = s0;
	
	switch (present_state) {
	s0:
		control.recieveInstruction()
		if(control.getMemRead()){

	s2:
	s3:
	s4:
	s5:
	s6:
	s7:
	s8:
	s9:


	enum mux2 { op1, op2, op3, op4 };
	mux2 pcSource = op1;
	switch (pcSource) {
	case op1:

	case op2:

	case op3:

	case op4:

	}
	cout <<"Input: " << rawInput;

	

}

