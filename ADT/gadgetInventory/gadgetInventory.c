#include <stdio.h>
#include <stdlib.h>
#include "gadgetInventory.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void createGadgetInventory(gadgetInventory *gi)
/* I.S. l sembarang */
/* F.S. Terbentuk item di gi dengan setiap itemnya bernilai 0(artinya tidak punya item tersebut) */
{
    for (int i = 0; i < 5;i++){
        (*gi).items[(i)] = 0;
    }
}