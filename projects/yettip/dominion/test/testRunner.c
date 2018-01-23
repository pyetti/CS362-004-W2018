/************************************************************************
Author: Peter Yetti 
Date:  1/22/18
Description: Implementation for testRunner.c
*************************************************************************/

#include <stdio.h>
#include "unittest.h"

int main() {

	struct unittest test1 = {unittest1};
//	struct unittest test2 = {unittest2};
//	struct unittest test3 = {unittest3};
//	struct unittest test4 = {unittest4};

	runner(&test1);
//	runner(&test2);
//	runner(&test3);
//	runner(&test4);
}
