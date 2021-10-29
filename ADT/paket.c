#include "paket.h"
#include "location.h"
#include "buildingList.h"
#include "building.h"
#include "nearBuilding.h"
void createPaket(paket * P, int t, char p, char d, char i, int e)
/* Membuat paket */
/* I.S P sembarang */
/* F.S TIME(P) = t, PICK_UP(P) = p, DROP_OFF(P) = d, TIPE(P) = i, EXP(P) = e. */
/* EXP(P) = -1 jika item bukan bertipe Perishable*/
{
    TIME(*P) = t;
    PICK_UP(*P) = p;
    DROP_OFF(*P) = d;
    TIPE(*P) = i;
    EXP(*P) = e;
}

building getPLocation(paket P, buildingList bl)
/* Mencari titik lokasi Pickup P */
/* prekondisi, PICK_UP(P) adalah Point yang valid dalam game */
{
    return bLELMT(bl, buildingListIndexOfName(bl ,PICK_UP(P)));
}

building getDLocation(paket P, buildingList bl)
/* Mencari titik lokasi Dropoff P */
/* prekondisi, DROP_OFF(P) adalah Point yang valid dalam game */
{
    return bLELMT(bl, buildingListIndexOfName(bl ,DROP_OFF(P)));
}