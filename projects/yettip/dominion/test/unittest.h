/************************************************************************
Author: Peter Yetti 
Date:  1/22/18
Description: Specification for unittest.h
*************************************************************************/

#ifndef DOMINION_UNITTEST_H
#define DOMINION_UNITTEST_H

#include "TestUtility.h"

int testCount;

struct unittest {
	// make vtable_ a pointer so they can be shared between instances
	// use _ to mark private members
	const struct unittest_vtable_ *vtable_;
	int randomTestCount;
};

struct unittest_vtable_ {
	const int (*run)(void);
};

// wrapper function
static inline const int runner(struct unittest *test) {
	testCount = test->randomTestCount;
	return test->vtable_->run();
}

void setRandomTestCount(int count);

// make the vtables arrays so they can be used as pointers
extern const struct unittest_vtable_ unittest1[], unittest2[], unittest3[], unittest4[],
	card_unittest1[], card_unittest2[], card_unittest3[], card_unittest4[], randomtestcard1[],
		randomtestcard2[], randomtestcard3[], seaHagCardTest[];

#endif //DOMINION_UNITTEST_H
