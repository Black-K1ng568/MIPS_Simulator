#pragma once
class RegisterBank
{
public:
	RegisterBank();

	//void recieveInstruction(bool* instruction);
	bool* read1( bool source1[], size_t size);
	bool* read2( bool source2[], size_t size);
	void writeRegister( bool dst[], size_t size, bool write);

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
	bool one[5] = { 0,0,0,0,1 };
	bool zero[5] = { 0 };
	bool two[5] = { 0,0,0,1,0 };
	bool three[5] = { 0,0,0,1,1 };
	bool four[5] = { 0,0,1,0,0 };
	bool five[5] = { 0,0,1,0,1 };
	bool six[5] = { 0,0,1,1,0 };
	bool seven[5] = { 0,0,1,1,1 };
	bool eight[5] = { 0,1,0,0,0 };
	bool nine[5] = { 0,1,0,0,1 };
	bool ten[5] = { 0,1,0,1,0 };
	bool eleven[5] = { 0,1,0,1,1 };
	bool twelve[5] = { 0,1,1,0,0 };
	bool thirteen[5] = { 0,1,1,0,1 };
	bool fourteen[5] = { 0,1,1,1,0 };
	bool fifteen[5] = { 0,1,1,1,1 };
	bool sixteen[5] = { 1, 0,0,0,0 };
	bool seventeen[5] = { 1,0,0,0,1 };
	bool eighteen[5] = { 1,0,0,1,0 };
	bool nineteen[5] = {1, 0, 0, 1, 1};
	bool twenty[5] = { 1, 0,1,0,0 };
	bool twentyOne[5] = { 1, 0,1,0,1 };
	bool twentyTwo[5] = {1,0,1,1,0};
	bool twentyThree[5] = { 1,0,1,1,1 };
	bool twentyFour[5] = {1,1,0,0,0};
	bool twentyFive[5] = { 1,1,0,0,1 };
	bool twentySix[5] = { 1,1,0,1,0 };
	bool twentySeven[5] = { 1,1,0,1,1 };
	bool twentyEight[5] = { 1,1,1,0,0 };
	bool twentyNine[5] = { 1,1,1,0,1 };
	bool thirty[5] = { 1,1,1,1,0 };
	bool thirtyOne[5] = { 1,1,1,1,1 };

	bool regWrite;
	bool dataA[32] = { 0 };
	bool dataB[32] = { 0 };

};

