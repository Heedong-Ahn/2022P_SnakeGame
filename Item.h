#pragma once

class Item
{
public:
	int x, y;
  float makeTime;
	Item(int col, int row, float makeTime) : x(col), y(row), makeTime(makeTime) {}
	Item() : x(0), y(0), makeTime(0) {}
};
