#include "../splash.h"
#include "../../Misc/io/io.h"

#include <stdio.h>
#include "help.h"

void helpStart()
{

    header();

    printf("Berikut command-command yang tersedia:\n");
    printf("1. START - Membaca file konfigurasi default yang berisi list game yang dapat dimainkan\n");
    printf("2. LOAD - Membaca save file yang ingin dibuka berisi list game yang dapat dimainkan\n");

    printf("\nTekan [ENTER] untuk kembali ke menu utama...");

    blankInput();
}

void help(){

    header();

    printf("Berikut command-command yang tersedia:\n");
    printf("1.  CREATE GAME - Menambahkan game baru pada daftar game\n");
    printf("2.  LIST GAME - Menampilkan daftar game yang disediakan oleh sistem\n");
    printf("3.  DELETE GAME - Menghapus sebuah game dari daftar game\n");
    printf("4.  QUEUE GAME - Mendaftarkan permainan ke dalam list\n");
    printf("5.  PLAY GAME - Memainkan sebuah permainan di urutan pertama antrian game\n");
    printf("6.  SKIP GAME <N> - Melewatkan permainan dalam antrian game sebanyak N\n");
    printf("7.  SCOREBOARD - Menampilkan nama dan skor untuk semua game\n");
    printf("8.  RESET SCOREBOARD - Melakukan reset terhadap scoreboard permainan\n");
    printf("9.  HISTORY <N> - Melihat sebanyak N game yang baru dimainkan\n");
    printf("10. RESET HISTORY - Menghapus semua history permainan yang telah dimainkan\n");
    printf("11. SAVE <filename>.txt - Menyimpan state game pemain saat ini ke dalam file filename\n");
    printf("12. QUIT - Keluar dari program\n");

    printf("\nTekan [ENTER] untuk kembali ke menu utama...");

    blankInput();

}