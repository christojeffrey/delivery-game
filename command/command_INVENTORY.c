//jef

#include "command.h"

#include "../ADT/location/location.h"

#include "../fungsi/intInput.h"
#include<stdio.h>
void command_INVENTORY(gameState* status){
    //PRINT INVENTORY
    int counter = 1; //untung menyimpan nomor
    int JumlahItem = 0;
    for(int b = 0; b< 4;b++){
        JumlahItem += status->inventory.items[b];
        for(int k = 1;k <= JumlahItem;k++){
            if(b == 0){
                //gadget = 
                printf("%d. ",counter);
            }
            else if(b == 1){
                //gadget = 
                printf("%d. ", counter);
            }
            else if (b == 2){
                //gadget = 
                printf("%d. ", counter);
            }
            counter += 1;
        }
    }
    //PRINT INVENTORY SELESAI
    if(JumlahItem == 0){
        printf("Kamu tidak memiliki gadget.\nAnter barang, dapet uang, beli gadget, baru bisa pake gadget, oke?\n");
    }
    else{
        printf("Pilih gadget yang ingin digunakan (0 untuk tidak menggunakan)\n");
        int pilihan = intInput();
        if(pilihan > counter-1){
            printf("pilihan tidak valid.\n");
            printf("program berhenti\n");
        }
        else if(pilihan == 0){
            printf("terima kasih sudah mampir ke inventory\n");
        }
        else{
            //pilihan valid
            //cari itemnya dulu
            int idxItem = 0; //mewakili item yang dipilih.
            int tempSum = 0;
            for(int b = 0;b<4;b++){
                tempSum += status->inventory.items[b];
                if(tempSum >= pilihan){
                    idxItem = b;
                    break;
                }
            }
            //idx item pasti ketemu
            if(idxItem == 0){
                // index 0 - pembungkus waktu
                // Setiap kain pembungkus waktu dapat dipakai sekali untuk perishable item
                // teratas pada tas agar kembali ke durasi semula.

                //jika topnya perishable, maka bisa dilakukan something
                if(status->tas.buffer[status->tas.idxTop].item == 'P'){
                    int expireTimeLama = status->tas.buffer[status->tas.idxTop].exp;
                    status->tas.buffer[status->tas.idxTop].exp = status->tas.buffer[status->tas.idxTop].totalPerishTime;
                    int expireTimeBaru = status->tas.buffer[status->tas.idxTop].exp;
                    printf("Gadget berhasil digunakan!\n");
                    printf("Waktu expire heavy item di top of bag berubah dari %d menjadi %d\n", expireTimeLama, expireTimeBaru);
                    status->inventory.items[idxItem] -= 1;
                }
                else{
                    printf("top of bag bukan perishable item. Gadget gagal digunakan.\n");
                }

            }
            else if(idxItem == 1){
                // index 1 - senter pembesar
                // Senter pembesar dapat digunakan untuk meningkatkan kapasitas tas
                // sebesar dua kali lipat, namun tidak melebihi batas maksimum kapasitas tas.
                status->tas.bagCapacity *= 2;
                if(status->tas.bagCapacity > 100){
                    status->tas.bagCapacity = 100;
                }
                printf("Gadget berhasil digunakan!\n");
                printf("kapasitas tasmu menjadi %d\n", status->tas.bagCapacity);
                status->inventory.items[idxItem] -= 1;
            }
            else if(idxItem == 2){
                // index 2 - pintu kemana saja
                // Pintu Kemana Saja dapat digunakan sekali untuk berpindah ke lokasi yang
                // diinginkan tanpa menambahkan unit waktu.
                //LIST BUILDING
                printf("List building yang dapat dipilih");
                //PILIH BUILDING
                char namaBuilding;
                location lokasiBuilding;
                printf("1. HQ(%d,%d)\n", status->hq.X, status->hq.Y);
                for(int i = 0; i < status->buildingCount;i++){
                    namaBuilding = status->buildings.buffer[i].name;
                    lokasiBuilding.X = status->buildings.buffer[i].loc.X;
                    lokasiBuilding.Y = status->buildings.buffer[i].loc.Y;
                    printf("%d. %c(%d,%d)\n", i+2, namaBuilding,lokasiBuilding.X,lokasiBuilding.Y);
                }
                printf("Pilih building\n");
                int pilihanLokasi = intInput();
                
                //PINDAH MYLOC
                if(pilihanLokasi <= 0 || pilihanLokasi > status->buildingCount+1){
                    printf("pilihan tidak valid.\n");
                    printf("command berhenti. Gadget gagal digunakan\n");
                } else {
                
                    if(pilihanLokasi == 1){
                        status->myLoc.X = status->hq.X;
                        status->myLoc.Y = status->hq.Y;
                        printf("Gadget berhasil digunakan!\n");
                        printf("lokasimu berubah! kamu sekarang berada di HQ(%d,%d).\n",status->myLoc.X,status->myLoc.Y);
                    }
                    else{
                        pilihanLokasi = pilihanLokasi - 2;
                        status->myLoc.X = status->buildings.buffer[pilihanLokasi].loc.X;
                        status->myLoc.Y = status->buildings.buffer[pilihanLokasi].loc.Y;
                        namaBuilding = status->buildings.buffer[pilihanLokasi].name;
                        
                        printf("Gadget berhasil digunakan!\n");
                        printf("lokasimu berubah! kamu sekarang berada di %c(%d,%d).\n",namaBuilding,status->myLoc.X,status->myLoc.Y);
                        status->inventory.items[idxItem] -= 1;
                    }
                }

            }
            else if(idxItem == 3){
                // index 3 - mesin waktu 
                // Mesin waktu dapat digunakan untuk mengurangi waktu sebanyak 50 unit.
                // (jika waktu kurang dari 50 unit, maka waktu menjadi 0 unit).
                status->time -= 50;
                if (status->time < 0){
                    status->time = 0;
                }
                printf("Gadget berhasil digunakan!\n");
                printf("waktu saat ini berubah menjadi %d\n", status->time);
                status->inventory.items[idxItem] -= 1;
            }
        }
    }
}