#include <stdio.h>
#include <stdlib.h>
#include "bag.h"
#include "../paket/paket.h"
#include "../nodePaket/nodePaket.h"

void displayItem(paket p) {
    int i = 1;
    printf("%c Item (Tujuan: %c)\n", pTIPE(p), pDROP_OFF(p));
}

int main () {
    bag tas;
    CreateBag(&tas);
    paket Paket;
    paket package;
    paket p;
    createPaket(&Paket, 1, 'A','B', 'N',-1);
    createPaket(&package, 1, 'R', 'Y', 'H', -1);
    createPaket(&p, 1, 'J', 'K', 'N', -1);
    pushBag(&tas, package);
    pushBag(&tas, Paket);
    pushBag(&tas, p);
    paket val;
    while (!(isBagEmpty(tas))) {
        popBag(&tas, &val);
        printf("Item yang di pop dari bag adalah: ");
        displayItem(val);
    }
    
}