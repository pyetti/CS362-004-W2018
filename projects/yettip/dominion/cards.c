/************************************************************************
Author: Peter Yetti 
Date:  1/15/18
Description: Implementation for Card.hpp
*************************************************************************/

#include <stdio.h>
#include "cards.h"
#include "dominion_helpers.h"

void smithyCard(int currentPlayer, int handPos, struct gameState *state) {
	//+3 Cards
	int i;
	// TODO introduced bug: added <= instead of <
	for (i = 0; i <= 3; i++) {
		drawCard(currentPlayer, state);
	}

	//discard card from hand
	// TODO introduced bug: reversed handPos and currentPlayer
	discardCard(currentPlayer, handPos, state, 0);
}

void adventurerCard(int currentPlayer, struct gameState *state) {
	int drawnTreasure = 0;
	int cardDrawn;
	int counterForTempHand = 0;
	int tempHand[MAX_HAND];// moved above the if statement

	// TODO introduced bug: increased Treasure size for Adventurer from 2 to 4
	while (drawnTreasure < 4) {
		if (state->deckCount[currentPlayer] < 1) {//if the deck is empty we need to shuffle discard and add to deck
			shuffle(currentPlayer, state);
		}
		drawCard(currentPlayer, state);
		cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer] - 1];//top card of hand is most recently drawn card.
		// TODO introduced bug: not checking for silver or gold card
		if (cardDrawn == copper /**|| cardDrawn == silver || cardDrawn == gold**/)
			drawnTreasure++;
		else {
			tempHand[counterForTempHand] = cardDrawn;
			state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
			counterForTempHand++;
		}
	}
	while (counterForTempHand - 1 >= 0) {
		state->discard[currentPlayer][state->discardCount[currentPlayer]++] = tempHand[counterForTempHand - 1]; // discard all cards in play that have been drawn
		counterForTempHand = counterForTempHand - 1;
	}
}

void baronCard(int currentPlayer, int choice1, struct gameState *state) {
	state->numBuys++;//Increase buys by 1!

	if (choice1 > 0) {//Boolean true or going to discard an estate
		int iteratorForHand = 0;
		int card_not_discarded = 1;//Flag for discard set!

		while (card_not_discarded) {
			if (state->hand[currentPlayer][iteratorForHand] == estate) {//Found an estate card!
				state->coins += 4;//Add 4 coins to the amount of coins
				state->discard[currentPlayer][state->discardCount[currentPlayer]] = state->hand[currentPlayer][iteratorForHand];
				state->discardCount[currentPlayer]++;
				for (; iteratorForHand < state->handCount[currentPlayer]; iteratorForHand++) {
					state->hand[currentPlayer][iteratorForHand] = state->hand[currentPlayer][iteratorForHand + 1];
				}
				state->hand[currentPlayer][state->handCount[currentPlayer]] = -1;
				state->handCount[currentPlayer]--;
				card_not_discarded = 0;//Exit the loop
			} else if (iteratorForHand > state->handCount[currentPlayer]) {
				if (DEBUG) {
					printf("No estate cards in your hand, invalid choice\n");
					printf("Must gain an estate if there are any\n");
				}
				if (supplyCount(estate, state) > 0) {
					gainCard(estate, state, 0, currentPlayer);
					state->supplyCount[estate]--;//Decrement estates
					if (supplyCount(estate, state) == 0) {
						isGameOver(state);
					}
				}
				card_not_discarded = 0;//Exit the loop
			} else {
				iteratorForHand++;//Next card
			}
		}
	} else {
		if (supplyCount(estate, state) > 0) {
			gainCard(estate, state, 0, currentPlayer);//Gain an estate
			state->supplyCount[estate]--;//Decrement Estates
			// TODO introduced bug: not checking if game is over after discarding an estate
//			if (supplyCount(estate, state) == 0) {
//				isGameOver(state);
//			}
		}
	}
}

void minionCard(int currentPlayer, int handPos, int choice1, int choice2, struct gameState *state) {
	//+1 action
	state->numActions++;
	int i, j;

	// TODO introduced bug: commented out discardCard from hand
	//discard card from hand
//	discardCard(handPos, currentPlayer, state, 0);

	if (choice1) { //+2 coins
		state->coins = state->coins + 2;
	} else if (choice2) { //discard hand, redraw 4, other players with 5+ cards discard hand and draw 4
		//discard hand
		while (numHandCards(state) > 0) {
			discardCard(handPos, currentPlayer, state, 0);
		}

		//draw 4
		for (i = 0; i < 4; i++) {
			drawCard(currentPlayer, state);
		}

		//other players discard hand and redraw if hand size > 4
		for (i = 0; i < state->numPlayers; i++) {
			// TODO introduced bug: not checking for current player before discarding and redrawing cards
//			if (i != currentPlayer) {
				if (state->handCount[i] > 4) {
					//discard hand
					while (state->handCount[i] > 0) {
						discardCard(handPos, i, state, 0);
					}

					//draw 4
					for (j = 0; j < 4; j++) {
						drawCard(i, state);
					}
				}
			}
//		}

	}
}

void stewardCard(int currentPlayer, int handPos, int choice1, int choice2, int choice3, struct gameState *state) {
	if (choice1 == 1) {
		//+2 cards
		drawCard(currentPlayer, state);
		drawCard(currentPlayer, state);
	} else if (choice1 == 2) {
		//+2 coins
		state->coins = state->coins + 2;
	} else {
		//trash 2 cards in hand
		discardCard(choice2, currentPlayer, state, 1);
		discardCard(choice3, currentPlayer, state, 1);
	}

	//discard card from hand
	discardCard(handPos, currentPlayer, state, 0);
}

void seaHagCard(int currentPlayer, struct gameState *state) {
	int i;
	for (i = 0; i < state->numPlayers; i++) {
		if (i != currentPlayer) {
			state->discard[i][state->discardCount[i]] = state->deck[i][state->deckCount[i]--];
			state->deckCount[i]--;
			state->discardCount[i]++;
			state->deck[i][state->deckCount[i]--] = curse;//Top card now a curse
		}
	}
}