#ifndef LETTERMACHINE_H
#define LETTERMACHINE_H

#include <stdio.h>

#define BLANK ' '
#define MARK ';'
#define CAPACITY 100

extern FILE *tape;
extern char currentChar;

void adv();

void start();

#endif
