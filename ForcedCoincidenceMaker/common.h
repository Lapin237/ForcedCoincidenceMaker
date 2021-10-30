#pragma once
using namespace std;
#include <iostream>
#include <cmath>
#include <iomanip>
#define initRandom InitWELLRNG512a
#define random WELLRNG512a

#define uc unsigned char

#define epsilon 1e-12
#define pi 3.1415926535897932384626433832795028841971693993751058209749445923
#define e 2.718281828459045235360287471352662497757247093699959574966967627
#define phi 1.6180339887498948482045868343656381177203091798057628621354486227
#define gamma 0.57721566490153286060651209008240243104215933593992359880576723
#define NaN nan("Lapin237")

//	#include "quadSwitch.h"

#define bound 7.0
#define allPositive true

#define million 1000000

void InitWELLRNG512a(void);
unsigned int WELLRNG512a(void);
float randomReal(void);
void initiate(void);
void initDictionary(void);
void initBound(void);
void initAccWeight(void);

int randomBetween(int, int);
double calculate(unsigned char* in);
void translate(unsigned char* fml);
void runCalculator(void);
void print(double);
uc* treeGen(int);
uc* treeGen(int, int);

struct expr {
	uc* form;
	double value;
};

expr normalize(uc*);
expr randomExpr(void);
void search0(void);