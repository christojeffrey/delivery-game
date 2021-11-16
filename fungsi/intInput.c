#include "intInput.h"
#include "../ADT/machine/machine.h"
#include <stdio.h>

int intInput(){
    //Kalau dimasukkin huruf nanti keluarnya 0
    startToken();
    return currentToken;
}