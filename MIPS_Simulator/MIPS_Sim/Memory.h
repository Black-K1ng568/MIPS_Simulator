#pragma once
#include <string>
class Memory
{
public:
	void readAddress(int address);

	void storeTextInstruction(std::string input, uint32_t num);
	int getInstruction();
	int getNumOfInstructions();
	void storeWord();
	bool* loadWord();





private:
	uint32_t memory[32];
	uint32_t address;
};

