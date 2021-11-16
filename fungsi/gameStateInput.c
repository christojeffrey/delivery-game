#include <stdio.h>
#include "gameStateInput.h"

//include ADT
#include "../ADT/boolean.h"
#include "../ADT/buildingList.h"
#include "../ADT/orderList.h"
#include "../ADT/gadgetInventory.h"
#include "../ADT/bag.h"
#include "../ADT/inProgressList.h"
#include "../ADT/todoList.h"
#include "machine.h"

#define BLANK ' '
#define MARK ';'
#define CAPACITY 100

void gameStateInput(gameState *State1){
    //initialize gameState mulai
    //masukin disini kalo perlu initialize gameState, kecuali gabisa disini(misal karena di initialize berdasarkan input file)

    //initalize gameState selesai
    //INPUT NAMA FILE MULAI
    printf("Masukkan nama file (relatif terhadap main.c):\n> ");
    startWord();
    tape = fopen(currentWord.contents,"r");

    while (tape == NULL){
        printf("TIDAK DITEMUKAN FILE CONFIG DENGAN NAMA TERSEBUT, MASUKKAN LAGI\n> ");
        startWord();
        tape = fopen(currentWord.contents,"r");
    }

    CreateInProgressList(&(State1->inProgress));
    CreateTodoList(&(State1->todos));
    createGadgetInventory(&(State1->inventory));
    CreateBag(&(State1->tas));
    (*State1).time = 0;
    (*State1).money = 0;
    (*State1).speedBoost = 0;
    //INPUT NAMA FLE SELESAI
    /*------MULAI MENULISKAN GAME STATE------ */
    //MENULISKAN UKURAN MAP DAN KOORDINAT HQ MULAI
    advToken();
    (*State1).mapHeight = currentToken;
    advToken();
    (*State1).mapWidth = currentToken;
    advToken();
    (*State1).hq.X = currentToken;
    (*State1).myLoc.X = currentToken;
    advToken();
    (*State1).hq.Y = currentToken;
    (*State1).myLoc.Y = currentToken;
    advToken();

    //MENULISKAN UKURAN MAP DAN KOORDINAT HQ SELESAI

    //MENULISKAN LOKASI BANGUNAN MULAI
    int jumlahVar = currentToken;

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
        advToken();
        (*State1).buildings.buffer[var].loc.X= currentToken;
        advToken();
        (*State1).buildings.buffer[var].loc.Y = currentToken;
        var++;
    }
    //MENULISKAN LOKASI BANGUNAN SELESAI
    // printf("INPUT LOKASI BUILDING SELESAI\n");
    (*State1).bangunanSekitar.rowcolEff = jumlahVar+1;
    int rowId = 0;
    int colId = 0;
    advToken();
    while (rowId<(*State1).bangunanSekitar.rowcolEff){
        colId=0;
        while (colId<(*State1).bangunanSekitar.rowcolEff){
            (*State1).bangunanSekitar.contents[rowId][colId] = currentToken;
            advToken();
            colId++;
        }
        rowId++;
    }
    int jumlahOrder = currentToken;
    int order = 0;

    CreateOrderList(&(State1 -> orders));
    while (order<jumlahOrder){
        advToken();
        (*State1).orders.buffer[order].t = currentToken;
        advWord();
        (*State1).orders.buffer[order].pickup = *currentWord.contents;
        advWord();
        (*State1).orders.buffer[order].dropoff = *currentWord.contents;
        advWord();
        (*State1).orders.buffer[order].item = *currentWord.contents;
        if ((*State1).orders.buffer[order].item == 'P'){
            advToken();
            (*State1).orders.buffer[order].exp = currentToken;
            (*State1).orders.buffer[order].totalPerishTime = currentToken;
        } else {
            (*State1).orders.buffer[order].exp = -1;
            (*State1).orders.buffer[order].totalPerishTime = -1;
        }

        if ((*State1).orders.idxTail==-1 && (*State1).orders.idxHead==-1){
            (*State1).orders.idxTail = 0;
            (*State1).orders.idxHead = 0;
        } else {
            (*State1).orders.idxTail++;
        }
        order++;
    }
}



