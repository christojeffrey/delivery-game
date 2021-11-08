#include <stdio.h>
#include "lettermachine.h"

FILE *tape;
static int retval;

void adv(){
    retval = fscanf(tape,"%c",&currentChar);
    if (currentChar == MARK){
        fclose(tape);
    }
}

void start(){
    tape = stdin;
    adv();
}