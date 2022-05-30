#pragma once

class Position
{
public:
	int x, y;
	Position(int col, int row) : x(col), y(row) {}
	Position() : x(0), y(0) {}
};
