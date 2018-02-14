/************************************************************************
Author: Peter Yetti 
Date:  2/13/18
Description: Implementation for randomTestRunner.c
*************************************************************************/

#include "unittest.h"

int main(int argc, char **argv) {
	struct unittest adventurer = {randomtestcard1};
//	struct unittest card2 = {randomtestcard2};
//	struct unittest card3 = {randomtestcard3};

	runner(&adventurer);
//	runner(&card2);
//	runner(&card3);
	return 1;
}
