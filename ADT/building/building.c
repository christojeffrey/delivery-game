#include "building.h"

/* *** Konstruktor/Kreator *** */
building makeBuilding(char n,location l)
/*menghasilkan building dengan nama n dan location l */
{
    building B;
    Nama(B) = n;
    Absis(B) = l.X;
    Ordinat(B) = l.Y;
    return B;
}

boolean inTheSameTiles (building P1, building P2)
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
{
    return Absis(P1) == Absis(P2) && Ordinat(P1) == Ordinat(P2);
}

boolean booleanIsIn(building P, location L)
/* mengirim trus jika P berada di L */
{
    return Absis(P) == L.X && Ordinat(P) == L.Y;
}