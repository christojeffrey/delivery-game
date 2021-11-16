
/*
Berisi stack of paket dan int bagCapacity
buffernya aku isi 150 karena, ukuran maks dari tas itu 100, jadi biar aman aku tulis 150.
ilustrasi dikit
idx     0   1   2   3
item    ada ada

habis itu di push
idx     0   1   2   3
item    ada ada ada

habis itu di pop
idx     0   1   2   3
item    ada ada

habis itu di pop
idx     0   1   2   3
item    ada 

*/


#ifndef BAG_H
#define BAG_H

#include "../boolean.h"
#include "../paket/paket.h"
typedef struct{
    paket buffer[150];  /*tabel penyimpanan elemen */
    int idxTop;             /*alamat TOP : elemen puncak */
    //modification of Stack
    int bagCapacity;
}bag;

/* *** Konstruktor/Kreator *** */
void CreateBag(bag *b);
/* I.S. sembarang; */
/* F.S. Membuat sebuah bag kosong kosong dengan kondisi sbb: */
/* - Index top bernilai -1 */
/* bag capacity bernilai 3 (sesuai dengan spek)*/

/* ************ Prototype ************ */
boolean isBagEmpty(bag b);
/* Mengirim true jika bag kosong: lihat definisi di atas */
boolean isBagFull(bag b);
/* Mengirim true jika idxTop+1 > bagCapacity bag penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void pushBag(bag *b, paket val);
/* Menambahkan val sebagai elemen bag b */
/* I.S. b mungkin kosong, tabel penampung elemen bag TIDAK penuh */
/* F.S. val menjadi TOP yang baru,IDX_TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void popBag(bag *b, paket *val);
/* Menghapus val dari bag b */
/* I.S. b tidak mungkin kosong */
/* F.S. val adalah nilai elemen TOP yang lama, IDX_TOP berkurang 1 */


#endif
