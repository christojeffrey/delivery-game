#include "orderList.h"

void CreateOrderList(orderList *q)
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index oLhead bernilai -1 */
/* - Index tail bernilai -1 */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
{
    oLIDX_HEAD(*q) = -1;
    oLIDX_TAIL(*q) = -1;
}

/* ********* Prototype ********* */
boolean isOrderListEmpty(orderList q)
/* Mengirim true jika q kosong: lihat definisi di atas */
{
    return oLIDX_HEAD(q) == -1;
}
boolean isOrderListFull(orderList q)
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu jika index oLhead bernilai 0 dan index tail bernilai 40-1 */
{
    return oLIDX_HEAD(q) == 0 && oLIDX_TAIL(q) == 39;
}
int lengthOrderList(orderList q)
/* Mengirimkan banyaknya elemen orderList. Mengirimkan 0 jika q kosong. */
{
    return (isOrderListEmpty(q)) ? 0 : (oLIDX_TAIL(q) - oLIDX_HEAD(q) + 1);
}
/* *** Primitif Add/Delete *** */
void enqueueOrderList(orderList *q, paket val)
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, oLIDX_TAIL "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen q
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */
{
    if (isOrderListEmpty(*q)){
        oLIDX_HEAD(*q) = 0;
        oLIDX_TAIL(*q) = 0;
    } else { 
        if (oLIDX_TAIL(*q) == 40 - 1) for (int i = oLIDX_HEAD(*q);  i < oLIDX_TAIL(*q); i++) (*q).buffer[i-oLIDX_HEAD(*q)] = (*q).buffer[i]; //kalo mentok geser duls ges
        int i = 0;
        while ((TIME((*q).buffer[i]) <= TIME(val)) && i < lengthOrderList(*q))
        {
            i++;
        }
        for (int j = lengthOrderList(*q) - 1; j > i; j--) (*q).buffer[j] = (*q).buffer[j-1];
        (*q).buffer[i] = val;
        oLIDX_TAIL(*q)++;
    }
}

void dequeueOrderList(orderList *q, paket *val)
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen oLHEAD pd I.S., oLHEAD dan oLIDX_HEAD "mundur"; 
        q mungkin kosong */
{
    *val = oLHEAD(*q);

    if (oLIDX_HEAD(*q) == oLIDX_TAIL(*q)){
        oLIDX_HEAD(*q) = -1;
        oLIDX_TAIL(*q) = -1;
    } else{
        oLIDX_HEAD(*q)++;
    }
}
