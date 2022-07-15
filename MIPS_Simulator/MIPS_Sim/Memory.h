#pragma once
#include <string>
#include <unordered_map>
class Memory
{
public:
	void readAddress(int address);

	void storeTextInstruction(std::string input, uint32_t num);
	int getAddress(bool *PC);
	int getNumOfInstructions();
	void storeWord();
	bool* loadWord();





private:
	std::unordered_map<uint32_t, std::string> memory; // Using unordered Maps to store data in similar situations 
	uint32_t address;
	bool memRead;
	bool memWrite;

};

