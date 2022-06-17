// Stage.h
#pragma once

#include "Snake.h"

using namespace std;

extern Snake *snake;
extern map* m;

class Stage{
public:
    int stageNum;
    int goalBodyLength;
    int goalGrowScore;
    int goalPoisonScore;
    int goalGateScore;
    int goalCnt; // if achieved all goals to next stage
    bool bodyDone = false;
    bool growDone = false;
    bool poisonDone = false;
    bool gateDone = false;
    const int totalStages = 4;
    //4 stages 4 missions (body length, grow, poision, gate)
    int goals[4][4] = {{3, 1, 1, 1}, 
                    {3, 1, 1, 1},
                    {3, 1, 1, 1}, 
                    {3, 1, 1, 1}}; //{6, 2, 2, 2}, {7, 3, 3, 3}, {8, 3, 3, 3}
    

    Stage(){
        stageNum = 1;
        goalBodyLength = goals[stageNum -1][0];
        goalGrowScore = goals[stageNum -1][1];
        goalPoisonScore = goals[stageNum -1][2];
        goalGateScore = goals[stageNum -1][3];
        
    }
    ~Stage(){}
    void levelUp(){
        bodyDone = false;
        growDone = false;
        poisonDone = false;
        gateDone = false;
        snake->bodyLength = 5;
        snake->growScore = 0;
        snake->poisonScore = 0;
        snake->gateScore = 0;
        snake->direction = 'l';
        snake->wholebody.clear();
        for (int i = 0; i < snake->bodyLength; i++)
        {
            snake->wholebody.push_back(Position(25 + i, 10));
        }
        if(stageNum == totalStages){
            // if play again go back to level 0
            
            goalBodyLength = goals[0][0];
            goalGrowScore = goals[0][1];
            goalPoisonScore = goals[0][2];
            goalGateScore = goals[0][3];
            stageNum = 0;

            m->getMap();
        }else{
            
            goalBodyLength = goals[stageNum][0];
            goalGrowScore = goals[stageNum][1];
            goalPoisonScore = goals[stageNum][2];
            goalGateScore = goals[stageNum][3];
            stageNum++;
            m->getMap();
        }
    }

};