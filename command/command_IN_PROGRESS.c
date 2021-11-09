// Feli
#include "command.h"
#include <stdio.h>

void command_IN_PROGRESS(gameState status) {
    /* KAMUS LOKAL */
    // dari gameState status, yang dipakai hanya inProgress
    Address p;
    int i;
    /* ALGORITMA */
    printf("Pesanan yang sedang diantarkan:\n");
    p = status.inProgress;
    i = 1;
    while(p != NULL) {
        printf("%d. %c Item (Tujuan: %c)\n", i, p->info.item, p->info.dropoff);
        i++;
        p = p->next;
    }
}