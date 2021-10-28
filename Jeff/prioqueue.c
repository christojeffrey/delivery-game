
#include "boolean.h"
#include <stdlib.h>
#include"prioqueue.h"
/* *** Kreator *** */
void CreatePrioQueue(PrioQueue *pq){
    (*pq).idxHead = IDX_UNDEF;
    (*pq).idxTail = IDX_UNDEF;
}
/* I.S. sembarang */
/* F.S. Sebuah pq kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah pq kosong */

boolean isEmpty(PrioQueue pq){
    return (length(pq) == 0);
}
/* Mengirim true jika pq kosong: lihat definisi di atas */

boolean isFull(PrioQueue pq){
    return (length(pq) == CAPACITY);
}
/* Mengirim true jika tabel penampung elemen pq sudah penuh */
/* yaitu jika index head bernilai 0 dan index tail bernilai CAPACITY-1 */

int length(PrioQueue pq){
    int panjang;
    if(IDX_HEAD(pq) == IDX_UNDEF){
        panjang = 0;
    }
    else{
        panjang = IDX_TAIL(pq) - IDX_HEAD(pq) + 1; 
    }
    return panjang;
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika pq kosong. */

/*** Primitif Add/Delete ***/
void enqueue(PrioQueue *pq, ElType val){
    if(IDX_TAIL(*pq) == CAPACITY - 1){//jika queue "rata kanan", geser rata kiri baru diisi
        for(int b = 0; b<length(*pq);b++){
            pq->buffer[b] = pq->buffer[IDX_HEAD(*pq) + b];
        }
        IDX_TAIL(*pq) = IDX_TAIL(*pq) - IDX_HEAD(*pq);
        IDX_HEAD(*pq) = 0;

    }
    //sekarang sisipin data baru
    if(isEmpty(*pq)){
        IDX_HEAD(*pq) = 0;
        IDX_TAIL(*pq) = 0;
        TAIL(*pq) = val;
    }
    else{
        IDX_TAIL(*pq) += 1;
        int IdxForNewData = IDX_HEAD(*pq);
        for(int b = IDX_TAIL(*pq)-1; b >= IDX_HEAD(*pq);b--){
            if(pq->buffer[b].score >= val.score){
                IdxForNewData = b+1;
                break;
            }
        }
        for(int b = IDX_TAIL(*pq);b > IdxForNewData;b--){
            pq->buffer[b] = pq->buffer[b-1];
        }
        pq->buffer[IdxForNewData] = val;
    }
    
}
/* Proses: Menambahkan val pada pq dengan aturan FIFO */
/* I.S. pq mungkin kosong, tabel penampung elemen pq TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen pq
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */

void dequeue(PrioQueue * pq, ElType *val){
     *val = pq->buffer[IDX_HEAD(*pq)];
    if(length(*pq) != 0){
        IDX_HEAD(*pq) += 1;
    }
    else{
        IDX_HEAD(*pq) = IDX_UNDEF;
        IDX_TAIL(*pq) = IDX_UNDEF;
    }
}
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. pq tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd
I.S., HEAD dan IDX_HEAD "mundur"; 
        pq mungkin kosong */
