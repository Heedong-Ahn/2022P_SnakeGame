//Snake.cpp
#include "Snake.h"
#include "map.h"

extern map *m;

Snake::Snake()
{
    direction = 'l';
    isDie = false;
    isGrow = false;
    makeBody();
}

Snake::~Snake()
{
}

void Snake::makeBody(){
  for (int i = 0; i < 3; i++)
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

void Snake::moveHead(){
  int ch;
  keypad(stdscr, TRUE);
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
    }

    if(wholebody.size() < 3){
      isDie = true;
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
      if (isGrow == false)
      {
          CutTail();
      }
      else
      {
          isGrow = false;
      }
    }
}
