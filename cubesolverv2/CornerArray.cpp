#include "CornerArray.h"
#include <utility>

CornerArray::CornerArray() {
	for (int i = 0; i < 8; ++i) {
		corners[i].identity = i;
	}
}

CornerArray::CornerArray(CornerArray& ca) {
	for (int i = 0; i < 8; ++i) {
		corners[i].identity = ca.corners[i].identity;
		corners[i].orientation = ca.corners[i].orientation;
	}
}

void CornerArray::addFacesToCharArr(char** faces) {
	char colorById[8][3] = {
		{'w', 'b', 'o'},
		{'w', 'r', 'b'},
		{'w', 'o', 'g'},
		{'w', 'g', 'r'},
		{'y', 'g', 'o'},
		{'y', 'r', 'g'},
		{'y', 'o', 'b'},
		{'y', 'b', 'r'},
	};
	//corners
	//w
	faces[0][0] = colorById[corners[0].identity][corners[0].orientation];
	faces[0][2] = colorById[corners[1].identity][corners[1].orientation];
	faces[0][6] = colorById[corners[2].identity][corners[2].orientation];
	faces[0][8] = colorById[corners[3].identity][corners[3].orientation];
	//y
	faces[5][0] = colorById[corners[4].identity][corners[4].orientation];
	faces[5][2] = colorById[corners[5].identity][corners[5].orientation];
	faces[5][6] = colorById[corners[6].identity][corners[6].orientation];
	faces[5][8] = colorById[corners[7].identity][corners[7].orientation];
	//g
	faces[1][0] = colorById[corners[2].identity][(corners[2].orientation + 2) % 3];
	faces[1][2] = colorById[corners[3].identity][(corners[3].orientation + 1) % 3];
	faces[1][6] = colorById[corners[4].identity][(corners[4].orientation + 1) % 3];
	faces[1][8] = colorById[corners[5].identity][(corners[5].orientation + 2) % 3];
	//r
	faces[2][0] = colorById[corners[3].identity][(corners[3].orientation + 2) % 3];
	faces[2][2] = colorById[corners[1].identity][(corners[1].orientation + 1) % 3];
	faces[2][6] = colorById[corners[5].identity][(corners[5].orientation + 1) % 3];
	faces[2][8] = colorById[corners[7].identity][(corners[7].orientation + 2) % 3];
	//b
	faces[3][0] = colorById[corners[1].identity][(corners[1].orientation + 2) % 3];
	faces[3][2] = colorById[corners[0].identity][(corners[0].orientation + 1) % 3];
	faces[3][6] = colorById[corners[7].identity][(corners[7].orientation + 1) % 3];
	faces[3][8] = colorById[corners[6].identity][(corners[6].orientation + 2) % 3];
	//o
	faces[4][0] = colorById[corners[0].identity][(corners[0].orientation + 2) % 3];
	faces[4][2] = colorById[corners[2].identity][(corners[2].orientation + 1) % 3];
	faces[4][6] = colorById[corners[6].identity][(corners[6].orientation + 1) % 3];
	faces[4][8] = colorById[corners[4].identity][(corners[4].orientation + 2) % 3];
}

bool CornerArray::isSolved() {
	for (int i = 0; i < 8; ++i) {
		if (corners[i].identity != i || corners[i].orientation != 0) {
			return false;
		}
	}

	return true;
}

void CornerArray::move(int m) {
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

void CornerArray::rmove() {
	corners[1].changeOrientation(2);
	corners[3].changeOrientation(1);
	corners[5].changeOrientation(2);
	corners[7].changeOrientation(1);

	Corner temp = corners[1];
	corners[1] = corners[3];
	corners[3] = corners[5];
	corners[5] = corners[7];
	corners[7] = temp;
}
void CornerArray::r2move() {
	std::swap(corners[1], corners[5]);
	std::swap(corners[3], corners[7]);
}
void CornerArray::rprime() {
	corners[1].changeOrientation(2);
	corners[3].changeOrientation(1);
	corners[5].changeOrientation(2);
	corners[7].changeOrientation(1);

	Corner temp = corners[1];
	corners[1] = corners[7];
	corners[7] = corners[5];
	corners[5] = corners[3];
	corners[3] = temp;
}

void CornerArray::umove() {
	Corner temp = corners[0];
	corners[0] = corners[2];
	corners[2] = corners[3];
	corners[3] = corners[1];
	corners[1] = temp;
}
void CornerArray::u2move() {
	std::swap(corners[0], corners[3]);
	std::swap(corners[1], corners[2]);
}
void CornerArray::uprime() {
	Corner temp = corners[0];
	corners[0] = corners[1];
	corners[1] = corners[3];
	corners[3] = corners[2];
	corners[2] = temp;
}

void CornerArray::fmove() {
	corners[3].changeOrientation(2);
	corners[2].changeOrientation(1);
	corners[4].changeOrientation(2);
	corners[5].changeOrientation(1);

	Corner temp = corners[2];
	corners[2] = corners[4];
	corners[4] = corners[5];
	corners[5] = corners[3];
	corners[3] = temp;
}
void CornerArray::f2move() {
	std::swap(corners[2], corners[5]);
	std::swap(corners[3], corners[4]);
}
void CornerArray::fprime() {
	corners[3].changeOrientation(2);
	corners[2].changeOrientation(1);
	corners[4].changeOrientation(2);
	corners[5].changeOrientation(1);

	Corner temp = corners[2];
	corners[2] = corners[3];
	corners[3] = corners[5];
	corners[5] = corners[4];
	corners[4] = temp;
}

void CornerArray::lmove() {
	corners[0].changeOrientation(1);
	corners[2].changeOrientation(2);
	corners[4].changeOrientation(1);
	corners[6].changeOrientation(2);

	Corner temp = corners[0];
	corners[0] = corners[6];
	corners[6] = corners[4];
	corners[4] = corners[2];
	corners[2] = temp;
}
void CornerArray::l2move() {
	std::swap(corners[0], corners[4]);
	std::swap(corners[2], corners[6]);
}
void CornerArray::lprime() {
	corners[0].changeOrientation(1);
	corners[2].changeOrientation(2);
	corners[4].changeOrientation(1);
	corners[6].changeOrientation(2);

	Corner temp = corners[0];
	corners[0] = corners[2];
	corners[2] = corners[4];
	corners[4] = corners[6];
	corners[6] = temp;
}

void CornerArray::bmove() {
	corners[0].changeOrientation(2);
	corners[1].changeOrientation(1);
	corners[6].changeOrientation(1);
	corners[7].changeOrientation(2);

	Corner temp = corners[0];
	corners[0] = corners[1];
	corners[1] = corners[7];
	corners[7] = corners[6];
	corners[6] = temp;
}
void CornerArray::b2move() {
	std::swap(corners[0], corners[7]);
	std::swap(corners[1], corners[6]);
}
void CornerArray::bprime() {
	corners[0].changeOrientation(2);
	corners[1].changeOrientation(1);
	corners[6].changeOrientation(1);
	corners[7].changeOrientation(2);

	Corner temp = corners[0];
	corners[0] = corners[6];
	corners[6] = corners[7];
	corners[7] = corners[1];
	corners[1] = temp;
}

void CornerArray::dmove() {
	Corner temp = corners[4];
	corners[4] = corners[6];
	corners[6] = corners[7];
	corners[7] = corners[5];
	corners[5] = temp;
}
void CornerArray::d2move() {
	std::swap(corners[4], corners[7]);
	std::swap(corners[6], corners[5]);
}
void CornerArray::dprime() {
	Corner temp = corners[4];
	corners[4] = corners[5];
	corners[5] = corners[7];
	corners[7] = corners[6];
	corners[6] = temp;
}