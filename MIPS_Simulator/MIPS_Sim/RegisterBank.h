#pragma once
class RegisterBank
{
public:
	void recieveInstruction(bool* instruction);
	int read1(bool* source1);
	int read2(bool* source2);
	void writeRegister(bool* dst, bool write);

private:
	bool* r0[32] = { 0 };
	bool* r1[32] = { 0 };
	bool* r2[32] = { 0 };
	bool* r3[32] = { 0 };
	bool* r4[32] = { 0 };
	bool* r5[32] = { 0 };
	bool* r6[32] = { 0 };
	bool* r7[32] = { 0 };
	bool* r8[32] = { 0 };
	bool* r9[32] = { 0 };
	bool* r10[32] = { 0 };
	bool* r11[32] = { 0 };
	bool* r12[32] = { 0 };
	bool* r13[32] = { 0 };
	bool* r14[32] = { 0 };
	bool* r15[32] = { 0 };
	bool* r16[32] = { 0 };
	bool* r17[32] = { 0 };
	bool* r18[32] = { 0 };
	bool* r19[32] = { 0 };
	bool* r20[32] = { 0 };
	bool* r21[32] = { 0 };
	bool* r22[32] = { 0 };
	bool* r23[32] = { 0 };
	bool* r24[32] = { 0 };
	bool* r25[32] = { 0 };
	bool* r26[32] = { 0 };
	bool* r27[32] = { 0 };
	bool* r28[32] = { 0 };
	bool* r29[32] = { 0 };
	bool* r30[32] = { 0 };
	bool* r31[32] = { 0 };
	bool regWrite;


};

