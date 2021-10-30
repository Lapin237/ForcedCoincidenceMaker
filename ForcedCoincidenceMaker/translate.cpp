#include "common.h"
#include "dictionary.h"
#include<algorithm>

unsigned char dictionary[128];

unsigned char diclist[][2] = {
	{'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, 
	{'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'~', 10}, 
	{'!', 11}, {'@', 12}, {'#', 13}, {'$', 14}, {'%', 15},
	{'p', pi_}, {'e', e_}, {'f', phi_}, {'g', gamma_},
	{'s', sin_}, {'c', cos_}, {'t', tan_},
	{'S', arcsin_}, {'C', arccos_}, {'T', arctan_},
	{'E', exp_}, {'L', ln_}, {'l', lg_}, {'G', Gamma_},
	{'Q', square_}, {'q', sqrt_}, {'B', cube_}, {'b', cbrt_},
	{'+', plus_}, {'-', minus_}, {'*', times_}, {'/', divide_}, {'^', power_}, 
	{0, 0}
};

void initDictionary(void) {
	int i = 0;
	while (diclist[i][0]) {
		dictionary[diclist[i][0]] = diclist[i][1];
		i++;
	}
}

void translate(unsigned char* fml) {
	int i = 0;
	while (fml[i]) {
		fml[i] = dictionary[fml[i]];
		i++;
	}
}

#ifdef QUAD_SWITCH
void print(__float128 x) {
	int prec = 25;
	int width = 46;
	char buf[128];
	int n = quadmath_snprintf(buf, sizeof buf, "%+-#*.35Qe", width, x);
	if ((size_t)n < sizeof buf)
		cout << buf;
}
#endif

#ifndef QUAD_SWITCH
void print(double x) {
	cout << setprecision(10) << x;
}
#endif

void runCalculator(void) {
	unsigned char c[1024];
	while (true) {
		cout << "<< ";
		cin >> c;
		translate(c);
		cout << ">> ";
		print(calculate(c));
		cout << endl;
	}
}