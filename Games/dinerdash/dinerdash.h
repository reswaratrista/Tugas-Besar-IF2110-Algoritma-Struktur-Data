#ifndef __DINER_DASH_H__
#define __DINER_DASH_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../../ADT/boolean.h"
#include "../../ADT/word/mesinkarakter/mesinkarakter.h"
#include "../../ADT/word/mesinkata/mesinkata.h"
#include "../../ADT/queue/prioqueue.h"
#include "../../Misc/io/io.h"
#include "../../ADT/word/word.h"
#include "../../Misc/ascii/ascii.h"
#include "../../ADT/list/array.h"
#include "../../Games/random.h"
#include "../../ADT/list/listDiner.h"
#include "../../ADT/map/listMap.h"
#include "../../ADT/set/listSet.h"
#include "../../Utility/splash.h"

PQElType addOrder(int i);
// -	Pada setiap putaran, akan terdapat 1 pelanggan baru.

void countAsTurn(ListDiner *Cook, ListDiner *Serve);
// -	Pada setiap putaran, seluruh durasi dari makanan yang sedang dimasak akan berkurang 1. Ketika durasi makanan mencapai 0, maka makanan sudah dapat di SERVE.

void dinerDash(ListMap *M, ListSet *S);
// -	Terdapat 3 command yang dapat dilakukan pada game, yaitu COOK, SERVE, dan SKIP
// -	COOK merupakan command yang bertujuan untuk memasak makanan
// -	SERVE merupakan command yang bertujuan untuk menyajikan makanan kepada pelanggan.
// -	Permainan akan dimulai dengan 3 pelanggan. Setiap pelanggan hanya dapat memesan satu makanan. Untuk setiap makanan, terdapat informasi tentang ID makanan yang dihasilkan secara increment (M01, M02, M03, dst), durasi memasak, harga makanan, serta ketahanan makanan. Semua informasi tersebut akan didapatkan secara random dengan menggunakan random number generator. Durasi dan ketahanan makanan akan berkisar diantara 1-5. Sedangkan, harga makanan akan berkisar diantara 10000 - 50000.
// -	Kapasitas dari pemain adalah memasak 5 makanan dalam waktu yang sama. Pelanggan yang dilayani adalah pelanggan yang duluan memasuki antrian.
// -	Permainan selesai apabila antrian melebihi 7 pelanggan atau jumlah pelanggan yang sudah dilayani mencapai 15 pelanggan.
// -	Ketika makanan sudah di SERVE, maka makanan dapat diantar kepada pelanggan dan pelanggan dapat meninggalkan antrian. Setelah pelanggan meninggalkan antrian, maka pemain akan menerima uang
// -	SERVE hanya dapat digunakan untuk pesanan yang berada di paling depan.
// -	Skor akhir dari pemain adalah total uang yang diterima oleh pemain.

void dinerSplash();

#endif