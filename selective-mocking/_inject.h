#include <stddef.h> // for size_t

// Replace all calls to malloc() with wrap_malloc() in the source code.
// This change only affects _your_ code and not any 3rd party or
// system libraries. The real malloc() will still be invoked by
// 3rd party code.
#define malloc wrap_malloc

#if defined(WIN32) // Pay attention to compiler linkage!
__declspec(dllexport)
#endif
void *wrap_malloc(size_t size);
