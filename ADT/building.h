
/*
ADT yang isinya pair value, char nama building dan location

contoh building
name 'A'
loc (3,4)
*/
#ifndef BUILDING_H
#define BUILDING_H

#include "boolean.h"
#include "location.h"

typedef struct{
    char name;
    location loc; 
}building;

/* Selektor Makro */
#define Nama(P) (P).name
#define Absis(P) (P).loc.X
#define Ordinat(P) (P).loc.Y


/* *** Konstruktor/Kreator *** */
building makeBuilding(char n,location l);
/*menghasilkan building dengan nama n dan location l */

boolean inTheSameTiles (building P1, building P2);   
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */

boolean booleanIsIn(building P, location L);
#endif
