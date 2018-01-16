/************************************************************************
Author: Peter Yetti 
Date:  1/15/18
Description: Specification for Card.hpp
*************************************************************************/

#ifndef DOMINION_CARD_HPP
#define DOMINION_CARD_HPP

#include "dominion.h"

void smithyCard(int currentPlayer, int handPos, struct gameState *state);
void adventurerCard(int currentPlayer, struct gameState *state);
void baronCard(int currentPlayer, int choice1, struct gameState *state);
void minionCard(int currentPlayer, int handPos, int choice1, int choice2, struct gameState *state);
void stewardCard(int currentPlayer, int handPos, int choice1, int choice2, int choice3, struct gameState *state);

#endif //DOMINION_CARD_HPP
