//jef
#include "../fungsi/intInput.h"
#include "command.h"

#include<stdio.h>
void command_BUY(gameState* status){
    //cek apakah command dijalankan ketika sedang di hq.
    if(status->myLoc.X == status->hq.X && status->myLoc.Y == status->myLoc.Y){
        printf("Uang anda sekarang : %d Yen\n", status->money);
        printf("gadget yang tersedia : \n");
        pritnf("1. Kain Pembungkus Waktu (800 Yen)\n");
        printf("2. Senter Pembesar (1200 Yen)\n");
        printf("3. Pintu Kemana Saja (1500 Yen)\n");
        printf("4. Mesin Waktu (3000 Yen)\n");
        printf("Gadget mana yang ingin Anda beli?(ketik 0 jika tidak membeli apapun)\n");
        int pilihan = intInput();
        //yang perlu di cek adalah apakah uang mencukupi, apakah inventory penuh
        if (pilihan >= 1 && pilihan <= 4){
            //cek apakah inventory penuh
            int totalOwnedGadget  = 0;
            for(int i = 0; i < 4; i++){
                totalOwnedGadget += status->inventory.items[i];
            }
            if (totalOwnedGadget >= 5){
                printf("Gadget inventory penuh, kamu tidak bisa bisa membeli gadget lagi.\n");
                printf("silakan melihat dan menggunakan gadget dengan command INVENTORY.\n");
            }
            else{
                if (pilihan == 1){
                    printf("Kamu memilih 1. Kain Pembungkus Waktu dengan harga 800 Yen\n");
                    if(status->money < 800){
                        printf("Uang kamu sebelum membeli adalah %d,\n", status->money);
                        printf("sedangkan harga gadgetnya adalah 800 Yen.\n");
                        printf("Uang yang kamu miliki tidak mencukupi.");
                    }
                    else{
                        //uang mencukupi
                        status->money = status->money - 800;
                        printf("Berhasil membeli gadget 1. Kain Pembungkus Waktu!\n");
                        printf("Gunakan command INVENTORY untuk melihat dan menggunakan gadget yang kamu miliki.\n");

                        printf("Uang kamu berubah menjadi %d\n", status->money);
                    }
                }//end of pilihan == 1
                else if(pilihan == 2){

                }//end of pilihan == 2
                else if(pilihan == 3){

                }//end of pilihan == 3
                else if(pilihan == 4){

                }//end of pilihan == 4

            }
            
        }
        //else, berarti pilihan == 0 atau pilihan > 4
        else{
            if(pilihan == 0){
                printf("Terima kasih, sampai jumpa lagi!\n");
            }
            else{
                printf("Input tidak legal. command berhenti\n");
            }
        }
        
    }
    else{ //command tidak dijalankan di hq
        printf("Maaf, kamu tidak bisa membeli gadget saat ini,\n");
        printf("kamu hanya bisa membeli gadget saat berada di HQ.");

    }
}