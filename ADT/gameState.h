#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "bag/bag.h"
#include "building/building.h"
#include "buildingList/buildingList.h"
#include "gadgetInventory/gadgetInventory.h"
#include "inProgressList/inProgressList.h"
#include "location/location.h"
#include "nearBuilding/nearBuilding.h"
#include "nodePaket/nodePaket.h"
#include "orderList/orderList.h"
#include "paket/paket.h"
#include "todoList/todoList.h"
typedef struct{
    int mapHeight;
    int mapWidth;
    int buildingCount;
    int time;
    int money;
    float speedBoost;
    location myLoc;
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