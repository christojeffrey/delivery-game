#ifndef MACHINE_H
#define MACHINE_H 

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
extern FILE *tape;
static FILE *tape2;
static int retval;

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