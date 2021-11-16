#include <stdio.h>
#include <stdlib.h>
#include "inProgressList.h"
#include "../nodePaket/nodePaket.h"

/* PROTOTYPE */
/****************** PEMBUATAN IN PROGRESS LIST KOSONG ******************/
void CreateInProgressList(inProgressList *ipl)
/* I.S. sembarang             */
/* F.S. Terbentuk ipl kosong */
{
    (*ipl) = NULL;
}

/****************** TEST IN PROGRESS LIST KOSONG ******************/
boolean isInProgressListEmpty(inProgressList ipl)
/* Mengirim true jika inprogresslist kosong */
{
    return ((ipl) == NULL);
}

int lengthInProgressList(inProgressList ipl)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika ipl kosong */
{
    int i = 0;
    Address inpl = ipl;

    while (inpl != NULL) {
        i++;
        inpl = (inpl)->next;
    }

    return i;
}


/*** PENAMBAHAN ELEMEN ***/
void insertFirstInProgressList(inProgressList *ipl, paket val)
/* I.S. ipl mungkin kosong */
/* menambahkan elemen pertama paket val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */
{
    Address p = newNodePaket(val);

    if (p != NULL) {
        (p)->next = (*ipl);
        (*ipl) = p;
    }
}

void insertLastInProgressList(inProgressList *ipl, paket val)
/* I.S. ipl mungkin kosong */
/* menambahkan elemen list di akhir: elemen terakhir val
 jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    if (isInProgressListEmpty(*ipl)) {
        insertFirstInProgressList(ipl, val);   
    }
    else {
        Address p = newNodePaket(val);
        if (p != NULL) {
            Address last = (*ipl);
            while ((last)->next != NULL) {
                last = (last)->next;
            }
            (last)->next = p;
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirstInProgressList(inProgressList *ipl, paket *val)
/* I.S. ipl tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada val */
/*      dan alamat elemen pertama di-dealokasi */
{
    Address p = *ipl;
    *val = (p)->info;
    (*ipl) = (p)->next;
    free(p);
}

void deleteLastInProgressList(inProgressList *ipl, paket *val)
/* I.S. ipl tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada val */
/*      dan alamat elemen terakhir di-dealokasi */
{
    Address last = *ipl;
    Address preclast = NULL;

    while ((last)->next != NULL) {
        preclast = last;
        last = (last)->next;
    }

    if (preclast == NULL) {
        (*ipl) = NULL;
    }
    else {
        (preclast)->next = NULL;
    }

    *val = (last)->info;
    free(last);
}