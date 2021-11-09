// Feli
#include "command.h"
#include "../ADT/todoList.h"
#include <stdio.h>

void command_TO_DO(gameState status){
    /* KAMUS LOKAL */
    // dari input gamestate status, yang dipakai hanya status.todos dan status.time
    Address p;
    int i;
    /* ALGORITMA */
    /* Display To Do */
    p = status.todos;
    i = 1;
    if (p == NULL) {
        printf("To do list masih kosong :D\n");
    } else {
        printf("Pesanan pada To Do List:\n");
        while(p != NULL) {
            printf("%d. %c -> %c (%c Item)\n", i, (p)->info.pickup, (p)->info.dropoff, (p)->info.item);
            i++;
            p = (p)->next;
        }
    }
}