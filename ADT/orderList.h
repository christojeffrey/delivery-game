#ifndef ORDER_LIST_H
#define ORDER_LIST_H

#include "boolean.h"
#include <stdlib.h>

#include"paket.h"
 /*
 jumlah pesanan maks adalah 30. jadi ya aku kasih 40 deh.
 */
typedef struct{
    paket buffer[40];
	int idxHead;
	int idxTail;
    //modification of priority queue
}orderList;

/* Seleketor Makro */
#define oLIDX_HEAD(q) (q).idxHead
#define oLIDX_TAIL(q) (q).idxTail
#define     oLHEAD(q) (q).buffer[(q).idxHead]
#define     oLTAIL(q) (q).buffer[(q).idxTail]


void CreateOrderList(orderList *ol);
/* I.S. sembarang */
/* F.S. Sebuah ol kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai -1 */
/* - Index tail bernilai -1 */
/* Proses : Melakukan alokasi, membuat sebuah ol kosong */

boolean isOrderListEmpty(orderList ol);
/* Mengirim true jika pq kosong: lihat definisi di atas */

boolean isOrderListFull(orderList ol);
/* Mengirim true jika pq Full: lihat definisi di atas */

int lengthOrderList(orderList ol);
/* Mengirimkan banyaknya paket dalam ol. Mengirimkan 0 jika ol kosong. */

/*** Primitif Add/Delete ***/
void enqueueOrderList(orderList *ol, paket val);
/* Proses: Menambahkan val pada ol dengan aturan FIFO */
/* I.S. ol mungkin kosong, tabel penampung elemen ol TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
        Jika ol penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen ol
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */

void dequeueOrderList(orderList * ol, paket *val);
/* Proses: Menghapus val pada ol dengan aturan FIFO */
/* I.S. ol tidak mungkin kosong */
/* F.S. val = nilai elemen pada head ol
I.S.,  IDX_HEAD "mundur"; 
        ol mungkin kosong */

#endif
