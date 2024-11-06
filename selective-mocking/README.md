# Selective Mocking

Mocking system functions, like `malloc` or `exit`, can potentially lead to significant problems, especially when those functions are fundamental to the operation of your code and third-party libraries you depend on.
For example:

* **Mocking malloc()** - If you stub malloc to return NULL, any code that relies on dynamic memory allocation will be adversely affected.
* **Mocking exit()** - Implementing a fake for exit that does not terminate the program will cause code expecting exit to terminate to continue executing, resulting in unintended consequences.

Additionally, some compilers may replace specific C standard function calls with their own implementions in the generated assembly code.
For example, at the time of this writing, GCC replaces calls to printf with __printf_chk when optimizations are enabled. In this case mocking printf won't work because it's __printf_chk that is called at runtime!

To safely mock system function it's safest to create a wrapper function for the system function you wish to mock and then mock the wrapper.
For example, if you want to mock `malloc` then wrap it behind a wrapper function and have your application call the wrapper instead of the actual `malloc` function.
Since only your code invokes the `malloc` wrapper, then when you mock the wrapper only your application will be affected.

The example in this repository demonstrates a technique for wrapping all `malloc` function calls.
This technique uses compiler-specific flags to inject a header before all source files.
The header uses prepcoressor directives to replace calls to `malloc` with calls to `wrap_malloc`.
If you're using the Gold (GNU) or lld (LLVM) linkers you can also use the `--wrap` flag to achieve the same result.
Since this flag isn't available for MSVC, the header injection technique is demonstrated here instead.
If you're willing to modify your souce code, then you could call the wrapped function directly without the need for header injection or special compiler flag.
