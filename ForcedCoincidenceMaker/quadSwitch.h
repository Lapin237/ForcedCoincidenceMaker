#pragma once
#include <quadmath.h>

#define QUAD_SWITCH

#define double __float128
#define pi M_PIq
#define e M_Eq
#define epsilon 1e-28q
#define phi 1.6180339887498948482045868343656381177203091798057628621354486227q
#define gamma 0.57721566490153286060651209008240243104215933593992359880576723q
#define pow powq
#define sin sinq
#define cos cosq
#define tan tanq
#define sqrt sqrtq
#define exp expq
#define log logq
#define log10 log10q
#define asin asinq
#define acos acosq
#define atan atanq
#define sinh sinhq
#define cosh coshq
#define tanh tanhq
#define tgamma tgammaq

void print(__float128 x);
