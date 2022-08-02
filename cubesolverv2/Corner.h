#pragma once
#include <stdint.h>
class Corner
{
public:
	uint8_t identity : 4;
	uint8_t orientation : 2;
	Corner();
	Corner(int i, int o);
	void changeOrientation(int change);
};

