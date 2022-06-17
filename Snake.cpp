//Snake.cpp
#include <iostream>
#include "Snake.h"
#include "map.h"
#include "GateController.h"

extern map *m;
extern ItemMaker *gItem;
extern ItemMaker *pItem;
extern GateController *gate;

Snake::Snake()
{
    direction = 'l';
    isDie = false;
    isGrow = false;
    int bodyLength = 5;
    int growScore = 0;
    int poisonScore = 0;
    int gateScore = 0;
    makeBody();
}

Snake::~Snake(){}

void Snake::makeBody(){
  for (int i = 0; i < 5; i++)
  {
      wholebody.push_back(Position(25 + i, 10));
  }
}

void Snake::PushData(){
  for (int i = 0; i < wholebody.size(); i++)
  {
      if (i == 0)
      {
          m->PatchData(wholebody[i].y, wholebody[i].x, '3');
      }
      else
      {
          m->PatchData(wholebody[i].y, wholebody[i].x, '4');
      }
  }
}

void Snake::CutTail()
{
    m->PatchData(wholebody[wholebody.size() - 1].y, wholebody[wholebody.size() - 1].x, '0');
    wholebody.pop_back();
}

inline bool Snake::kbhit(void){
    int ch;
    bool ret;

    nodelay(stdscr, TRUE);

    ch = getch();
    if ( ch == ERR ) {
        ret = false;
    } else {
        ret = true;
        ungetch(ch); // 마지막에 받은 문자를 버퍼에 다시 넣어서 다음 getch()가 받을 수 있도록 합니다.
    }

    nodelay(stdscr, FALSE);
    return ret;
}



void Snake::moveHead(){
  int ch;
  keypad(stdscr, TRUE);

  if(kbhit()){
    ch = getch();

    switch(ch){

      case KEY_LEFT:
      if(direction == 'r'){
        isDie = true;
      }
      direction = 'l';
      break;
      case KEY_RIGHT:
      if(direction == 'l'){
        isDie = true;
      }
      direction = 'r';
      break;
      case KEY_UP:
      if(direction == 'd'){
        isDie = true;
      }
      direction = 'u';
      break;
      case KEY_DOWN:
      if(direction == 'u'){
        isDie = true;
      }
      direction = 'd';
      break;

      case NULL:
      break;
      }
  }




    if(isDie == false){
      if (direction == 'l')
      {
          wholebody.insert(wholebody.begin(), Position(wholebody[0].x - 1, wholebody[0].y));
      }
      else if (direction == 'r')
      {
          wholebody.insert(wholebody.begin(), Position(wholebody[0].x + 1, wholebody[0].y));
      }
      else if (direction == 'u')
      {
          wholebody.insert(wholebody.begin(), Position(wholebody[0].x, wholebody[0].y - 1));
      }
      else if (direction == 'd')
      {
          wholebody.insert(wholebody.begin(), Position(wholebody[0].x, wholebody[0].y + 1));
      }

      // hitting body self -> die || hitting wall and immune wall
      if(m->data[wholebody[0].y][wholebody[0].x] == '4' ||
    m->data[wholebody[0].y][wholebody[0].x] == '1' ||
  m->data[wholebody[0].y][wholebody[0].x] == '2' ){
        isDie = true;
      }

      // eatting Growth item -> isGrow = true , delete the item
      if(m->data[wholebody[0].y][wholebody[0].x] == '5'){
        gItem->Deleting(wholebody[0].y,wholebody[0].x);
        isGrow = true;
        bodyLength++;
        growScore++;
      }
      // eatting Poison item -> cutTail , delete the item
      else if(m->data[wholebody[0].y][wholebody[0].x] == '6'){
        pItem->Deleting(wholebody[0].y,wholebody[0].x);
        CutTail();
        bodyLength--;
        poisonScore++;
      }

      // entering gate
      if(m->data[wholebody[0].y][wholebody[0].x] == '7'){
        gate->isEntering = true;
        Position newPos = gate->passGates();
        wholebody[0].x = newPos.y;
        wholebody[0].y = newPos.x;
        gateScore++;
        gate->gateChgCnt = wholebody.size();
      }

      // tail exiting gate
      if(gate->isEntering){
        if(gate->gateChgCnt == wholebody.size()){
          gate->isEntering = false;
        }
        gate->gateChgCnt++;
      }

      if(wholebody.size() <= 3){
        isDie = true;
        return;
      }


      if (isGrow == false)
      {
          CutTail();
      }

      else
      {
          isGrow = false;
      }

      usleep(150000);
  }
}
