#include<stdio.h>
#include "time.h"


/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsTIMEValid (int H, int M, int S){
    /* Mengirim true jika H,M,S dapat membentuk T yang valid */
    /* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
    if (H < 0 || H > 23)
        return false;
    if (M < 0 || M > 59)
        return false;
    if (S < 0 || S > 59)
        return false;
    return true;
}

/* *** Konstruktor: Membentuk sebuah TIME dari komponen-komponennya *** */
TIME MakeTIME (int HH, int MM, int SS){
    // waktu diasumsikan pasti valid
    TIME temp;
    Hour(temp) = HH;
    Minute(temp) = MM;
    Second(temp) = SS;
    return temp;
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaTIME (TIME * T){
    int h,m,s;
    do{
        scanf("%d%d%d",&h,&m,&s);
        if (IsTIMEValid(h,m,s)){
            *T = MakeTIME(h,m,s);
        }
        else
            printf("Jam tidak valid\n");
    }while (IsTIMEValid(h,m,s) == false);
}

   
void TulisTIME (TIME T){
    printf("%d:%d:%d", Hour(T), Minute(T), Second(T));
}
/* I.S. : T sembarang */
/* F.S. : Nilai T ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen T ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/ 

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long TIMEToDetik (TIME T){
    return (3600*Hour(T) + 60*Minute(T) + Second(T));
}
/* Diberikan sebuah TIME, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */

TIME DetikToTIME (long N){
    N = N % 86400;
    int h,m,s;
    h = N / 3600;
    N = N % 3600;
    m = N / 60;
    N = N % 60;
    s = N;
    TIME temp = MakeTIME(h,m,s);
    return temp;
}
/* Mengirim  konversi detik ke TIME */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang 
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus: 
   N1 = N mod 86400, baru N1 dikonversi menjadi TIME */

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean TEQ (TIME T1, TIME T2){
    /* Mengirimkan true jika T1=T2, false jika tidak */
    return (Hour(T1) == Hour(T2) && Minute(T1) == Minute(T2) && Second(T1) == Second(T2));
}
boolean TNEQ (TIME T1, TIME T2){
    /* Mengirimkan true jika T1 tidak sama dengan T2 */
    return !(Hour(T1) == Hour(T2) && Minute(T1) == Minute(T2) && Second(T1) == Second(T2));
}
boolean TLT (TIME T1, TIME T2){
    /* Mengirimkan true jika T1<T2, false jika tidak */
    return (TIMEToDetik(T1) < TIMEToDetik(T2));
}
boolean TGT (TIME T1, TIME T2){
    /* Mengirimkan true jika T1>T2, false jika tidak */
    return (TIMEToDetik(T1) > TIMEToDetik(T2));
}
/* *** Operator aritmatika TIME *** */
TIME NextDetik (TIME T){
    /* Mengirim 1 detik setelah T dalam bentuk TIME */
    return DetikToTIME(TIMEToDetik(T) + 1);
}
TIME NextNDetik (TIME T, int N){
    /* Mengirim N detik setelah T dalam bentuk TIME */
    return DetikToTIME(TIMEToDetik(T) + N);

}
TIME PrevDetik (TIME T){
    /* Mengirim 1 detik sebelum T dalam bentuk TIME */
    return DetikToTIME(TIMEToDetik(T) - 1);
}
TIME PrevNDetik (TIME T, int N){
    /* Mengirim N detik sebelum T dalam bentuk TIME */
    return DetikToTIME(TIMEToDetik(T) - N);
}
/* *** Kelompok Operator Aritmetika *** */
long Durasi (TIME TAw, TIME TAkh){
    long dak,daw;
    daw = TIMEToDetik(TAw);
    dak = TIMEToDetik(TAkh);
    if (daw < dak)
        return dak - daw;
    else
        return (86400 - daw) + dak;
}
