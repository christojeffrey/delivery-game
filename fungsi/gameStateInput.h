
#include "../ADT/gameState.h"
void gameStateInput(gameState* status);
//melakukan input file game config hingga benar. jika masih salah, di loop hingga benar.

//file path relative di dalam gameconfig, contoh,
//jika file config adala gameconfig/config2.txt, berikut contoh programnya
/*
MASUKKAN NAMA FILE : config1.txt
TIDAK DITEMUKAN FILE CONFIG DENGAN NAMA TERSEBUT, MASUKKAN LAGI
MASUKKAN NAMA FILE : config2.txt
FILE BERHASIL DI LOAD, GAME STATE BERHASIL DI LOAD
==============
WELCOME TO GAME NOBITA STUFF
...
*/

//jika sudah benar, ambil data2 dalam file tersebut, lalu simpan ke dalam status.
//diasumsikan text didalam file config sudah sesuai dengan spek