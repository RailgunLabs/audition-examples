#include <audition.h>
#include <stdlib.h>
#include "_inject.h"

char *copy_string(const char *string);

// Verify the behavior when malloc succeeds.
TEST(copy_string, happy_path)
{
    char *copy = copy_string("foobar");
    EXPECT_STR_EQ(copy, "foobar");
    free(copy);
}

// Verify the behavior when malloc fails.
TEST(copy_string, out_of_memory)
{
    // Safely mock the wrapper which is only invoked by our code.
    // This prevents third-party code from being affected by our mocks.
    STUB(wrap_malloc, NULL);

    char *copy = copy_string("foobar");
    EXPECT_NULL(copy);
}
