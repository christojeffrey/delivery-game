

#ifndef TODO_LIST_H
#define TODO_LIST_H

#include "boolean.h"
#include "nodePaket.h"


typedef Address todoList;
    //modification of LinkedList

// sebuah linked list of paket


/* PROTOTYPE */
/****************** PEMBUATAN TODO LIST KOSONG ******************/
void CreateTodoList(todoList *tl);
/* I.S. sembarang             */
/* F.S. Terbentuk tl kosong */

/****************** TEST TODO LIST KOSONG ******************/
boolean isTodoListEmpty(todoList tl);
/* Mengirim true jika todolist kosong */

int lengthTodoList(todoList tl);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika tl kosong */



/*** PENAMBAHAN ELEMEN ***/
void insertFirstTodoList(todoList *tl, paket val);
/* I.S. tl mungkin kosong */
/* menambahkan elemen pertama paket val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void insertLastTodoList(todoList *tl, paket val);
/* I.S. tl mungkin kosong */
/* menambahkan elemen list di akhir: elemen terakhir val
 jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */


/*** PENGHAPUSAN ELEMEN ***/
void deleteFirstTodoList(todoList *tl, paket *val);
/* I.S. tl tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada val */
/*      dan alamat elemen pertama di-dealokasi */
void deleteLastTodoList(todoList *tl, paket *val);
/* I.S. tl tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada val */
/*      dan alamat elemen terakhir di-dealokasi */


#endif