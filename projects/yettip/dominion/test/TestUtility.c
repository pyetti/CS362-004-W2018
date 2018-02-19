/************************************************************************
Author: Peter Yetti 
Date:  2/18/18
Description: Implementation for TestUtility.c
*************************************************************************/

#include "TestUtility.h"

int cardCountInHand(int player, int card, struct gameState state) {
	int count = 0;

	for (int cardPos = 0; cardPos < 500; ++cardPos) {
		if (state.hand[player][cardPos] == card) {
			count++;
		}
	}

	return count;
}

int getRandomNumberOfPlayers(int maxPlayers, int minPlayers) {
	return rand() % (maxPlayers + 1 - minPlayers) + minPlayers;
}

int getRandomPlayer(int numberOfPlayers) {
	return rand() % (numberOfPlayers);
}