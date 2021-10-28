

/*
CATATAN,
PALING KECIL ITU 1,1. GADA 0,0. CEK SPEK KALO RAGU
*/
#ifndef LOCATION_H
#define LOCATION_H

typedef struct{
	float X; /* absis   */
	float Y; /* ordinat */
    //modification of point (atau kalau gk dimodif juga gapapa, tergantung kebutuhan)
}location;

/* *** DEFINISI PROTOTIPE PRIMITIF *** */

location makeLocation(float X, float Y);
/* Membentuk sebuah loccation dari komponen-komponennya */
#endif