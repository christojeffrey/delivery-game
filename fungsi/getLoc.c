#include "getLoc.h"

char getLoc(location l, buildingList list) {
    // mengembalikan lokasi dalam bentuk char (building name)
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    i = 0;
    while(i<list.nEff) {
        if (Absis(bLELMT(list, i)) == l.X && Ordinat(bLELMT(list, i)) == l.Y) {
            return (Nama(bLELMT(list, i)));
        } else {
            i++;
        }
    }
    return "";
}