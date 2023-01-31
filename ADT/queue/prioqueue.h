/* File : queue.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi statik */

#ifndef __PRIO_QUEUE_H
#define __PRIO_QUEUE_H

#include "../boolean.h"

#define IDX_UNDEF -1
#define PQCAPACITY 7

/* Definisi elemen dan address */
typedef struct
{
        /* data */
        int foodId;
        int cookTime;
        int stayTime;
        int price;
} PQElType;

typedef struct
{
        PQElType buffer[PQCAPACITY];
        int idxHead;
        int idxTail;
} PrioQueue;

/* ********* AKSES (Selektor) ********* */
/* Jika pq adalah Queue, maka akses elemen : */
#define IDX_HEAD(pq) (pq).idxHead
#define IDX_TAIL(pq) (pq).idxTail
#define HEAD(pq) (pq).buffer[(pq).idxHead]
#define TAIL(pq) (pq).buffer[(pq).idxTail]

/* *** Kreator *** */
void createQueuePQ(PrioQueue *pq);
/* I.S. sembarang */
/* F.S. Sebuah pq kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah pq kosong */

/* ********* Prototype ********* */
boolean isEmptyPQ(PrioQueue pq);
/* Mengirim true jika pq kosong: lihat definisi di atas */
boolean isFullPQ(PrioQueue pq);
/* Mengirim true jika tabel penampung elemen pq sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/

int lengthPQ(PrioQueue pq);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika pq kosong. */

/* *** Primitif Add/Delete *** */
void enqueuePQ(PrioQueue *pq, PQElType val);
/* Proses: Menambahkan val pada pq dengan aturan FIFO */
/* I.S. pq mungkin kosong, tabel penampung elemen pq TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void dequeuePQ(PrioQueue *pq, PQElType *val);
/* Proses: Menghapus val pada pq dengan aturan FIFO */
/* I.S. pq tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., isi elemen mundur;
        pq mungkin kosong */

void printOrders(PrioQueue pq);
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. pq di awal berisi tiga pesanan, default saat memulai game */

PQElType getElmtPQ(PrioQueue pq, int id);

boolean isMemberPQ(PrioQueue pq, int id);

#endif
