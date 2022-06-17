//Tmain.cpp
#include <iostream>
#include <ncurses.h>
#include <chrono>
#include <cmath>
#include "Position.h"
#include "map.h"
#include "Snake.h"
#include "GameScene.h"
#include "ItemMaker.h"
#include "GateController.h"

using namespace std;


map *m;
Snake *snake;
ItemMaker *gItem;
ItemMaker *pItem;
GateController *gate;

float getMakeTime(std::chrono::steady_clock::time_point startTime){
  auto endTime = std::chrono::steady_clock::now();
  std::chrono::duration<float> elapsed_seconds = endTime - startTime;
  float Time = (float)elapsed_seconds.count();
  return Time;
}

int main(){

  initscr();
  resize_term(60,60);
  start_color();
  init_pair(1, COLOR_BLACK, COLOR_WHITE);

  refresh();
  getch();

  int width = 50;
  int height = 23;

  std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock::now();





  m = new map();
  snake = new Snake();
  gItem = new ItemMaker('G');
  pItem = new ItemMaker('P');
  gate = new GateController();

  // gate->placeGates();
  // gate->lastMakeTime = getMakeTime(startTime);

  getch();
  while(true){


    pItem->Making(getMakeTime(startTime));
    gItem->Making(getMakeTime(startTime));
    gate->Making(getMakeTime(startTime));


    snake->moveHead();
    snake->PushData();
    
    // mvprint(30, 60, snake->growScore);
    // mvprint(35, 60, snake->poisonScore);
    if(snake->isDie == true) break;
    for (int i = 0; i < HEIGHT; i++)
      {
        for (int j = 0; j < WIDTH; j++)
        {
          switch (m->data[i][j])
          {
          case '0':
            mvaddch(i, j, ' ');
            break;
          case '1':
            mvaddch(i, j, '-');
            break;
          case '2':
            mvaddch(i, j, 'X');
            break;
          case '3':
            mvaddch(i, j, 'H');
            break;
          case '4':
            mvaddch(i, j, 'B');
            break;
          case '5':
            mvaddch(i, j, 'G');
            break;
          case '6':
            mvaddch(i, j, 'P');
            break;
          case '7':
            mvaddch(i, j, '?');
            break;
          case '8':
            mvaddch(i, j, ' ');
          }
        }
      }
    refresh();
  }

  getch();

  endwin();
  return 0;
}
