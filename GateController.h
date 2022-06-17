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

    std::vector<Position> gateVector;
    bool isEntering = false;
    float lastMakeTime = 0;
    int gateChgCnt = 0;
};

