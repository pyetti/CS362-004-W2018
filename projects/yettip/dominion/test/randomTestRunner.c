/************************************************************************
Author: Peter Yetti 
Date:  2/13/18
Description: Implementation for randomTestRunner.c
*************************************************************************/

#include "unittest.h"

int main(int argc, char **argv) {
	struct unittest adventurer = {randomtestcard1};
	struct unittest smithy = {randomtestcard2};
	struct unittest baron = {randomtestcard3};

	adventurer.randomTestCount = 1000;
	smithy.randomTestCount = 1000;
	baron.randomTestCount = 1000;

	runner(&adventurer);
	runner(&smithy);
	runner(&baron);
	return 0;
}
