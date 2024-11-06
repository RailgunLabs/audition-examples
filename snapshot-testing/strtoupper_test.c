#include <audition.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char *uppercase_string(const char *str); // The function to be tested.

struct TestData
{
    char *input;
    char *snapshot;
    char *snapshot_file;
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
    if (directory)
    {
        return;
    }

    char filepath[256];

    // Grab the current test data record.
    struct TestData *td = &test_data[test_data_length];
    test_data_length += 1;

    // Read the input data.
    snprintf(filepath, sizeof(filepath), DATA_DIR "/%s", file);
    td->input = read_file(filepath);

    // Verify the snapshot directory exists.
    snprintf(filepath, sizeof(filepath), DATA_DIR "/snapshots");
    audit_mkdir(filepath);

    // Read the expected snapshot data.
    snprintf(filepath, sizeof(filepath), DATA_DIR "/snapshots/%s", file);
    td->snapshot = read_file(filepath);
    td->snapshot_file = strdup(filepath);
}

SUITE_SETUP(file_driven)
{
    // Tally the number of files in the test data directory.
    const int file_count = audit_listdir(DATA_DIR, NULL, NULL);

    // Allocate an array large enough to accommodate all the files;
    // each element of this array represents a file in the test directory.
    test_data = calloc(file_count, sizeof(test_data[0]));

    // Iterate the files of the test data directory again, but read in the test data.
    audit_listdir(DATA_DIR, NULL, process_file);

    // Set the number of times the test case will be invoked.
    SET_TEST_ITERATIONS(uppercase, test_data_length);
}

SUITE_TEARDOWN(file_driven)
{
    for (int i = 0; i < test_data_length; i++)
    {
        struct TestData *td = &test_data[i];
        free(td->input);
        free(td->snapshot);
        free(td->snapshot_file);
    }
    free(test_data);
}

TEST(file_driven, uppercase, .iterations=DYNAMIC_ITERATIONS)
{
    // Grab the test data for the current iteration.
    const struct TestData *td = &test_data[TEST_ITERATION];

    // Invoke the function being tested.
    char *result = uppercase_string(td->input);

    // If the snapshot doesn't exist, then generate it otherwise
    // verify it matches the actual results.
    if (td->snapshot == NULL)
    {
        printf("regenerating snapshot: %s\n", td->snapshot_file);
        FILE *fp = fopen(td->snapshot_file, "wb");
        fputs(result, fp);
        fclose(fp);
    }
    else
    {
        EXPECT_STR_EQ(result, td->snapshot);
    }

    // Cleanup.
    free(result);
}
