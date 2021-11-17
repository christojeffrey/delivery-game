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
        if(bLELMT(l,i).name == '!'){
            printf("%d. HQ (%d,%d)\n", i+1, bLELMT(l,i).loc.X, bLELMT(l,i).loc.Y);
        }
        else{
            printf("%d. %c (%d,%d)\n", i+1, bLELMT(l,i).name, bLELMT(l,i).loc.X, bLELMT(l,i).loc.Y);
        }
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
            for( int i = status->tas.idxTop; i > -1;i--){
                if(status->tas.buffer[i].item == 'H'){
                    jumlahWaktuBerjalan++;
                }
            }
        }
        printf("jumlah waktu berjalan = %d\n", jumlahWaktuBerjalan);
        // kasus pertama, jika tidak ada heavy item di dalam bag
        if(jumlahWaktuBerjalan == 0){
            if(status->speedBoost > 0){
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
        }// kasus kedua, ada heavy item di dalam bag
        else{
            //jika ada heavy item di dalam tas, efek speedbost akan langsung hilang
            status->speedBoost = 0;
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
        //dua tempat yang perlu di update, bag dan in progress list
        if(!isBagEmpty(status->tas)){
            printf("Bag tidak kosong, updating bag\n");
            int start = status->tas.idxTop;
            int end = status->tas.idxTop + status->tas.bagCapacity;
            for( int i = start; i < end;i++){
                if(status->tas.buffer[i].item == 'P'){
                    status->tas.buffer[i].exp -= jumlahWaktuBerjalan;
                    if(status->tas.buffer[i].exp <= 0){
                        //hapus
                        for(int idel = i; idel > status->tas.idxTop;idel--){
                            status->tas.buffer[idel] = status->tas.buffer[idel-1];
                        }
                        status->tas.idxTop -= 1;
                    }
                }
            }
        }
        //cek progresslist
        Address walker = status->inProgress;
        Address prewalker = status->inProgress;
        if(walker != NULL){
            printf("in progress tidak kosong, updating bag\n");
            //cek elemen selain pertama
            walker = walker->next;
            while(walker != NULL){
                if (walker->info.item == 'P'){
                    walker->info.exp -= jumlahWaktuBerjalan;
                    if(walker->info.exp <= 0){
                        prewalker->next = walker->next;
                        free(walker);
                        walker = prewalker->next;
                    }
                }
                prewalker = walker;
                walker = walker->next;
            }
            //cek elemen pertama
            if (status->inProgress->info.item == 'P'){
                status->inProgress->info.exp -= jumlahWaktuBerjalan;
                if(status->inProgress->info.exp <= 0){
                    walker = status->inProgress;
                    status->inProgress = status->inProgress->next;
                    free(walker); 
                }
            }
        }

        printf("Mobita sekarang berada di titik %c (%d,%d)!\n", bLELMT(l, input-1).name, status->myLoc.X, status->myLoc.Y);
        printf("Waktu: %d\n", status->time);
    } 
}