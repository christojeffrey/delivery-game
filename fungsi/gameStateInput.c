#include <stdio.h>
#include "gameStateInput.h"

//include ADT
#include "../ADT/boolean.h"
#include "../ADT/buildingList.h"
#include "../ADT/orderList.h"
#include "machine.h"

#define BLANK ' '
#define MARK ';'
#define CAPACITY 100


void gameStateInput(gameState *State1){
    //initialize gameState mulai
    //masukin disini kalo perlu initialize gameState, kecuali gabisa disini(misal karena di initialize berdasarkan input file)


    //initalize gameState selesai
    //INPUT NAMA FILE MULAI
    printf("masukkan nama file(relative terhadap main.c):\n");
    startWord();
    tape = fopen(currentWord.contents,"r");

    while (tape == NULL){
        printf("TIDAK DITEMUKAN FILE CONFIG DENGAN NAMA TERSEBUT, MASUKKAN LAGI\n");
        startWord();
        tape = fopen(currentWord.contents,"r");
    }
    //INPUT NAMA FLE SELESAI
    /*------MULAI MENULISKAN GAME STATE------ */
    //MENULISKAN UKURAN MAP DAN KOORDINAT HQ MULAI
    advToken();
    (*State1).mapWidth = currentToken;
    printf("%d ", (*State1).mapWidth);
    advToken();
    (*State1).mapHeight = currentToken;
    printf("%d\n", (*State1).mapHeight);
    advToken();
    (*State1).hq.X = currentToken;
    printf("%d ", (*State1).hq.X);
    advToken();
    (*State1).hq.Y = currentToken;
    printf("%d\n", (*State1).hq.Y);
    advToken();
    //MENULISKAN UKURAN MAP DAN KOORDINAT HQ SELESAI

    //MENULISKAN LOKASI BANGUNAN MULAI
    int jumlahVar = currentToken;
    printf("%d\n",jumlahVar);

    createBuildingList(&(State1->buildings), jumlahVar);
    int var = 0;
    (*State1).buildingCount = jumlahVar;
    (*State1).buildings.capacity = jumlahVar;
    (*State1).buildings.nEff = jumlahVar;
    while (var<jumlahVar){
        advWord();
        // printf("disini aman");
        // printf("currentword content[0] = %c\n", currentWord.contents[0]);
        (*State1).buildings.buffer[var].name = currentWord.contents[0];
        printf("%c ", (*State1).buildings.buffer[var].name);
        advToken();
        (*State1).buildings.buffer[var].loc.X= currentToken;
        printf("%d ", (*State1).buildings.buffer[var].loc.X);
        advToken();
        (*State1).buildings.buffer[var].loc.Y = currentToken;
        printf("%d\n", (*State1).buildings.buffer[var].loc.Y);
        var++;
    }
    //MENULISKAN LOKASI BANGUNAN SELESAI
    // printf("INPUT LOKASI BUILDING SELESAI\n");
    (*State1).bangunanSekitar.rowcolEff = jumlahVar+1;
    printf("%d ",(*State1).bangunanSekitar.rowcolEff);
    printf("%d\n",(*State1).bangunanSekitar.rowcolEff);
    int rowId = 0;
    int colId = 0;
    advToken();
    while (rowId<(*State1).bangunanSekitar.rowcolEff){
        colId=0;
        while (colId<(*State1).bangunanSekitar.rowcolEff){
            (*State1).bangunanSekitar.contents[rowId][colId] = currentToken;
            printf("%d ", (*State1).bangunanSekitar.contents[rowId][colId]);
            advToken();
            colId++;
        }
        rowId++;
        printf("\n");
    }
    int jumlahOrder = currentToken;
    printf("%d\n",jumlahOrder);
    int order = 0;

    CreateOrderList(&(State1 -> orders));
    while (order<jumlahOrder){
        advToken();
        (*State1).orders.buffer[order].t = currentToken;
        printf("%d ", (*State1).orders.buffer[order].t);
        advWord();
        (*State1).orders.buffer[order].pickup = *currentWord.contents;
        printf("%c ", (*State1).orders.buffer[order].pickup);
        advWord();
        (*State1).orders.buffer[order].dropoff = *currentWord.contents;
        printf("%c ", (*State1).orders.buffer[order].dropoff);
        advWord();
        (*State1).orders.buffer[order].item = *currentWord.contents;
        printf("%c ", (*State1).orders.buffer[order].item);
        if ((*State1).orders.buffer[order].item == 'P'){
            advToken();
            (*State1).orders.buffer[order].exp = currentToken;
            printf("%d ", (*State1).orders.buffer[order].exp);
        } else {
            (*State1).orders.buffer[order].exp = -1;
        }

        if ((*State1).orders.idxTail==-1 && (*State1).orders.idxHead==-1){
            (*State1).orders.idxTail = 0;
            (*State1).orders.idxHead = 0;
        } else {
            (*State1).orders.idxTail++;
        }
        printf("\n");
        order++;
    }
    printf("%d\n", (*State1).orders.idxHead);
    printf("%d\n", (*State1).orders.idxTail);
}

