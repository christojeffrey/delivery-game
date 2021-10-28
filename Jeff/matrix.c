// NIM : 13520055
// Nama : Christopher Jeffrey
// Tanggal : 22 September 2021
// Topik praktikum : Matriks
// Deskripsi : pra prak 5 tentang matriks

#include "matrix.h"
#include<stdio.h>

//TAMBAHAAAAAAN 1 biji fungsi buat ngitung determinan
float det(int arr[ROW_CAP][COL_CAP],int size){ //fungsi rekursif
   float hasil = 0;
   //basis
   if(size == 2){
      hasil = (arr[0][0]*arr[1][1]) - (arr[0][1] * arr[1][0]);
   }
   //bkn basis, lupa namanya apa
   else{
       hasil = 0;
        for(int kygditutup = 0;kygditutup < size;kygditutup++){ //b yang ditutup selalu index 0
         //buat array baru yg sudah 'ditutupi baris sama kolom' nya
            int arrbaru[ROW_CAP][COL_CAP];
            for(int b = 0;b< size-1;b++){
                for(int k= 0;k< size-1;k++){
                    if(k >= kygditutup){
                        arrbaru[b][k] = arr[b+1][k+1];
                }
                    else{
                        arrbaru[b][k] = arr[b+1][k];
                    }
                }
            }
            //hitung detnya pake cofactor
            float temp = det(arrbaru,size-1);
            if(kygditutup % 2 == 0){
                hasil = (float) hasil + (arr[0][kygditutup]*temp);
            }
            else{
                hasil =(float) hasil - (arr[0][kygditutup]*temp);
            }
        }
   }
   return hasil;
}

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void CreateMatrix(int nRow, int nCol, Matrix *m){
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
    ROWS(*m) = nRow;
    COLS(*m) = nCol;
}

/* *** Selektor "DUNIA Matrix" *** */
boolean isIdxValid(int i, int j){
   /* Mengirimkan true jika i, j adalah Index yang valid untuk matriks apa pun */
   return ((i >= 0 && i < ROW_CAP) && (j >= 0 && j < COL_CAP));
}

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
Index getLastIdxRow(Matrix m){
   /* Mengirimkan Index baris terbesar m */
   return (ROWS(m) - 1);
}

Index getLastIdxCol(Matrix m){
   /* Mengirimkan Index kolom terbesar m */
   return (COLS(m) - 1);
}

boolean isIdxEff(Matrix m, Index i, Index j){
   /* Mengirimkan true jika i, j adalah Index efektif bagi m */
   return ((i >= 0 && i < ROWS(m)) && (j >= 0 && j < COLS(m)));
}

ElType getElmtDiagonal(Matrix m, Index i){
   /* Mengirimkan elemen m(i,i) */
   return ELMT(m,i,i);
}

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mRes){
   /* Melakukan assignment MRes = MIn */
   ROWS(*mRes) = ROWS(mIn);
   COLS(*mRes) = COLS(mIn);
   for(int b = 0;b<ROWS(mIn);b++){
      for(int k = 0;k<COLS(mIn);k++){
         ELMT(*mRes,b,k) = ELMT(mIn,b,k);
      }
   }
}

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol){
   /* I.S. isIdxValid(nRow,nCol) */
   /* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
   /* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
   /* Selanjutnya membaca nilai elemen per baris dan kolom */
   /* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
   1 2 3
   4 5 6
   8 9 10 
   */
   CreateMatrix(nRow,nCol,m);
   ElType temp;
   for(int b = 0;b<ROWS(*m);b++){
      for(int k = 0;k<COLS(*m);k++){
         scanf("%d", &temp);
         ELMT(*m, b,k) = temp;
      }
   }
}

void displayMatrix(Matrix m){
   /* I.S. m terdefinisi */
   /* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
      dipisahkan sebuah spasi */
   /* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
   /* Contoh: Menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
   1 2 3
   4 5 6
   8 9 10
   */
   for(int b = 0;b<ROWS(m);b++){
      for(int k = 0;k<COLS(m);k++){
         printf("%d", ELMT(m,b,k));
         if(k < COLS(m) -1){
            printf(" ");
         }
      }
      if (b<ROWS(m) -1)
         printf("\n");
   }
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2){
   /* Prekondisi : m1 berukuran sama dengan m2 */
   /* Mengirim hasil penjumlahan matriks: m1 + m2 */
   Matrix m;
   CreateMatrix(ROWS(m1), COLS(m1), &m);
   for(int b = 0;b<ROWS(m1);b++){
      for(int k = 0;k<COLS(m1);k++){
         ELMT(m, b,k) = ELMT(m1,b,k) + ELMT(m2,b,k);
      }
   }
   return m;
}

Matrix subtractMatrix(Matrix m1, Matrix m2){
   /* Prekondisi : m1 berukuran sama dengan m2 */
   /* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
   Matrix m;
   CreateMatrix(ROWS(m1), COLS(m1), &m);
   for(int b = 0;b<ROWS(m1);b++){
      for(int k = 0;k<COLS(m1);k++){
         ELMT(m, b,k) = ELMT(m1,b,k) - ELMT(m2,b,k);
      }
   }
   return m;
}

Matrix multiplyMatrix(Matrix m1, Matrix m2){ //responsible for test case no 34 and 35
   /* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
   /* Mengirim hasil perkalian matriks: salinan m1 * m2 */
   Matrix m;
   CreateMatrix(ROWS(m1), COLS(m2), &m);
   
   int hasil = 0;
   for(int b = 0;b<ROWS(m1);b++){
      for(int k = 0;k<COLS(m2);k++){
         hasil = 0;
         for(int plus = 0;plus < COLS(m1);plus++){
            hasil = hasil + (ELMT(m1,b,plus)*ELMT(m2,plus,k));
         }
         ELMT(m,b,k) = hasil;
      }
   }
   return m;
}

Matrix multiplyConst(Matrix m, ElType x){
   /* Mengirim hasil perkalian setiap elemen m dengan x */
   for(int b = 0;b<ROWS(m);b++){
      for(int k = 0;k<COLS(m);k++){
         ELMT(m, b,k) = x*ELMT(m,b,k);
      }
   }
   return m;
}

void pMultiplyConst(Matrix *m, ElType k){
   /* I.S. m terdefinisi, k terdefinisi */
   /* F.S. Mengalikan setiap elemen m dengan k */
   for(int b = 0;b<ROWS(*m);b++){
      for(int kolom = 0;kolom<COLS(*m);kolom++){
         ELMT(*m, b,kolom) = k*ELMT(*m,b,kolom);
      }
   }
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isEqual(Matrix m1, Matrix m2){
   /* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
   /* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
   /* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
   boolean flag = true;
   if(ROWS(m1) == ROWS(m2) && COLS(m1) == COLS(m2)){
      int b = 0; 
      int k = 0;
      while(flag && b < ROWS(m1)){
         if(ELMT(m1,b,k) != ELMT(m2,b,k)){
            flag = false;
         }
         if(k < COLS(m1)-1){
            k++;
         }
         else{
            k = 0;
            b++;
         }
      }
   }
   else //ukuran tidak sama
      flag = false;
   return flag;
}

boolean isNotEqual(Matrix m1, Matrix m2){
   /* Mengirimkan true jika m1 tidak sama dengan m2 */
   return (!isEqual(m1,m2));
}

boolean isSizeEqual(Matrix m1, Matrix m2){
   /* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
   boolean flag = true;
   if (!(ROWS(m1) == ROWS(m2) && COLS(m1) == COLS(m2)))
      flag = false;
   return flag;
}

/* ********** Operasi lain ********** */
int count(Matrix m){
   /* Mengirimkan banyaknya elemen m */
   return(ROWS(m)*COLS(m));
}

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m){
   /* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
   return (ROWS(m) == COLS(m));
}

boolean isSymmetric(Matrix m){
   /* Mengirimkan true jika m adalah matriks simetri : isSquare(m) 
      dan untuk setiap elemen m, m(i,j)=m(j,i) */
   boolean flag = true;
   if (isSquare(m)){
      int b = 0;
      int k = b+1;
      while(flag && b < ROWS(m) && k < COLS(m)){
         if(ELMT(m,b,k) != ELMT(m,k,b)){
            flag = false;
         }
         if(k < COLS(m)-1){
            k++;
         }
         else{
            b++;
            k = b+1;

         }
      }
   }
   else //ukurannya gk persegi
      flag = false;
   return flag;
}

boolean isIdentity(Matrix m){
   /* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan 
      setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
   boolean flag = true;
   if(isSquare(m)){
      int b = 0;
      int k = 0;
      while(flag && b < ROWS(m)){
         if(b == k){ //jika diagonal,harus nilainya 1
            if (ELMT(m,b,k) != 1){
               flag = false;
            }
         }
         else{ //selain diagonalnya, harus nilainya 0
            if(ELMT(m,b,k)!= 0){
               flag = false;
            }
         }
         // cek data selanjutnya
         if(k < COLS(m) - 1){
            k++;
         }
         else{
            k = 0;
            b++;
         }
      }
   }
   else{ // matrix tidak persegi
      flag = false;
   }
   return flag;
}

boolean isSparse(Matrix m){
   /* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
      hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
   int MaxEff = ROWS(m)*COLS(m)/20; //semoga round kebawah, aku gk inget di c gimnaa
   int b = 0;
   int k = 0;
   int Eff = 0;
   while(Eff <= MaxEff && b < ROWS(m)){
      if(ELMT(m,b,k) != 0){
         Eff++;
      }
      if(k < COLS(m) - 1){
         k++;
      }
      else{
         k = 0;
         b++;
      }
   }
   boolean flag = true;
   if (Eff>MaxEff){
      flag = false;
   }
   return flag;
}

Matrix inverse1(Matrix m){
   /* Menghasilkan salinan m dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
   Matrix mOut;
   CreateMatrix(ROWS(m), COLS(m), &mOut);
   for(int b = 0;b < ROWS(m);b++){
      for(int k = 0;k < COLS(m);k++){
         ELMT(mOut,b,k) = -1 * ELMT(m,b,k);
      }
   }
   return mOut;
}

void pInverse1(Matrix *m){
   /* I.S. m terdefinisi */
   /* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
   for(int b = 0;b < ROWS(*m);b++){
      for(int k = 0;k < COLS(*m);k++){
         ELMT(*m,b,k) = -1 * ELMT(*m,b,k);
      }
   }
}

float determinant(Matrix m){
   /* Prekondisi: isSquare(m) */
   /* Menghitung nilai determinan m */
   // aku ubah jadi array aja, soalnya aku gk butuh lainnya. ngitung pake cofaktor baris pertama.
   int arr[ROW_CAP][COL_CAP];
   for(int b = 0;b < ROWS(m);b++){
      for(int k = 0;k< COLS(m);k++){
         arr[b][k] = ELMT(m,b,k);
      }
   }
   float hasil = det(arr,ROWS(m));
   return hasil;
}

void transpose(Matrix *m){
   /* I.S. m terdefinisi dan isSquare(m) */
   /* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
   int temp;
   for(int b = 0;b <ROWS(*m);b++){
      for(int k = b+1;k<COLS(*m);k++){
         temp = ELMT(*m,b,k);
         ELMT(*m,b,k) = ELMT(*m,k,b);
         ELMT(*m,k,b) = temp;
      }
   }
}