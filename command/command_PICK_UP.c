// Feli
#include "command.h"
#include "../fungsi/gameStateInput.h"
#include <stdio.h>
#include "../fungsi/getLoc.h"

void command_PICK_UP(gameState* status) {
    /* KAMUS LOKAL */
    Address p;
    paket paket;
    char currLoc;
    boolean found;
    /* ALGORITMA */
    currLoc = getLoc(status->myLoc, status->buildings);
    printf("currLoc: %c\n", currLoc);
    p = status->todos;
    found = false;
    while(p != NULL && !found) {
        if ((p)->info.pickup == currLoc) {
            paket = (p)->info;
            if ((p)->next != NULL) {
                (p)->next = ((p)->next)->next;
            } else {
                deleteLastTodoList(&(status->todos), &paket);
            }
            found = true;
        }
        p = (p)->next;
    }
    if (found) {
        pushBag(&(status->tas), paket);
        insertFirstInProgressList(&(status->inProgress), paket);
        printf("Pesanan berupa %c Item berhasil diambil!\n", paket.item);
    } else {
        printf("Pesanan tidak ditemukan!\n");
    }
}