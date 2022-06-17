#include "map.h"
#include "Stage.h"
#include <fstream>
#include <ncurses.h>
#include <chrono>

using namespace std;

extern Stage *stage;
extern Snake *snake;

WINDOW *winScore;
WINDOW *winMission;
WINDOW *guideWin;

map::map(){
  for(int i = 0; i < WIDTH; i++){
    for(int j = 0; j < HEIGHT; j++){
      if(i == 0 || i == WIDTH-1 || j ==0 || j == HEIGHT-1){
        if((i==0 && j == 0) || (i == WIDTH-1 && j == HEIGHT -1) || (i==0 && j==HEIGHT-1) ||  (i == WIDTH-1 && j == 0) ){
          data[j][i] = '2';
        }
        else{
          data[j][i] = '1';
        }
      }
      else{
        data[j][i] = '0';
      }
    }
  }
}
map::~map(){}
void map::getMap() {
  ifstream infile;
  string src = "maps/map" + to_string(stage->stageNum) + ".txt";
  infile.open(src);
  

  int cnt = 0;
  char buf[120];
  while(infile.getline(buf, 120)){
    
    for(int i =0;i<WIDTH; i++){
      data[cnt][i] = buf[i];
    }
    cnt++;
  }

  infile.close();
}

void map::update(){
  mvwprintw(winScore, 2, 1, "B: %d/ %d", snake->bodyLength, stage->goalBodyLength);
  mvwprintw(winScore, 3, 1, "+: %d", snake->growScore);
  mvwprintw(winScore, 4, 1, "-: %d", snake->poisonScore);
  mvwprintw(winScore, 5, 1, "G: %d", snake->gateScore);
 
  if(stage->goalBodyLength <= snake->bodyLength){
    if(stage->goalBodyLength == snake->bodyLength)
      stage->goalCnt++;
    mvwprintw(winMission, 2, 1, "B: %d (%s)", stage->goalBodyLength, "V");
    
  }else{
    mvwprintw(winMission, 2, 1, "B: %d (%s)", stage->goalBodyLength, " ");
    stage->goalCnt--;
  }

  if(stage->goalGrowScore <= snake->growScore){
    if(stage->goalGrowScore == snake->growScore)
      stage->goalCnt++;
    mvwprintw(winMission, 3, 1, "+: %d (%s)", stage->goalGrowScore, "V");
    
  }else{
    mvwprintw(winMission, 3, 1, "+: %d (%s)", stage->goalGrowScore, " ");
    stage->goalCnt--;
  }

  if(stage->goalPoisonScore <= snake->poisonScore){
    if(stage->goalPoisonScore == snake->poisonScore)
      stage->goalCnt++;
    mvwprintw(winMission, 4, 1, "-: %d (%s)", stage->goalPoisonScore, "V");
    
  }else{
    mvwprintw(winMission, 4, 1, "-: %d (%s)", stage->goalPoisonScore, " ");
    stage->goalCnt--;
  }

  if(stage->goalGateScore <= snake->gateScore){
    if(stage->goalGateScore == snake->gateScore)
      stage->goalCnt++;
    mvwprintw(winMission, 5, 1, "G: %d (%s)", stage->goalGateScore, "V");
    
  }else{
    mvwprintw(winMission, 5, 1, "G: %d (%s)", stage->goalGateScore, " ");
    stage->goalCnt--;
  }
  
  wrefresh(winScore);
  wrefresh(winMission);

  if(stage->goalCnt == 4){
    
    guideWin = newwin(4, 20, 5, 20);
    wbkgd(guideWin, COLOR_PAIR(1));
    wborder(guideWin, '.', '.', '.', '.', '.', '.', '.', '.');
    
    if(stage->stageNum != 3){
      mvwprintw(guideWin, 1, 1, "Stage Clear");
      stage->levelUp();
    }else{
      mvwprintw(guideWin, 1, 1, "All Stages Complete");
    }
    wrefresh(guideWin);

  }

}

void map::drawScreen(){
  initscr();
  resize_term(100,120);
  start_color();
  init_pair(1, COLOR_BLACK, COLOR_WHITE);

  refresh();
  guideWin = newwin(4, 35, 5, 20);
  wbkgd(guideWin, COLOR_PAIR(1));
  wborder(guideWin, '.', '.', '.', '.', '.', '.', '.', '.');
  mvwprintw(guideWin, 1, 1, "Are you ready to start?\nPress 'y' to start or else to quit");
  wrefresh(guideWin);

  //scoreboard
  winScore = newwin(7, 30, 5, 50);
  wbkgd(winScore, COLOR_PAIR(1));
  wattron(winScore, COLOR_PAIR(1));
  mvwprintw(winScore, 1, 1, "Score Board");
  mvwprintw(winScore, 2, 1, "B: %d/ %d", snake->bodyLength, stage->goalBodyLength);
  mvwprintw(winScore, 3, 1, "+: %d", snake->growScore);
  mvwprintw(winScore, 4, 1, "-: %d", snake->poisonScore);
  mvwprintw(winScore, 5, 1, "G: %d", snake->gateScore);
  wborder(winScore, '|','|','-','-','-','-','-','-');
  

  //mission board
  winMission = newwin(7, 30, 15, 50);
  wbkgd(winMission, COLOR_PAIR(1));
  wattron(winMission, COLOR_PAIR(1));
  mvwprintw(winMission, 1, 1, "Mission");
  mvwprintw(winMission, 2, 1, "B: %d", stage->goalBodyLength);
  mvwprintw(winMission, 3, 1, "+: %d", stage->goalGrowScore);
  mvwprintw(winMission, 4, 1, "-: %d", stage->goalPoisonScore);
  mvwprintw(winMission, 5, 1, "G: %d", stage->goalGateScore);
  wborder(winMission, '|','|','-','-','-','-','-','-');
  
  
  if(getch() == 'y'){
    delwin(guideWin);
    wrefresh(winScore);wrefresh(winMission);
    wrefresh(winMission);
    refresh();
    getMap();
  }else{
    endwin();
    snake->isDie=true;
  }

  
}

void *map::getData(){
  return data;
}

void map::PatchData(int y, int x, char patchData){
  this->data[y][x] = patchData;
}
