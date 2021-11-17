#include "orderList.h"
#include "../paket/paket.h"
#include "../buildingList/buildingList.h"
#include "../building/building.h"
#include "../nearBuilding/nearBuilding.h"
#include <stdio.h>
int main(){
    orderList oL;
    CreateOrderList(&oL);
    printf("%d\n",lengthOrderList(oL));
    paket P1;
    createPaket(&P1, 2,'H', 'N','N',-1);
    enqueueOrderList(&oL, P1);
    printf("%d\n", lengthOrderList(oL));
    printf("%c\n", pTIPE(oLHEAD(oL))); // barang normal
    createPaket(&P1, 2,'H', 'N','P',2);
    for (int i = 1; i < 40; i++){
        enqueueOrderList(&oL, P1);
    }
    printf("%d\n", lengthOrderList(oL));
    printf("%d\n", isOrderListFull(oL));
    dequeueOrderList(&oL, &P1);
    printf("%d\n", lengthOrderList(oL));
    
}