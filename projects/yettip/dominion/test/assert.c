/************************************************************************
Author: Peter Yetti 
Date:  1/23/18
Description: Implementation for assert.c
*************************************************************************/

#include <stdio.h>
#include "assert.h"

//void print_int(int x) {
//	printf("%d", x);
//}
//
//void print_double(double x) {
//	printf("%f", x);
//}
//
//void print_string(char *x) {
//	printf("%s", x);
//}
//
//void print_char(char x) {
//	printf("%c", x);
//}

#define print(X) _Generic((X),             \
                     float: print_double,  \
                     double: print_double, \
                     default: print_int    \
                 )(X)

void assertA_Equals_B(const void *expected, const void *actual, const char* testName) {
	char *testResult;
	if (expected == actual) {
		testResult = "PASSED";
	} else {
		testResult = "FAILED";
	}
	printf("TEST %s: %s.\n", testResult ,testName);
}

void assertA_GreaterThan_B(const void *expected, const void *actual, const char* testName) {
	char *testResult;
	if (expected > actual) {
		printf("TEST PASSED: %s\n", testName);
	} else {
		printf("TEST FAILED: %s\n", testName);
	}
	printf("TEST %s: %s.\n", testResult ,testName);
}

void assertTrue(const void *value, const char* testName) {
	if (value) {
		printf("TEST PASSED: %s\n", testName);
	} else {
		printf("TEST FAILED: %s\n", testName);
	}
}