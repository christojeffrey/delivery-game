
//import ADT
#include "ADT/boolean.h"

#include"ADT/gameState.h"

#include "ADT/bag.h"
#include "ADT/building.h"
#include "ADT/buildingList.h"
#include "ADT/gadgetInventory.h"
#include "ADT/inProgressList.h"
#include "ADT/location.h"
#include "ADT/nearBuilding.h"
#include "ADT/nodePaket.h"
#include "ADT/orderList.h"
#include "ADT/paket.h"
#include "ADT/todoList.h"
#include "ADT/orderList.h"

//import fungsi-fungsi command
#include "command/command.h"

//import fungsi lain
#include "fungsi/gameStateInput.h"
#include "fungsi/commandInput.h"
#include "fungsi/intInput.h"
#include "fungsi/isContinue.h"

#include<stdio.h>


#include "debug.h"



int main(){
    printf("this is welcome screen\n");
    printf("ketik 1 untuk new game, pilih 2 untuk exit:\n>");
    int menuOption = intInput();
    if(menuOption == 1){
        /*+++++ LOAD STATUS GAME +++++*/
        gameState status;
        boolean continueFlag = true;

        printf("loading game...\n");
        gameStateInput(&status);

        //tambahi printf dari game state, untuk memastikan isinya bener.
        apaIsiGameState(status);
        //print game state done
        
        while(continueFlag){
            /*+++++ INPUT COMMAND +++++*/
            printf("masukkan command:\n");
            int command = commandInput();

            /*+++++ MENJALANKAN COMMAND +++++*/
            printf("command = %d\n", command);
            // move
            // pickup
            // dropoff
            // map
            // todo
            // in prog
            // buy
            if (command == 1){
                printf("command = gaapal");
            }
            else if(command == 4){
                printf("command = map\n");
                command_MAP(status);
            }
            else{
                printf("command tidak valid. masukkan HELP untuk bantuan\n");
            }
            // //...

            // /*+++++ CEK KEBERLANGSUNGAN GAME +++++*/
            // continueFlag = isContinue(status);
        }
    }
    else if (menuOption == 2){
        printf("sampai jumpa\n");
    }
    else{
        printf("hanya menerima input satu dan dua. program ditutup\n");
    }   
}