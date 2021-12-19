#ifndef _conditions_h_
#define _conditions_h_

#include <stdio.h>
#include <stdbool.h>

extern char playerOneSymbol;
extern char playerTwoSymbol;
//bool startingPlayerAndSymbol(void);
bool startingPlayer(void);
bool victory(char currentPlayerSymbol);
bool draw(void);
int chooseField(bool player, bool version, bool startingPlayerStaticForAI);

#endif
