// Feli
#include "command.h"
#include "../fungsi/gameStateInput.h"
#include "../fungsi/getType.h"
#include <stdio.h>
#include "../fungsi/getLoc.h"

void command_DROP_OFF(gameState* status){
    /* KAMUS LOKAL */
    Address p;
    paket paket;
    char currLoc;
    boolean found;
    int uang;
    /* ALGORITMA */
    currLoc = getLoc(status->myLoc, status->buildings);
    if (!isBagEmpty(status->tas)){
        paket = status->tas.buffer[status->tas.idxTop];
        if (paket.dropoff == currLoc) {
            if (paket.item == 'N') {
                uang = 200;
            } else if (paket.item == 'H') {
                uang = 400;
                // mendapat speedboost
                status->speedBoost += 10;
            } else if (paket.item == 'P') {
                uang = 400;
                //capacity bag bertambah 1
                status->tas.bagCapacity += 1;
            } else if (paket.item == 'V') {
                uang = 600;
                // ability return to sender
            }
            popBag(&(status->tas), &paket);
            deleteFirstInProgressList(&(status->inProgress), &paket);
            status->money += uang;
            printf("Pesanan %s Item berhasil diantarkan!\n", getType(paket));
            printf("Uang yang didapatkan: %d Yen\n", uang);
        } else {
            printf("Tidak ada pesanan yang dapat diantarkan!\n");
        }
    } else {
        printf("Kamu belum mengambil pesanan apa-apa\n");
    }
}