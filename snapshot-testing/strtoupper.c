// This source file implements the function to be tested.

#include <ctype.h>
#include <string.h>

char *uppercase_string(const char *str)
{
    char *copy = strdup(str);
    for (char *c = copy; *c; c++)
    {
        *c = toupper(*c);
    }
    return copy;
}