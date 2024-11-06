#include <stdlib.h>

#if defined(WIN32) // Pay attention to compiler linkage!
__declspec(dllexport)
#endif
void *wrap_malloc(size_t size)
{
    return malloc(size);
}
