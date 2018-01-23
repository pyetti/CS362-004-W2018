/************************************************************************
Author: Peter Yetti 
Date:  1/23/18
Description: Implementation for unittest3.c
*************************************************************************/

#import "unittest.h"

static const int run(void) {
	return 3;
}

const struct unittest_vtable_ unittest3[] = { { run } };