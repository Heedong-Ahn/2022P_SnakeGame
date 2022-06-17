// GateController.cpp

#include "Snake.h"
#include "GateController.h"

extern map *m;
extern Snake *snake;

Position nextPos;

GateController::GateController(){}
GateController::~GateController(){}

Position GateController::getRandomPosition()
{
    srand(time(NULL));
    Position p;
    while (1){
        int x = rand() % (HEIGHT);
        int y = rand() % (WIDTH);
        if (m->data[x][y] == '1'){
            p.x = x;
            p.y = y;
            break;
            
        }
    }
    return p;
}

void GateController::placeGates()
{
    Position p = getRandomPosition();
    gateVector.push_back(p);
    pushData();
    p = getRandomPosition();
    gateVector.push_back(p);
    pushData();
}

void GateController::Making(float Time){
    //if over exists time then delete
    if((Time - lastMakeTime > 8.0f && !isEntering) || lastMakeTime == 0){ 

        for(int i = gateVector.size() - 1; i >= 0; i--){
            m -> PatchData(gateVector[i].x, gateVector[i].y, '1');
            gateVector.pop_back();
            pushData();
        }

        // new gates 
        placeGates();
        lastMakeTime = Time;
    }
}


Position GateController::passGates(){
    Position exitPos;
    int exitIndex = 0;

    for(int i = 0; i < gateVector.size(); i++){
        if(gateVector[i].y == snake->wholebody[0].x && gateVector[i].x == snake->wholebody[0].y)
            exitIndex = i;
    }
    if (exitIndex == 0)
        exitIndex = 1;
    else
        exitIndex = 0;
    


    exitPos = gateVector[exitIndex]; // 5, 0
    
    // first check if it is going in the same direction, if not check in clockwise direction
    if(snake->direction == 'r'){
        if((exitPos.y+1 >= 0) && (exitPos.y+1 < WIDTH) && m->data[exitPos.x][exitPos.y+1] == '0'){
            exitPos.y += 1;
        
        }else if ((exitPos.x+1 >= 0) && (exitPos.x+1 < HEIGHT) &&m->data[exitPos.x+1][exitPos.y] == '0'){
            exitPos.x += 1;
            snake->direction = 'd';

        }else if ((exitPos.y-1 >= 0) && (exitPos.y-1 < WIDTH) && m->data[exitPos.x][exitPos.y-1] == '0' ){
            exitPos.y -= 1;
            snake->direction = 'l';

        }else if ((exitPos.x-1 >= 0) && (exitPos.x-1 < HEIGHT) && m->data[exitPos.x-1][exitPos.y] == '0'){
            exitPos.x -= 1;
            snake->direction = 'u';
        }

    }else if(snake->direction == 'l'){
        if((exitPos.y-1 >= 0) && (exitPos.y-1 < WIDTH) && m->data[exitPos.x][exitPos.y-1] == '0' ){
            exitPos.y -= 1;
        
        }else if ((exitPos.x-1 >= 0) && (exitPos.x-1 < HEIGHT) && m->data[exitPos.x-1][exitPos.y] == '0'){
            exitPos.x -= 1;
            snake->direction = 'u';

        }else if ((exitPos.y+1 >= 0) && (exitPos.y+1 < WIDTH) && m->data[exitPos.x][exitPos.y+1] == '0'){
            exitPos.y += 1;
            snake->direction = 'r';

        }else if ((exitPos.x+1 >= 0) && (exitPos.x+1 < HEIGHT) &&m->data[exitPos.x+1][exitPos.y] == '0'){
            exitPos.x += 1;
            snake->direction = 'd';
        }

    }else if(snake->direction == 'u'){
        if((exitPos.x-1 >= 0) && (exitPos.x-1 < HEIGHT) && m->data[exitPos.x-1][exitPos.y] == '0'){
            exitPos.x -= 1;
        
        }else if ((exitPos.y+1 >= 0) && (exitPos.y+1 < WIDTH) && m->data[exitPos.x][exitPos.y+1] == '0'){
            exitPos.y += 1;
            snake->direction = 'r';

        }else if ((exitPos.x+1 >= 0) && (exitPos.x+1 < HEIGHT) &&m->data[exitPos.x+1][exitPos.y] == '0'){
            exitPos.x += 1;
            snake->direction = 'd';

        }else if ((exitPos.y-1 >= 0) && (exitPos.y-1 < WIDTH) && m->data[exitPos.x][exitPos.y-1] == '0' ){
            exitPos.y -= 1;
            snake->direction = 'l';
        }

    }else if(snake->direction == 'd'){
        if((exitPos.x+1 >= 0) && (exitPos.x+1 < HEIGHT) &&m->data[exitPos.x+1][exitPos.y] == '0'){
            exitPos.x += 1;
        
        }else if ((exitPos.y-1 >= 0) && (exitPos.y-1 < WIDTH) && m->data[exitPos.x][exitPos.y-1] == '0' ){
            exitPos.y -= 1;
            snake->direction = 'l';

        }else if ((exitPos.x-1 >= 0) && (exitPos.x-1 < HEIGHT) && m->data[exitPos.x-1][exitPos.y] == '0'){
            exitPos.x -= 1;
            snake->direction = 'u';

        }else if ((exitPos.y+1 >= 0) && (exitPos.y+1 < WIDTH) && m->data[exitPos.x][exitPos.y+1] == '0'){
            exitPos.y += 1;
            snake->direction = 'r';
        }
    }

    return exitPos;
}

void GateController::pushData()
{
    for(int i = 0; i < gateVector.size(); i++)
    {
        m->PatchData(gateVector[i].x, gateVector[i].y, '7');
    }
}

