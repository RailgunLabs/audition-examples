#include <audition.h>
#include <signal.h>

TEST(foo, bar, .signal=SIGTERM /* Expect the test to teterminate with SIGTERM. */)
{
    // Invoke code that is supposed to raise a POSIX signal.
    // For this example we 'raise' the signal directly from the test case.
    raise(SIGTERM);
}
