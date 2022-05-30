//main.cpp
#include <iostream>
#include <ncurses.h>
#include "map.h"

#include "SnakeHead.h"

using namespace std;

int main(){

  WINDOW *winGameZone;
  WINDOW *winScore;
  WINDOW *winMission;

  initscr();
  resize_term(60,60);
  start_color();
  init_pair(1, COLOR_BLACK, COLOR_WHITE);

  border('*','*','*','*','*','*','*','*');
  refresh();
  getch();

  int width = 50;
  int height = 23;

  SnakeHead sh(width/2, height/2);

  winGameZone = newwin(height,width, 1, 1);
  wbkgd(winGameZone, COLOR_PAIR(1));
  wattron(winGameZone, COLOR_PAIR(1));
  //initialize map
  // 3 == SnakeHead;
  // 2 == immune wall
  // 1 == wall
  // 0 == nothing
  for(int i = 0; i < width; i++){
    for(int j = 0; j < height; j++){
      if(i == 0 || i == width-1 || j ==0 || j == height-1){
        if( (i == j) || (i==0 && j==height-1) ||  (i == width-1 && j == 0) ){
          mvwprintw(winGameZone, j, i, "2");
        }
        else{
          mvwprintw(winGameZone, j, i, "1");
        }
      }
      else{
        mvwprintw(winGameZone, j, i, "0");
      }
    }
  }
  mvwprintw(winGameZone, sh.getY(), sh.getX(), "3");

  wrefresh(winGameZone);

  getch();
  for(int k = 0; k < 20; k++){
    if(sh.moveHead()){
      for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){
          if(i == 0 || i == width-1 || j ==0 || j == height-1){
            if( (i == j) || (i==0 && j==height-1) ||  (i == width-1 && j == 0) ){
              mvwprintw(winGameZone, j, i, "2");
            }
            else{
              mvwprintw(winGameZone, j, i, "1");
            }
          }
          else{
            mvwprintw(winGameZone, j, i, "0");
          }
        }
      }
      mvwprintw(winGameZone, sh.getY(), sh.getX(), "3");
      wrefresh(winGameZone);
    }else{
      delwin(winScore);
      delwin(winMission);
      endwin();
    }
  }


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

  //scoreboard
  winScore = newwin(7, 25, 5, width + 5);
  wbkgd(winScore, COLOR_PAIR(1));
  wattron(winScore, COLOR_PAIR(1));
  mvwprintw(winScore, 1, 1, "Score Board");
  mvwprintw(winScore, 2, 1, "B: /");
  mvwprintw(winScore, 3, 1, "+: ");
  mvwprintw(winScore, 4, 1, "-: ");
  mvwprintw(winScore, 5, 1, "G: ");
  wborder(winScore, '|','|','-','-','-','-','-','-');
  wrefresh(winScore);

  //mission board
  winMission = newwin(7, 25, 15, width + 5);
  wbkgd(winMission, COLOR_PAIR(1));
  wattron(winMission, COLOR_PAIR(1));
  mvwprintw(winMission, 1, 1, "Mission");
  mvwprintw(winMission, 2, 1, "B: ");
  mvwprintw(winMission, 3, 1, "+: ");
  mvwprintw(winMission, 4, 1, "-: ");
  mvwprintw(winMission, 5, 1, "G: ");
  wborder(winMission, '|','|','-','-','-','-','-','-');
  wrefresh(winMission);

  getch();
  delwin(winScore);
  delwin(winMission);
  endwin();
  return 0;
}
