#pragma once
#include "Position.h"
#include "Snake.h"
#include "map.h"
#include "Item.h"
#include <vector>
#include <ncurses.h>
#include <ctime>
#include <chrono>
#include <cmath>
#include <cstdlib>


class ItemMaker{
public:

  ItemMaker(char Type);
  ~ItemMaker();

  Position getRandomPosition();
  void Making(float Time);
  void Deleting(int y, int x);

  char Type;
  float lastMakeTime = 0;
  std::vector<Item> itemVector;
};
