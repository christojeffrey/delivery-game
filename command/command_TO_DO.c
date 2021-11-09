// Feli
#include "command.h"
#include "../ADT/todoList.h"
#include <stdio.h>

void command_TO_DO(gameState status){
    /* KAMUS LOKAL */
    // dari input gamestate status, yang dipakai hanya status.todos
    Address p;
    int i;
    /* ALGORITMA */
    printf("Pesanan pada To Do List:\n");
    p = status.todos;
    i = 1;
    while((p)->next != NULL) {
        printf("%d. %c -> %c (%c Item)\n", i, (p)->info.pickup, (p)->info.dropoff, (p)->info.item);
        i++;
        p = (p)->next;
    }
}