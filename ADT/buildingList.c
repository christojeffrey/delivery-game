#include <stdio.h>
#include "buildingList.h"
#include "building.h"
#include<stdlib.h>
/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void createBuildingList(buildingList *bl, int capacity)
/* I.S. bl sembarang, capacity > 0 */
/* F.S. Terbentuk buildinglist kosong dengan kapasitas capacity */
{
    do {
        bLBUFFER(*bl) = (building*)malloc(capacity * sizeof(building));
    } while (bLBUFFER(*bl) == NULL);
    bLCAPACITY(*bl) = capacity;
    bLNEFF(*bl) = 0;
}

void dealocateBuildingList(buildingList *bl)
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
{
    free(bLBUFFER(*bl));
    bLCAPACITY(*bl) = 0;
    bLNEFF(*bl) = 0;
}


/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
int buildingListIndexOf(buildingList bl, building val)
/* Search apakah ada elemen List bl yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List bl kosong */
/* Skema Searching yang digunakan bebas */
{
    int i = 0;
    while (i < bLNEFF(bl) && Nama(bLELMT(bl, i)) != Nama(val)) i++;
    if (i == bLNEFF(bl)) i = -1;
    return i;
}

int buildingListIndexOfName(buildingList bl, char name)
{
    int i = 0;
    while (i < bLNEFF(bl) && Nama(bLELMT(bl, i)) != name) i++;
    if (i == bLNEFF(bl)) i = -1;
    return i;
}
/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastBuildingList(buildingList *bl, building val)
/* Proses: Menambahkan val sebagai elemen terakhir buildingList */
/* I.S. bl boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir bl yang baru */
{
    bLELMT(*bl, bLNEFF(*bl)) = val;
    bLNEFF(*bl) += 1;
}
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLastBuildingList(buildingList *bl, building *val)
/* Proses : Menghapus elemen terakhir buildingList */
/* I.S. buildingList tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      building list mungkin menjadi kosong */
{
    *val = bLELMT(*bl, bLNEFF(*bl) - 1);
    bLNEFF(*bl) -= 1;
}

/* ********** OPERASI LAIN ********** */
void copyBuildingList(buildingList lIn, buildingList *lOut)
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */
{
    createBuildingList(lOut, bLCAPACITY(lIn));
    for (int i = 0; i < bLNEFF(lIn); i++) bLELMT(*lOut, i) = bLELMT(lIn, i);
    bLNEFF(*lOut) = bLNEFF(lIn);
}

void compactBuildingList(buildingList *bl)
/* Proses : Mengurangi capacity sehingga nEff = capacity */
/* I.S. List lidak kosong */
/* F.S. Ukuran nEff = capacity */
{
    buildingList temp;
    copyBuildingList(*bl, &temp);
    dealocateBuildingList(bl);
    createBuildingList(bl, bLNEFF(temp));
    for (int i = 0; i < bLNEFF(temp); i++) bLELMT(*bl, i) = bLELMT(temp, i);
    bLNEFF(*bl) = bLNEFF(temp);
}