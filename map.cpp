#include "map.h"
#include <fstream>

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

void *map::getData(){
  return data;
}

void map::PatchData(int y, int x, char patchData){
  this->data[y][x] = patchData;
}
