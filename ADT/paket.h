
#ifndef __PAKET__H__
#define __PAKET__H__

#include "location.h"
#include "buildingList.h"
#include "building.h"
#include "nearBuilding.h"
typedef struct paket
{
    int t;
    char pickup;
    char dropoff;
    char item; //pilihannya apa aja? sesuai spek
    int exp;
    //tambahan total perishTime.
    /*
    jadi total Perish Time itu konstan, diem terus. yg Exp, menurun setiap waktu berjalan.
    alasan keberadaan totalperishtime adalah agar bisa menggunakan gadget pembungkus waktu
    */
    int totalPerishTime;
}paket;

/* Selektor Makro */
#define pTIME(P) (P).t
#define pPICK_UP(P) (P).pickup
#define pDROP_OFF(P) (P).dropoff
#define pTIPE(P) (P).item
#define pEXP(P) (P).exp
#define pTPT(P) (P).totalPerishTime


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
