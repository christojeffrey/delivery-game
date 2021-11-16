#include <stdio.h>
#include "../ADT/boolean.h"
#include "machine.h"

Token currentToken;

boolean endWord;
boolean endToken;

Word currentWord;

char currentChar;

void ignoreBlank(){
/* memajukan karakter jika menemukan BLANK atau newline 
   I.S. : currentChar sembarang
   F.S. : currentChar bukan BLANK atau currentChar bukan newline atau currentChar = MARK*/
    while (currentChar == BLANK || currentChar == '\n'){
        adv();
    }
}

void emptyWord(){
/* menghapus isi dalam currentWord
   I.S. : currentWord sembarang
   F.S. : currentWord menjadi kosong */
    int i;
    for (i=0; i<CAPACITY; i++){
        currentWord.contents[i] = '\0';
        currentWord.length = 0;
    }
}

void emptyChar(){
/* menghapus isi dalam currentChar
   I.S. : currentChar sembarang
   F.S. : currentChar menjadi kosong */
    currentChar = '\0';
}

void copyWord(){
/* mengakuisisi kata yang disimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dalam Word
   F.S. : currentChar = BLANK
          currentChar = newline
          currentChar = MARK
          currentChar adalah karakter setelah currentChar yang lama */
    int i;
    i=0;
    emptyWord();
    while ((currentChar!=MARK) && (currentChar!=BLANK) && (i<CAPACITY) && (currentChar != '\n')){
        currentWord.contents[i] = currentChar;
        i++;
        adv();
        // printf("testing");
    }
    currentWord.length = i;
    // printf("currentword content = %s\n", currentWord.contents);
    // printf("current word length = %d\n", i);
}

void advWord(){
/* Akuisisi kata selanjutnya dengan menggunakan copyWord
   I.S. : currentChar adalah karakter pertama dalam Word
   F.S. : currentChar = MARK, maka akuisisi berhenti
          currentChar adalah karakter setelah currentChar yang lama
          currentWord adalah Word terakhir yang diakuisisi */
    ignoreBlank();
    if(currentChar == MARK){
        endWord = true;
    }
    else{
        copyWord();
    }
}

void startWord(){
/* memulai akuisisi kata
   I.S. : currentChar sembarang
   F.S. : currentChar = MARK
          currentChar karakter pertama sesudah karakter terakhir kata 
          currentWord selesai diakuisisi */
    start();
    ignoreBlank();
    if (currentChar != MARK){
        copyWord();
    }
}

void copyToken(){
/* mengakuisisi angka yang disimpan dalam currentToken
   I.S. : currentChar adalah karakter pertama dalam Token
   F.S. : currentChar = BLANK
          currentChar = newline
          currentChar = MARK
          currentChar adalah karakter setelah currentChar yang lama */
    int i;
    i=0;
    currentToken = 0;
    while ((currentChar!=MARK) && (currentChar!=BLANK) && (i<CAPACITY) && (currentChar!='\n')){
        if(currentChar == '0' || currentChar == '1' || currentChar == '2' || currentChar == '3' || currentChar == '4' || currentChar == '5' || currentChar == '6' || currentChar == '7' || currentChar == '8' || currentChar == '9'){
            int temp = currentChar - '0';
            currentToken = ((((int)currentToken) * 10) + temp);
            i++;
        }
        adv();
    }
}

void advToken(){
/* Akuisisi angka selanjutnya dengan menggunakan copyToken
   I.S. : currentChar adalah karakter pertama dalam Token
   F.S. : currentChar = MARK, maka akuisisi berhenti
          currentChar adalah karakter setelah currentChar yang lama
          currentToken adalah angka terakhir yang diakuisisi */
    ignoreBlank();
    if(currentChar == MARK){
        endToken = true;
    }
    else{
        copyToken();
    }
}

void startToken(){
/* memulai akuisisi angka
   I.S. : currentChar sembarang
   F.S. : currentChar = MARK
          currentChar karakter pertama sesudah karakter terakhir Token 
          currentWord selesai diakuisisi */
    start();
    ignoreBlank();
    if (currentChar != MARK){
        copyToken();
    }
}