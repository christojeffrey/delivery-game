#include <stdio.h>
#include "machine.h"
#include "../lettermachine/lettermachine.h"

int main(){
    startWord();
    advWord();
    printf("%s",currentWord);
    printf("\n");
    startToken();
    advToken();
    printf("%d",currentToken);
}