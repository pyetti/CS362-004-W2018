/************************************************************************
Author: Peter Yetti 
Date:  1/23/18
Description: Implementation for unittest4.c
*************************************************************************/

#import "unittest.h"

static const int run(void) {
	return 4;
}

const struct unittest_vtable_ unittest4[] = { { run } };