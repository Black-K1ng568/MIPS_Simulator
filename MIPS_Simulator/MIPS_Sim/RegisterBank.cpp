#include "RegisterBank.h"
#include <iostream>
using namespace std;
RegisterBank::RegisterBank() {

}
bool* RegisterBank::read1( bool source1[], size_t size) {
	int location = booltoInteger(source1, size);
	enum Registers { zero,at,v0,v1,a0,a1,a2,a3,t0,t1,t2,t3,t4,t5,t6,t7, s0,s1,s2,s3,s4,s5,s6,s7, t8,t9, k0,k1, gp, sp, fp, ra };
	switch (location)
	{
	zero:
		for(int i =0; i<32;i++)
			dataA[i] = 0;
	at:
		cout << "Error";
		break;
	v0:
		for (int i = 0; i < 32; i++)
			dataA[i] = r2[i];
	v1:
		for (int i = 0; i < 32; i++)
			dataA[i] = r3[i];
	a0:
		for (int i = 0; i < 32; i++)
			dataA[i] = r4[i];
	a1:
		for (int i = 0; i < 32; i++)
			dataA[i] = r5[i];
	a2:
		for (int i = 0; i < 32; i++)
			dataA[i] = r6[i];
	a3:
		for (int i = 0; i < 32; i++)
			dataA[i] = r7[i];
	t0:
		for (int i = 0; i < 32; i++)
			dataA[i] = r8[i];
	t1:
		for (int i = 0; i < 32; i++)
			dataA[i] = r9[i];
	t2:
		for (int i = 0; i < 32; i++)
			dataA[i] = r10[i];
	t3:
		for (int i = 0; i < 32; i++)
			dataA[i] = r11[i];
	t4:
		for (int i = 0; i < 32; i++)
			dataA[i] = r12[i];
	t5:
		for (int i = 0; i < 32; i++)
			dataA[i] = r13[i];
	t6:
		for (int i = 0; i < 32; i++)
			dataA[i] = r14[i];
	t7:
		for (int i = 0; i < 32; i++)
			dataA[i] = r15[i];
	s0:
		for (int i = 0; i < 32; i++)
			dataA[i] = r16[i];
	s1:
		for (int i = 0; i < 32; i++)
			dataA[i] = r17[i];
	s2:
		for (int i = 0; i < 32; i++)
			dataA[i] = r18[i];
	s3:
		for (int i = 0; i < 32; i++)
			dataA[i] = r19[i];

	s4:
		for (int i = 0; i < 32; i++)
			dataA[i] = r20[i];
	s5:
		for (int i = 0; i < 32; i++)
			dataA[i] = r21[i];
	s6:
		for (int i = 0; i < 32; i++)
			dataA[i] = r22[i];
	s7:
		for (int i = 0; i < 32; i++)
			dataA[i] = r23[i];

	t8:
		for (int i = 0; i < 32; i++)
			dataA[i] = r24[i];
	t9:
		for (int i = 0; i < 32; i++)
			dataA[i] = r25[i];

	k0:
		for (int i = 0; i < 32; i++)
			dataA[i] = r26[i];
	k1:
		for (int i = 0; i < 32; i++)
			dataA[i] = r27[i];

	gp:
		for (int i = 0; i < 32; i++)
			dataA[i] = r28[i];
	sp:
		for (int i = 0; i < 32; i++)
			dataA[i] = r29[i];
	fp:
		for (int i = 0; i < 32; i++)
			dataA[i] = r30[i];
	ra:
		for (int i = 0; i < 32; i++)
			dataA[i] = r31[i];
	default:
		break;
	}
	
	return dataA;
}

bool* RegisterBank::read2( bool source2[], size_t size) {
	int location = booltoInteger(source2, size);
	enum Registers { zero, at, v0, v1, a0, a1, a2, a3, t0, t1, t2, t3, t4, t5, t6, t7, s0, s1, s2, s3, s4, s5, s6, s7, t8, t9, k0, k1, gp, sp, fp, ra };
	switch (location)
	{
	zero:
		for (int i = 0; i < 32; i++)
			dataA[i] = 0;
	at:
		cout << "Error";
		break;
	v0:
		for (int i = 0; i < 32; i++)
			dataA[i] = r2[i];
	v1:
		for (int i = 0; i < 32; i++)
			dataA[i] = r3[i];
	a0:
		for (int i = 0; i < 32; i++)
			dataA[i] = r4[i];
	a1:
		for (int i = 0; i < 32; i++)
			dataA[i] = r5[i];
	a2:
		for (int i = 0; i < 32; i++)
			dataA[i] = r6[i];
	a3:
		for (int i = 0; i < 32; i++)
			dataA[i] = r7[i];
	t0:
		for (int i = 0; i < 32; i++)
			dataA[i] = r8[i];
	t1:
		for (int i = 0; i < 32; i++)
			dataA[i] = r9[i];
	t2:
		for (int i = 0; i < 32; i++)
			dataA[i] = r10[i];
	t3:
		for (int i = 0; i < 32; i++)
			dataA[i] = r11[i];
	t4:
		for (int i = 0; i < 32; i++)
			dataA[i] = r12[i];
	t5:
		for (int i = 0; i < 32; i++)
			dataA[i] = r13[i];
	t6:
		for (int i = 0; i < 32; i++)
			dataA[i] = r14[i];
	t7:
		for (int i = 0; i < 32; i++)
			dataA[i] = r15[i];
	s0:
		for (int i = 0; i < 32; i++)
			dataA[i] = r16[i];
	s1:
		for (int i = 0; i < 32; i++)
			dataA[i] = r17[i];
	s2:
		for (int i = 0; i < 32; i++)
			dataA[i] = r18[i];
	s3:
		for (int i = 0; i < 32; i++)
			dataA[i] = r19[i];

	s4:
		for (int i = 0; i < 32; i++)
			dataA[i] = r20[i];
	s5:
		for (int i = 0; i < 32; i++)
			dataA[i] = r21[i];
	s6:
		for (int i = 0; i < 32; i++)
			dataA[i] = r22[i];
	s7:
		for (int i = 0; i < 32; i++)
			dataA[i] = r23[i];

	t8:
		for (int i = 0; i < 32; i++)
			dataA[i] = r24[i];
	t9:
		for (int i = 0; i < 32; i++)
			dataA[i] = r25[i];

	k0:
		for (int i = 0; i < 32; i++)
			dataA[i] = r26[i];
	k1:
		for (int i = 0; i < 32; i++)
			dataA[i] = r27[i];

	gp:
		for (int i = 0; i < 32; i++)
			dataA[i] = r28[i];
	sp:
		for (int i = 0; i < 32; i++)
			dataA[i] = r29[i];
	fp:
		for (int i = 0; i < 32; i++)
			dataA[i] = r30[i];
	ra:
		for (int i = 0; i < 32; i++)
			dataA[i] = r31[i];
	default:
		break;
	}
	return dataA;
	
}

void RegisterBank::writeRegister( bool dst[], size_t size, bool write) {

	int location = booltoInteger(dst, size);
	enum Registers { zero, at, v0, v1, a0, a1, a2, a3, t0, t1, t2, t3, t4, t5, t6, t7, s0, s1, s2, s3, s4, s5, s6, s7, t8, t9, k0, k1, gp, sp, fp, ra };
	if (write) {
		switch (location)
		{
		zero:
			for (int i = 0; i < 32; i++)
				dataA[i] = 0;
		at:
			cout << "Error";
			break;
		v0:
			for (int i = 0; i < 32; i++)
				dataA[i] = r2[i];
		v1:
			for (int i = 0; i < 32; i++)
				dataA[i] = r3[i];
		a0:
			for (int i = 0; i < 32; i++)
				dataA[i] = r4[i];
		a1:
			for (int i = 0; i < 32; i++)
				dataA[i] = r5[i];
		a2:
			for (int i = 0; i < 32; i++)
				dataA[i] = r6[i];
		a3:
			for (int i = 0; i < 32; i++)
				dataA[i] = r7[i];
		t0:
			for (int i = 0; i < 32; i++)
				dataA[i] = r8[i];
		t1:
			for (int i = 0; i < 32; i++)
				dataA[i] = r9[i];
		t2:
			for (int i = 0; i < 32; i++)
				dataA[i] = r10[i];
		t3:
			for (int i = 0; i < 32; i++)
				dataA[i] = r11[i];
		t4:
			for (int i = 0; i < 32; i++)
				dataA[i] = r12[i];
		t5:
			for (int i = 0; i < 32; i++)
				dataA[i] = r13[i];
		t6:
			for (int i = 0; i < 32; i++)
				dataA[i] = r14[i];
		t7:
			for (int i = 0; i < 32; i++)
				dataA[i] = r15[i];
		s0:
			for (int i = 0; i < 32; i++)
				dataA[i] = r16[i];
		s1:
			for (int i = 0; i < 32; i++)
				dataA[i] = r17[i];
		s2:
			for (int i = 0; i < 32; i++)
				dataA[i] = r18[i];
		s3:
			for (int i = 0; i < 32; i++)
				dataA[i] = r19[i];

		s4:
			for (int i = 0; i < 32; i++)
				dataA[i] = r20[i];
		s5:
			for (int i = 0; i < 32; i++)
				dataA[i] = r21[i];
		s6:
			for (int i = 0; i < 32; i++)
				dataA[i] = r22[i];
		s7:
			for (int i = 0; i < 32; i++)
				dataA[i] = r23[i];

		t8:
			for (int i = 0; i < 32; i++)
				dataA[i] = r24[i];
		t9:
			for (int i = 0; i < 32; i++)
				dataA[i] = r25[i];

		k0:
			for (int i = 0; i < 32; i++)
				dataA[i] = r26[i];
		k1:
			for (int i = 0; i < 32; i++)
				dataA[i] = r27[i];

		gp:
			for (int i = 0; i < 32; i++)
				dataA[i] = r28[i];
		sp:
			for (int i = 0; i < 32; i++)
				dataA[i] = r29[i];
		fp:
			for (int i = 0; i < 32; i++)
				dataA[i] = r30[i];
		ra:
			for (int i = 0; i < 32; i++)
				dataA[i] = r31[i];
		default:
			break;
		}
	}
	cout << "Register %d", location, "updated";
}

bool compareArray(const bool array1[], size_t size1,const bool array2[], size_t size2) {
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
int booltoInteger(const bool array[], size_t size) {
	int value = 0;

	for (int i = 0; i < size; i++) {
		if (array[i]) {
			value |= 1 << (size - i - 1);
		}
		//cout << "\nValue in Progress Number" << i << " : " << value << endl;

	}
	return value;
}