

#ifndef IN_PROGRESS_LIST_H
#define IN_PROGRESS_LIST_H

#include "../boolean.h" 
#include "../nodePaket/nodePaket.h"


typedef Address inProgressList;
    //modification of LinkedList


/* PROTOTYPE */
/****************** PEMBUATAN IN PROGRESS LIST KOSONG ******************/
void CreateInProgressList(inProgressList *ipl);
/* I.S. sembarang             */
/* F.S. Terbentuk ipl kosong */

/****************** TEST IN PROGRESS LIST KOSONG ******************/
boolean isInProgressListEmpty(inProgressList ipl);
/* Mengirim true jika inprogresslist kosong */



int lengthInProgressList(inProgressList ipl);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika ipl kosong */



/*** PENAMBAHAN ELEMEN ***/
void insertFirstInProgressList(inProgressList *ipl, paket val);
/* I.S. ipl mungkin kosong */
/* menambahkan elemen pertama paket val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void insertLastInProgressList(inProgressList *ipl, paket val);
/* I.S. ipl mungkin kosong */
/* menambahkan elemen list di akhir: elemen terakhir val
 jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */


/*** PENGHAPUSAN ELEMEN ***/
void deleteFirstInProgressList(inProgressList *ipl, paket *val);
/* I.S. ipl tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada val */
/*      dan alamat elemen pertama di-dealokasi */
void deleteLastInProgressList(inProgressList *ipl, paket *val);
/* I.S. ipl tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada val */
/*      dan alamat elemen terakhir di-dealokasi */


#endif