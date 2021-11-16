#include "orderList.h"

void CreateOrderList(orderList *ol)
/* I.S. sembarang */
/* F.S. Sebuah ol kosong terbentuk dengan kondisi sbb: */
/* - Index oLhead bernilai -1 */
/* - Index tail bernilai -1 */
/* Proses : Melakukan alokasi, membuat sebuah ol kosong */
{
    oLIDX_HEAD(*ol) = -1;
    oLIDX_TAIL(*ol) = -1;
}

/* ********* Prototype ********* */
boolean isOrderListEmpty(orderList ol)
/* Mengirim true jika ol kosong: lihat definisi di atas */
{
    return oLIDX_HEAD(ol) == -1;
}
boolean isOrderListFull(orderList ol)
/* Mengirim true jika tabel penampung elemen ol sudah penuh */
/* yaitu jika index oLhead bernilai 0 dan index tail bernilai 40-1 */
{
    return oLIDX_HEAD(ol) == 0 && oLIDX_TAIL(ol) == 39;
}
int lengthOrderList(orderList ol)
/* Mengirimkan banyaknya elemen orderList. Mengirimkan 0 jika ol kosong. */
{
    return (isOrderListEmpty(ol)) ? 0 : (oLIDX_TAIL(ol) - oLIDX_HEAD(ol) + 1);
}
/* *** Primitif Add/Delete *** */
void enqueueOrderList(orderList *ol, paket val)
/* Proses: Menambahkan val pada ol dengan aturan FIFO */
/* I.S. ol mungkin kosong, tabel penampung elemen ol TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, oLIDX_TAIL "mundur".
        Jika ol penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen ol
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */
{
    if (isOrderListEmpty(*ol)){
        oLIDX_HEAD(*ol) = 0;
        oLIDX_TAIL(*ol) = 0;
        (*ol).buffer[0] = val;
    } else { 
        if (oLIDX_TAIL(*ol) == 40 - 1) for (int i = oLIDX_HEAD(*ol);  i < oLIDX_TAIL(*ol); i++) (*ol).buffer[i-oLIDX_HEAD(*ol)] = (*ol).buffer[i]; //kalo mentok geser duls ges
        int i = 0;
        while ((pTIME((*ol).buffer[i]) <= pTIME(val)) && i < lengthOrderList(*ol))
        {
            i++;
        }
        for (int j = lengthOrderList(*ol); j > i; j--) (*ol).buffer[j] = (*ol).buffer[j-1];
        (*ol).buffer[i] = val;
        oLIDX_TAIL(*ol)++;
    }
}

void dequeueOrderList(orderList *ol, paket *val)
/* Proses: Menghapus val pada ol dengan aturan FIFO */
/* I.S. ol tidak mungkin kosong */
/* F.S. val = nilai elemen oLHEAD pd I.S., oLHEAD dan oLIDX_HEAD "mundur"; 
        ol mungkin kosong */
{
    *val = oLHEAD(*ol);

    if (oLIDX_HEAD(*ol) == oLIDX_TAIL(*ol)){
        oLIDX_HEAD(*ol) = -1;
        oLIDX_TAIL(*ol) = -1;
    } else{
        oLIDX_HEAD(*ol)++;
    }
}
