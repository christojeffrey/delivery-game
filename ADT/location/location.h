

/*
CATATAN,
PALING KECIL ITU 1,1. GADA 0,0. CEK SPEK KALO RAGU
*/
#ifndef LOCATION_H
#define LOCATION_H

typedef struct{
	int X; //BARIS
	int Y; //KOLOM
	//SORI BARISNYA 'X' DAN KOLOMNYA 'Y', BIKIN BINGUNG
    //modification of point (atau kalau gk dimodif juga gapapa, tergantung kebutuhan)
}location;

/* *** DEFINISI PROTOTIPE PRIMITIF *** */

location makeLocation(int X, int Y);
/* Membentuk sebuah loccation dari komponen-komponennya */

#endif