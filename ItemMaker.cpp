#include "ItemMaker.h"
#include "Position.h"
#include "Snake.h"
#include "map.h"

extern map *m;

ItemMaker::ItemMaker(char Type):Type(Type){}

ItemMaker::~ItemMaker(){}

Position ItemMaker::getRandomPosition(){
  srand(time(NULL));
  Position p;
  while (1){
    int x = rand() % (WIDTH);
    int y = rand() % (HEIGHT);
    if (m->data[y][x] == '0')
    {
        p.x = x;
        p.y = y;
        break;
    }
  }
  return p;
}

void ItemMaker::Making(float Time){
  //make part
  if(itemVector.size() < 3 && Time - lastMakeTime > 3.0f){
    Position pos = getRandomPosition();
    itemVector.push_back(Item(pos.x,pos.y, Time));
    for(int i = 0; i < itemVector.size(); i++){
      if(this->Type == 'G'){
        m->PatchData(itemVector[i].y, itemVector[i].x, '5');
      }
      else if(this->Type = 'P'){
        m->PatchData(itemVector[i].y, itemVector[i].x, '6');
      }
    }
    lastMakeTime = Time;
  }

  //if over exists time then delete
  for(int i = itemVector.size() - 1; i >= 0; i--){
    if(Time - itemVector[i].makeTime > 7.0f){
      m -> PatchData(itemVector[i].y, itemVector[i].x, '0');
      itemVector.erase(itemVector.begin() + i);
    }
  }

}





void ItemMaker::Deleting(int y, int x){
  int pos;

  for (int i = 0; i < itemVector.size(); i++){
    if (itemVector[i].x == x && itemVector[i].y == y){
      pos = i;
    }
  }
  itemVector.erase(itemVector.begin() + pos);
}
