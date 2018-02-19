/************************************************************************
Author: Peter Yetti 
Date:  2/14/18
Description: Specification for TestUtility.h
*************************************************************************/

#ifndef DOMINION_TESTUTILITY_H
#define DOMINION_TESTUTILITY_H

#include "../dominion.h"
#include <stdlib.h>
#include <time.h>

int cardCountInHand(int player, int card, struct gameState state);

int getRandomNumberOfPlayers(int maxPlayers, int minPlayers);

int getRandomPlayer(int numberOfPlayers);

int getRandomChoice(int maxChoice, int minChoice);

#endif //DOMINION_TESTUTILITY_H
