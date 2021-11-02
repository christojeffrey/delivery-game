//jef
#include "command_MAP.h"
#include "../ADT/boolean.h"
char isThereBuildingInThisLoc(buildingList bl, int x, int y){
//mengembalikan char building jika building exist. mengembalikan '0' jika tidak ada.

}
void command_MAP(gameState status){
    //KAMUS
    int baris = status.mapHeight;
    int kolom = status.mapWidth;
    char namaB = '0';

    //ALGORITMA

    //print bintang awal
    for(int loop = 1;loop <= kolom;loop++){
        print("*");
    }
    print("\n");
    for(int b = 1; b<= baris;b++){
        print("*");
        for(int k = 1; k <= kolom;k++){
            //yang akan dicek, building, HQ, lokasi mobita
            namaB = isThereBuildingInThisLoc(status.buildings,b,k); 
            if(namaB == '0'){
                print(" ");
            }
            else{
                print(namaB);
            }
        }
        printf("*\n");
    }
    //print bintang akhir
    for(int loop = 1;loop <= kolom;loop++){
        print("*");
    }
    print("\n");
}