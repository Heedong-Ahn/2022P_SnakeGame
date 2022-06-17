// GateController.h
#pragma once

#include "Position.h"
#include <ncurses.h>
#include <vector>


class GateController
{
public:
    GateController();
    ~GateController();
    Position getRandomPosition();
    void placeGates();
    void Making(float Time);
    Position passGates();
    void pushData();
    int gateChgCnt = 0;


    std::vector<Position> gateVector;
    bool isEntering = false;
    float lastMakeTime = 0;
};

