#ifndef TREE_H
#define TREE_H

#include "../boolean.h"

/* Selektor */
#define ROOT(p) (p)->info
#define LEFT(p) (p)->left
#define RIGHT(p) (p)->right

typedef int TreeElType;
typedef struct treeNode* AddressTree;
typedef struct treeNode { 
     TreeElType info;
     AddressTree left;
     AddressTree right;
} TreeNode;

/* Definisi PohonBiner */
/* pohon Biner kosong p = NIL */

typedef AddressTree BinTree;

BinTree NewTree(TreeElType akar, BinTree l, BinTree r);
// Menghasilkan sebuah pohon biner dari akar, l, dan r, jika alokasi berhasil
// Menghasilkan pohon kosong (NIL) jika alokasi gagal

void CreateTree (TreeElType akar, BinTree l, BinTree r, BinTree *p);
// I.S. Sembarang
// F.S. Menghasilkan sebuah pohon p
// Menghasilkan sebuah pohon biner p dari akar, l, dan r, jika alokasi berhasil
// Menghasilkan pohon p yang kosong (NIL) jika alokasi gagal

AddressTree newTreeNode(TreeElType x);
// Mengirimkan AddressTree hasil alokasi sebuah elemen bernilai x
// Jika alokasi berhasil, maka AddressTree tidak NIL, dan misalnya
// menghasilkan p, maka p↑.info = x, p↑.left = NIL, p↑.right = NIL
// Jika alokasi gagal, mengirimkan NIL

void deallocTreeNode (AddressTree p);
// I.S. p terdefinisi 
// F.S. p dikembalikan ke sistem 
// Melakukan dealokasi/pengembalian AddressTree p

boolean isTreeEmpty (BinTree p);
// Mengirimkan true jika p adalah pohon biner yang kosong 

boolean isOneElmt (BinTree p);
// Mengirimkan true jika p tidak kosong dan hanya terdiri atas 1 elemen

boolean isUnerLeft (BinTree p);
// Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerleft: 
// hanya mempunyai subpohon kiri 

boolean isUnerRight (BinTree p);
// Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerright: 
// hanya mempunyai subpohon kanan 

boolean isBinary (BinTree p);
// Mengirimkan true jika pohon biner tidak kosong, p adalah pohon biner: 
// mempunyai subpohon kiri dan subpohon kanan

int nbElmt (BinTree p);
// Mengirimkan jumlah elemen dari pohon

int nbLeaf(BinTree p);
// Prekondisi: Pohon Biner tidak mungkin kosong,
// Mengirimkan banyaknya daun pohon

#endif