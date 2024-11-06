#include "static.c" // Include the C source file with the static function.
#include <audition.h>

TEST(static_functions, factorial)
{
    const int result = factorial(5);
    ASSERT_EQ(result, 120);
}
