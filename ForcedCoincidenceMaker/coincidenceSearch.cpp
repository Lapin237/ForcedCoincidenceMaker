#include "common.h"
#define exprLength 12

bool equal(double a, double b) {
	return (a / b < 1 + epsilon) && (b / a < 1 + epsilon);
}

expr randomExpr(void) {
	return normalize(treeGen(exprLength));
}

const double search0Error = 0.49;

void search0Once(void) {
	expr r;
	r = randomExpr();
	if (r.value - floor(r.value) < search0Error || ceil(r.value) - r.value < search0Error) {
		cout << r.form << " = ";
		print(r.value);
		cout << endl;
	}
}

void search0(void) {
	int count = 0;
	while (true) {
		search0Once();
		count++;
		if (count % million == 0) {
			cout << count / million << "M trials.\n";
		}
	}
}