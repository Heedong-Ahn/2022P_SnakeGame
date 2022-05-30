//Snake.h
#pragma once
#include <ncurses.h>
#include <vector>
#include "map.h"
#include "Position.h"


class Snake{
public:
  Snake();
  ~Snake();

  void makeBody();

  void PushData();
  void CutTail();

  void moveHead();

  // void setDirection();

  std::vector<Position> wholebody;
  bool isDie;
  char direction;
  bool isGrow;

  //def score
};
