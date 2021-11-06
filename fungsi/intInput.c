#include <stdio.h>
#include "machine.h"

int intInput(){
    //Kalau dimasukkin huruf nanti keluarnya 0
    startToken();
    return currentToken;
}