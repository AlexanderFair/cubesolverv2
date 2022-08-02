#include "Edge.h"

Edge::Edge() {
	identity = 0;
	isFlipped = false;
}

Edge::Edge(int i, bool f) {
	identity = i;
	isFlipped = f;
}

void Edge::flip() {
	isFlipped ^= 1;
}
