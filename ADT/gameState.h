#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "bag.h"
#include "building.h"
#include "buildingList.h"
#include "gadgetInventory.h"
#include "inProgressList.h"
#include "location.h"
#include "nearBuilding.h"
#include "nodePaket.h"
#include "orderList.h"
#include "paket.h"
#include "todoList.h"
typedef struct{
    int mapHeight;
    int mapWidth;
    int buildingCount;
    int time;
    int money;
    float speedBoost;
    location hq;
    orderList orders;
    todoList todos;
    inProgressList inProgress;
    bag tas;
    gadgetInventory inventory;
    nearBuilding bangunanSekitar;
    buildingList buildings;
}gameState;

#endif