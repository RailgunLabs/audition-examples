#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *copy_string(const char *string)
{
    const size_t length = strlen(string) + 1;
    char *copy = malloc(length);
    if (copy == NULL)
    {
        return NULL;
    }
    memcpy(copy, string, length);
    return copy;
}
