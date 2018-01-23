/************************************************************************
Author: Peter Yetti 
Date:  1/22/18
Description: Implementation for unittest2.c
*************************************************************************/

#import "unittest.h"

static const int run(void) {
	return 2;
}

const struct unittest_vtable_ unittest2[] = { { run } };