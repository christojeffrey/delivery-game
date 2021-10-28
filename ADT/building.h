
/*
ADT yang isinya pair value, char nama building dan location

contoh building
name 'A'
loc (3,4)
*/
#ifndef BUILDING_H
#define BUILDING_H

#include "location.h"

typedef struct{
    char name;
    location loc; 
}building;


/* *** Konstruktor/Kreator *** */
building makeBuilding(char n,location l);
/*menghasilkan building dengan nama n dan location l */

#endif
