#pragma once
/*
	1 -- 31 就用本数。32 开始的是一些常数，64 开始是一元函数，128开始是二元函数。
	0 表示完毕。
*/
enum element :unsigned char {
	pi_ = 32, e_, phi_, gamma_,
	sin_ = 64, cos_, tan_, cot_, sec_, csc_,
	arcsin_, arccos_, arctan_, arccot_, arcsec_, arccsc_,
	exp_, ln_, lg_, Gamma_, factorial_, 
	square_, cube_, sqrt_, cbrt_,
	sinh_, cosh_, tanh_,
	plus_ = 128, minus_, times_, divide_, power_, powerneg_
};