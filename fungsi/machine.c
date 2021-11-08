#include <stdio.h>
#include "../ADT/boolean.h"
#include "machine.h"

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
void adv(){
    printf("mau retval\n");
    retval = fscanf(tape,"%c",&currentChar);
    printf("curent char adv awl= %c\n", currentChar);
    if (currentChar == MARK){
        fclose(tape);
    }
    printf("curent char adv akhir= %c\n", currentChar);
}

void ignoreBlank(){
    printf("currentchar seb = %c\n", currentChar);
    while (currentChar == BLANK || currentChar == '\n'){
        printf("mau adv di ignore blank\n");
        adv();
        printf("currentchar loop = %c\n", currentChar);
    }
    printf("currentchar sudah = %c\n", currentChar);
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
        // printf("testing");
    }
    currentWord.length = i;
    // printf("currentword content = %s\n", currentWord.contents);
    // printf("current word length = %d\n", i);
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
    char chartemp;
    fscanf(tape,"%c", &chartemp);
    printf("char temp = %c\n");
    fscanf(tape,"%c", &chartemp);
    printf("char temp = %c\n");
    fscanf(tape,"%c", &chartemp);
    printf("char temp = %c\n");
    fscanf(tape,"%c", &chartemp);
    printf("char temp = %c\n");
    printf("testign advToken\n");
    ignoreBlank();

    if(currentChar == MARK){
        endToken = true;
        printf("end token true\n");
    }
    else{
        printf("mau copy token\n");
        copyToken();
    }
    printf("testign advToken selesai\n");
}

void startToken(){
    printf("testing starttoken\n");
    start();
    ignoreBlank();
    if (currentChar != MARK){
        copyToken();
    }
}