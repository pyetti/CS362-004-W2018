/************************************************************************
Author: Peter Yetti 
Date:  2/14/18
Description: Specification for TestUtility.h
*************************************************************************/

#ifndef DOMINION_TESTUTILITY_H
#define DOMINION_TESTUTILITY_H

#include "../dominion.h"

// utility functions
int cardCountInHand(int player, int card, struct gameState state) {
	int count = 0;

	for (int cardPos = 0; cardPos < 500; ++cardPos) {
		if (state.hand[player][cardPos] == card) {
			count++;
		}
	}

	return count;
}

#endif //DOMINION_TESTUTILITY_H
