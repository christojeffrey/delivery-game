#include "../ADT/boolean.h"
#include "../ADT/gameState.h"
#include "../ADT/todoList.h"
#include "../ADT/bag.h"
boolean isContinue(gameState status){
    boolean lanjut;
    lanjut = true;
    if(status.orders.idxHead == -1 && status.orders.idxTail == -1 && isTodoListEmpty(status.todos) && isBagEmpty(status.tas)){
        lanjut = false;
    }
    return lanjut;
}