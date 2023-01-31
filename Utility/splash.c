#include <stdio.h> 
#include "../ADT/boolean.h" 
#include "splash.h"
#include "../Misc/io/colors.h"

void header() {

    printf("\e[1;1H\e[2J");
    printf("======================================BNMO======================================\n");
    printf("\n");

}

void splash(int tries, boolean started) {

    printf("             *#%%(                :::::::::  ::::    ::: ::::    ::::   :::::::: \n");
    printf(" /((******/#%%&@@@&%%##((((#       :+:    :+: :+:+:   :+: +:+:+: :+:+:+ :+:    :+:\n");
    printf(" *(@(/(((((..............(,      +:+    +:+ :+:+:+  +:+ +:+ +:+:+ +:+ +:+    +:+\n");
    printf(" *(/((((((%%...@.......@..(,      +#++:++#+  +#+ +:+ +#+ +#+  +:+  +#+ +#+    +:+\n");
    printf(" /(&#&%%#((%%......@#@.....(       +#+    +#+ +#+  +#+#+# +#+       +#+ +#+    +#+\n");
    printf(" /(&&&/(((&..............(       #+#    #+# #+#   #+#+# #+#       #+# #+#    #+#\n");
    printf(" /(@&&&((((@@&%%(((((((&&((       #########  ###    #### ###       ###  ######## \n");
    printf(" /(((%%&(/(((((((((((((((((                                                      \n");
    printf(" %%((%%&&/((((&***((((%%,((((       18220010 - Agnes Tamara Putri\n");
    printf(" &(&/*&/(((((((((((((&##@(&      18221102 - Salman Ma'arif Achsien\n");
    printf(" (((**#(((((((((#((&((&(( **@    18221122 - Reswara Trista Aulia C\n");
    printf("     &&**(((((((((&(((#&( &(.&   18221166 - Erensi Ratu Chelsia\n");
    printf("          *& /#(((((             18221168 - Rania Sasi Kirana\n");
    printf(" \n");
    printf(" - Tugas Besar 1 IF2111 Algoritma dan Struktur Data STI - Kelompok 06 Kelas 02 -\n");
    printf("\n");
    selamatDatang(tries);
    suruhInput(started);
    printf("root@BNMO:~$ ");
    
}

void selamatDatang(int tries) {

    if (tries < 10) {
        printf("Selamat Datang di BNMO! Jalankan dalam Linux; jangan ubah ukuran terminal.\n");
    } else {
        printf("Melihatmu sudah gagal menginput perintah sebanyak ini, BNMO tertawa kecil.\n");
    }
    
}

void suruhInput(boolean started) {

    if (started) {
        printf("Silahkan input perintah atau lihat daftarnya menggunakan [HELP]...\n");
    } else {
        printf("Silahkan input [START], [LOAD <FILENAME>], atau [HELP]...\n");
    }

}

//             *#%(                :::::::::  ::::    ::: ::::    ::::   ::::::::  
// /((******/#%&@@@&%##((((#       :+:    :+: :+:+:   :+: +:+:+: :+:+:+ :+:    :+:
// *(@(/(((((..............(,      +:+    +:+ :+:+:+  +:+ +:+ +:+:+ +:+ +:+    +:+
// *(/((((((%...@.......@..(,      +#++:++#+  +#+ +:+ +#+ +#+  +:+  +#+ +#+    +:+ 
// /(&#&%#((%......@#@.....(       +#+    +#+ +#+  +#+#+# +#+       +#+ +#+    +#+ 
// /(&&&/(((&..............(       #+#    #+# #+#   #+#+# #+#       #+# #+#    #+# 
// /(@&&&((((@@&%(((((((&&((       #########  ###    #### ###       ###  ########
// /(((%&(/(((((((((((((((((      
// %((%&&/((((&***((((%,((((       18220010 - Agnes Tamara Putri
// &(&/*&/(((((((((((((&##@(&      18221102 - Salman Ma'arif Achsien
// (((**#(((((((((#((&((&(( **@    18221122 - Reswara Trista Aulia C
//     &&**(((((((((&(((#&( &(.&   18221166 - Erensi Ratu Chelsia
//          *& /#(((((             18221168 - Rania Sasi Kirana
//
// - Tugas Besar 1 IF2111 Algoritma dan Struktur Data STI - Kelompok 06 Kelas 02 -
// 
// Selamat Datang di BNMO!
// INPUT [START] ATAU [LOAD]...
// root@BNMO:~$ 