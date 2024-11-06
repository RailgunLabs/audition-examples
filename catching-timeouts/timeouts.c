#include <audition.h>

TEST(foo, bar, .timeout=150 /* Timeout the test after 150 milliseconds. */)
{
    // Try suspending execution for one second. Since the
    // test has a timeout of 150 milliseconds this test
    // will be aborted before the full second elapses.
    audit_sleep(1000);
}
