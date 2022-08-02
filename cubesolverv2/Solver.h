#pragma once
#include "Cube.h"
#include <vector>
class Solver
{
public:
	Solver(Cube& c);
	Cube cube;
	void scramble();
	void iterativeDeepening();
	void solve();
	bool dfs(int lastMoveType, int movesLeft);
};

