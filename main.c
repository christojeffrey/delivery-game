
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
    /* Bicycle ASCII Art */
    printf("              __\n    ,--.      <__)\n    `- |________7\n        |`.      |\\ \n    .--|. \\     |.\\--.\n    /   j \\ `.7__j__\\  \\ \n   |   o   | (o)____O)  |\n    \\     /   J  \\     /\n    `---'        `---'      hjw\n\n------------------------------------------------\n");
    printf("Ketik 1 untuk new game, ketik 2 untuk exit:\n> ");
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
            printf("------------------------------------------------\n");
            printf("masukkan command:\n>");
            int command = commandInput();

            /*+++++ MENJALANKAN COMMAND +++++*/
            printf("command = %d\n", command);
            /* Daftar command dan angkanya: 
                1. MOVE
                2. PICK_UP
                3. DROP_OFF
                4. MAP
                5. TO_DO
                6. IN_PROGRESS
                7. BUY
                8. INVENTORY
                9. HELP
                Invalid command = -1
            */
            if (command == 1){
                command_MOVE(&status);
            }
            else if (command == 2) {
                command_PICK_UP(&status);
            }
            else if (command == 3) {
                command_DROP_OFF(&status);
            }
            else if (command == 4) {
                command_MAP(status);
            }
            else if (command == 5) {
                command_TO_DO(status);
            }
            else if(command == 6){
                command_IN_PROGRESS(status);
            }
            else if (command == 7) {
                command_BUY(&status);
            }
            else if (command == 8) {
                command_INVENTORY(&status);
            }
            else if (command == 9) {
                command_HELP();
            }
            else{
                printf("Command tidak valid. masukkan HELP untuk bantuan\n");
            }
            // //...

            // /*+++++ CEK KEBERLANGSUNGAN GAME +++++*/
            // continueFlag = isContinue(status);
        }
    }
    else if (menuOption == 2){
        printf("Sampai jumpa...\n");
    }
    else{
        printf("Hanya menerima input satu dan dua. Program ditutup\n");
    }   
}