// Feli
#include "command.h"
#include "../ADT/todoList/todoList.h"
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
            printf("%d. %c -> %c (%s Item", i, (p)->info.pickup, (p)->info.dropoff, type);
            if ((p)->info.item == 'P') {
                printf(", sisa waktu %d", (p)->info.exp);
            }
            printf(")\n");
            i++;
            p = (p)->next;
        }
    }
}