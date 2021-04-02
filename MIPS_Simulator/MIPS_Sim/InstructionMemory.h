#pragma once
#include "Memory.h"
class InstructionMemory :
    public Memory
{ // 20 Instructions in set
public:
    void readInstruction();

private:
    bool data[20][64];

};

