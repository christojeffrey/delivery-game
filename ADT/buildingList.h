

#ifndef BUILDING_LIST_H
#define BUILDING_LIST_H

#include "boolean.h"
#include "building.h"
typedef struct{
    building *buffer; /* memori tempat penyimpan elemen (container) */
    int nEff;       /* >=0, banyaknya elemen efektif */
    int capacity;   /* ukuran elemen */
    //modification of list dinamis
}buildingList;

#define bLNEFF(l) (l).nEff
#define bLBUFFER(l) (l).buffer
#define bLELMT(l, i) (l).buffer[i]
#define bLCAPACITY(l) (l).capacity

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void createBuildingList(buildingList *bl, int capacity);
/* I.S. bl sembarang, capacity > 0 */
/* F.S. Terbentuk buildinglist kosong dengan kapasitas capacity */

void dealocateBuildingList(buildingList *bl);
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */


/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
int buildingListIndexOf(buildingList bl, building val);
/* Search apakah ada elemen List bl yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List bl kosong */
/* Skema Searching yang digunakan bebas */

int buildingListIndexOfName(buildingList bl, char name);
/* mencari apakah ada lokasi yang bernama name di bl, jika ada return indeks i terkecil dengan Name(elemet ke i) = name
/* jika tidak ada return -1*/

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

void copyBuildingList(buildingList lIn, buildingList *lOut);


void compactBuildingList(buildingList *bl);
/* Proses : Mengurangi capacity sehingga nEff = capacity */
/* I.S. List lidak kosong */
/* F.S. Ukuran nEff = capacity */
#endif