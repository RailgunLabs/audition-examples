#include <audition.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

char *uppercase_string(const char *str); // This is the function we'll be testing.

struct TestData
{
    char *input;
    char *output;
};

static struct TestData *test_data;
static int test_data_length;

static char *read_file(const char *filename)
{
    // Open the file.
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        return NULL;
    }

    // Get the size of the file.
    fseek(fp, 0L, SEEK_END);
    size_t bufsize = ftell(fp);
    rewind(fp);

    // Allocate a buffer large enough to accommodate the file plus null byte.
    char *buf = malloc(bufsize + 1);

    // Read the contents of the file.
    fread(buf, sizeof(buf[0]), bufsize, fp);
    buf[bufsize] = '\0';

    fclose(fp);
    return buf;
}

static void process_file(void *cb_data, const char *file, bool directory)
{
    char filepath[256];

    // Grab the current test data record.
    struct TestData *td = &test_data[test_data_length];
    test_data_length += 1;

    // Read the input data.
    snprintf(filepath, sizeof(filepath), INPUT_DIR "/%s", file);
    td->input = read_file(filepath);

    // Read the expected output data.
    snprintf(filepath, sizeof(filepath), OUTPUT_DIR "/%s", file);
    td->output = read_file(filepath);
    assert(td->output != NULL); // This code assumes the output file exists!
}

SUITE_SETUP(file_driven)
{
    // Tally the number of files in the test data directory.
    const int file_count = audit_listdir(INPUT_DIR, NULL, NULL);

    // Allocate an array large enough to accommodate all the files;
    // each element of this array represents a file in the test directory.
    test_data = calloc(file_count, sizeof(test_data[0]));

    // Iterate the files of the test data directory again, but read in the test data.
    audit_listdir(INPUT_DIR, NULL, process_file);

    // Set the number of times the test case will be invoked.
    SET_TEST_ITERATIONS(uppercase, file_count);
}

SUITE_TEARDOWN(file_driven)
{
    for (int i = 0; i < test_data_length; i++)
    {
        struct TestData *td = &test_data[i];
        free(td->input);
        free(td->output);
    }
    free(test_data);
}

TEST(file_driven, uppercase, .iterations=DYNAMIC_ITERATIONS)
{
    // Grab the test data for the current iteration.
    const struct TestData *td = &test_data[TEST_ITERATION];

    // Invoke the function being tested.
    char *result = uppercase_string(td->input);

    // Verify the actual result matches the expected result.
    EXPECT_STR_EQ(result, td->output);

    // Cleanup.
    free(result);
}
