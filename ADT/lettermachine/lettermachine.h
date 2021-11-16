#ifndef LETTERMACHINE_H
#define LETTERMACHINE_H

#include <stdio.h>

#define BLANK ' '
#define MARK ';'
#define CAPACITY 100

extern FILE *tape;
extern char currentChar;

void adv();
/* memajukan pita sebanyak 1 karakter
   I.S. : Karakter pertama pada pita = currentChar
   F.S. : currentChar adalah karakter setelah currentChar yang lama,
          currentChar adalah MARK dan program menghentikan pembacaan */


void start();
/* memulai pembacaan sebuah input dari pita yang dibaca per karakter
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama dalam pita
          Jika currentChar != MARK maka pembacaan pita akan dilanjutkan
          Jika currentChar == MARK maka pembacaan pita akan diberhentikan */

#endif
