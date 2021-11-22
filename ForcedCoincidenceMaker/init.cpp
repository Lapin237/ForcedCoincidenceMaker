#include "common.h"

extern double hi, lo;

void initiate(void) {
	initRandom();
	initDictionary();
	initBound();
	initAccWeight();
	initMemory();
}