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
    //3 stages 4 missions (body length, grow, poision, gate)
    int goals[3][4] = {{5, 1, 1, 1}, 
                    {6, 2, 2, 2},
                    {7, 3, 3, 3}};
    

    Stage(){
        stageNum = 1;
        goalBodyLength = goals[stageNum -1][0];
        goalGrowScore = goals[stageNum -1][1];
        goalPoisonScore = goals[stageNum -1][2];
        goalGateScore = goals[stageNum -1][3];
        
    }
    ~Stage(){}
    void levelUp(){
        if(stageNum == 3){
            // if play again go back to level 0
            stageNum = 0;
            goalBodyLength = goals[0][0];
            goalGrowScore = goals[0][1];
            goalPoisonScore = goals[0][2];
            goalGateScore = goals[0][3];
            m->getMap();
        }else{
            stageNum++;
            goalBodyLength = goals[stageNum][0];
            goalGrowScore = goals[stageNum][1];
            goalPoisonScore = goals[stageNum][2];
            goalGateScore = goals[stageNum][3];
            m->getMap();
        }
        bodyDone = false;
        growDone = false;
        poisonDone = false;
        gateDone = false;
        // switch (stageNum)
        // {
        // case 1:
        // case 2:
        //     stageNum++;
        //     goalBodyLength = goals[stageNum][0];
        //     goalGrowScore = goals[stageNum][1];
        //     goalPoisonScore = goals[stageNum][2];
        //     goalGateScore = goals[stageNum][3];
        //     m->getMap();
        //     break;
        
        // default:
        //     // if play again go back to level 0
        //     stageNum = 0;
        //     goalBodyLength = goals[0][0];
        //     goalGrowScore = goals[0][1];
        //     goalPoisonScore = goals[0][2];
        //     goalGateScore = goals[0][3];
        //     m->getMap();
        //     break;
        // }
    }

};