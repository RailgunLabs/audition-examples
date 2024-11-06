/*
 *  This work is dedicated to the public domain.
 *  No rights reserved.
 *  http://creativecommons.org/publicdomain/zero/1.0/
 */

// This example repeats the 'abs' test case 10 times.
// The current iteration is obtained with the 'TEST_ITERATION' macro.

#include <audition.h>
#include <stdlib.h>

TEST(looped, abs, .iterations=10)
{
    const long result = labs(-TEST_ITERATION); // pass a negative number to abs()
    ASSERT_EQ(result, TEST_ITERATION); // verify abs() makes it a positive
}
