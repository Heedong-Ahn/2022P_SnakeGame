//Tmain.cpp
#include <iostream>
#include <ncurses.h>
#include "Position.h"
#include "map.h"
#include "Snake.h"
#include "GameScene.h"
using namespace std;

extern Snake *snake;

int main(){

  // WINDOW *winScore;
  // WINDOW *winMission;


  // initscr();
  // resize_term(60,60);
  // start_color();
  // init_pair(1, COLOR_BLACK, COLOR_WHITE);
  //
  // refresh();
  // getch();
  //
  // int width = 50;
  // int height = 23;

  // Snake *snake;
  // map *m;
  //
  // m = new map();
  // snake = new Snake();
  //
  // snake->makeBody();


  //initialize map
  // 3 == SnakeHead;
  // 2 == immune wall
  // 1 == wall
  // 0 == nothing
  // for (int i = 0; i < HEIGHT; i++)
  //   {
  //     for (int j = 0; j < WIDTH; j++)
  //     {
  //       switch (m->data[i][j])
  //       {
  //       case '0':
  //         mvaddch(i, j, ' ');
  //         break;
  //       case '1':
  //         mvaddch(i, j, '-');
  //         break;
  //       case '2':
  //         mvaddch(i, j, 'X');
  //         break;
  //       case '3':
  //         mvaddch(i, j, 'H');
  //         break;
  //       case '4':
  //         mvaddch(i, j, 'B');
  //         break;
  //       case '5':
  //         mvaddch(i, j, 'G');
  //         break;
  //       case '6':
  //         mvaddch(i, j, 'P');
  //         break;
  //       case '7':
  //         mvaddch(i, j, '?');
  //         break;
  //       case '8':
  //         mvaddch(i, j, ' ');
  //       }
  //     }
  //   }
  // refresh();
  GameScene *gameScene;
  gameScene = new GameScene();
  gameScene->Render();


  getch();
  for(int k = 0; k < 20; k++){
    snake->moveHead();
    snake->PushData();
    gameScene->Render();
  }

  //scoreboard
  // winScore = newwin(7, 25, 5, width + 5);
  // wbkgd(winScore, COLOR_PAIR(1));
  // wattron(winScore, COLOR_PAIR(1));
  // mvwprintw(winScore, 1, 1, "Score Board");
  // mvwprintw(winScore, 2, 1, "B: /");
  // mvwprintw(winScore, 3, 1, "+: ");
  // mvwprintw(winScore, 4, 1, "-: ");
  // mvwprintw(winScore, 5, 1, "G: ");
  // wborder(winScore, '|','|','-','-','-','-','-','-');
  // wrefresh(winScore);
  //
  // //mission board
  // winMission = newwin(7, 25, 15, width + 5);
  // wbkgd(winMission, COLOR_PAIR(1));
  // wattron(winMission, COLOR_PAIR(1));
  // mvwprintw(winMission, 1, 1, "Mission");
  // mvwprintw(winMission, 2, 1, "B: ");
  // mvwprintw(winMission, 3, 1, "+: ");
  // mvwprintw(winMission, 4, 1, "-: ");
  // mvwprintw(winMission, 5, 1, "G: ");
  // wborder(winMission, '|','|','-','-','-','-','-','-');
  // wrefresh(winMission);

  getch();
  // delwin(winScore);
  // delwin(winMission);
  endwin();
  return 0;
}
