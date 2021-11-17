// Feli
#include "command.h"
#include <stdio.h>
#include "../fungsi/getType.h"

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
        printf("%d. %s Item (Tujuan: %c)", i, getType(p->info), p->info.dropoff);
        if(p->info.item == 'P') {
            printf(", expire dalam %d waktu", p->info.exp);
        }
        printf("\n");
        i++;
        p = p->next;
    }
}