#include "EdgeArray.h"
#include <utility>

EdgeArray::EdgeArray() {
	for (int i = 0; i < 12; ++i) {
		edges[i].identity = i;
	}
}

EdgeArray::EdgeArray(EdgeArray& ea) {
	for (int i = 0; i < 12; ++i) {
		edges[i].identity = ea.edges[i].identity;
		edges[i].isFlipped = ea.edges[i].isFlipped;
	}
}


void EdgeArray::addEdgesToCharArr(char** faces) {
	//edges
	char edgeColorByID[12][2] = {
		{'w', 'b'},
		{'w', 'o'},
		{'w', 'r'},
		{'w', 'g'},
		{'g', 'o'},
		{'g', 'r'},
		{'b', 'o'},
		{'b', 'r'},
		{'y', 'g'},
		{'y', 'o'},
		{'y', 'r'},
		{'y', 'b'}
	};
	//w
	faces[0][1] = edgeColorByID[edges[0].identity][edges[0].isFlipped];
	faces[0][3] = edgeColorByID[edges[1].identity][edges[1].isFlipped];
	faces[0][5] = edgeColorByID[edges[2].identity][edges[2].isFlipped];
	faces[0][7] = edgeColorByID[edges[3].identity][edges[3].isFlipped];
	//y
	faces[5][1] = edgeColorByID[edges[8].identity][edges[8].isFlipped];
	faces[5][3] = edgeColorByID[edges[9].identity][edges[9].isFlipped];
	faces[5][5] = edgeColorByID[edges[10].identity][edges[10].isFlipped];
	faces[5][7] = edgeColorByID[edges[11].identity][edges[11].isFlipped];
	//g
	faces[1][1] = edgeColorByID[edges[3].identity][edges[3].isFlipped ^ 1];
	faces[1][3] = edgeColorByID[edges[4].identity][edges[4].isFlipped];
	faces[1][5] = edgeColorByID[edges[5].identity][edges[5].isFlipped];
	faces[1][7] = edgeColorByID[edges[8].identity][edges[8].isFlipped ^ 1];
	//r
	faces[2][1] = edgeColorByID[edges[2].identity][edges[2].isFlipped ^ 1];
	faces[2][3] = edgeColorByID[edges[5].identity][edges[5].isFlipped ^ 1];
	faces[2][5] = edgeColorByID[edges[7].identity][edges[7].isFlipped ^ 1];
	faces[2][7] = edgeColorByID[edges[10].identity][edges[10].isFlipped ^ 1];
	//b
	faces[3][1] = edgeColorByID[edges[0].identity][edges[0].isFlipped ^ 1];
	faces[3][3] = edgeColorByID[edges[7].identity][edges[7].isFlipped];
	faces[3][5] = edgeColorByID[edges[6].identity][edges[6].isFlipped];
	faces[3][7] = edgeColorByID[edges[11].identity][edges[11].isFlipped ^ 1];
	//o
	faces[4][1] = edgeColorByID[edges[1].identity][edges[1].isFlipped ^ 1];
	faces[4][3] = edgeColorByID[edges[6].identity][edges[6].isFlipped ^ 1];
	faces[4][5] = edgeColorByID[edges[4].identity][edges[4].isFlipped ^ 1];
	faces[4][7] = edgeColorByID[edges[9].identity][edges[9].isFlipped ^ 1];
}

bool EdgeArray::isSolved() {
	for (int i = 0; i < 12; ++i) {
		if (edges[i].identity != i || edges[i].isFlipped) {
			return false;
		}
	}
	return true;
}

void EdgeArray::move(int m) {
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
		dmove();
		break;
	case 17:
		dmove();
		break;
	}
}


void EdgeArray::rmove() {
	Edge temp = edges[2];
	edges[2] = edges[5];
	edges[5] = edges[10];
	edges[10] = edges[7];
	edges[7] = temp;
}
void EdgeArray::r2move() {
	std::swap(edges[2], edges[10]);
	std::swap(edges[5], edges[7]);
}
void EdgeArray::rprime() {
	Edge temp = edges[2];
	edges[2] = edges[7];
	edges[7] = edges[10];
	edges[10] = edges[5];
	edges[5] = temp;
}

void EdgeArray::lmove() {
	Edge temp = edges[1];
	edges[1] = edges[6];
	edges[6] = edges[9];
	edges[9] = edges[4];
	edges[4] = temp;
}
void EdgeArray::l2move() {
	std::swap(edges[1], edges[9]);
	std::swap(edges[4], edges[6]);
}
void EdgeArray::lprime() {
	Edge temp = edges[1];
	edges[1] = edges[4];
	edges[4] = edges[9];
	edges[9] = edges[6];
	edges[6] = temp;
}

void EdgeArray::umove() {
	Edge temp = edges[0];
	edges[0] = edges[1];
	edges[1] = edges[3];
	edges[3] = edges[2];
	edges[2] = temp;
}
void EdgeArray::u2move() {
	std::swap(edges[0], edges[3]);
	std::swap(edges[1], edges[2]);
}
void EdgeArray::uprime() {
	Edge temp = edges[0];
	edges[0] = edges[2];
	edges[2] = edges[3];
	edges[3] = edges[1];
	edges[1] = temp;
}

void EdgeArray::dmove() {
	Edge temp = edges[8];
	edges[8] = edges[9];
	edges[9] = edges[11];
	edges[11] = edges[10];
	edges[10] = temp;
}
void EdgeArray::d2move() {
	std::swap(edges[8], edges[11]);
	std::swap(edges[9], edges[10]);
}
void EdgeArray::dprime() {
	Edge temp = edges[8];
	edges[8] = edges[10];
	edges[10] = edges[11];
	edges[11] = edges[9];
	edges[9] = temp;
}

void EdgeArray::fmove() {
	edges[3].flip();
	edges[4].flip();
	edges[5].flip();
	edges[8].flip();
	Edge temp = edges[3];
	edges[3] = edges[4];
	edges[4] = edges[8];
	edges[8] = edges[5];
	edges[5] = temp;
}
void EdgeArray::f2move() {
	std::swap(edges[3], edges[8]);
	std::swap(edges[4], edges[5]);
}
void EdgeArray::fprime() {
	edges[3].flip();
	edges[4].flip();
	edges[5].flip();
	edges[8].flip();
	Edge temp = edges[3];
	edges[3] = edges[5];
	edges[5] = edges[8];
	edges[8] = edges[4];
	edges[4] = temp;
}

void EdgeArray::bmove() {
	edges[0].flip();
	edges[6].flip();
	edges[7].flip();
	edges[11].flip();
	Edge temp = edges[0];
	edges[0] = edges[7];
	edges[7] = edges[11];
	edges[11] = edges[6];
	edges[6] = temp;
}
void EdgeArray::b2move() {
	std::swap(edges[0], edges[11]);
	std::swap(edges[6], edges[7]);
}
void EdgeArray::bprime() {
	edges[0].flip();
	edges[6].flip();
	edges[7].flip();
	edges[11].flip();
	Edge temp = edges[0];
	edges[0] = edges[6];
	edges[6] = edges[11];
	edges[11] = edges[7];
	edges[7] = temp;
}