#ifndef MACHINE_H
#define MACHINE_H 

#include "../ADT/boolean.h"
#include "lettermachine.h"

typedef struct {
    char contents[CAPACITY];
    int length;
} Word;

typedef int Token;

extern Token currentToken;

extern boolean endWord;
extern boolean endToken;

extern Word currentWord;


void ignoreBlank();
/* memajukan karakter jika menemukan BLANK atau newline 
   I.S. : currentChar sembarang
   F.S. : currentChar bukan BLANK atau currentChar bukan newline atau currentChar = MARK*/

void emptyWord();
/* menghapus isi dalam currentWord
   I.S. : currentWord sembarang
   F.S. : currentWord menjadi kosong */

void emptyChar();
/* menghapus isi dalam currentChar
   I.S. : currentChar sembarang
   F.S. : currentChar menjadi kosong */

void copyWord();
/* mengakuisisi kata yang disimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dalam Word
   F.S. : currentChar = BLANK
          currentChar = newline
          currentChar = MARK
          currentChar adalah karakter setelah currentChar yang lama */

void advWord();
/* Akuisisi kata selanjutnya dengan menggunakan copyWord
   I.S. : currentChar adalah karakter pertama dalam Word
   F.S. : currentChar = MARK, maka akuisisi berhenti
          currentChar adalah karakter setelah currentChar yang lama
          currentWord adalah Word terakhir yang diakuisisi */
          
void startWord();
/* memulai akuisisi kata
   I.S. : currentChar sembarang
   F.S. : currentChar = MARK
          currentChar karakter pertama sesudah karakter terakhir kata 
          currentWord selesai diakuisisi */

void copyToken();
/* mengakuisisi angka yang disimpan dalam currentToken
   I.S. : currentChar adalah karakter pertama dalam Token
   F.S. : currentChar = BLANK
          currentChar = newline
          currentChar = MARK
          currentChar adalah karakter setelah currentChar yang lama */

void advToken();
/* Akuisisi angka selanjutnya dengan menggunakan copyToken
   I.S. : currentChar adalah karakter pertama dalam Token
   F.S. : currentChar = MARK, maka akuisisi berhenti
          currentChar adalah karakter setelah currentChar yang lama
          currentToken adalah angka terakhir yang diakuisisi */

void startToken();
/* memulai akuisisi angka
   I.S. : currentChar sembarang
   F.S. : currentChar = MARK
          currentChar karakter pertama sesudah karakter terakhir Token 
          currentWord selesai diakuisisi */

#endif