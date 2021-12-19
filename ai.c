#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#include "ai.h"
#include "gameboard.h"
#include "conditions.h"


/*
https://puzzling.stackexchange.com/questions/30/what-is-the-optimal-first-move-in-tic-tac-toe
http://blog.maxant.co.uk/pebble/2018/04/07/1523086680000.html
https://en.wikipedia.org/wiki/Talk:Tic-tac-toe#xkcd_graphic
https://en.wikipedia.org/wiki/Tic-tac-toe
best first move as a starting player is either corner/middle. Corner leads to easier wins against unskilled players and is
much easier to implement. But leads to more straightforward game (player who goes second has only one option to pick to tie the game,
otherwise its a win for starting player - the games are very similar). Starting in center can test your opponent's attention
and force him to make a mistake.
*/

int chosen; //final decision
bool firstMoveDone;
bool secondMoveDone;
bool thirdMoveDone;
bool specialSituation = false;
int firstChoice;

bool firstMove(bool startingPlayer){

    if(!firstMoveDone){
        //ai starts = false
        if(!startingPlayer){
            //randomizing which corner to take
            int corners[4] = {1,3,7,9};
            int tmp = rand() % 4;
            chosen = corners[tmp];
        }
        else{
            //first move as a second player always best middle unless taken
            if(board[4] == '\0'){
                chosen = 5;
            }
            else{
                //randomizing which corner to take
                int corners[4] = {1,3,7,9};
                int tmp = rand() % 4;
                chosen = corners[tmp];
            }
        }

        firstChoice = chosen;
        firstMoveDone = true;
        return true;
    }

    return false;
}

bool secondMove(bool startingPlayer){

    if(!secondMoveDone){
        if(!startingPlayer){
            //if opponent took a side next to your symbol in their first move - go to center
            if( (firstChoice == 1 && (board[1] == playerOneSymbol || board[3] == playerOneSymbol ))
                    || (firstChoice == 3 && (board[1] == playerOneSymbol || board[5] == playerOneSymbol ))
                    || (firstChoice == 7 && (board[3] == playerOneSymbol || board[7] == playerOneSymbol ))
                    || (firstChoice == 9 && (board[7] == playerOneSymbol || board[5] == playerOneSymbol ))
                    ){
                specialSituation = true;
                chosen = 5;
                secondMoveDone = true;
                return true;
            }

            //always go to opposite corner, if taken go to any other corner

            if(firstChoice == 1 && board[8] != playerOneSymbol){
                chosen = 9;
                secondMoveDone = true;
                return true;
            }
            if(firstChoice == 3 && board[6] != playerOneSymbol) {
                chosen = 7;
                secondMoveDone = true;
                return true;
            }
            if(firstChoice == 7 && board[2] != playerOneSymbol) {
                chosen = 3;
                secondMoveDone = true;
                return true;
            }
            if(firstChoice == 9 && board[0] != playerOneSymbol) {
                chosen = 1;
                secondMoveDone = true;
                return true;
            }

            bool condition = false;
            do{
                int corners[4] = {1,3,7,9};
                int tmp = rand() % 4;
                chosen = corners[tmp];
                if(board[chosen - 1] == '\0'){
                    condition = true;
                }
            }while(!condition);

            secondMoveDone = true;
            return true;
        }
        else{
            if(firstChoice == 5){
                //prevent opponent from making two doubles
                if((board[0] == playerOneSymbol && board[8] == playerOneSymbol) || (board[2] == playerOneSymbol && board[6] == playerOneSymbol)){
                    int choices[4] = {2,4,6,8};
                    int tmp = rand() % 4;
                    chosen = choices[tmp];
                    secondMoveDone = true;
                    return true;
                }
                //to prevent an unlikely randomized loss in case opponent goes eg. 1+8 in their first two moves (as a starting player)
                //two spots are a loss in such case
                if(board[0] == playerOneSymbol && board[7] == playerOneSymbol){
                    int choices[4] = {4,6,7,9};
                    int tmp = rand() % 4;
                    chosen = choices[tmp];
                    secondMoveDone = true;
                    return true;
                }
                if(board[0] == playerOneSymbol && board[5] == playerOneSymbol){
                    int choices[4] = {2,3,8,9};
                    int tmp = rand() % 4;
                    chosen = choices[tmp];
                    secondMoveDone = true;
                    return true;
                }
                if(board[2] == playerOneSymbol && board[3] == playerOneSymbol){
                    int choices[4] = {1,2,7,8};
                    int tmp = rand() % 4;
                    chosen = choices[tmp];
                    secondMoveDone = true;
                    return true;
                }
                if(board[2] == playerOneSymbol && board[7] == playerOneSymbol){
                    int choices[4] = {4,6,7,9};
                    int tmp = rand() % 4;
                    chosen = choices[tmp];
                    secondMoveDone = true;
                    return true;
                }
                if(board[6] == playerOneSymbol && board[1] == playerOneSymbol){
                    int choices[4] = {1,3,4,6};
                    int tmp = rand() % 4;
                    chosen = choices[tmp];
                    secondMoveDone = true;
                    return true;
                }
                if(board[6] == playerOneSymbol && board[5] == playerOneSymbol){
                    int choices[4] = {2,3,8,9};
                    int tmp = rand() % 4;
                    chosen = choices[tmp];
                    secondMoveDone = true;
                    return true;
                }
                if(board[8] == playerOneSymbol && board[1] == playerOneSymbol){
                    int choices[4] = {1,3,4,6};
                    int tmp = rand() % 4;
                    chosen = choices[tmp];
                    secondMoveDone = true;
                    return true;
                }
                if(board[8] == playerOneSymbol && board[3] == playerOneSymbol){
                    int choices[4] = {1,2,7,8};
                    int tmp = rand() % 4;
                    chosen = choices[tmp];
                    secondMoveDone = true;
                    return true;
                }
            }
            //opponent took middle - if opponent second move is opposite corner to AI first move - prevent from making two doubles
            else if(firstChoice == 1 && board[8] == playerOneSymbol){
                int choices[2] = {3,7};
                int tmp = rand() % 2;
                chosen = choices[tmp];
                secondMoveDone = true;
                return true;
            }
            else if(firstChoice == 3 && board[6] == playerOneSymbol){
                int choices[2] = {1,9};
                int tmp = rand() % 2;
                chosen = choices[tmp];
                secondMoveDone = true;
                return true;
            }
            else if(firstChoice == 7 && board[2] == playerOneSymbol){
                int choices[2] = {1,9};
                int tmp = rand() % 2;
                chosen = choices[tmp];
                secondMoveDone = true;
                return true;
            }
            else if(firstChoice == 9 && board[0] == playerOneSymbol){
                int choices[2] = {3,7};
                int tmp = rand() % 2;
                chosen = choices[tmp];
                secondMoveDone = true;
                return true;
            }
        }
    }
    secondMoveDone = true;
    return false;
}


bool thirdMove(bool startingPlayer){
    if(!thirdMoveDone){
        if(!startingPlayer){
            //this makes the AI win if opponent made their first move next to AI corner move
            if(specialSituation){
                if(firstChoice == 1 && board[1] == playerOneSymbol){
                    chosen = 7;
                    thirdMoveDone = true;
                    return true;
                }
                if(firstChoice == 1 && board[3] == playerOneSymbol){
                    chosen = 3;
                    thirdMoveDone = true;
                    return true;
                }
                if(firstChoice == 3 && board[1] == playerOneSymbol){
                    chosen = 9;
                    thirdMoveDone = true;
                    return true;
                }
                if(firstChoice == 3 && board[5] == playerOneSymbol){
                    chosen = 1;
                    thirdMoveDone = true;
                    return true;
                }
                if(firstChoice == 7 && board[3] == playerOneSymbol){
                    chosen = 9;
                    thirdMoveDone = true;
                    return true;
                }
                if(firstChoice == 7 && board[7] == playerOneSymbol){
                    chosen = 1;
                    thirdMoveDone = true;
                    return true;
                }
                if(firstChoice == 9 && board[5] == playerOneSymbol){
                    chosen = 7;
                    thirdMoveDone = true;
                    return true;
                }
                if(firstChoice == 9 && board[7] == playerOneSymbol){
                    chosen = 3;
                    thirdMoveDone = true;
                    return true;
                }
            }
            //if AI player starts, third move situation is mostly guaranteed to evaluate by blocking opponent doubles/finishing its own
            //if opponent plays very poorly - one situation must be evaluated
            if(board[0] == '\0'){
                chosen = 1;
                thirdMoveDone = true;
                return true;
            }
            else if(board[2] == '\0'){
                chosen = 3;
                thirdMoveDone = true;
                return true;
            }
            else if(board[6] == '\0'){
                chosen = 7;
                thirdMoveDone = true;
                return true;
            }
            else if(board[8] == '\0'){
                chosen = 9;
                thirdMoveDone = true;
                return true;
            }
        }
        else{
            //finish here what AI does when starting second
            /* controlling third move for AI as a second player should not be necessary
             * can be randomized or preventing/finishing doubles functions should do their job
             */
            thirdMoveDone = true;
            return false;
        }
    }

    return false;
}


int aiChoice(bool startingPlayer){
    chosen = 0;
    if(finishDoubleForWin()) return chosen;
    if(preventOpponentDoubles()) return chosen;
    if(firstMove(startingPlayer)) return chosen;
    if(secondMove(startingPlayer)) return chosen;
    if(thirdMove(startingPlayer)) return chosen;

    moveCanBeRandom();
    return chosen;
}

bool finishDoubleForWin(void){
    int toValidateMember = -1, validatingMember = -1;

    for (int i = 0; i < 9; ++i) {
        if(board[i] == playerTwoSymbol){
            toValidateMember = i;
        }
        for (int j = 0; j < 9; ++j) {
            if(board[j] == playerTwoSymbol && j != i){
                validatingMember = j;
            }

            if(toValidateMember != -1 && validatingMember != -1){
                //horizontal
                if(toValidateMember == 0 && validatingMember == 1) if(board[2] == '\0') {
                    chosen = 3;
                    return true;
                }
                if(toValidateMember == 0 && validatingMember == 2) if(board[1] == '\0') {
                    chosen = 2;
                    return true;
                }
                if(toValidateMember == 1 && validatingMember == 2) if(board[0] == '\0') {
                    chosen = 1;
                    return true;
                }
                if(toValidateMember == 3 && validatingMember == 4) if(board[5] == '\0') {
                    chosen = 6;
                    return true;
                }
                if(toValidateMember == 3 && validatingMember == 5) if(board[4] == '\0') {
                    chosen = 5;
                    return true;
                }
                if(toValidateMember == 4 && validatingMember == 5) if(board[3] == '\0') {
                    chosen = 4;
                    return true;
                }
                if(toValidateMember == 6 && validatingMember == 7) if(board[8] == '\0') {
                    chosen = 9;
                    return true;
                }
                if(toValidateMember == 6 && validatingMember == 8) if(board[7] == '\0') {
                    chosen = 8;
                    return true;
                }
                if(toValidateMember == 7 && validatingMember == 8) if(board[6] == '\0') {
                    chosen = 7;
                    return true;
                }

                //diagonal
                if(toValidateMember == 2 && validatingMember == 4) if(board[6] == '\0') {
                    chosen = 7;
                    return true;
                }
                if(toValidateMember == 2 && validatingMember == 6) if(board[4] == '\0') {
                    chosen = 5;
                    return true;
                }
                if(toValidateMember == 4 && validatingMember == 6) if(board[2] == '\0') {
                    chosen = 3;
                    return true;
                }
                if(toValidateMember == 0 && validatingMember == 4) if(board[8] == '\0') {
                    chosen = 9;
                    return true;
                }
                if(toValidateMember == 0 && validatingMember == 8) if(board[4] == '\0') {
                    chosen = 5;
                    return true;
                }
                if(toValidateMember == 4 && validatingMember == 8) if(board[0] == '\0') {
                    chosen = 1;
                    return true;
                }

                //vertical
                if(toValidateMember == 0 && validatingMember == 3) if(board[6] == '\0') {
                    chosen = 7;
                    return true;
                }
                if(toValidateMember == 0 && validatingMember == 6) if(board[3] == '\0') {
                    chosen = 4;
                    return true;
                }
                if(toValidateMember == 3 && validatingMember == 6) if(board[0] == '\0') {
                    chosen = 1;
                    return true;
                }
                if(toValidateMember == 1 && validatingMember == 4) if(board[7] == '\0') {
                    chosen = 8;
                    return true;
                }
                if(toValidateMember == 1 && validatingMember == 7) if(board[4] == '\0') {
                    chosen = 5;
                    return true;
                }
                if(toValidateMember == 4 && validatingMember == 7) if(board[1] == '\0') {
                    chosen = 2;
                    return true;
                }
                if(toValidateMember == 2 && validatingMember == 5) if(board[8] == '\0') {
                    chosen = 9;
                    return true;
                }
                if(toValidateMember == 2 && validatingMember == 8) if(board[5] == '\0') {
                    chosen = 6;
                    return true;
                }
                if(toValidateMember == 5 && validatingMember == 8) if(board[2] == '\0') {
                    chosen = 3;
                    return true;
                }
            }

            validatingMember = -1;
        }

        toValidateMember = -1;
    }

    return false;
}

bool preventOpponentDoubles(void){
    int toValidateMember = -1, validatingMember = -1;

    for (int i = 0; i < 9; ++i) {
        if(board[i] == playerOneSymbol){
            toValidateMember = i;
        }
        for (int j = 0; j < 9; ++j) {
            if(board[j] == playerOneSymbol && j != i){
                validatingMember = j;
            }

            if(toValidateMember != -1 && validatingMember != -1){
                //horizontal
                if(toValidateMember == 0 && validatingMember == 1) if(board[2] == '\0') {
                    chosen = 3;
                    return true;
                }
                if(toValidateMember == 0 && validatingMember == 2) if(board[1] == '\0') {
                    chosen = 2;
                    return true;
                }
                if(toValidateMember == 1 && validatingMember == 2) if(board[0] == '\0') {
                    chosen = 1;
                    return true;
                }
                if(toValidateMember == 3 && validatingMember == 4) if(board[5] == '\0') {
                    chosen = 6;
                    return true;
                }
                if(toValidateMember == 3 && validatingMember == 5) if(board[4] == '\0') {
                    chosen = 5;
                    return true;
                }
                if(toValidateMember == 4 && validatingMember == 5) if(board[3] == '\0') {
                    chosen = 4;
                    return true;
                }
                if(toValidateMember == 6 && validatingMember == 7) if(board[8] == '\0') {
                    chosen = 9;
                    return true;
                }
                if(toValidateMember == 6 && validatingMember == 8) if(board[7] == '\0') {
                    chosen = 8;
                    return true;
                }
                if(toValidateMember == 7 && validatingMember == 8) if(board[6] == '\0') {
                    chosen = 7;
                    return true;
                }

                //diagonal
                if(toValidateMember == 2 && validatingMember == 4) if(board[6] == '\0') {
                    chosen = 7;
                    return true;
                }
                if(toValidateMember == 2 && validatingMember == 6) if(board[4] == '\0') {
                    chosen = 5;
                    return true;
                }
                if(toValidateMember == 4 && validatingMember == 6) if(board[2] == '\0') {
                    chosen = 3;
                    return true;
                }
                if(toValidateMember == 0 && validatingMember == 4) if(board[8] == '\0') {
                    chosen = 9;
                    return true;
                }
                if(toValidateMember == 0 && validatingMember == 8) if(board[4] == '\0') {
                    chosen = 5;
                    return true;
                }
                if(toValidateMember == 4 && validatingMember == 8) if(board[0] == '\0') {
                    chosen = 1;
                    return true;
                }

                //vertical
                if(toValidateMember == 0 && validatingMember == 3) if(board[6] == '\0') {
                    chosen = 7;
                    return true;
                }
                if(toValidateMember == 0 && validatingMember == 6) if(board[3] == '\0') {
                    chosen = 4;
                    return true;
                }
                if(toValidateMember == 3 && validatingMember == 6) if(board[0] == '\0') {
                    chosen = 1;
                    return true;
                }
                if(toValidateMember == 1 && validatingMember == 4) if(board[7] == '\0') {
                    chosen = 8;
                    return true;
                }
                if(toValidateMember == 1 && validatingMember == 7) if(board[4] == '\0') {
                    chosen = 5;
                    return true;
                }
                if(toValidateMember == 4 && validatingMember == 7) if(board[1] == '\0') {
                    chosen = 2;
                    return true;
                }
                if(toValidateMember == 2 && validatingMember == 5) if(board[8] == '\0') {
                    chosen = 9;
                    return true;
                }
                if(toValidateMember == 2 && validatingMember == 8) if(board[5] == '\0') {
                    chosen = 6;
                    return true;
                }
                if(toValidateMember == 5 && validatingMember == 8) if(board[2] == '\0') {
                    chosen = 3;
                    return true;
                }
            }

            validatingMember = -1;
        }

        toValidateMember = -1;
    }

    return false;
}

void moveCanBeRandom(void){
    int tmp;

    do{
        tmp = 1 + rand() % 9;
        if(board[tmp-1] != '\0'){
            tmp = 0;
        }
    } while(tmp == 0);

    chosen = tmp;
}
