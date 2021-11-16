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
#include "../ADT/paket.h"
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
    paket temp;
    int temp_time;
    char temp_pickup;
    char temp_dropoff;
    char temp_item;
    int temp_exp;
    int temp_totalPerishTime;
    while (order<jumlahOrder){
        advToken();
        temp_time = currentToken;
        advWord();
        temp_pickup = *currentWord.contents;
        advWord();
        temp_dropoff = *currentWord.contents;
        advWord();
        temp_item = *currentWord.contents;
        if (temp_item == 'P'){
            advToken();
            temp_exp = currentToken;
            temp_totalPerishTime = currentToken;
        } else {
            temp_exp = -1;
            temp_totalPerishTime = -1;
        }

        createPaket(&temp,temp_time,temp_pickup,temp_dropoff,temp_item,temp_exp);
        enqueueOrderList(&(State1->orders),temp);
        order++;
    }
}



