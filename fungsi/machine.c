#include <stdio.h>
#include "../ADT/boolean.h"
#include "machine.h"

Token currentToken;

boolean endWord;
boolean endToken;

Word currentWord;

char currentChar;

void ignoreBlank(){
    while (currentChar == BLANK || currentChar == '\n'){
        adv();
    }
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