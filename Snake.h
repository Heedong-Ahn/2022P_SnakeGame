//Snake.h
#pragma once
#include <ncurses.h>
#include <vector>
#include <chrono>
#include <ctime>
#include <unistd.h>
#include <cmath>
#include <stdlib.h>
#include "ItemMaker.h"
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
  inline bool kbhit(void);

  std::vector<Position> wholebody;
  bool isDie;
  char direction;
  bool isGrow;
  int bodyLength;
  int growScore;
  int poisonScore;
  int gateScore;


};
