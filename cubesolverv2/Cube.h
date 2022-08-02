#pragma once
#include "CornerArray.h"
#include "EdgeArray.h"
#include <string>

class Cube
{
public:
	CornerArray corners;
	EdgeArray edges;

	Cube();
	Cube(Cube& c);
	void print();

	void move(int m);
	void unmove(int m);
	void moveFromStr(std::string s);
	std::string getMoveInStrForm(int m);

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

