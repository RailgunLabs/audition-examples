// This is a minimal "Hello, World!" example for Audition.
// It demonstrates testing one function with one test case.

#include <audition.h>

TEST(simulate, input, .sandbox=true)
{
    audit_write(stdin, "hello", 5); // Write to standard input.
    audit_close(stdin);             // Indicate end-of-file (EOF).

    // Now invoke some code that reads from stdin.
    // For this example we'll read from the test directly.
    char buf[32];
    fgets(buf, sizeof(buf), stdin);

    // Verify stdin was read successfully.
    ASSERT_STR_EQ(buf, "hello");
}
