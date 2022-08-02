#pragma once
#include <stdint.h>
class Edge
{
public:
	uint8_t identity : 4;
	bool isFlipped : 1;
	Edge();
	Edge(int identity, bool flipped);
	void flip();
};

