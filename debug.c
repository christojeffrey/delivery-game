// berisi fungsi untuk memprint isi dari GameState
#include"ADT/gameState.h"

#include<stdio.h>
#include<stdlib.h>

void printPaket(paket p){
    printf("arrival time = %d\n", p.t);
    printf("pickup name = %c\n", p.pickup);
    printf("dropoff name = %c\n", p.dropoff);
    printf("item type = %c\n", p.item);
    printf("expire in = %d\n", p.exp);
    printf("totalperishtime = %d\n", p.totalPerishTime);
}

void apaIsiGameState(gameState status){
    printf("DEBUG MULAI\n");
    printf("Map Height = %d\n", status.mapHeight);
    printf("Map Width = %d\n", status.mapWidth);
    printf("Building count = %d\n", status.buildingCount);
    printf("time = %d\n", status.time);
    printf("money = %d\n", status.money);
    printf("speedboost = %.2f\n", status.speedBoost);
    printf("myloc = (%d, %d)\n", status.myLoc.X, status.myLoc.Y);
    printf("hq = (%d, %d)\n", status.hq.X, status.hq.Y);
    printf("orderlist:\n");
    int panjangOl = status.orders.idxTail - status.orders.idxHead;
    printf("banyak order list = %d\n", panjangOl);
    for(int i = 0; i< panjangOl ;i++){
        printf("i.\n", i);
        printPaket(status.orders.buffer[i]);
    }
    printf("todo list : \n");
    int counter = 1;
    Address p = status.todos;
    if(p != NULL){
        while(p->next != NULL){
            printf("%d. \n", counter);
            printPaket(p->info);
            p = p->next;
            counter++;
        }
        printPaket(p->info);
    }
    printf("in progress List:\n");
    counter = 1;
    p = status.inProgress;
    if(p != NULL){
        while(p->next != NULL){
            printf("%d. \n", counter);
            printPaket(p->info);
            p = p->next;
            counter++;
        }
        printPaket(p->info);
    }
    printf("bag:\n");
    for(int b = 0; b<= status.tas.idxTop;b++){
        printf("%d. \n", b);
        printPaket(status.tas.buffer[b]);
    }
    printf("gadget inventory:[");
    for(int b = 0; b < 4; b++){
        printf("%d",status.inventory.items[b]);
        if(b != 3) printf(",");
        else printf("]\n");
    }
    printf("near building:\n");
    for(int i = 0 ; i < status.bangunanSekitar.rowcolEff;i++){
        for(int j = 0; j < status.bangunanSekitar.rowcolEff;j++){
            printf("%2d", status.bangunanSekitar.contents[i][j]);
        }
        printf("\n");
    }
    printf("building list:\n");
    building bl;
    for(int b = 0 ; b< status.buildings.nEff;b++){
        bl = status.buildings.buffer[b];
        printf("%C(%d,%d)\n", bl.name, bl.loc.X,bl.loc.Y);
    }
    printf("DEBUG SELESAI\n");
}