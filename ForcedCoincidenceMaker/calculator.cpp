#include "common.h"
#include "dictionary.h"
#include <stack>

double hi = 0, lo = 0;

void initBound(void) {
	if (bound >= 0) {
		hi = exp(bound);
		lo = allPositive ? 1 / hi : -hi;
	}
	else {
		hi = 1.79e308;
		if (allPositive)
			lo = 0;
		else
			lo = -hi;
	}
}

double constant(unsigned char i) {
	switch (i) {
	case pi_:
		return pi;
	case e_:
		return e;
	case phi_:
		return phi;
	case gamma_:
		return gamma;
	default:
		return (double)i;
	}
}

double unary(double x, unsigned char i) {
	switch (i) {
	case sqrt_:
		return sqrt(x);
	case cbrt_:
		return x >= 0 ? pow(x, 1.0 / 3.0) : -pow(-x, 1.0 / 3.0);
	case sin_:
		return sin(x);
	case cos_:
		return cos(x);
	case tan_:
		return tan(x);
	case cot_:
		return 1.0 / tan(x);
	case sec_:
		return 1.0 / cos(x);
	case csc_:
		return 1.0 / sin(x);
	case exp_:
		return exp(x);
	case ln_:
		return log(x);
	case lg_:
		return log10(x);
	case arcsin_:
		return asin(x);
	case arccos_:
		return acos(x);
	case arctan_:
		return atan(x);
	case arccot_:
		return atan(1.0 / x);
	case arcsec_:
		return acos(1.0 / x);
	case arccsc_:
		return asin(1.0 / x);
	case sinh_:
		return sinh(x);
	case cosh_:
		return cosh(x);
	case tanh_:
		return tanh(x);
	case Gamma_:
		return tgamma(x);
	case factorial_:
		return tgamma(x + 1);
	case square_:
		return x * x;
	case cube_:
		return x * x * x;
	default:
		return x;
	}
}

double binary(double x, double y, int i) {
	switch (i) {
	case plus_:
		return x + y;
	case minus_:
		return x - y;
	case times_:
		return x * y;
	case divide_:
		return x / y;
	case power_:
		return pow(x, y);
	case powerneg_:
		return pow(x, -y);
	default:
		return x;
	}
}

//result = 0: 正常, 1: 相反数, 2: 过大或者过小，输出了自变量
double unaryb(double x, unsigned char i, short* result = NULL) {
	double r = unary(x, i);
	if (allPositive && r < 0) {
		r = -r;
		if (result != NULL)
			*result = 1;
	}
	else if (result != NULL) {
		*result = 0;
	}
	if (r >= lo && r <= hi)
		return r;
	if (result != NULL)
		*result = 2;
	return x;
}

double binaryb(double x, double y, unsigned char i, short* result = NULL) {
	double r = binary(x, y, i);
	if (allPositive && r < 0) {
		r = -r;
		if (result != NULL)
			*result = 1;
	}
	else if (result != NULL) {
		*result = 0;
	}
	if (r >= lo && r <= hi)
		return r;
	if (result != NULL)
		*result = 2;
	return x;
}

double calculate(unsigned char* in) {
	int i = 0;
	double x, y;
	stack <double> mem;
	while (in[i]) {
		switch (in[i] & 192)
		{
		case 0:
			mem.push(constant(in[i]));
			break;
		case 64:
			if (mem.empty())
				return NaN;
			x = mem.top();
			mem.pop();
			mem.push(unaryb(x, in[i]));
			break;
		default:
			if (mem.size() < 2)
				return NaN;
			y = mem.top();
			mem.pop();
			x = mem.top();
			mem.pop();
			mem.push(binaryb(x, y, in[i]));
			break;
		}
		i++;
	}
	if (mem.size() == 1)
		return mem.top();
	else
		return NaN;
}


expr normalize(uc* in) {
	expr a;
	a.form = in;
	a.value = calculate(in);
	return a;
}

/*
expr normalize(uc* in) {
	expr a;
	short result;
	int pos = 0;


}
*/