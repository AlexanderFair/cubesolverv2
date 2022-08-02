#include "Cube.h"
#include "Solver.h"
#include <iostream>
#include <Windows.h>
#include <string>
using std::cout;
using std::string;

void setup() {
	CONSOLE_SCREEN_BUFFER_INFOEX info;
	info.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfoEx(hConsole, &info);

	info.ColorTable[1] = RGB(255, 255, 255);
	info.ColorTable[2] = RGB(0, 255, 0);
	info.ColorTable[3] = RGB(255, 0, 0);
	info.ColorTable[4] = RGB(0, 0, 255);
	info.ColorTable[5] = RGB(255, 120, 30);
	info.ColorTable[6] = RGB(255, 255, 0);
	SetConsoleScreenBufferInfoEx(hConsole, &info);
}

int main() {
	setup();

	
	Cube cube = Cube();
	Solver solver = Solver(cube);
	cube.print();

	while (true) {
		string move;
		std::cin >> move;
		if (move == "sc") {
			solver.scramble();
			continue;
		}
		else if (move == "s") {
			solver.solve();
		}
		solver.cube.moveFromStr(move);
		solver.cube.print();
	}
	
}