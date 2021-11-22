#include "common.h"
#include "dictionary.h"
#include <cstring>

const float constantWeight[64] = {
//	0		1		2		3		4		5		6		7	
	0,		30,		25,		20,		15,		10,		10,		10,
//	8		9		10		11		12		13		14		15
	10,		10,		10,		6,		8,		3,		3,		6,
//	16		17		18		19		20		21		22		23	
	5,		2.5,	2.5,	2.5,	8,		1,		0.5,	0.5,
//	24		25		26		27		28		29		30		31
	5,		5,		0.5,	3,		0.5,	0.1,	5,		0.1,
//	pi		e		phi		gamma
	100,	100,	70,		70
};

const float unaryWeight[64] = {
//	sin		cos		tan		cot		sec		csc
	10,		10,		10,		5,		5,		5,
//	arcsin	arccos	arctan	arccot	arcsec	arccsc
	2.5,	2.5,	2.5,	1,		1,		1,
//	exp		ln		lg		Gamma	factorial
	20,		20,		10,		0,		5,
//	square	cube	sqrt	cbrt	sinh	cosh	tanh
	40,		20,		40,		10,		3,		3,		3
};

const float binaryWeight[64] = {
//	plus	minus	times	divide	power	powneg
	1,		1,		1,		0.5,	0.5,	0.5
};

const float unaryProb = 0.3;

//Acc : accumulating
float constantAccWeight[64] = { 0 };
float unaryAccWeight[64] = { 0 };
float binaryAccWeight[64] = { 0 };

void initAccWeight(void) {
	constantAccWeight[0] = constantWeight[0];
	unaryAccWeight[0] = unaryWeight[0];
	binaryAccWeight[0] = binaryWeight[0];
	for (int i = 1; i < 64; i++) {
		constantAccWeight[i] = constantAccWeight[i - 1] + constantWeight[i];
		unaryAccWeight[i] = unaryAccWeight[i - 1] + unaryWeight[i];
		binaryAccWeight[i] = binaryAccWeight[i - 1] + binaryWeight[i];
	}
	for (int i = 0; i < 64; i++) {
		constantAccWeight[i] /= constantAccWeight[63];
		unaryAccWeight[i] /= unaryAccWeight[63];
		binaryAccWeight[i] /= binaryAccWeight[63];
	}
}

int search(float x, float* ar) {
	int i = 0;
	while (true) {
		if (ar[i] >= x)
			return i;
		i++;
	}
}

uc* strcat(uc* p, uc* q) {
	return (uc*)strcat_s((char*)p, sizeof(p) ,(char*)q);
}

uc randomConstant(void) {
	float x = randomReal();
	return search(x, constantAccWeight);
}

uc randomUnary(void) {
	float x = randomReal();
	return search(x, unaryAccWeight) + 64;
}

uc randomBinary(void) {
	float x = randomReal();
	return search(x, binaryAccWeight) + 128;
}

uc* treeGen(int n, int len) {
	if (n <= 1) {
		uc* p = newMemory();
		p[0] = randomConstant();
		p[1] = 0;
		return p;
	}
	if (randomReal() < unaryProb || n == 2) {
		uc* p = treeGen(n - 1, len);
		p[n - 1] = randomUnary();
		p[n] = 0;
		return p;
	}
	int k = randomBetween(1, n - 2);
	uc* p = treeGen(k, len);
	uc* q = treeGen(n - 1 - k, len);
	strcat(p, q);
	p[n - 1] = randomBinary();
	p[n] = 0;
	deleteMemory(q);
	return p;
}

uc* treeGen(int n) {
	return treeGen(n, n + 1);
}

//qwq