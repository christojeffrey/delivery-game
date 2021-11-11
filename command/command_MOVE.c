// Feli
#include "command.h"
#include "../ADT/nearBuilding.h"
#include <stdio.h>

void command_MOVE(gameState* status) {
    /* KAMUS LOKAL */
    buildingList l;
    int i, input;
    paket paket;
    /* ALGORITMA */
    l = getMove(status->bangunanSekitar, status->buildings, status->myLoc,status->hq);
    printf("Posisi yang dapat dicapai:\n");
    for (i=0; i<bLNEFF(l); i++) {
        printf("%d. %c (%d,%d)\n", i+1, bLELMT(l,i).name, bLELMT(l,i).loc.X, bLELMT(l,i).loc.Y);
    }
    printf("Posisi yang dipilih? (ketik 0 jika ingin kembali)\n> ");
    scanf("%d", &input);
    while (input>i || input<0) {
        printf("Masukkan pilihan dari 0 sampai %d\n> ", i);
        scanf("%d", &input);
    }
    if (input != 0) {
        printf("Moving...\n");
        /* Moving */
        status->myLoc = bLELMT(l,input-1).loc;
        /* Time travel */
        status->time += 1;
        /* Updating To Do */
        while (!isOrderListEmpty(status->orders) && (oLHEAD(status->orders).t <= status->time)) {
            dequeueOrderList(&(status->orders), &paket);
            insertLastTodoList(&(status->todos), paket);
        }
        printf("Mobita sekarang berada di titik %c (%d,%d)!\n", bLELMT(l, input-1).name, status->myLoc.X, status->myLoc.Y);
        printf("Waktu: %d\n", status->time);
    } 
}