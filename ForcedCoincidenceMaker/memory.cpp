#include "common.h"
#define memSize 10000
#define memLength 16

uc memory[memSize][memLength];
int memNext[memSize];
int memNow = 0;
int memPrev = 0;

void initMemory(void) {
	for (int i = 0; i < memSize; i++) {
		memNext[i] = i + 1;
	}
	memNext[memSize - 1] = -1;
}

uc* newMemory(void) {
	memPrev = memNow;
	memNow = memNext[memNow];
	if(memPrev != -1)
	return memory[memPrev];
	else {
		cout << "Memory Exceeding" << endl;
		system("pause");
		return NULL;
	}
}

void deleteMemory(uc* p) {
	int pos = p - memory[0];
	memNext[pos] = memNow;
	memNow = pos;
}