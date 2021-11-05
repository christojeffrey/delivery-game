#include <stdio.h>
#include "machine.c"

int intInput(){
    //Kalau dimasukkin huruf nanti keluarnya 0
    startToken();
    return currentToken;
}