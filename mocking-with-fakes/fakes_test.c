#include <audition.h>
#include <stdio.h>

int add(int x, int y); // The function we want to test/mock.

// This is a "fake" implementation of the "add" function that returns
// the multiplication rather than addition of its arguments.
static int fake_add(int x, int y)
{
    return x * y;
}

TEST(fakes, add)
{
    // Mock the "add" function by redirecting calls to "add" to "fake_add".
    FAKE(add, fake_add);

    const int result = add(2, 5);
    ASSERT_EQ(result, 10); // The fake function multiples instead of adds.
}
