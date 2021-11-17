//jef
#include "../fungsi/intInput.h"
#include "command.h"

#include<stdio.h>
void command_BUY(gameState* status){
    //cek apakah command dijalankan ketika sedang di hq.
    if(status->myLoc.X == status->hq.X && status->myLoc.Y == status->hq.Y){
        printf("Uang anda sekarang : %d Yen\n", status->money);
        printf("gadget yang tersedia : \n");
        printf("1. Kain Pembungkus Waktu (800 Yen)\n");
        printf("2. Senter Pembesar (1200 Yen)\n");
        printf("3. Pintu Kemana Saja (1500 Yen)\n");
        printf("4. Mesin Waktu (3000 Yen)\n");
        printf("Gadget mana yang ingin Anda beli?(ketik 0 jika tidak membeli apapun)\n>");
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
                int harga = 0;
                if (pilihan == 1){
                    harga = 800;
                    printf("Kamu memilih 1. Kain Pembungkus Waktu dengan harga %d Yen\n", harga);
                    if(status->money < 800){
                        printf("Uang kamu sebelum membeli adalah %d,\n", status->money);
                        printf("sedangkan harga gadget adalah %d Yen.\n", harga);
                        printf("Uang yang kamu miliki tidak mencukupi.\n");
                    }
                    else{
                        //uang mencukupi
                        status->money = status->money - harga;
                        status->inventory.items[0] ++;
                        printf("Berhasil membeli gadget 1. Kain Pembungkus Waktu!\n");
                        printf("Gunakan command INVENTORY untuk melihat dan menggunakan gadget yang kamu miliki.\n");
                        printf("Uang kamu berubah menjadi %d\n", status->money);
                    }
                }//end of pilihan == 1
                else if(pilihan == 2){
                    harga = 1200;
                    printf("Kamu memilih 2. Senter Pembesar dengan harga %d Yen\n", harga);
                    if(status->money < harga){
                        printf("Uang kamu sebelum membeli adalah %d,\n", status->money);
                        printf("sedangkan harga gadget adalah %d Yen.\n", harga);
                        printf("Uang yang kamu miliki tidak mencukupi.\n");
                    }
                    else{
                        //uang mencukupi
                        status->money = status->money - harga;
                        status->inventory.items[1] ++;
                        printf("Berhasil membeli gadget 2. Senter Pembesar!\n");
                        printf("Gunakan command INVENTORY untuk melihat dan menggunakan gadget yang kamu miliki.\n");

                        printf("Uang kamu berubah menjadi %d\n", status->money);
                    }
                }//end of pilihan == 2
                else if(pilihan == 3){
                    harga = 1500;
                    printf("Kamu memilih 3. Pintu Kemana Saja dengan harga %d Yen\n", harga);
                    if(status->money < 800){
                        printf("Uang kamu sebelum membeli adalah %d,\n", status->money);
                        printf("sedangkan harga gadget adalah %d Yen.\n", harga);
                        printf("Uang yang kamu miliki tidak mencukupi.\n");
                    }
                    else{
                        //uang mencukupi
                        status->money = status->money - harga;
                        status->inventory.items[2] ++;
                        printf("Berhasil membeli gadget 3. Pintu Kemana Saja!\n");
                        printf("Gunakan command INVENTORY untuk melihat dan menggunakan gadget yang kamu miliki.\n");
                        printf("Uang kamu berubah menjadi %d\n", status->money);
                    }
                }//end of pilihan == 3
                else if(pilihan == 4){
                    harga = 3000;
                    printf("Kamu memilih 4. Mesin Waktu dengan harga %d Yen\n", harga);
                    if(status->money < 800){
                        printf("Uang kamu sebelum membeli adalah %d,\n", status->money);
                        printf("sedangkan harga gadget adalah %d Yen.\n", harga);
                        printf("Uang yang kamu miliki tidak mencukupi.\n");
                    }
                    else{
                        //uang mencukupi
                        status->money = status->money - harga;
                        status->inventory.items[3] ++;
                        printf("Berhasil membeli gadget 4. Mesin Waktu!\n");
                        printf("Gunakan command INVENTORY untuk melihat dan menggunakan gadget yang kamu miliki.\n");
                        printf("Uang kamu berubah menjadi %d\n", status->money);
                    }
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
        printf("kamu hanya bisa membeli gadget saat berada di HQ.\n");

    }
}