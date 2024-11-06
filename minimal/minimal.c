#include <audition.h>

// This is the function to test.
int factorial(int n)
{
    if (n < 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

// Define a test case named "example" belonging to test
// suite "minimal" to test the factorial function.
TEST(minimal, example)
{
    const int result = factorial(5);
    ASSERT_EQ(result, 120);
}
