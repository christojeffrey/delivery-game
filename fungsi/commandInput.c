#include "commandInput.h"
#include "machine.h"
#include <stdio.h>

int commandInput(){
    int result;
    startWord();
    if (currentWord.contents[0] == 'M' && currentWord.contents[1] == 'O' && currentWord.contents[2] == 'V' && currentWord.contents[3] == 'E'){
        result = 1;
    }
    else if (currentWord.contents[0] == 'P' && currentWord.contents[1] == 'I' && currentWord.contents[2] == 'C' && currentWord.contents[3] == 'K' && currentWord.contents[4] == '_' && currentWord.contents[5] == 'U' && currentWord.contents[6] == 'P'){
        result = 2;
    }
    else if(currentWord.contents[0] == 'D' && currentWord.contents[1] == 'R' && currentWord.contents[2] == 'O' && currentWord.contents[3] == 'P' && currentWord.contents[4] == '_' && currentWord.contents[5] == 'O' && currentWord.contents[6] == 'F' && currentWord.contents[7] == 'F'){
        result = 3;
    }
    else if (currentWord.contents[0] == 'M' && currentWord.contents[1] == 'A' && currentWord.contents[2] == 'P'){
        result = 4;
    }
    else if (currentWord.contents[0] == 'T' && currentWord.contents[1] == 'O' && currentWord.contents[2] == '_' && currentWord.contents[3] == 'D' && currentWord.contents[4] == 'O'){
        result = 5;
    }
    else if(currentWord.contents[0] == 'I' && currentWord.contents[1] == 'N' && currentWord.contents[2] == '_' && currentWord.contents[3] == 'P' && currentWord.contents[4] == 'R' && currentWord.contents[5] == 'O' && currentWord.contents[6] == 'G' && currentWord.contents[7] == 'R' && currentWord.contents[8] == 'E' && currentWord.contents[9] == 'S' && currentWord.contents[10] == 'S'){
        result = 6;
    }
    else if (currentWord.contents[0] == 'B' && currentWord.contents[1] == 'U' && currentWord.contents[2] == 'Y'){
        result = 7;
    }
    else if(currentWord.contents[0] == 'I' && currentWord.contents[1] == 'N' && currentWord.contents[2] == 'V' && currentWord.contents[3] == 'E' && currentWord.contents[4] == 'N' && currentWord.contents[5] == 'T' && currentWord.contents[6] == 'O' && currentWord.contents[7] == 'R' && currentWord.contents[8] == 'Y'){
        result = 8;
    }
    else if (currentWord.contents[0] == 'H' && currentWord.contents[1] == 'E' && currentWord.contents[2] == 'L' && currentWord.contents[3] == 'P'){
        result = 9;
    }
    else {
        result = -1;
    }
    return result;
}

