#include "gameboard.h"
#include <stdio.h>

//gameboard array
char board[9];

//print gameboard
void showGameBoard(void){
    printf("\n   1   |   2   |   3   \n");
    printSymbol(board[0], board[1], board[2]);
    printf("-------|-------|-------\n");
    printf("   4   |   5   |   6   \n");
    printSymbol(board[3], board[4], board[5]);
    printf("-------|-------|-------\n");
    printf("   7   |   8   |   9   \n");
    printSymbol(board[6], board[7], board[8]);
    printf("\n");
}

//printing gameboard symbol combinations
//done manually due to printf limitations
void printSymbol(char symbol1, char symbol2, char symbol3){
    if(symbol1 == 'X' && symbol2 == 'X' && symbol3 == 'X'){
        printf("  \\ /  |"); printf("  \\ /  |"); printf("  \\ /  \n");
        printf("   X   |"); printf("   X   |"); printf("   X   \n");
        printf("  / \\  |"); printf("  / \\  |"); printf("  / \\  \n");
    }
    else if(symbol1 == 'X' && symbol2 == 'O' && symbol3 == 'O'){
        printf("  \\ /  |"); printf(" /---\\ |"); printf(" /---\\ \n");
        printf("   X   |"); printf(" |   | |"); printf(" |   | \n");
        printf("  / \\  |"); printf(" \\---/ |"); printf(" \\---/ \n");
    }
    else if(symbol1 == 'O' && symbol2 == 'X' && symbol3 == 'O'){
        printf(" /---\\ |");printf("  \\ /  |");printf(" /---\\ \n");
        printf(" |   | |");printf("   X   |");printf(" |   | \n");
        printf(" \\---/ |");printf("  / \\  |");printf(" \\---/ \n");
    }
    else if(symbol1 == 'O' && symbol2 == 'O' && symbol3 == 'X'){
        printf(" /---\\ |");printf(" /---\\ |");printf("  \\ /  \n");
        printf(" |   | |");printf(" |   | |");printf("   X   \n");
        printf(" \\---/ |");printf(" \\---/ |");printf("  / \\  \n");
    }
    else if(symbol1 == 'O' && symbol2 == 'X' && symbol3 == 'X'){
        printf(" /---\\ |");printf("  \\ /  |");printf("  \\ /  \n");
        printf(" |   | |");printf("   X   |");printf("   X   \n");
        printf(" \\---/ |");printf("  / \\  |");printf("  / \\  \n");
    }
    else if(symbol1 == 'X' && symbol2 == 'O' && symbol3 == 'X'){
        printf("  \\ /  |");printf(" /---\\ |");printf("  \\ /  \n");
        printf("   X   |");printf(" |   | |");printf("   X   \n");
        printf("  / \\  |");printf(" \\---/ |");;printf("  / \\  \n");
    }
    else if(symbol1 == 'X' && symbol2 == 'X' && symbol3 == 'O'){
        printf("  \\ /  |");printf("  \\ /  |");printf(" /---\\ \n");
        printf("   X   |");printf("   X   |");printf(" |   | \n");
        printf("  / \\  |");printf("  / \\  |");printf(" \\---/ \n");
    }
    else if(symbol1 == 'X' && symbol2 == '\0' && symbol3 == '\0'){
        printf("  \\ /  |");printf("       |");printf("       \n");
        printf("   X   |");printf("       |");printf("       \n");
        printf("  / \\  |");printf("       |");printf("       \n");
    }
    else if(symbol1 == '\0' && symbol2 == '\0' && symbol3 == 'X'){
        printf("       |");printf("       |");printf("  \\ /  \n");
        printf("       |");printf("       |");printf("   X   \n");
        printf("       |");printf("       |");printf("  / \\  \n");
    }
    else if(symbol1 == '\0' && symbol2 == 'X' && symbol3 == '\0'){
        printf("       |");printf("  \\ /  |");printf("       \n");
        printf("       |");printf("   X   |");printf("       \n");
        printf("       |");printf("  / \\  |");printf("       \n");
    }
    else if(symbol1 == 'X' && symbol2 == '\0' && symbol3 == 'X'){
        printf("  \\ /  |");printf("       |");printf("  \\ /  \n");
        printf("   X   |");printf("       |");printf("   X   \n");
        printf("  / \\  |");printf("       |");printf("  / \\  \n");
    }
    else if(symbol1 == 'X' && symbol2 == 'X' && symbol3 == '\0'){
        printf("  \\ /  |");printf("  \\ /  |");printf("       \n");
        printf("   X   |");printf("   X   |");printf("       \n");
        printf("  / \\  |");printf("  / \\  |");printf("       \n");
    }
    else if(symbol1 == '\0' && symbol2 == 'X' && symbol3 == 'X'){
        printf("       |");printf("  \\ /  |");printf("  \\ /  \n");
        printf("       |");printf("   X   |");printf("   X   \n");
        printf("       |");printf("  / \\  |");printf("  / \\  \n");
    }
    else if(symbol1 == 'O' && symbol2 == '\0' && symbol3 == 'X'){
        printf(" /---\\ |");printf("       |");printf("  \\ /  \n");
        printf(" |   | |");printf("       |");printf("   X   \n");
        printf(" \\---/ |");printf("       |");printf("  / \\  \n");
    }
    else if(symbol1 == 'X' && symbol2 == '\0' && symbol3 == 'O'){
        printf("  \\ /  |");printf("       |");printf(" /---\\ \n");
        printf("   X   |");printf("       |");printf(" |   | \n");
        printf("  / \\  |");printf("       |");printf(" \\---/ \n");
    }
    else if(symbol1 == '\0' && symbol2 == 'O' && symbol3 == 'X'){
        printf("       |");printf(" /---\\ |");printf("  \\ /  \n");
        printf("       |");printf(" |   | |");printf("   X   \n");
        printf("       |");printf(" \\---/ |");printf("  / \\  \n");
    }
    else if(symbol1 == '\0' && symbol2 == 'X' && symbol3 == 'O'){
        printf("       |");printf("  \\ /  |");printf(" /---\\ \n");
        printf("       |");printf("   X   |");printf(" |   | \n");
        printf("       |");printf("  / \\  |");printf(" \\---/ \n");
    }
    else if(symbol1 == 'O' && symbol2 == 'X' && symbol3 == '\0'){
        printf(" /---\\ |");printf("  \\ /  |");printf("       \n");
        printf(" |   | |");printf("   X   |");printf("       \n");
        printf(" \\---/ |");printf("  / \\  |");printf("       \n");
    }
    else if(symbol1 == 'X' && symbol2 == 'O' && symbol3 == '\0'){
        printf("  \\ /  |");printf(" /---\\ |");printf("       \n");
        printf("   X   |");printf(" |   | |");printf("       \n");
        printf("  / \\  |");printf(" \\---/ |");printf("       \n");
    }
    else if(symbol1 == 'O' && symbol2 == 'O' && symbol3 == 'O'){
        printf(" /---\\ |");printf(" /---\\ |");printf(" /---\\ \n");
        printf(" |   | |");printf(" |   | |");printf(" |   | \n");
        printf(" \\---/ |");printf(" \\---/ |");printf(" \\---/ \n");
    }
    else if(symbol1 == 'O' && symbol2 == '\0' && symbol3 == '\0'){
        printf(" /---\\ |");printf("       |");printf("       \n");
        printf(" |   | |");printf("       |");printf("       \n");
        printf(" \\---/ |");printf("       |");printf("       \n");
    }
    else if(symbol1 == '\0' && symbol2 == '\0' && symbol3 == 'O'){
        printf("       |");printf("       |");printf(" /---\\ \n");
        printf("       |");printf("       |");printf(" |   | \n");
        printf("       |");printf("       |");printf(" \\---/ \n");
    }
    else if(symbol1 == '\0' && symbol2 == 'O' && symbol3 == '\0'){
        printf("       |");printf(" /---\\ |");printf("       \n");
        printf("       |");printf(" |   | |");printf("       \n");
        printf("       |");printf(" \\---/ |");printf("       \n");
    }
    else if(symbol1 == 'O' && symbol2 == '\0' && symbol3 == 'O'){
        printf(" /---\\ |");printf("       |");printf(" /---\\ \n");
        printf(" |   | |");printf("       |");printf(" |   | \n");
        printf(" \\---/ |");printf("       |");printf(" \\---/ \n");
    }
    else if(symbol1 == 'O' && symbol2 == 'O' && symbol3 == '\0'){
        printf(" /---\\ |");printf(" /---\\ |");printf("       \n");
        printf(" |   | |");printf(" |   | |");printf("       \n");
        printf(" \\---/ |");printf(" \\---/ |");printf("       \n");
    }
    else if(symbol1 == '\0' && symbol2 == 'O' && symbol3 == 'O'){
        printf("       |");printf(" /---\\ |");printf(" /---\\ \n");
        printf("       |");printf(" |   | |");printf(" |   | \n");
        printf("       |");printf(" \\---/ |");printf(" \\---/ \n");
    }
    else {
        printf("       |"); printf("       |"); printf("       \n");
        printf("       |"); printf("       |"); printf("       \n");
        printf("       |"); printf("       |"); printf("       \n");

    }
}
