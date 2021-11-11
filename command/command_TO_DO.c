// Feli
#include "command.h"
#include "../ADT/todoList.h"
#include "../fungsi/getType.h"
#include <stdio.h>

void command_TO_DO(gameState status){
    /* KAMUS LOKAL */
    // dari input gamestate status, yang dipakai hanya status.todos dan status.time
    Address p;
    int i;
    char* type;
    /* ALGORITMA */
    /* Display To Do */
    p = status.todos;
    i = 1;
    if (p == NULL) {
        printf("To do list masih kosong :D\n");
    } else {
        printf("Pesanan pada To Do List:\n");
        while(p != NULL) {
            type = getType((p)->info);
            printf("%d. %c -> %c (%s Item)\n", i, (p)->info.pickup, (p)->info.dropoff, type);
            i++;
            p = (p)->next;
        }
    }
}