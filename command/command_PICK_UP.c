// Feli
#include "command.h"
#include "../fungsi/getType.h"
#include "../fungsi/gameStateInput.h"
#include <stdio.h>
#include "../fungsi/getLoc.h"

void command_PICK_UP(gameState* status) {
    /* KAMUS LOKAL */
    Address p, prev;
    paket paket;
    char currLoc;
    boolean found, VIP, VIPtas;
    /* ALGORITMA */
    if (isBagFull(status->tas)) {
        printf("Tas Mobita penuh!\n");
    } else {
        currLoc = getLoc(status->myLoc, status->buildings);
        found = false;
        VIPtas = false;
        VIP = false;
        if (!isTodoListEmpty(status->todos)) {
            prev = status->todos;
            p = prev->next;
            /* BONUSSSSSS */
            // Cek ada VIP ngga
            // Di tas
            if (!isBagEmpty(status->tas)) {
                for (int i = status->tas.idxTop; i>=0; i--) {
                    if (status->tas.buffer[i].item == 'V') {
                        VIPtas = true;
                    }
                }
            }
            if (!isTodoListEmpty(prev)) {
                // Cek elemen pertama
                if (prev->info.item == 'V') {
                    VIP = true;
                    if (prev->info.pickup == currLoc) {
                        found = true;
                        deleteFirstTodoList(&(status->todos),&paket);
                    }
                }
                // Cek elemen sisa
                while (p != NULL && !found) {
                    if ((p)->info.item == 'V') {
                        // activate VIP status
                        VIP = true;
                        if ((p)->info.pickup == currLoc) {  
                            (prev)->next = p->next;
                            paket = (p)->info;
                            found = true;
                            free(p);
                        }
                    }
                    prev = (prev)->next;
                    p = (p)->next;
                }
            }
        }
        
        if (!VIP && !VIPtas) {
            p = status->todos;
            // baru cari yang item non-VIP
            if (!isTodoListEmpty(p)) {
                if (p->info.pickup == currLoc && !found){
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
                    if (p->info.pickup == currLoc && !found){
                        found = true;
                        deleteLastTodoList(&(status->todos),&paket);
                    }
                }
            }
        }

        // Output
        if (found) {
            pushBag(&(status->tas), paket);
            insertFirstInProgressList(&(status->inProgress), paket);
            printf("Pesanan berupa %s Item berhasil diambil!\n", getType(paket));
        } else if (VIPtas) {
            printf("Antarkan terlebih dahulu pesanan VIP!\n");
        } else if (VIP) {
            printf("Pick up pesanan VIP terlebih dahulu!\n");
        } else {
            printf("Pesanan tidak ditemukan!\n");
        }
    }
}