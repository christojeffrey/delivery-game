#include "location.h"

/*
ADT paket berisi
waktu kedatangan, dalam integer.
lokasi pickup.
lokasi drop off.
char item. N normal, H heavy, P perishable, V VIP.

keempat hal tersebut wajib memiliki isi, tidak bisa kosong
untuk perishTime, hanya digunakan jika item Perishable. Jika tidak, akan menyimpan value -1
*/

typedef struct{
    int timeArrival;
    location pickupLoc;
    location dropoffLoc;
    char itemType;
    int perishTime;
}paket;

paket makePaket(int time,location pickup, location dropoff, char itemtype, int perishtime);
/* membuat sebuah paket. mengembalikan sebuah paket yang isinya sudah lengkap sesuai input.
kalau itemtype bukan yg bisa perish, tidak perduli inputnya apa, perishtime di paket yang di return jadi -1*/