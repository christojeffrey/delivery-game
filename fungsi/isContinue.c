#include "../ADT/boolean.h"
#include "../ADT/gameState.h"
boolean isContinue(gameState status){
    boolean lanjut;
    if(status.orders.idxHead == -1 && status.orders.idxTail == -1){
        lanjut = false;
    }
    return lanjut;
}