// NIM : 13520055
// Nama : Christopher Jeffrey
// Tanggal : 4 Oktober 2021
// Topik praktikum : queue
// Deskripsi : pra prak 7 tentang queue

#include "boolean.h"
#include "queue.h"
#include<stdio.h>
/* *** Kreator *** */
void CreateQueue(Queue *q){
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean isEmpty(Queue q){
    return (length(q) == 0);
}
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean isFull(Queue q){
    return(length(q) == CAPACITY);
}
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu jika index head bernilai 0 dan index tail bernilai CAPACITY-1 */
int length(Queue q){
    int panjang = 0;
    if(IDX_HEAD(q) != IDX_UNDEF)
        panjang = (IDX_TAIL(q) - IDX_HEAD(q) + 1);
    // printf("panjangnya %d\n", panjang);
    return panjang;
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElType val){
    if(IDX_TAIL(*q) == CAPACITY - 1){//jika queue "rata kanan", geser rata kiri baru diisi
        for(int b = 0; b<length(*q);b++){
            q->buffer[b] = q->buffer[IDX_HEAD(*q) + b];
        }
        IDX_TAIL(*q) = IDX_TAIL(*q) - IDX_HEAD(*q);
        IDX_HEAD(*q) = 0;

    }
    if(isEmpty(*q)){
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    }
    else{
        IDX_TAIL(*q) += 1;
    }
    TAIL(*q) = val;
}
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen q
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */

void dequeue(Queue *q, ElType *val){
    *val = q->buffer[IDX_HEAD(*q)];
    if(length(*q) != 0){
        IDX_HEAD(*q) += 1;
    }
    else{
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }
    
}
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., HEAD dan IDX_HEAD "mundur"; 
        q mungkin kosong */

/* *** Display Queue *** */
void displayQueue(Queue q){
    printf("[");
    for(int b = 0;b<length(q);b++){
        printf("%d", q.buffer[IDX_HEAD(q) + b]);
        if(b != length(q) - 1){
            printf(",");
        }
    }

    printf("]");
}
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
