#include <stdio.h>
#include <stdlib.h>
#include "todoList.h"
#include "../nodePaket/nodePaket.h"
#include "../paket/paket.h"

char* getType(paket input) {
    if (input.item == 'N') {
        return "Normal";
    } else if (input.item == 'H') {
        return "Heavy";
    } else if (input.item == 'P') {
        return "Perishable";
    } else if (input.item == 'V') {
        return "VIP";
    } else {
        return "???";
    }
}

void displayList(todoList l)
{
    if (isTodoListEmpty(l)) {
        printf("To Do List Kosong");
    }
    else {
        Address p = l;
        char *type;
        int i = 1;
        printf("Pesanan pada To Do List:\n");
        while(p != NULL) {
            type = getType((p)->info);
            printf("%d. %c -> %c (%s Item)\n", i, (p)->info.pickup, (p)->info.dropoff, type);
            i++;
            p = (p)->next;
        }
    }
}

int main () {
    todoList tdl;
    paket Paket;
    paket package;
    CreateTodoList(&tdl);
    createPaket(&Paket, 1, 'A','B', 'N',-1);
    createPaket(&package, 1, 'R', 'Y', 'H', -1);
    insertFirstTodoList(&tdl, Paket);
    displayList(tdl);
    insertLastTodoList(&tdl, package);
    displayList(tdl);
    deleteFirstTodoList(&tdl, &Paket);
    displayList(tdl);
    deleteLastTodoList(&tdl, &package);
    displayList(tdl);
}