#include "inProgressList.h"
#include <stdio.h>
#include <stdlib.h>
#include "../nodePaket/nodePaket.h"
#include "../paket/paket.h"

void displayList(inProgressList l)
{
    if (isInProgressListEmpty(l)) {
        printf("In Progress List Kosong");
    }
    else {
        Address p = l;
        int i = 1;
        while(p != NULL) {
            printf("%d. %c Item (Tujuan: %c)\n", i, p->info.item, p->info.dropoff);
            i++;
            p = p->next;
        }
    }
}

int main () {
    inProgressList ipl;
    paket Paket;
    paket package;
    CreateInProgressList(&ipl);
    createPaket(&Paket, 1, 'A','B', 'N',-1);
    createPaket(&package, 1, 'R', 'Y', 'H', -1);
    insertFirstInProgressList(&ipl, Paket);
    displayList(ipl);
    insertLastInProgressList(&ipl, package);
    displayList(ipl);
    deleteFirstInProgressList(&ipl, &Paket);
    displayList(ipl);
    deleteLastInProgressList(&ipl, &package);
    displayList(ipl);
}