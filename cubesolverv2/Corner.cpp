#include "Corner.h"

Corner::Corner() {
	identity = 0;
	orientation = 0;
}

Corner::Corner(int i, int o) {
	identity = i;
	orientation = o;
}

void Corner::changeOrientation(int change) {
	orientation = (orientation + change) % 3;
}