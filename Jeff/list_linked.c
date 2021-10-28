// NIM : 13520055
// Nama : Christopher Jeffrey
// Tanggal : 26 Oktober 2021
// Topik praktikum : node dan linked list
// Deskripsi : file list_linked.c
#include<stdio.h>
#include "boolean.h"
#include "node.h"
typedef Address List;

#define IDX_UNDEF (-1)
#define FIRST(l) (l)

/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */

//declare diatas biar bisa dipake
int length(List l); 

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l){
    *l = NULL;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** TEST LIST KOSONG ******************/
/* Mengirim true jika list kosong */
boolean isEmpty(List l){
    return (l == NULL);
}

/****************** GETTER SETTER ******************/
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */
ElType getElmt(List l, int idx){
    Address p;
    p = l;
    for(int i  = 0; i < idx;i++){
        p = NEXT(p);
    }
    return (INFO(p));
}

/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */
void setElmt(List *l, int idx, ElType val){
    Address p;
    p = *l;
    for(int i  = 0; i < idx;i++){
        p = NEXT(p);
    }
    INFO(p) = val;
}

/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */
int indexOf(List l, ElType val){
    int flag = IDX_UNDEF;
    if(!isEmpty(l)){
        Address walker = l;
        int counter = 0;
        while(NEXT(walker) != NULL && INFO(walker) != val){
            walker = NEXT(walker);
            counter += 1;
        }
        // walker merupakan elemen terakhir, atau info dari walker merupakan val
        if (INFO(walker) == val){
            flag = counter;
        }
    }
    return flag;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/

/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */
void insertFirst(List *l, ElType val){
    Address p;
    p = newNode(val);
    if(*l == NULL){
        *l = p;
    }
    else{
        NEXT(p) = *l;
        *l  = p;
    }
}

/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
void insertLast(List *l, ElType val){
    Address p;
    Address walker;
    walker = *l;
    p = newNode(val);
    int panjang = length(*l);
    //get to the last
    if (*l != NULL){ //list tidak kosong
        for(int i = 0; i < panjang - 1; i++){
            walker = NEXT(walker);
        }
        //walker menunjuk pada last elemen
        NEXT(walker) = p;

    }
    else{ //l kosong
        *l = p;
    }
}

/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
void insertAt(List *l, ElType val, int idx){
    Address walker;
    walker = *l;
    Address p;
    if(p != NULL){
        p = newNode(val);
        if (idx != 0){
            for(int i = 1; i < idx;i++){
                walker = NEXT(walker);
            }
            NEXT(p) = NEXT(walker);
            NEXT(walker) = p;
        }
        else{
            if(*l != NULL){
                NEXT(p) = *l;
            }
            *l = p;
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/

/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
void deleteFirst(List *l, ElType *val){
    Address firstlist = FIRST(*l);
    *val = INFO(firstlist);
    *l = NEXT(firstlist);
    free(firstlist);

}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */
void deleteLast(List *l, ElType *val){
    Address behind = *l;
    Address p = *l;
    if (NEXT(p) != NULL){ // elemen list lebih dari satu elemen
        p = NEXT(p);
        while(NEXT(p) != NULL){
            p = NEXT(p);
            behind = NEXT(behind);
        }
        *val = INFO(p);
        NEXT(behind) = NULL;
    }
    else{ //list hanya mempunyai satu elemen
        *val = INFO(*l);
        *l = NULL;
    }
}

/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */
void deleteAt(List *l, int idx, ElType *val){
    Address behind = *l;
    Address p = *l;
    if (idx > 0){  //bukan elemen ke 0
        p = NEXT(p);
        for(int i = 0; i < idx-1; i++){
            p = NEXT(p);
            behind = NEXT(behind);
        }
        *val = INFO(p);
        //sekarang p menunjuk pada elemen yang akan dihapus.
        //jika di belakang p masih ada elemen, maka perlu disambungkan.
        //jika tidak, next dari behind = null
        if(NEXT(p) != NULL){
            NEXT(behind) = NEXT(p);
        }
        else{
            NEXT(behind) = NULL;
        }
    }
    else{ //elemen ke 0
        *val = INFO(*l);
        //jika list terdiri lebih dari satu elemen, maka perlu disambungkan.
        //jika tidak, list menjadi kosong, l = null.
        if(NEXT(*l) != NULL){
            *l = NEXT(*l);
        }
        else{
            *l = NULL;
        }
    }
    free(p);
}


/****************** PROSES SEMUA ELEMEN LIST ******************/

// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
void displayList(List l){
    printf("[");
    Address p = l;
    if(l != NULL){
        while(NEXT(p) != NULL){
            printf("%d,", INFO(p));
            p = NEXT(p);
        }
        printf("%d", INFO(p));
    }
    printf("]");
}

/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
int length(List l){
    Address p = l;
    int panjang = 0;
    if(p != NULL){
        while(NEXT(p) != NULL){
            panjang += 1;
            p = NEXT(p);
        }
        panjang += 1;
    }
    return panjang;
}
/****************** PROSES TERHADAP LIST ******************/
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */
List concat(List l1, List l2){
    List l3;
    CreateList(&l3);

    int panjang = length(l1);
    Address walker = l1;
    for(int i = 0; i < panjang;i++){
        insertLast(&l3,INFO(walker));
        walker = NEXT(walker);
    }
    panjang = length(l2);
    walker = l2;
    for(int i = 0; i < panjang; i++){
        insertLast(&l3,INFO(walker));
        walker = NEXT(walker);
    }
    return l3;
}

