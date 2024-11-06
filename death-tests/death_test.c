#include <audition.h>
#include <stdlib.h>

TEST(foo, bar, .exit_status=12 /* Expect the test to teterminate with exit status 12. */)
{
    // Invoke code that is supposed to terminate the program with exit status 12.
    // Here we invoke 'exit(12)' directly, but in a real situtation you'd invoke
    // external code that terminates the process.
    exit(12);
}
