#pragma once
#include "Corner.h"
class CornerArray
{
public:
	CornerArray();
	CornerArray(CornerArray& ca);

	Corner corners[8];

	void move(int m);
	void addFacesToCharArr(char** faces);

	bool isSolved();

	void rmove();
	void r2move();
	void rprime();

	void lmove();
	void l2move();
	void lprime();

	void umove();
	void u2move();
	void uprime();

	void dmove();
	void d2move();
	void dprime();

	void fmove();
	void f2move();
	void fprime();

	void bmove();
	void b2move();
	void bprime();
};

