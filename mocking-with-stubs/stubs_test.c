#include <audition.h>

int add(int x, int y);

TEST(stubs, add)
{
    // Mock the "add" function to always return 42.
    // Note that the original "add" function is never invoked.
    STUB(add, 42);

    const int result = add(1, 2);
    ASSERT_EQ(result, 42);
}
