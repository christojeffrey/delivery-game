#include "bag.h"
#include <stdio.h>

void CreateBag(bag *b)
/* I.S. sembarang; */
/* F.S. Membuat sebuah bag kosong kosong dengan kondisi sbb: */
/* - Index top bernilai -1 */
/* bag capacity bernilai 3 (sesuai dengan spek)*/
{
    (*b).idxTop = -1;
    (*b).bagCapacity = 3;
}

/* ************ Prototype ************ */
boolean isBagEmpty(bag b)
/* Mengirim true jika bag kosong: lihat definisi di atas */
{
    return ((b).idxTop == -1 && (b).bagCapacity == 3);
}

boolean isBagFull(bag b)
/* Mengirim true jika idxTop+1 > bagCapacity bag penuh */
{
    return((b).idxTop+1 >= (b).bagCapacity);
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void pushBag(bag *b, paket val)
/* Menambahkan val sebagai elemen bag b */
/* I.S. b mungkin kosong, tabel penampung elemen bag TIDAK penuh */
/* F.S. val menjadi TOP yang baru,IDX_TOP bertambah 1 */
{
    (*b).idxTop++;
    (*b).buffer[(*b).idxTop] = val;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void popBag(bag *b, paket *val)
/* Menghapus val dari bag b */
/* I.S. b tidak mungkin kosong */
/* F.S. val adalah nilai elemen TOP yang lama, IDX_TOP berkurang 1 */
{
    *val = (*b).buffer[(*b).idxTop];
    (*b).idxTop--;
}