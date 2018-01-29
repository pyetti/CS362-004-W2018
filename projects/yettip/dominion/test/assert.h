/************************************************************************
Author: Peter Yetti 
Date:  1/23/18
Description: Specification for assert.h
*************************************************************************/

#ifndef DOMINION_ASSERT_H
#define DOMINION_ASSERT_H

void assertA_Equals_B(const void *expected, const void *actual, const char* testName);

void assertA_GreaterThan_B(const void *expected, const void *actual, const char* testName);

void assertTrue(const void *value, const char* testName);

#endif //DOMINION_ASSERT_H
