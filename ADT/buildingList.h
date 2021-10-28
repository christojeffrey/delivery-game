

#ifndef BUILDING_LIST_H
#define BUILDING_LIST_H

#include "boolean.h"

typedef struct{
    building *buffer; /* memori tempat penyimpan elemen (container) */
    int nEff;       /* >=0, banyaknya elemen efektif */
    int capacity;   /* ukuran elemen */
    //modification of list dinamis
}buildingList;

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void createBuildingList(buildingList *bl, int capacity);
/* I.S. bl sembarang, capacity > 0 */
/* F.S. Terbentuk buildinglist kosong dengan kapasitas capacity */

void dealocateBuildingList(buildingList *bl);
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */


/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastBuildingList(buildingList *bl, building val);
/* Proses: Menambahkan val sebagai elemen terakhir buildingList */
/* I.S. bl boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir bl yang baru */

/* ********** MENGHAPUS ELEMEN ********** */
void deleteLastBuildingList(buildingList *bl, building *val);
/* Proses : Menghapus elemen terakhir buildingList */
/* I.S. buildingList tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      building list mungkin menjadi kosong */

#endif