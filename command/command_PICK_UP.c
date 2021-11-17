// Feli
#include "command.h"
#include "../fungsi/getType.h"
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
    p = status->todos;
    found = false;
    if (p->info.pickup == currLoc){
        found = true;
        deleteFirstTodoList(&(status->todos),&paket);
    }
    else {
        while((p)->next != NULL && !found) {
            if ((p->next)->info.pickup == currLoc) {
                paket = (p->next)->info;
                (p)->next = ((p)->next)->next;
                found = true;
            } else {
                p = (p)->next;
            }
        }
    }

    if (p->info.pickup == currLoc){
        found = true;
        deleteLastTodoList(&(status->todos),&paket);
    }

    if (found) {
        pushBag(&(status->tas), paket);
        insertFirstInProgressList(&(status->inProgress), paket);
        printf("Pesanan berupa %s Item berhasil diambil!\n", getType(paket));
    } else {
        printf("Pesanan tidak ditemukan!\n");
    }
}