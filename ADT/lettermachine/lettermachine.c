#include <stdio.h>
#include "lettermachine.h"

FILE *tape;
static int retval;

void adv(){
/* memajukan pita sebanyak 1 karakter
   I.S. : Karakter pertama pada pita = currentChar
   F.S. : currentChar adalah karakter setelah currentChar yang lama,
          currentChar adalah MARK dan program menghentikan pembacaan */
    retval = fscanf(tape,"%c",&currentChar);
    if (currentChar == MARK){
        fclose(tape);
    }
}

void start(){
/* memulai pembacaan sebuah input dari pita yang dibaca per karakter
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama dalam pita
          Jika currentChar != MARK maka pembacaan pita akan dilanjutkan
          Jika currentChar == MARK maka pembacaan pita akan diberhentikan */
    tape = stdin;
    adv();
}