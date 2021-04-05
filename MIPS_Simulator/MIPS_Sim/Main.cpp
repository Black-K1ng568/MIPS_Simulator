#include <iostream>
#include <string>
#include <sstream>
#include <chrono>
#include "Assembler.h"
#include "RegisterBank.h"
#include "ALU.h"
#include "Control.h"

// Send Boolean arrays as integers to demonstrate register interactions
bool* Assembler(std::string userInput);
bool* initRegister(std::string reg);
using namespace std;

int main() {
	string rawInput;
	ALU alu;

	bool programCounter[32] = { 0 };

	cout << "MIPS Processor Simulator";
	getline(cin, rawInput);
	Assembler(rawInput);

	cout <<"Input: " << rawInput;

	

}

