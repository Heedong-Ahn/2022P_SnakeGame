#pragma once
#include "Snake.h"
#include "Position.h"
#include <vector>
#include <ncurses.h>

#define WIDTH 50
#define HEIGHT 23

class map{
public:
  map();
  ~map();

  void *getData();
  void PatchData(int y, int x, char patchData);


  char data[HEIGHT][WIDTH];
};
