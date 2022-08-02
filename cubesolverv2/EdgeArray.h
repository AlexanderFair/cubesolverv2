#pragma once
#include "Edge.h"
class EdgeArray
{
public:
	EdgeArray();
	EdgeArray(EdgeArray& ea);

	Edge edges[12];

	void addEdgesToCharArr(char** faces);

	bool isSolved();

	void move(int m);

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

