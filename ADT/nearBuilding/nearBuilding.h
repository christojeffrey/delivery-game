

    //modification of matriks
/*
jumlah maks bangunan adalah 26, ditambah HQ menjadi 27. jadi aku bikin 30 aja biar enak lol
contents akan bernilai 1 jika terhubung, bernilai 0 jika tidak(persis seperti input dari file)
*/
#ifndef NEAR_BUILDING_H
#define NEAR_BUILDING_H

#include "../buildingList/buildingList.h"
#include "../location/location.h"

typedef struct{
   int contents[30][30];
   int rowcolEff; 
} nearBuilding;
/* rowEff >= 1 dan colEff >= 1 */
/* Indeks matriks yang digunakan: [0..rowcolEff-1][0..rowcolEff-1] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk nearBuilding *** */
void CreatenearBuilding(int rowcol, nearBuilding *nb);
/* Membentuk sebuah nearbulding yang semuad datanya 0 yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. rowcol valid untuk memori matriks yang dibuat */
/* F.S. nearbuilding nb sesuai dengan definisi di atas terbentuk */

/* *** Selektor *** */
#define nBSIZE(M) (M).rowcolEff
#define nBELMT(M, i, j) (M).contents[(i)][(j)]

buildingList getMove(nearBuilding m, buildingList l, location p,location hq);
/* mencari move legal dari suatu posisi */


#endif