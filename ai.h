#ifndef _ai_h_
#define _ai_h_

#include <stdio.h>
#include <stdbool.h>

extern int chosen;
extern bool firstMoveDone;
extern bool secondMoveDone;
extern bool thirdMoveDone;
extern int firstChoice;
extern bool specialSituation;
bool firstMove(bool startingPlayer);
bool secondMove(bool startingPlayer);
bool thirdMove(bool startingPlayer);
bool finishDoubleForWin(void);
bool preventOpponentDoubles(void);
void moveCanBeRandom(void);
int aiChoice(bool startingPlayer);

#endif
