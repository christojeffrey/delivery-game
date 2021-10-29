
#ifndef __pAKET__H__
#define __pAKET__H__

#include "location.h"

typedef struct paket
{
    int t;
    char pickup;
    char dropoff;
    char item;
    int exp;
}paket;

/* Selektor Makro */
#define TIME(P) (P).t
#define PICK_UP(P) (P).pickup
#define DROP_OFF(P) (P).dropoff
#define TIPE(P) (P).item
#define EXP(P) (P).exp



void createPaket(paket * P, int t, char p, char d, char i, int e);
/* Membuat paket */
/* I.S P sembarang */
/* F.S TIME(P) = t, PICK_UP(P) = p, DROP_OFF(P) = d, TIPE(P) = i, EXP(P) = e. */
/* EXP(P) = -1 jika item bukan bertipe Perishable*/

building getPLocation(paket P, buildingList bl);
/* Mencari titik lokasi Pickup P */
/* prekondisi, PICK_UP(P) adalah Point yang valid dalam game */

building getDLocation(paket P, buildingList bl);
/* Mencari titik lokasi Dropoff P */
/* prekondisi, DROP_OFF(P) adalah Point yang valid dalam game */
#endif  //!__PAKET__H__
