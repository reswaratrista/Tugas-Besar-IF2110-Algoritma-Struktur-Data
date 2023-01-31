#include "battleship.h"
#include "../../Misc/io/io.h"
#include <stdio.h>

// AI
// Yor Forger -> nembak asal (kalo gk sempet, implement yg ini aja)
// Loid Forger -> lebih hoki 
// Anya Forger -> hax (baca pikiran), harus bener terus ato nggak auto kalah

void battleship(ListMap *M, ListSet *S) {

    Word inputEnemy;
    int enemy;
    boolean validEnemy = false;
    boolean inGame = false;

    int shots = 0;

    while (!validEnemy) {

        header();

        battleshipSplash();

        printf("Silahkan pilih lawan Anda [YOR/LOID/ANYA/QUIT]: ");

        validEnemy = wordInput(&inputEnemy,3,4);

        if (validEnemy) {
            if (isWordEqual(inputEnemy,stringToWord("YOR"))) {
                inGame = true;
                enemy = 1;
                printf("Tekan [ENTER] untuk memulai permainan.\n");
            } else if (isWordEqual(inputEnemy,stringToWord("LOID"))) {
                inGame = true;
                enemy = 2;
                printf("Tekan [ENTER] untuk memulai permainan.\n");
            } else if (isWordEqual(inputEnemy,stringToWord("ANYA"))) {
                inGame = true;
                enemy = 3;
                printf("Tekan [ENTER] untuk memulai permainan.\n");
            } else if (isWordEqual(inputEnemy,stringToWord("QUIT"))) {
                inGame = false;
                printf("Pengecut. Tekan [ENTER] untuk kembali ke menu utama.\n");
            } else {
                validEnemy = false;
            }
        } 

        if (!validEnemy) {
            printf("Masukan tidak valid. Tekan [ENTER] dan ulangi masukan.\n");
        }

        blankInput();

    }

    if (inGame) {

        header();

        Grid PlayerGrid;
        Grid EnemyGrid;

        initializeGrid(&PlayerGrid,false);
        initializeGrid(&EnemyGrid,true);

        placeShipsPlayer(&PlayerGrid);
        placeShipsEnemy(&EnemyGrid);

        boolean playerWinner = false;
        boolean enemyWinner = false;

        while (!playerWinner && !enemyWinner) {

            header();

            printBothGrids(PlayerGrid,EnemyGrid, enemy);

            playerShoot(&EnemyGrid);
            endTurn(&EnemyGrid,&playerWinner);

            if (!playerWinner) {
                enemyShoot(&PlayerGrid,enemy);
                endTurn(&PlayerGrid,&enemyWinner);
            }
            
            shots = shots + 1;

        }

        int score;
        header();   

        printBothGrids(PlayerGrid,EnemyGrid, enemy);

        if (playerWinner) {
            printf("Musuh berhasil dikalahkan. Selamat, Laksamana.\n");
            score = 50000 + (enemy * 50000) - (shots - 16);
        } else {
            printf("Mundur, Laksamana! Seluruh kapal tenggelam!\n");
            score = 0;
        }

        printf("Skor Anda: %d\n",score);
        inputDataListMap(M, S, 5, score);

        printf("\nTekan [ENTER] untuk kembali ke menu utama...\n");

        blankInput();

    }
    
}

void initializeGrid(Grid *G, boolean Enemy) {

    int i = 0;

    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {

            Point P;
            createPoint(&P,x,y);

            HAS_SHIP(TILE(*G,P)) = false;
            WAS_SHOT(TILE(*G,P)) = false;
            ENEMY(*G) = Enemy;

        }
    }

}

void createShip(Ship *S, char *N, Point P, boolean V, int L) {

    NAME(*S) = N;
    POSITION(*S) = P;
    VERTICAL(*S) = V;
    SHIPLENGTH(*S) = L;
    SUNK(*S) = false;

}

void copyShip(Ship *S1, Ship *S2) {

    NAME(*S1) = NAME(*S2);
    POSITION(*S1) = POSITION(*S2);
    VERTICAL(*S1) = VERTICAL(*S2);
    SHIPLENGTH(*S1) = SHIPLENGTH(*S2);
    SUNK(*S1) = SUNK(*S2);

}

int shipsAlive(Grid G) {

    int alive = 0;
    for (int i = 0; i < 5; i++) {
        if (G.ships[i].sunk != true) {
            alive = alive + 1;
        }
    }
    return alive;

}

void setShip (Grid *G, int i, Ship S) {

    NAME(G->ships[i]) = NAME(S);
    POSITION(G->ships[i]) = POSITION(S);
    VERTICAL(G->ships[i]) = VERTICAL(S);
    SHIPLENGTH(G->ships[i]) = SHIPLENGTH(S);
    SUNK(G->ships[i]) = SUNK(S);

}

void placeShipsPlayer(Grid *G) {

    Ship Carrier;
    Ship Battleship;
    Ship Cruiser;
    Ship Submarine;
    Ship Destroyer;
    
    boolean Repeat = true;

    while (Repeat) {

        initializeGrid(G,false);

        header();
        printSingleGrid(*G);
        shipInput(G,&Carrier,"Carrier",5);
        setShip(G,0,Carrier);

        header();
        printSingleGrid(*G);
        shipInput(G,&Battleship,"Battleship",4);
        setShip(G,1,Battleship);

        header();
        printSingleGrid(*G);
        shipInput(G,&Cruiser,"Cruiser",3);
        setShip(G,2,Cruiser);

        header();
        printSingleGrid(*G);
        shipInput(G,&Submarine,"Submarine",3);
        setShip(G,3,Submarine);

        header();
        printSingleGrid(*G);
        shipInput(G,&Destroyer,"Destroyer",2);
        setShip(G,4,Destroyer);

        header();
        printSingleGrid(*G);
        
        Word RepeatInput;
        boolean Valid = false;
        boolean InputValid = false;
        int InvalidInputs = 0;

        while (!InputValid) {
        
            if (InvalidInputs == 0) {
                printf("Apakah Anda ingin mengulangi input? [Y/N]: ");
            } else {
                printf("Ulangi input!: ");
            }

            Valid = wordInput(&RepeatInput,1,1);

            if (Valid) {
                if (isAlpha(RepeatInput.buffer[0]) && (lower(RepeatInput.buffer[0]) == 'y' || lower(RepeatInput.buffer[0]) == 'n')) {
                    if (lower(RepeatInput.buffer[0]) == 'y') {
                        Repeat = true;
                    } else {
                        Repeat = false;
                    }
                    InputValid = true;
                } else {
                    InvalidInputs = InvalidInputs + 1;
                }
            } else {
                InvalidInputs = InvalidInputs + 1; 
            }

        }

    }

}

void placeShipsEnemy(Grid *G) {

    Ship Carrier;
    Ship Battleship;
    Ship Cruiser;
    Ship Submarine;
    Ship Destroyer;

    shipInputEnemy(G,&Carrier,"Carrier",5);
    setShip(G,0,Carrier);

    shipInputEnemy(G,&Battleship,"Battleship",4);
    setShip(G,1,Battleship);

    shipInputEnemy(G,&Cruiser,"Cruiser",3);
    setShip(G,2,Cruiser);

    shipInputEnemy(G,&Submarine,"Submarine",3);
    setShip(G,3,Submarine);

    shipInputEnemy(G,&Destroyer,"Destroyer",2);
    setShip(G,4,Destroyer);

}

void shipInputEnemy(Grid *G, Ship *S, char *N, int L) {

    boolean Valid = false;
    Point P;
    boolean V;

    while (!Valid) {

        createPoint(&P,random_range(0,10),random_range(0,10));
        V = random_range(0,1);

        createShip(S,N,P,V,L);

        if (shipPosValid(*G,*S)) {
            Valid = true;
        }

    }

    P = POSITION(*S);
    V = VERTICAL(*S);

    for (int i = 0; i < L; i++) {

        HAS_SHIP(TILE(*G,P)) = true;
        movePoint(&P,V,!V);

    }

}

void shipInput(Grid *G, Ship *S, char *N, int L) {

    int InvalidInputs = 0;
    boolean Valid = false;

    while (!Valid) {
        
        if (InvalidInputs == 0) {
            printf("Silahkan masukkan posisi dan orientasi kapal %s.\n",N);
        } else {
            printf("Posisi kapal tidak valid! Ulangi masukan.\n");
        }

        Point P;
        boolean V;

        posInput(&P);
        verticalInput(&V);

        createShip(S,N,P,V,L);

        if (shipPosValid(*G,*S)) {
            Valid = true;
        } else {
            InvalidInputs = InvalidInputs + 1;
        }

    }

    Point P = POSITION(*S);
    boolean V = VERTICAL(*S);

    for (int i = 0; i < L; i++) {

        HAS_SHIP(TILE(*G,P)) = true;
        movePoint(&P,V,!V);

    }

}

void posInput(Point *P) {

    int InvalidInputs = 0;
    boolean Valid = false;

    Word Input;

    while (!Valid) {
        
        if (InvalidInputs == 0) {
            printf("Silahkan masukkan koordinat dengan format [A-J][0-9]: ");
        } else {
            printf("Masukan bukan merupakan koordinat yang valid! Ulangi Input!: ");
        }
        
        boolean InputValid = wordInput(&Input,2,2);

        if (InputValid) {
            if ((isAlpha(Input.buffer[0]) && isCharInRange(lower(Input.buffer[0]), ord('a'), ord('j'))) && (isNumeric(Input.buffer[1]))) {
                Valid = true;
            } else {
                InvalidInputs = InvalidInputs + 1;
            }
        } else {
            InvalidInputs = InvalidInputs + 1;
        }

    }

    ORDINATE(*P) = alphabeticalOrd(Input.buffer[0]);
    
    ABSCISSA(*P) = charToInt(Input.buffer[1]);
}

void verticalInput(boolean *V) {

    int InvalidInputs = 0;
    boolean Valid = false;

    Word Input;

    while (!Valid) {
        
        if (InvalidInputs == 0) {
            printf("Apakah kapal berorientasi vertikal? [Y/N]: ");
        } else {
            printf("Ulangi input!: ");
        }

        boolean InputValid = wordInput(&Input,1,1);

        if (InputValid) {
            if (isAlpha(Input.buffer[0]) && (lower(Input.buffer[0]) == 'y' || lower(Input.buffer[0]) == 'n')) {
                Valid = true;
            } else {
                InvalidInputs = InvalidInputs + 1;
            }
        } else {
           InvalidInputs = InvalidInputs + 1; 
        }

    }

    if (lower(Input.buffer[0]) == 'y') {
        *V = true;
    } else {
        *V = false;
    }

}

boolean shipPosValid(Grid G, Ship S) {

    boolean Valid = false;
    Point P = POSITION(S);

    if (VERTICAL(S)) {
        if (ABSCISSA(P) + SHIPLENGTH(S) - 1 < 10 && ORDINATE(P) < 10 && isFirstQuadrant(P)) {
            int i = 0;
            boolean Overlap = false;
            while (!Overlap && i < SHIPLENGTH(S)) {
                if (HAS_SHIP(TILE(G,P))) {
                    Overlap = true;
                }
                movePoint(&P,1,0);
                i = i + 1;
            }
            Valid = !Overlap;
        }
    } else {
        if (ORDINATE(P) + SHIPLENGTH(S) - 1 < 10 && ABSCISSA(P) < 10 && isFirstQuadrant(P)) {
            int i = 0;
            boolean Overlap = false;
            while (!Overlap && i <= SHIPLENGTH(S)) {
                if (HAS_SHIP(TILE(G,P))) {
                    Overlap = true;
                }
                movePoint(&P,0,1);
                i = i + 1;
            }
            Valid = !Overlap;
        }
    }

    return Valid;

}

void playerShoot(Grid *G) {

    int InvalidInputs = 0;
    boolean Valid = false;
    Point P;

    while (!Valid) {
        
        if (InvalidInputs == 0) {
            printf("Silahkan tembak salah satu koordinat lawan.\n");
        } else {
            printf("Koordinat tidak valid! Ulangi masukan.\n");
        }

        posInput(&P);

        if ((WAS_SHOT(TILE(*G,P)))) {
            Valid = false;
        } else {
            Valid = true;
        }

    }

    shoot(G,P);

}

void enemyShoot(Grid *G, int Enemy) {

    Point P;
    boolean Valid = false;

    if (Enemy == 1) { // Yor

        while (!Valid) {

            createPoint(&P,random_range(0,9),random_range(0,9));

            if ((WAS_SHOT(TILE(*G,P)))) {
                Valid = false;
            } else {
                Valid = true;
            }

        }
        
    } else if (Enemy == 2) {

            int luck = random_range(1,10);

            if (luck > 8) {
                int i = 0, j = 0;
                while (!Valid) {

                    createPoint(&P,random_range(1,10),random_range(1,10));

                    if ((WAS_SHOT(TILE(*G,P)) || !HAS_SHIP(TILE(*G,P)))) {
                        Valid = false;
                    } else {
                        Valid = true;
                    }

                    i = i + 1;
                    if (i == 10) {
                        j = j + 1;
                        i = 0;
                    }

                }
            } else {
                while (!Valid) {
                    createPoint(&P,random_range(0,9),random_range(0,9));
                    if ((WAS_SHOT(TILE(*G,P)))) {
                        Valid = false;
                    } else {
                        Valid = true;
                    }
                }
            }
        

    } else { // ANYA
        int i = 0, j = 0;
        while (!Valid) {

            createPoint(&P,j,i);

            if ((WAS_SHOT(TILE(*G,P)) || !HAS_SHIP(TILE(*G,P)))) {
                Valid = false;
            } else {
                Valid = true;
            }

            i = i + 1;
            if (i == 10) {
                j = j + 1;
                i = 0;
            }

        } 
    }

    shoot(G,P);

}

void shoot(Grid *G, Point P) {
    
    WAS_SHOT(TILE(*G,P)) = true;

}

void endTurn(Grid *G, boolean *Winner) {

    for (int i = 0; i < SHIPCOUNT; i++) {

        boolean sunk = SUNK(SHIP(*G,i));

        if (!sunk) {

            boolean AllTilesShot = true;
            Point CheckPos = POSITION(SHIP(*G,i));
            int ShipLength = SHIPLENGTH(SHIP(*G,i));

            while (AllTilesShot && ShipLength > 0) {
                boolean tileshot = WAS_SHOT(TILE(*G,CheckPos));
                if (!tileshot) {
                    AllTilesShot = false;
                }
                ShipLength = ShipLength - 1;
                boolean V = VERTICAL(SHIP(*G,i));
                movePoint(&CheckPos,V,!V);
            }

            if (AllTilesShot) {
                SUNK(SHIP(*G,i)) = true;
            }

        }

    }

    boolean AllShipsSunk = true;

    for (int i = 0; i < SHIPCOUNT; i++) {

        boolean sunk = SUNK(SHIP(*G,i));

        if (!sunk) {
            AllShipsSunk = false;
        }

    }

    if (AllShipsSunk) {
        *Winner = true;
    }

}

void battleshipSplash() {

    printf("                                             #.                                 \n");
    printf("                                             @ #                                \n");
    printf("                                             .@ ,                               \n");
    printf("                                           @. @                                 \n");
    printf("                       &@             @@*     @#                                \n");
    printf("                      @@@           @@@       @  @@@@@@                         \n");
    printf("                       @        &@@ @@@  @    @@@@@@@@@                         \n");
    printf("                @@@@ @@@     @@@@@@@@@@@@@@@@@@@@@@@@@@ @@@@@. @((@@@,@@@    @& \n");
    printf(" @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \n");
    printf(" @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \n");
    printf("\n");
    printf("  ######   #####  ######## ######## ##      ####### ####### ##   ## ## ######   \n");
    printf("  ##   ## ##   ##    ##       ##    ##      ##      ##      ##   ## ## ##   ##  \n");
    printf("  ######  #######    ##       ##    ##      #####   ####### ####### ## ######   \n");
    printf("  ##   ## ##   ##    ##       ##    ##      ##           ## ##   ## ## ##       \n");
    printf("  ##   ## ##   ##    ##       ##    ##      ##           ## ##   ## ## ##       \n");
    printf("  ######  ##   ##    ##       ##    ####### ####### ####### ##   ## ## ##       \n");
    printf("\n");
    printf("==========================Selamat datang, Laksamana.============================\n");
    printf("\n");

}

void printSingleGrid(Grid G) {

    printf("   PAPAN ANDA SAAT INI\n");
    printf("   A B C D E F G H I J\n");

    for (int i = 0; i < 10; i++) {

        printf("%d)",i);
        
        for (int j = 0; j < 10; j++) {
            if ((G.tiles[i*10 + j].ship == true)) {
                printf(" #");
            } else {
                printf(" .");
            }
        }

        printf("\n");

    }

    printf("\n");

}

void printBothGrids(Grid PlayerGrid, Grid EnemyGrid, int Enemy) {

    printf("                   PAPAN ANDA                     PAPAN ");

    if (Enemy == 1) {
        printf(" Yor\n");
    } else if (Enemy == 2) {
        printf("Loid\n");
    } else {
        printf("Anya\n");
    }

    printf("                   A B C D E F G H I J | A B C D E F G H I J                   \n");
    
    for (int i = 0; i < 10; i++) {
        printf("                 %d)",i);
        for (int j = 0; j < 10; j++) {
            if ((PlayerGrid.tiles[i*10 + j].shot == true && PlayerGrid.tiles[i*10 + j].ship == true)) {
                printf("X ");
            } else if ((PlayerGrid.tiles[i*10 + j].shot == true)) {
                printf("@ ");
            } else if (PlayerGrid.tiles[i*10 + j].ship == true) {
                printf("# ");
            } else {
                printf(". ");
            }
        }
        printf("| ");
        for (int j = 0; j < 10; j++) {
            if ((EnemyGrid.tiles[i*10 + j].shot == true && EnemyGrid.tiles[i*10 + j].ship == true)) {
                printf("X ");
            } else if ((EnemyGrid.tiles[i*10 + j].shot == true)) {
                printf("@ ");
            } else {
                printf(". ");
            }
        }
        printf("(%d\n",i);
    }

    printf("                   A B C D E F G H I J | A B C D E F G H I J                   \n");
    printf("                   %d/5           KAPAL TERSISA           %d/5\n",shipsAlive(PlayerGrid),shipsAlive(EnemyGrid));
    printf("\n");
    printf("===============================================================================\n");
    printf("\n");

}

/* 

                                                                                
================================================================================                                                                                
                                                                                                    
                                             #.                                 
                                             @ #                                
                                             .@ ,                               
                                           @. @                                 
                       &@             @@*     @#                                
                      @@@           @@@       @  @@@@@@                         
                       @        &@@ @@@  @    @@@@@@@@@                         
                @@@@ @@@     @@@@@@@@@@@@@@@@@@@@@@@@@@ @@@@@. @((@@@,@@@    @& 
 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 
 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

  ######   #####  ######## ######## ##      ####### ####### ##   ## ## ######  
  ##   ## ##   ##    ##       ##    ##      ##      ##      ##   ## ## ##   ## 
  ######  #######    ##       ##    ##      #####   ####### ####### ## ######  
  ##   ## ##   ##    ##       ##    ##      ##           ## ##   ## ## ##      
  ######  ##   ##    ##       ##    ####### ####### ####### ##   ## ## ##       

===========================Selamat datang, Laksamana.===========================

Silahkan pilih lawan Anda [YOR/LOID/ANYA]: 


*/

/*

------------------KAPALPERANG-------------------

           
           A B C D E F G H I J | A B C D E F G H I J
##### C 0)                     |                     (0 C #####
        1)                     |                     (1 
####. B 2)                     |                     (2 B .####            
        3)                     |                     (3
###.. D 4)                     |                     (4 D ..###
        5)                     |                     (5
###.. S 6)                     |                     (6 S ..###
        7)                     |                     (7
##... P 8)                     |                     (8 P ...##
        9)                     |                     (9 
           A B C D E F G H I J | A B C D E F G H I J
                2/5 KAPAL             2/5 KAPAL



void initializeGrid(Grid *G) {

    int i = 0;

    for (int x = 1; x < 11; x++) {
        for (int y = 1; y < 11; y++) {

            Point P;
            createPoint(&P,x,y);

            SHIP(TILE(*G,P)) = false;
            SHOT(TILE(*G,P)) = false;

            destroyPoint(&P);

        }
    }

}

void printGrid(Grid G,boolean Enemy) {

    for (int x = 1; x < 11; x++) {

        for (int y = 1; y < 11; y++) {

            Point P;
            createPoint(&P,x,y);

            if (SHOT(TILE(G,P))) {
                printf("X");
            } else if (SHIP(TILE(G,P))) {
                if (!Enemy) {
                    printf("#");
                }
            } else {
                printf(" ");
            }

            destroyPoint(&P);

        }

        printf("\n");

    }

}

boolean shipPosValid(Point P, int Length, boolean Vertical) {

    if (Vertical) {
        return (ORDINATE(P) + Length - 1 <= 10 && ABSICSSA(P) <= 10 && isFirstQuadrant(P));
    } else {
        return (ABSICSSA(P) + Length - 1 <= 10 && ORDINATE(P) <= 10 && isFirstQuadrant(P));
    }

}

*/