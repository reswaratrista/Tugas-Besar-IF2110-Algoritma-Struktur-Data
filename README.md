# **BNMO**

Tugas Besar Alstrukdat IF2110

Game console kesayangan Indra dan Doni, BNMO, setelah rusak dan diperbaiki oleh teknisi, memunculkan banyak bug dalam game mereka. Tugas kamu adalah memperbaiki program BNMO mereka agar mereka bisa kembali memainkan game kesayangan mereka.

BNMO merupakan suatu robot game console yang diprogram menggunakan bahasa C, dengan game-game didalamnya merupakan permainan berbasis CLI (Command Line Interface). Program ini memanfaatkan berbagai struktur data, diantaranya adalah list/array, mesin karakter, mesin kata, queue, point, dan juga grid. Program pada BNMO dapat digunakan untuk memainkan game, menambahkan game, menghapus game, dan juga mengurutkan game yang akan dimainkan.  

### Anggota Kelompok
| Nama | NIM |
| :----------- |  :----------: |
| Agnes Tamara Putri | 18220010 |
| Salman Ma'arif Achsien | 18221102 |
| Reswara Trista Aulia C. | 18221122 |
| Erensi Ratu Chelsia | 18221166 |
| Rania Sasi Kirana | 18221168 |

### Kompilasi Program
Untuk melakukan kompilasi program dan kompilasi driver tiap ADT, buka file compile.txt pada folder bin, lalu salin bagian compile program ke terminal. Pastikan terminal sedang berada di folder utama program.

### Struktur Program
```
│   .gitignore
│   README.md
|   main.c
│
├───.vscode
│       settings.json
│
├───Config
│       config.txt
|       test.txt
│
├───bin
|       compile.txt
|
├───docs
|       IF2111_TB1_K2_06.pdf
│
└───src
        ├───ADT
        |   │   boolean.h
        |   │
        |   ├───list
        |   │       array.c
        |   │       array.h
        |   │       driverArray.c   
        |   │       driverLinkedList.c
        |   │       driverListDiner.c
        |   │       linkedList.c
        |   │       linkedList.h
        |   │       listDiner.c
        |   │       listDiner.h    
        |   │
        |   ├───map
        |   │       driverListMap.c
        |   |       driverMap.c
        |   │       listMap.c
        |   │       listMap.h
        |   |       map.c
        |   |       map.h
        |   │
        |   ├───point
        |   │       driverPoint.c
        |   │       point.c
        |   │       point.h
        |   │
        |   ├───queue
        |   |       driverPrioqueue.c
        |   │       driverQueue2.c
        |   │       prioqueue.c
        |   |       prioqueue.h
        |   │       queue2.c
        |   │       queue2.h
        |   │
        |   ├───set
        |   │       driverListSet.c
        |   |       driverset.c
        |   │       listSet.c
        |   │       listSet.h
        |   |       set.c
        |   |       set.h
        |   │
        |   ├───stack
        |   │       driverStack.c
        |   │       stack.c
        |   │       stack.h
        |   |
        |   ├───tree
        |   │       driverTree.c
        |   │       tree.c
        |   │       tree.h
        |   |
        |   └───word
        |         |   driverWord.c
        |         |   word.c
        |         |   word.h
        |         |
        |         ├───mesinkarakter
        |         |       driverMesinKarakter.c
        |         |       mesinkarakter.c
        |         |       mesinkarakter.h
        |         |       test.txt
        |         |
        |         └───mesinkata
        |                 driverMesinKata.c
        |                 mesinkata.c
        |                 mesinkata.h
        |                 test.txt
        |       
        ├───Games
        |   │   random.c
        |   |   random.h
        |   │
        |   ├───battleship
        |   │       battleship.c
        |   │       battleship.h
        |   │
        |   ├───dinerdash
        |   │       dinerdash.c
        |   │       dinerdash.h
        |   │
        |   ├───hangman
        |   │       hangman.c
        |   │       hangman.h
        |   │       listKata.txt
        |   │       man.c
        |   │       man.h
        |   │
        |   ├───rng
        |   │       rng.c
        |   │       rng.h
        |   |
        |   ├───snakeonmeteor
        |   │       snakeonmeteor.c
        |   │       snakeonmeteor.h
        |   |
        |   ├───tgg
        |   │       tgg.c
        |   │       tgg.h
        |   |
        |   └───towerofhanoi
        |           towerOfHanoi.c
        |           towerOfHanoi.h
        |
        ├───Misc
        |   │
        |   ├───ascii
        |   │       ascii.c
        |   │       ascii.h
        |   │
        |   └───io
        |           colors.h
        |           io.c
        |           io.h
        |
        └───Utility
            │   splash.c
            |   splash.h
            │
            ├───commandlain
            │       commandlain.c
            │       commandlain.h
            │
            ├───creategame
            │       createGame.c
            │       createGame.h
            │
            ├───deleteGame
            │       deleteGame.c
            │       deleteGame.h
            │
            ├───help
            │       help.c
            │       help.h
            │
            ├───history
            │       history.c
            │       history.h
            │
            ├───listGame
            │       listGame.c
            │       listGame.h
            │
            ├───load
            │       load.c
            │       load.h
            │
            ├───playGame
            │       playGame.c
            │       playGame.h
            |
            ├───queuegame
            │       queueGame.c
            │       queueGame.h
            │
            ├───quit
            │       quit.c
            │       quit.h
            │
            ├───save
            │       save.c
            │       save.h
            │
            ├───scoreboard
            │       scoreboard.c
            │       scoreboard.h
            │
            ├───skipGame
            │       skipGame.c
            │       skipGame.h
            │
            └───start
                    start.c
                    start.h     
          
```

