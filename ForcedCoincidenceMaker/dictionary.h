#pragma once
/*
	1 -- 31 ���ñ�����32 ��ʼ����һЩ������64 ��ʼ��һԪ������128��ʼ�Ƕ�Ԫ������
	0 ��ʾ��ϡ�
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