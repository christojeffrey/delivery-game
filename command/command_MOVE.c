// Feli
#include "command.h"
#include "../ADT/nearBuilding/nearBuilding.h"
#include <stdio.h>
#include<math.h>
void command_MOVE(gameState* status) {
    /* KAMUS LOKAL */
    buildingList l;
    int i, input;
    paket paket;
    /* ALGORITMA */
    l = getMove(status->bangunanSekitar, status->buildings, status->myLoc,status->hq);
    printf("Posisi yang dapat dicapai:\n");
    for (i=0; i<bLNEFF(l); i++) {
        printf("%d. %c (%d,%d)\n", i+1, bLELMT(l,i).name, bLELMT(l,i).loc.X, bLELMT(l,i).loc.Y);
    }
    printf("Posisi yang dipilih? (ketik 0 jika ingin kembali)\n> ");
    scanf("%d", &input);
    while (input>i || input<0) {
        printf("Masukkan pilihan dari 0 sampai %d\n> ", i);
        scanf("%d", &input);
    }
    if (input != 0) {
        printf("Moving...\n");
        /* Moving */
        status->myLoc = bLELMT(l,input-1).loc;
        /* Time travel */

        int jumlahWaktuBerjalan = 0;
        if(!isBagEmpty(status->tas)){
            for( int i = status->tas.idxTop; i < status->tas.idxTop + status->tas.bagCapacity;i++){
                if(status->tas.buffer[i].item = 'H'){
                    jumlahWaktuBerjalan++;
                }
            }
        }
        // kasus pertama, jika tidak ada heavy item di dalam bag
        if(jumlahWaktuBerjalan == 0){
            if(status->speedBoost != 0){
                status->speedBoost -= 0.5;
                if(roundf(status->speedBoost) == status->speedBoost){
                    jumlahWaktuBerjalan += 1;
                }
                //else berarti gk bulat, berarti waktu nggak jalan
            }
            else{
                //gapunya speedboost;
                jumlahWaktuBerjalan += 1;
            }
        }
        // kasus kedua, ada heavy item di dalam bag
        else{
            //ditambahkan 1 lagi, yaitu waktu berjalan normal
            jumlahWaktuBerjalan++;
        }
        
        status->time += jumlahWaktuBerjalan;
        /* Updating To Do */
        while (!isOrderListEmpty(status->orders) && (oLHEAD(status->orders).t <= status->time)) {
            dequeueOrderList(&(status->orders), &paket);
            insertLastTodoList(&(status->todos), paket);
        }
        /*updating perishable item*/


        printf("Mobita sekarang berada di titik %c (%d,%d)!\n", bLELMT(l, input-1).name, status->myLoc.X, status->myLoc.Y);
        printf("Waktu: %d\n", status->time);
    } 
}