#include <audition.h>
#include <stdio.h>

TEST(capture, streams, .sandbox=true /* capturing standard streams requires the sandbox. */)
{
    // Begin testing some code that prints to stdout or stderr.
    // For this example we'll print from the test directly.
    fprintf(stdout, "Hello, World!");

    // In this test we'll read from stdout, but you can also read from stderr.
    char buf[32] = {0};
    const int buflen = audit_read(stdout, buf, sizeof(buf));

    // Verify the code being tested printed what we expected.
    ASSERT_EQ(buflen, 13);
    ASSERT_STR_EQ(buf, "Hello, World!");
}
