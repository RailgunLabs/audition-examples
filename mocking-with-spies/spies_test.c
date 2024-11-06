#include <audition.h>
#include <stdio.h>

int add(int x, int y); // The function we want to spy on.

// This function intercepts all calls to the "add" function without
// changing its behavior. In this example the arguments and return
// valule are asserted with the 'EXPECT_EQ' macros, however, in
// real test code you might also (1) record the call count and
// (2) save the arguments/return values to some list for
// verification in the test case.
static int spy_add(int x, int y)
{
    EXPECT_EQ(x, 2);
    EXPECT_EQ(y, 5);

    int result;
    CALL_GET(add, &result, x, y); // Call the original function.

    EXPECT_EQ(result, 7);
    return result;
}

TEST(spies, add)
{
    FAKE(add, spy_add); // Install the spy.

    // In real unit tests the function you're spying on might be
    // deep in the function call hierarchy, but here we'll call
    // it directly for the sake of this example.
    add(2, 5);
}
