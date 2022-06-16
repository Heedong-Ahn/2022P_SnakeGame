#pragma once
#include "Snake.h"
#include "map.h"
#include <iostream>

#include <vector>
#include <ncurses.h>
#include <cstdlib>
#include <ctime>

class GameScene{
public:
  int score;
  char edgechar;

  GameScene();
  ~GameScene();

  void InitGameWindow();
  void Update(float eTime);
  void Render();
  void ProcessCollision();

};
