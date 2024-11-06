#include <audition.h>

TEST(foo, bar, .sandbox=true /* Catching crashes requires the sandbox. */)
{
    int *ptr = (int *)0xDEADBEEFCAFEBABE;
    *ptr = 123;
}
