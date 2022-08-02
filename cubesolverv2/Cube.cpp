#include "Cube.h"
#include <Windows.h>
#include <iostream>

using std::cout;
using std::string;


Cube::Cube() : corners(), edges(){}

Cube::Cube(Cube& c) : corners(c.corners), edges(c.edges){}

void printChar(char c) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	switch (c) {
	case 'w':
		SetConsoleTextAttribute(hConsole, 17);
		break;
	case 'g':
		SetConsoleTextAttribute(hConsole, 34);
		break;
	case 'r':
		SetConsoleTextAttribute(hConsole, 51);
		break;
	case 'b':
		SetConsoleTextAttribute(hConsole, 68);
		break;
	case 'o':
		SetConsoleTextAttribute(hConsole, 85);
		break;
	case 'y':
		SetConsoleTextAttribute(hConsole, 102);
		break;
	default:
		break;
	}
	std::cout << c << ' ';
	SetConsoleTextAttribute(hConsole, 15);
}

void Cube::print() {
	char ** faces;
	faces = new char*[6];
	for (int i = 0; i < 6; ++i) {
		faces[i] = new char[9];
	}
	corners.addFacesToCharArr(faces);
	edges.addEdgesToCharArr(faces);

	//centers
	faces[0][4] = 'w';
	faces[1][4] = 'g';
	faces[2][4] = 'r';
	faces[3][4] = 'b';
	faces[4][4] = 'o';
	faces[5][4] = 'y';

	//printing
	int howManyCharsPerSticker = 3;
	int charGap = 2;
	//w
	cout << '\n';
	for (int line = 0; line < 3; ++line) {
		for (int i = 0; i < howManyCharsPerSticker; ++i) {
			//spaces pre white face
			for (int j = 0; j < charGap * 2 + howManyCharsPerSticker * 3 * 2; ++j) {
				cout << ' ';
			}
			//print this line of stickers
			for (int rowNum = 0; rowNum < 3; ++rowNum) {
				//print a sticker
				for (int j = 0; j < howManyCharsPerSticker; ++j) {
					printChar(faces[0][line * 3 + rowNum]);
				}
			}
			cout << '\n';
		}
	}

	//gap between w and middle
	for (int i = 0; i < charGap / 2; ++i) {
		cout << '\n';
	}

	//o g r b
	int midf[4] = { 4, 1, 2, 3 };
	for (int line = 0; line < 3; ++line) {
		for (int j = 0; j < howManyCharsPerSticker; ++j) {
			//print each face
			for (int face = 0; face < 4; ++face) {
				//prespaces
				for (int i = 0; i < charGap; ++i) {
					cout << ' ';
				}

				for (int sticker = 0; sticker < 3; ++sticker) {
					for (int i = 0; i < howManyCharsPerSticker; ++i) {
						printChar(faces[midf[face]][line * 3 + sticker]);
					}
				}
			}
			cout << '\n';
		}//zoinks scoobs!! l-l-like, there's a MONSTER over there!!!!'
	}

	//gap between middle and y
	for (int i = 0; i < charGap / 2; ++i) {
		cout << '\n';
	}

	//y
	for (int line = 0; line < 3; ++line) {
		for (int i = 0; i < howManyCharsPerSticker; ++i) {
			//spaces pre white face
			for (int j = 0; j < charGap * 2 + howManyCharsPerSticker * 3 * 2; ++j) {
				cout << ' ';
			}
			//print this line of stickers
			for (int rowNum = 0; rowNum < 3; ++rowNum) {
				//print a sticker
				for (int j = 0; j < howManyCharsPerSticker; ++j) {
					printChar(faces[5][line * 3 + rowNum]);
				}
			}
			cout << '\n';
		}
	}

}

void Cube::move(int m) {
	switch (m) {
	case 0:
		rmove();
		break;
	case 1:
		r2move();
		break;
	case 2:
		rprime();
		break;
	case 3:
		lmove();
		break;
	case 4:
		l2move();
		break;
	case 5:
		lprime();
		break;
	case 6:
		fmove();
		break;
	case 7:
		f2move();
		break;
	case 8:
		fprime();
		break;
	case 9:
		bmove();
		break;
	case 10:
		b2move();
		break;
	case 11:
		bprime();
		break;
	case 12:
		umove();
		break;
	case 13:
		u2move();
		break;
	case 14:
		uprime();
		break;
	case 15:
		dmove();
		break;
	case 16:
		d2move();
		break;
	case 17:
		dprime();
		break;
	}
}
void Cube::unmove(int m) {
	switch (m) {
	case 0:
		rprime();
		break;
	case 1:
		r2move();
		break;
	case 2:
		rmove();
		break;
	case 3:
		lprime();
		break;
	case 4:
		l2move();
		break;
	case 5:
		lmove();
		break;
	case 6:
		fprime();
		break;
	case 7:
		f2move();
		break;
	case 8:
		fmove();
		break;
	case 9:
		bprime();
		break;
	case 10:
		b2move();
		break;
	case 11:
		bmove();
		break;
	case 12:
		uprime();
		break;
	case 13:
		u2move();
		break;
	case 14:
		umove();
		break;
	case 15:
		dprime();
		break;
	case 16:
		d2move();
		break;
	case 17:
		dmove();
		break;
	}
}
void Cube::moveFromStr(string s) {
	if (s == "r" || s == "R") { move(0); }
	else if (s == "r2" || s == "R2") { move(1); }
	else if (s == "rp" || s == "RP" || s == "r'" || s == "R'") { move(2); }
	else if (s == "l" || s == "L") { move(3); }
	else if (s == "l2" || s == "L2") { move(4); }
	else if (s == "lp" || s == "LP" || s == "l'" || s == "L'") { move(5); }
	else if (s == "f" || s == "F") { move(6); }
	else if (s == "f2" || s == "F2") { move(7); }
	else if (s == "fp" || s == "FP" || s == "f'" || s == "F'") { move(8); }
	else if (s == "b" || s == "B") { move(9); }
	else if (s == "b2" || s == "B2") { move(10); }
	else if (s == "bp" || s == "BP" || s == "b'" || s == "B'") { move(11); }
	else if (s == "u" || s == "U") { move(12); }
	else if (s == "u2" || s == "U2") { move(13); }
	else if (s == "up" || s == "UP" || s == "u'" || s == "U'") { move(14); }
	else if (s == "d" || s == "D") { move(15); }
	else if (s == "d2" || s == "D2") { move(16); }
	else if (s == "dp" || s == "DP" || s == "d'" || s == "D'") { move(17); }
	else {
		cout << "Illegal move!\n";
	}
}
string Cube::getMoveInStrForm(int m) {
	switch (m) {
	case 0:
		return "R";
	case 1:
		return "R2";
	case 2:
		return "R'";
	case 3:
		return "L";
	case 4:
		return "L2";
	case 5:
		return "L'";
	case 6:
		return "F";
	case 7:
		return "F2";
	case 8:
		return "F'";
	case 9:
		return "B";
	case 10:
		return "B2";
	case 11:
		return "B'";
	case 12:
		return "U";
	case 13:
		return "U2";
	case 14:
		return "U'";
	case 15:
		return "D";
	case 16:
		return "D2";
	case 17:
		return "D'";
	}
	return "Not a valid move!";
}

bool Cube::isSolved() {
	return corners.isSolved() && edges.isSolved();
}

void Cube::rmove() {
	corners.rmove();
	edges.rmove();
}
void Cube::r2move() {
	corners.r2move();
	edges.r2move();
}
void Cube::rprime() {
	corners.rprime();
	edges.rprime();
}

void Cube::lmove() {
	corners.lmove();
	edges.lmove();
}
void Cube::l2move() {
	corners.l2move();
	edges.l2move();
}
void Cube::lprime() {
	corners.lprime();
	edges.lprime();
}

void Cube::umove() {
	corners.umove();
	edges.umove();
}
void Cube::u2move() {
	corners.u2move();
	edges.u2move();
}
void Cube::uprime() {
	corners.uprime();
	edges.uprime();
}

void Cube::dmove() {
	corners.dmove();
	edges.dmove();
}
void Cube::d2move() {
	corners.d2move();
	edges.d2move();
}
void Cube::dprime() {
	corners.dprime();
	edges.dprime();
}

void Cube::fmove() {
	corners.fmove();
	edges.fmove();
}
void Cube::f2move() {
	corners.f2move();
	edges.f2move();
}
void Cube::fprime() {
	corners.fprime();
	edges.fprime();
}

void Cube::bmove() {
	corners.bmove();
	edges.bmove();
}
void Cube::b2move() {
	corners.b2move();
	edges.b2move();
}
void Cube::bprime() {
	corners.bprime();
	edges.bprime();
}