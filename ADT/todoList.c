#include <stdlib.h>
#include "todoList.h"
#include "nodePaket.h"
#include "boolean.h"

/* PROTOTYPE */
/****************** PEMBUATAN TODO LIST KOSONG ******************/
void CreateTodoList(todoList *tl)
/* I.S. sembarang             */
/* F.S. Terbentuk tl kosong */
{
    (*tl) = NULL;
}

/****************** TEST TODO LIST KOSONG ******************/
boolean isTodoListEmpty(todoList tl)
/* Mengirim true jika todolist kosong */
{
    return ((tl) == NULL);
}

int lengthTodoList(todoList tl)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika tl kosong */
{
    int i = 0;
    Address tdl = tl;

    while (tdl != NULL) {
        i++;
        tdl = (tdl)->next;
    }
    return i;
}


/*** PENAMBAHAN ELEMEN ***/
void insertFirstTodoList(todoList *tl, paket val)
/* I.S. tl mungkin kosong */
/* menambahkan elemen pertama paket val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */
{
    Address p = newNodePaket(val);

    if (p != NULL) {
        (p)->next = (*tl);
        (*tl) = p;
    }
}

void insertLastTodoList(todoList *tl, paket val)
/* I.S. tl mungkin kosong */
/* menambahkan elemen list di akhir: elemen terakhir val
 jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    if (isTodoListEmpty(*tl)) {
        insertFirstTodoList(tl, val);   
    }
    else {
        Address p = newNodePaket(val);
        if (p != NULL) {
            Address last = (*tl);
            while ((last)->next != NULL) {
                last = (last)->next;
            }
            (last)->next = p;
        }
    }
}


/*** PENGHAPUSAN ELEMEN ***/
void deleteFirstTodoList(todoList *tl, paket *val)
/* I.S. tl tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada val */
{
    Address p = *tl;
    *val = (p)->info;
    (*tl) = (p)->next;
    free(p);
}
/*      dan alamat elemen pertama di-dealokasi */
void deleteLastTodoList(todoList *tl, paket *val)
/* I.S. tl tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada val */
/*      dan alamat elemen terakhir di-dealokasi */
{
    Address last = *tl;
    Address preclast = NULL;

    while ((last)->next != NULL) {
        preclast = last;
        last = (last)->next;
    }

    if (preclast == NULL) {
        (*tl) = NULL;
    }
    else {
        (preclast)->next = NULL;
    }

    *val = (last)->info;
    free(last);
}
