#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

#include "gameboard.h"
#include "ai.h"
#include "conditions.h"

//player one - always X
//player two - always O
//randomizer only chooses whether X or O starts
//according to rules - X always starts - possible to use function "bool startingPlayerAndSymbol(void)" in condition.c

//main function to call. Aggregates other functions. Version - true = PVP, false = PVE
void play(bool version){
    srand( time(NULL) );
    bool victoryBool = false;
    bool drawBool = false;
    bool player = startingPlayer(); //true = playerOne starts, false = playerTwo starts

    //stuff for AI
    bool startingPlayerStaticForAI;
    if(player) startingPlayerStaticForAI = true; else startingPlayerStaticForAI = false;
    firstMoveDone = false;
    secondMoveDone = false;
    thirdMoveDone = false;

    while(!victoryBool && !drawBool){
        if(player){
            board[chooseField(player, version, startingPlayerStaticForAI) - 1] = playerOneSymbol;
            player = false;

            if(victory(playerOneSymbol)){
                printf("Vitezi hrac %c.\n", playerOneSymbol);
                victoryBool = true;
            }

            if(draw()){
                if(!version){
                    printf("Dobra prace. Pocitac nelze porazit. Remiza je jako vitezstvi!\n");
                }
                else printf("Remiza.\n");
                drawBool = true;
            }
        }
        else {
            board[chooseField(player, version, startingPlayerStaticForAI) - 1] = playerTwoSymbol;
            player = true;

            if(victory(playerTwoSymbol)){
                if(!version){
                    printf("Vitezi pocitac.\n");
                }
                else printf("Vitezi hrac %c.\n", playerTwoSymbol);
                victoryBool = true;
            }

            if(draw()){
                if(!version){
                    printf("Dobra prace. Pocitac nelze porazit. Remiza je jako vitezstvi!\n");
                }
                else printf("Remiza.\n");
                drawBool = true;
            }
        }
    }
}



int main()
{
    printf("Vitejte!!! Pojdme si zahrat piskvorky. Chcete hrat proti jinemu hraci nebo proti pocitaci?\n");
    char choice = '0';

    while(choice != '3'){

        fflush(stdin);
        printf("Chcete hrat proti jinemu hraci[1] nebo proti pocitaci[2]? ([3] pro konec)\n");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            //player
            play(true);
            break;
        case '2':
            //AI
            play(false);
            break;
        case '3':
            printf("Preji prijemny den.\n");
            break;
        default:
            printf("Spatna volba, zkuste znovu.\n");
            break;
        }
    }
    return 0;
}


