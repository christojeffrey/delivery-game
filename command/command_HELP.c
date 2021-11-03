//jef
#include "command.h"

void command_HELP(){
    printf("berikut pilihan command yang dapat dilakukan\n");
    printf("1. MOVE -> berpindah ke lokasi selanjutnya\n");
    printf("2. PICK_UP -> mengambil item di lokasi sekarang\n");
    printf("3. DROP_OFF -> mengantarkan jika tujuan item di top tas adalah lokasi sekarang\n");
    printf("4. MAP -> memunculkan peta\n");
    printf("5. TO_DO -> menampilkan pesanan yang  masuk ke To Do List\n");
    printf("6. IN_PROGRESS ->  menampilkan pesanan yang sedang dikerjakan\n");
    printf("7. BUY -> menampilkan dan membeli gadget. hanya dapat dilakukan di HQ\n");
    printf("8. INVENTORY -> menampilkan gadget yang dimiliki dan menggunakannya\n");
    printf("9. HELP -> menampilkan list command dan kegunaannya\n");
    printf("program tidak menerima command selain command diatas");
}