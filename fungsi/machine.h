#ifndef MACHINE_H
#define MACHINE_H 

#include "../ADT/boolean.h"
#include "lettermachine.h"

typedef struct {
    char contents[CAPACITY];
    int length;
} Word;

typedef int Token;

extern Token currentToken;

extern boolean endWord;
extern boolean endToken;

extern Word currentWord;

void adv();

void ignoreBlank();

void start();

void emptyWord();

void emptyChar();

void copyWord();

void advWord();

void startWord();

void copyToken();

void advToken();

void startToken();

#endif