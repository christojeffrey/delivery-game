#include<stdio.h>
#include<math.h>
#include "point.h"

/* *** Konstruktor membentuk POINT *** */
// implementasi MakePOINT
POINT MakePOINT (float X, float Y){
/* Membentuk sebuah POINT dari komponen-komponennya */
    POINT temp;
    Absis(temp) = X;
    Ordinat(temp) = Y;
    return temp;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void BacaPOINT (POINT * P){
    float x,y;
    scanf("%f %f",&x, &y);
    *P = MakePOINT(x,y);
}
void TulisPOINT (POINT P){
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}
              

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2){
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
    return (Absis(P1) == Absis(P2) && Ordinat(P1) == Ordinat(P2));
}
boolean NEQ (POINT P1, POINT P2){
    /* Mengirimkan true jika P1 tidak sama dengan P2 */
    return !(Absis(P1) == Absis(P2) && Ordinat(P1) == Ordinat(P2));
}

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P){
    /* Menghasilkan true jika P adalah titik origin */
    return (Absis(P) == 0 && Ordinat(P) == 0);
}
boolean IsOnSbX (POINT P){
    /* Menghasilkan true jika P terletak Pada sumbu X */
    return !(Ordinat(P) == 0);
}
boolean IsOnSbY (POINT P){
    /* Menghasilkan true jika P terletak pada sumbu Y */
    return !(Absis(P) == 0);
}
int Kuadran (POINT P){
    // P sudah pasti bukan titik origin atau di salah satu sumbu
    if (Absis(P) > 0 && Ordinat(P) > 0){
        return 1;
    }
    if (Absis(P) < 0 && Ordinat(P) > 0){
        return 2;
    }
    if (Absis(P) < 0 && Ordinat(P) < 0){
        return 3;
    }
    if (Absis(P) > 0 && Ordinat(P) < 0){
        return 4;
    }
    
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */                           
POINT NextX (POINT P){
/* Mengirim salinan P dengan absis ditambah satu */              
    return (MakePOINT((Absis(P) + 1), Ordinat(P)));
}
POINT NextY (POINT P){
    /* Mengirim salinan P dengan ordinat ditambah satu */
    return (MakePOINT(Absis(P), (Ordinat(P) + 1)));
}
POINT PlusDelta (POINT P, float deltaX, float deltaY){
    /* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
    return (MakePOINT((Absis(P) + deltaX), (Ordinat(P) + deltaY)));
}
POINT MirrorOf (POINT P, boolean SbX){
    /* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
    if (SbX == '1')
        return (MakePOINT(Absis(P), -Ordinat(P)));
    else
        return (MakePOINT(-Absis(P), Ordinat(P)));

}

float Jarak0 (POINT P){
    /* Menghitung jarak P ke (0,0) */
    return sqrt((Absis(P)*Absis(P)) + (Ordinat(P)*Ordinat(P)));
}
float Panjang (POINT P1, POINT P2){
    // menggihitung jarak P1 ke P2
    return sqrt(pow(Absis(P1)- Absis(P2), 2) + pow(Ordinat(P1)- Ordinat(P2), 2));
}

void Geser (POINT *P, float deltaX, float deltaY){
    Absis(*P) = Absis(*P) + deltaX;
    Ordinat(*P) = Ordinat(*P) + deltaY;
}
void GeserKeSbX (POINT *P){
    Ordinat(*P) = 0;
}
void GeserKeSbY (POINT *P){
    Absis(*P) = 0;
}
void Mirror (POINT *P, boolean SbX){
    if (SbX)
        Ordinat(*P) =  -Ordinat(*P);
    else
        Absis(*P) = -Absis(*P);
}

void Putar (POINT *P, float Sudut){
    // dalam radian
    Absis(*P) = Absis(*P)*cos(Sudut) + Ordinat(*P)*sin(Sudut);
    Ordinat(*P)= Ordinat(*P)*cos(Sudut) - Absis(*P)*sin(Sudut);
    
}
