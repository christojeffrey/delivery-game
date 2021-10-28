#include "boolean.h"
#include "listpos.h"
#include <stdio.h>
/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListPos(ListPos *l){
    for (int b = 0; b < CAPACITY;b++){
        ELMT(*l, b) = VAL_UNDEF;
    }
}
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan VAL_UNDEF */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length(ListPos l){
    int b = 0;
    while (ELMT(l, b) != VAL_UNDEF && b < CAPACITY)
        b++;
    return b;
}
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListPos l, int i){
    return (i >= 0 && i < CAPACITY);
}
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEff(ListPos l, int i){
    return (i >= 0 && i < length(l));
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListPos l){
    if (length(l) == 0)
        return true;
    return false;
}
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */
boolean isFull(ListPos l){
    if (length(l) == CAPACITY)
        return true;
    else 
        return false;
}
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readList(ListPos *l){
    int n = -1;
    while(n < 0 || n > CAPACITY){
        scanf("%d", &n);
    }
    ElType temp;
    CreateListPos(l);
    for(int b = 0; b < n;b++){
        scanf("%d", &temp);
        ELMT(*l, b) = temp;
    }
}
/* I.S. l sembarang */
/* F.S. List l terdefinisi */
/* Proses: membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < n <= CAPACITY; Lakukan n kali: 
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
/*    Jika n = 0; hanya terbentuk List kosong */
void displayList(ListPos l){
    printf("[");
    for(int b = 0; b < length(l);b++){
        printf("%d", ELMT(l, b));
        if(b != length(l) - 1)
            printf(",");
    }
    printf("]");
}
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListPos plusMinusTab(ListPos l1, ListPos l2, boolean plus){
    ListPos lp;
    CreateListPos(&lp);
    if (plus)
        for(int b = 0;b < length(l1);b++){
            ELMT(lp, b) = ELMT(l1, b) + ELMT(l2, b);
        }
    else
        for(int b = 0;b < length(l1);b++){
            ELMT(lp, b) = ELMT(l1, b) - ELMT(l2, b);
        }
    return lp;
}
/* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada 
       indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi 
       elemen l2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqual(ListPos l1, ListPos l2){
    if (length(l1) != length(l2))
        return false;
    int b = 0;
    while(b<length(l1)){
        if (ELMT(l1,b) != ELMT(l2,b))
            return false;
        b++;
    }
    return true;
}
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
   elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf(ListPos l, ElType val){
    int b = 0;
    while(b < length(l)){
        if (ELMT(l, b) == val){
            return b;
        }
        b++;
    }
    return IDX_UNDEF;
}
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void extremes(ListPos l, ElType *max, ElType *min){
    *max = ELMT(l, 0);
    *min = ELMT(l, 0);
    for(int b = 0; b< length(l);b++){
        if(ELMT(l,b) > *max)
            *max = ELMT(l,b);
        if(ELMT(l,b) < *min)
            *min = ELMT(l,b);
    }

}
/* I.S. List l tidak kosong */
/* F.S. Max berisi nilai terbesar dalam l;
        Min berisi nilai terkecil dalam l */

/* ********** OPERASI LAIN ********** */
boolean isAllEven(ListPos l){
    int b = 0;
    while(b < length(l)){
        if(ELMT(l,b) % 2 != 0)
            return false;
        b++;
    }
    return true;
}
/* Menghailkan true jika semua elemen l genap */

/* ********** SORTING ********** */
void sort(ListPos *l, boolean asc){
    boolean changes = true;
    ElType temp;
    if (asc)
        while(changes){
            changes = false;
            for(int b = 1;b<length(*l);b++){
                if(ELMT(*l,b-1) > ELMT(*l, b)){
                    temp = ELMT(*l, b-1);
                    ELMT(*l,b-1) = ELMT(*l, b);
                    ELMT(*l, b) = temp;
                    changes = true;
                }
            }
        }
    else
        while(changes){
            changes = false;
            for(int b = 1;b<length(*l);b++){
                if(ELMT(*l,b-1) < ELMT(*l, b)){
                    temp = ELMT(*l, b-1);
                    ELMT(*l,b-1) = ELMT(*l, b);
                    ELMT(*l, b) = temp;
                    changes = true;
                }
            }
        }
}
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListPos *l, ElType val){
    ELMT(*l, length(*l)) = val;
}
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListPos *l, ElType *val){
    if(length(*l) != 0){
        *val = ELMT(*l, length(*l) - 1);
        ELMT(*l, length(*l) - 1) = VAL_UNDEF;
    }
}
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */