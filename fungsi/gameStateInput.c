#include <stdio.h>
#include "gameStateInput.h"

//include ADT
#include "../ADT/boolean.h"
#include "../ADT/buildingList.h"
#include "../ADT/orderList.h"

#include "../ADT/boolean.h"

#define BLANK ' '
#define MARK ';'
#define CAPACITY 100

typedef struct {
    char contents[CAPACITY];
    int length;
}Word;

typedef int Token;

Token currentToken;

boolean endWord;
boolean endToken;

Word currentWord;

char currentChar;

extern boolean eot;

static FILE *fp;
static FILE *tape;
static FILE *tape2;
static int retval;

typedef int Token;
Token currentToken;

boolean endWord;
boolean endToken;

Word currentWord;

char currentChar;

extern boolean eot;

void adv(){
    retval = fscanf(tape,"%c",&currentChar);
    if (currentChar == MARK){
        fclose(tape);
    }
}

void ignoreBlank(){
    while (currentChar == BLANK || currentChar == '\n'){
        adv();
    }
}

void start(){
    tape = stdin;
    adv();
}

void emptyWord(){
    int i;
    for (i=0; i<CAPACITY; i++){
        currentWord.contents[i] = '\0';
        currentWord.length = 0;
    }
}

void emptyChar(){
    currentChar = '\0';
}

void copyWord(){
    int i;
    i=0;
    emptyWord();
    while ((currentChar!=MARK) && (currentChar!=BLANK) && (i<CAPACITY) && (currentChar != '\n')){
        currentWord.contents[i] = currentChar;
        i++;
        adv();
    }
    currentWord.length = i;
}

void advWord(){
    ignoreBlank();
    if(currentChar == MARK){
        endWord = true;
    }
    else{
        copyWord();
    }
}

void startWord(){
    start();
    ignoreBlank();
    if (currentChar != MARK){
        copyWord();
    }
}

void copyToken(){
    int i;
    i=0;
    currentToken = 0;
    while ((currentChar!=MARK) && (currentChar!=BLANK) && (i<CAPACITY) && (currentChar!='\n')){
        if(currentChar == '0' || currentChar == '1' || currentChar == '2' || currentChar == '3' || currentChar == '4' || currentChar == '5' || currentChar == '6' || currentChar == '7' || currentChar == '8' || currentChar == '9'){
            int temp = currentChar - '0';
            currentToken = ((((int)currentToken) * 10) + temp);
            i++;
        }
        adv();
    }
}

void advToken(){
    ignoreBlank();

    if(currentChar == MARK){
        endToken = true;
    }
    else{
        copyToken();
    }
}

void startToken(){
    start();
    ignoreBlank();
    if (currentChar != MARK){
        copyToken();
    }
}

void gameStateInput(gameState *State1){
    //initialize gameState mulai
    //masukin disini kalo perlu initialize gameState, kecuali gabisa disini(misal karena di initialize berdasarkan input file)
    createGadgetInventory(&State1->inventory);
    CreateBag(&State1->tas);
    CreateInProgressList(State1->inProgress);
    
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
    printf("FILE DITEMUKAN\n");
    printf("membaca file...\n");
    //INPUT NAMA FLE SELESAI
    /*------MULAI MENULISKAN GAME STATE------ */
    //MENULISKAN UKURAN MAP DAN KOORDINAT HQ MULAI
    advToken();
    printf("testing\n");
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
