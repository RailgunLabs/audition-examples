#include <audition.h>
#include <stdlib.h>

// Handy macro for computing the number of elements in a static array.
#define countof(array) (sizeof(array) / sizeof(array[0]))

static const struct TestData {
    long input;
    long output;
} test_data[] = {
    { 0, 0 },
    { -7, 7 },
    { 9, 9 },
    { -42, 42 },
    { -123, 123 },
};

TEST(table_driven, abs, .iterations=countof(test_data))
{
    const struct TestData *td = &test_data[TEST_ITERATION];
    const long result = labs(td->input);
    ASSERT_EQ(result, td->output);
}
