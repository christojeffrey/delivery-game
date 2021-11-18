#include "../ADT/boolean.h"
#include "../ADT/gameState.h"
#include "../ADT/todoList/todoList.h"
#include "../ADT/bag/bag.h"
#include <stdio.h>
boolean isContinue(gameState status){
    boolean lanjut;
    lanjut = true;
    if(status.orders.idxHead == -1 && status.orders.idxTail == -1 && isTodoListEmpty(status.todos) && isBagEmpty(status.tas)){
        lanjut = false;
        printf("semua order telah selesai\n");
        printf("sisa uang : %d\n", status.money);
    }
    return lanjut;
}