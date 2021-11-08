#include "intInput.h"
#include "machine.h"
#include <stdio.h>

int intInput(){
    //Kalau dimasukkin huruf nanti keluarnya 0
    startToken();
    printf("%d", currentToken);
    return currentToken;
}