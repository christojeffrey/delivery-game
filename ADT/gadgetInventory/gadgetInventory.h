
/*
Karena isinya cuman 5, mungkin implementasinya biar ganteng dibikin list of integer, 
dengan masing-masing index merepresentasikan gadget yang berbeda. 

    index 0 - pembungkus waktu
    index 1 - senter pembesar
    index 2 - pintu kemana saja
    index 3 - mesin waktu 
    index 4 - senter pengecil // ini bonus.
Kalo ada itemnya, brarti diisi 11(atau 2 kalau item yang dimiliki 2 buah, dst). Kalo gada itemnya, diisi 0
*/

#ifndef GADGET_INVENTORY_H
#define GADGET_INVENTORY_H
typedef struct {
   int items[5]; /* memori tempat penyimpan elemen (container) */
    //modification of list statis
}gadgetInventory;

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void createGadgetInventory(gadgetInventory *gi);
/* I.S. l sembarang */
/* F.S. Terbentuk item di gi dengan setiap itemnya bernilai 0(artinya tidak punya item tersebut) */


#endif