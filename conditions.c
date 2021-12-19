#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

#include "conditions.h"
#include "gameboard.h"
#include "ai.h"

char playerOneSymbol = 'X';
char playerTwoSymbol = 'O';

//randomize starting player
bool startingPlayer(void){
    return (rand() & 1);
}

//randomize the starting players (X or O), return true for XO and false for OX
/* v případě že chceme, aby začínající hráč měl vždy X podle pravidel
bool startingPlayerAndSymbol(void){
    bool player = (rand() & 1);

    //starts player 1
    if(player == 1){
        playerOneSymbol = 'X';
        playerTwoSymbol = 'O';
    }
    //starts player 2
    else{
        playerOneSymbol = 'O';
        playerTwoSymbol = 'X';
    }

    return player;
}
*/

//check whether someone is victorious
bool victory(char currentPlayerSymbol){
    bool victory = false;

    if(board[0] == currentPlayerSymbol && board[1] == currentPlayerSymbol && board[2] == currentPlayerSymbol) victory = true;
    if(board[3] == currentPlayerSymbol && board[4] == currentPlayerSymbol && board[5] == currentPlayerSymbol) victory = true;
    if(board[6] == currentPlayerSymbol && board[7] == currentPlayerSymbol && board[8] == currentPlayerSymbol) victory = true;
    if(board[0] == currentPlayerSymbol && board[3] == currentPlayerSymbol && board[6] == currentPlayerSymbol) victory = true;
    if(board[1] == currentPlayerSymbol && board[4] == currentPlayerSymbol && board[7] == currentPlayerSymbol) victory = true;
    if(board[2] == currentPlayerSymbol && board[5] == currentPlayerSymbol && board[8] == currentPlayerSymbol) victory = true;
    if(board[0] == currentPlayerSymbol && board[4] == currentPlayerSymbol && board[8] == currentPlayerSymbol) victory = true;
    if(board[2] == currentPlayerSymbol && board[4] == currentPlayerSymbol && board[6] == currentPlayerSymbol) victory = true;

    if(victory == true){
        system("cls");
        showGameBoard();
        memset(board, 0, 255);
    }

    return victory;
}

//check whether board is full and noone victorious, call after victory() function
bool draw(void){
    bool condition = true;
    for (int i = 0; i < 9; ++i) {
        if(board[i] == '\0'){
            condition = false;
        }
    }
    if(condition == true){
        system("cls");
        showGameBoard();
        memset(board, 0, 255);
    }
    return condition;
}


//returns position of wanted spot. Player - true = first player, false = second player. Version - true = PVP, false = PVE
//player == true je vždycky člověk. Player == false je buďto počítač nebo jiný hráč, version condition.
int chooseField(bool player, bool version, bool startingPlayerStaticForAI){
    system("cls");
    showGameBoard();
    int choice = -1;
    bool evaluation = false;

    if(player){
        printf("Hrac - symbol %c - je na tahu. Prosim vyberte pole [1-9].\n", playerOneSymbol);

        while(!evaluation){
            scanf("%d", &choice);
            if(board[choice - 1] != '\0'){
                printf("Pole je jiz zabrane, prosim zvolte jine.\n");
            }
            else if(choice < 1 || choice > 9){
                printf("Spatna volba. Vyberte pole cislem 1 az 9.\n");
            }
            else evaluation = true;
        }

        return choice;
    }
    else{
        if(version){
            printf("Hrac - symbol %c - je na tahu. Prosim vyberte pole [1-9].\n", playerTwoSymbol);
            while(!evaluation){
                scanf("%d", &choice);
                if(board[choice - 1] != '\0'){
                    printf("Pole je jiz zabrane, prosim zvolte jine.\n");
                }
                else if(choice < 1 || choice > 9){
                    printf("Spatna volba. Vyberte pole cislem 1 az 9.\n");
                }
                else evaluation = true;
            }

            return choice;
        }
        else{
            printf("Jsem na tahu. Premyslim.\n");
            //sleep(3);
            //AI always chooses the right spot - no need for evaluation whether spot is taken
            return aiChoice(startingPlayerStaticForAI);
        }
    }
}
