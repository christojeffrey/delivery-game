#include "paket.h"
#include "../buildingList/buildingList.h"
#include "../building/building.h"
#include "../nearBuilding/nearBuilding.h"
#include <stdio.h>
int main(){
    paket P;
    createPaket(&P, 1, 'A','B', 'N',-1);
    printf("Paket datang di t = %d, lokasi pick-up di p = %c, lokasi drop-off di d = %c, dan paket bertipe %c", pTIME(P), pPICK_UP(P),pDROP_OFF(P),pTIPE(P));
    //untu fungsi getPlocation dan getDlocation hanya berguna di game
}