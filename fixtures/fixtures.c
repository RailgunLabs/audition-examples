#include <audition.h>

RUNNER_SETUP()
{
    puts("Runner setup fixture is invoked.");
}

RUNNER_TEARDOWN()
{
    puts("Runner teardown fixture is invoked.");
}

SUITE_SETUP(bank)
{
    puts("Suite setup fixture is invoked once before any test in a suite execute.");
}

SUITE_TEARDOWN(bank)
{
    puts("Suite teardown fixture is invoked once after all tests in a suite execute.");
}

TEST_SETUP(bank)
{
    puts("Test setup fixture is invoked before each test.");
}

TEST_TEARDOWN(bank)
{
    puts("Test teardown fixture is invoked after each test.");
}

TEST(bank, deposit)
{
    puts("Running 'deposit' test case.");
}

TEST(bank, withdraw)
{
    puts("Running 'withdraw' test case.");
}
