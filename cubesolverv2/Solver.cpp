#include "Solver.h"
#include <iostream>
#include <chrono>

typedef std::chrono::high_resolution_clock Clock;
using std::cout;
using std::vector;

int totalVisited = 0;
vector<int> solutionPath;

Solver::Solver(Cube& c) {
	cube = c;
}

float getTime(std::chrono::steady_clock::time_point start, std::chrono::steady_clock::time_point end) {
	return (float)std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / 1000000000;
}

void printTime(std::chrono::steady_clock::time_point start, std::chrono::steady_clock::time_point end) {
	cout << getTime(start, end);
}

int getRand(int max) {
	return (int)((float)std::rand() / RAND_MAX * max);
}

void Solver::scramble() {
	auto t = (unsigned int) time(0);
	std::srand(t);
	/*for (int i = 0; i < 100; ++i) {
		cout << getRand(2) << '\n';
	}*/
	cout << "Enter how many moves to scramble\n";
	int moves;
	std::cin >> moves;
	cout << "Scramble is: ";
	//first move
	int lastMove = getRand(3);
	bool doneOp = false;
	bool inv = getRand(2);
	int change = getRand(3);
	cube.move(lastMove * 6 + inv * 3 + change);
	cout << cube.getMoveInStrForm(lastMove * 6 + inv * 3 + change) << ' ';
	//cout << lastMove << " l " << inv << " i " << change << " c\n";
	moves--;
	while (moves > 0) {
		int newMove = getRand(3);
		//cout << newMove << " new\n";
		if (newMove == lastMove) {
			//either make a new move, or do inverse of this move
			if (doneOp) {
				//make new
				newMove += 1 + getRand(2);
				newMove %= 3;
				lastMove = newMove;
				doneOp = false;
				inv = getRand(2);
				change = getRand(3);
				cube.move(lastMove * 6 + inv * 3 + change);
				cout << cube.getMoveInStrForm(lastMove * 6 + inv * 3 + change) << ' ';
			} else {
				doneOp = true;
				change = getRand(3);
				cout << cube.getMoveInStrForm(lastMove * 6 + (inv ^ 1) * 3 + change) << ' ';
				cube.move(lastMove * 6 + (inv ^ 1) * 3 + change);
			}
		}
		else {
			doneOp = false;
			inv = getRand(2);
			change = getRand(3);
			lastMove = newMove;
			cube.move(lastMove * 6 + inv * 3 + change);
			cout << cube.getMoveInStrForm(lastMove * 6 + inv * 3 + change) << ' ';
		}
		--moves;
	}
	cout << '\n';
	cube.print();
}

void Solver::iterativeDeepening() {
	solutionPath.clear();
	if (cube.isSolved()) {
		cout << "Already solved!\n";
		return;
	}

	cout << "Enter the max depth that it will search\n";
	int maxDepth;
	std::cin >> maxDepth;
	auto totalStart = Clock::now();
	for (int d = 1; d <= maxDepth; d++) {
		totalVisited = 0;
		auto iterStart = Clock::now();
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; ++j) {
				cube.move(i * 3 + j);
				if (dfs(i, d - 1)) {
					solutionPath.push_back(i * 3 + j);
					break;
				}
				cube.unmove(i * 3 + j);
			}
		}
		if (!solutionPath.empty()) {
			break;
		}
		auto iterEnd = Clock::now();
		cout << "Couldn't find a solution with a depth of " << d;
		cout << " visited " << totalVisited << " states with ";
		cout << (long int)((float) totalVisited / getTime(iterStart, iterEnd)) << " sps";
		cout << " (took ";
		printTime(iterStart, iterEnd);
		cout << " seconds)";
		cout << ", increasing depth...\n";
	}
	auto totalEnd = Clock::now();

	if (solutionPath.empty()) {
		cout << "Couldn't find a solution :(\n";
		return;
	}

	cout << "Found a solution! It is:\n";
	for (auto i = solutionPath.size() - 1; i > 0; --i) {
		cout << cube.getMoveInStrForm(solutionPath.at(i)) << ' ';
	}
	cout << cube.getMoveInStrForm(solutionPath.at(0)) << '\n';
	cout << "\nTotal time taken: ";
	printTime(totalStart, totalEnd);
	cout << " seconds\n";

}

bool Solver::dfs(int lastMoveType, int movesLeft) {
	//be in bools add to a master path only wehn solved?, carry trhough the last move as a num instead
	++totalVisited;
	if (movesLeft == 0) {
		if (cube.isSolved()) {
			return true;
		}
		return false;;
	}

	int otherDontDo = lastMoveType  - lastMoveType % 2;
	int tm;
	for (int i = 0; i < 6; ++i) {
		if (i == lastMoveType || i == otherDontDo) {
			continue;
		}
		tm = i * 3;

		//do the move!
		for (int c = 0; c < 3; ++c) {
			//@TODO:: do three r moves instead of r - rp, r2 - r2, rp - r??
			cube.move(tm);
			if (dfs(i, movesLeft - 1)) {
				solutionPath.push_back(tm + c);
				return true;
			}
		}
		cube.move(tm);
	}

	return false;
}


void Solver::solve() {
	iterativeDeepening();
}