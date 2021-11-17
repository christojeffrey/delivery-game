#include "stdio.h"
#include "stdlib.h"
#include "gadgetInventory.h"

int main () {
    gadgetInventory inventory;
    createGadgetInventory(&inventory);
    (inventory).items[0] = 1;
    printf("Jumlah item yang ada sebanyak: %d", (inventory).items[0]);
}