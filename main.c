
//import ADT
#include "boolean.h"

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
// #include "ADT/orderList.h"

//import fungsi-fungsi command
#include "command/command_HELP.h"


int main(){
    /*+++++ LOAD STATUS GAME +++++*/
    gameState status;
    //anggep ini ngeload, status sudah lengkap isinya berdasarkan file yang diinput

    //buat ilustrasi, misalkan input command disimpan di variabel command
    char command[100];
    boolean flag = true;
    while(true){
        /*+++++ INPUT COMMAND +++++*/
        //inputing command from user..
        //now command sudah berisi input dari user

        /*+++++ MENJALANKAN COMMAND +++++*/
        if (command == 'HELP'){
            command_HELP(&status);
        }
        else if(command == 'MAP'){
            command_MAP(&status);
        }
        //dan else if else if lainnya

        flag = isContinue(status);
    }
}