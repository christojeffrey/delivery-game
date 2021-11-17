#include <stdio.h>
#include <stdlib.h>
#include "nodePaket.h"
#include "../paket/paket.h"
#include "../buildingList/buildingList.h"

int main () {
    paket val;
    createPaket(&val,  1, 'R', 'Y', 'H', -1);
    Address paket = newNodePaket(val);
    printf("%p", paket);
}