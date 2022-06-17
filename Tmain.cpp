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
#include "Stage.h"

using namespace std;


map *m;
Snake *snake;
ItemMaker *gItem;
ItemMaker *pItem;
GateController *gate;
Stage *stage;

float getMakeTime(std::chrono::steady_clock::time_point startTime){
  auto endTime = std::chrono::steady_clock::now();
  std::chrono::duration<float> elapsed_seconds = endTime - startTime;
  float Time = (float)elapsed_seconds.count();
  return Time;
}

void setScreen() {
  // WINDOW *winGameZone;
  WINDOW *winScore;
  WINDOW *winMission;

  // setlocale(LC_ALL, ""); // using Unicode

  // initscr();
  // resize_term(80,60);
  // start_color();
  // init_pair(1, COLOR_BLACK, COLOR_WHITE);

  // border('*','*','*','*','*','*','*','*');
  // refresh();
  // getch();

  int width = 60;
  // int height = 60;

  // // SnakeHead sh(width/2, height/2);

  // winGameZone = newwin(height,width, 1, 1);
  // wbkgd(winGameZone, COLOR_PAIR(1));
  // wattron(winGameZone, COLOR_PAIR(1));
  // //initialize map
  // // 3 == SnakeHead;
  // // 2 == immune wall
  // // 1 == wall
  // // 0 == nothing
  // for(int i = 0; i < width; i++){
  //   for(int j = 0; j < height; j++){
  //     if(i == 0 || i == width-1 || j ==0 || j == height-1){
  //       if( (i == j) || (i==0 && j==height-1) ||  (i == width-1 && j == 0) ){
  //         mvwprintw(winGameZone, j, i, "2");
  //       }
  //       else{
  //         mvwprintw(winGameZone, j, i, "1");
  //       }
  //     }
  //     else{
  //       mvwprintw(winGameZone, j, i, "0");
  //     }
  //   }
  // }
  // mvwprintw(winGameZone, 10, 10, "3");

  // wrefresh(winGameZone);

  // getch();
  // for(int k = 0; k < 20; k++){
  //   if(sh.moveHead()){
  //     for(int i = 0; i < width; i++){
  //       for(int j = 0; j < height; j++){
  //         if(i == 0 || i == width-1 || j ==0 || j == height-1){
  //           if( (i == j) || (i==0 && j==height-1) ||  (i == width-1 && j == 0) ){
  //             mvwprintw(winGameZone, j, i, "2");
  //           }
  //           else{
  //             mvwprintw(winGameZone, j, i, "1");
  //           }
  //         }
  //         else{
  //           mvwprintw(winGameZone, j, i, "0");
  //         }
  //       }
  //     }
  //     mvwprintw(winGameZone, sh.getY(), sh.getX(), "3");
  //     wrefresh(winGameZone);
  //   }else{
  //     delwin(winScore);
  //     delwin(winMission);
  //     endwin();
  //   }
  // }


  // for(int k = 0; k < 20; k++){
  //   sh.moveHead();
  //   for(int i = 0; i < width; i++){
  //     for(int j = 0; j < height; j++){
  //       if(i == 0 || i == width-1 || j ==0 || j == height-1){
  //         if( (i == j) || (i==0 && j==height-1) ||  (i == width-1 && j == 0) ){
  //           mvwprintw(winGameZone, j, i, "2");
  //         }
  //         else{
  //           mvwprintw(winGameZone, j, i, "1");
  //         }
  //       }
  //       else{
  //         mvwprintw(winGameZone, j, i, "0");
  //       }
  //     }
  //   }
  //   mvwprintw(winGameZone, sh.getY(), sh.getX(), "3");
  //   wrefresh(winGameZone);
  // }


}

int main(){

  // initscr();
  // resize_term(100,60);
  // start_color();
  // init_pair(1, COLOR_BLACK, COLOR_WHITE);

  // // WINDOW *scoreWin;
  // WINDOW *guideWin;

  // // scoreWin = newwin(5, 10, 40, 40);
  



  // refresh();
  // // int ch;
  // guideWin = newwin(3, 30, 10, 20);
  // wbkgd(guideWin, COLOR_PAIR(1));
  // wborder(guideWin, '.', '.', '.', '.', '.', '.', '.', '.');
  // mvwprintw(guideWin, 1, 1, "Are you ready to start?");
  // wrefresh(guideWin);

  
  // if(getch() == 'y'){
  //   delwin(guideWin);
  //   setScreen();
  // }

  // int width = 50;
  // int height = 23;

  std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock::now();





  m = new map();
  stage = new Stage();
  snake = new Snake();
  gItem = new ItemMaker('G');
  pItem = new ItemMaker('P');
  gate = new GateController();

  m->drawScreen();
  
  // m->getMap();

  // getch();
  while(true){
    

    pItem->Making(getMakeTime(startTime));
    gItem->Making(getMakeTime(startTime));
    gate->Making(getMakeTime(startTime));


    snake->moveHead();
    snake->PushData();
    m->update();
    
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
    // refresh();
  }



  endwin();
  return 0;
}
