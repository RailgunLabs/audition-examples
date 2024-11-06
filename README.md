# Audition Examples

This repository contains examples for the [Audition testing framework](https://github.com/RailgunLabs/audition).
No example exceeds the test limit for the unregistered version of Audition which means you can try them with Audition for free (no purchase necessary).

[![Build Status](https://github.com/RailgunLabs/audition-examples/actions/workflows/build.yml/badge.svg)](https://github.com/RailgunLabs/audition-examples/actions/workflows/build.yml)

The examples include:

* [Minimal Example](https://github.com/RailgunLabs/audition-examples/tree/master/minimal) - One function, one test case (the “Hello, World!” of Audition).
* [Looped Test](https://github.com/RailgunLabs/audition-examples/tree/master/looped) - Repeat one test case multiple times.
* [Test Fixtures](https://github.com/RailgunLabs/audition-examples/tree/master/fixtures) - Define preconditions and postconditions for the runner, suite(s), and test(s).
* [Table Driven Testing](https://github.com/RailgunLabs/audition-examples/tree/master/table-driven) - Drive tests using an array of input data.
* [Capture Standard Streams](https://github.com/RailgunLabs/audition-examples/tree/master/capture-standard-streams) - Capture `stdout` and verify its contents are correct.
* [Simulate Standard Input](https://github.com/RailgunLabs/audition-examples/tree/master/simulate-standard-input) - Simulate `stdin` for code that reads from it.
* [Catch Crashes](https://github.com/RailgunLabs/audition-examples/tree/master/catching-crashes) - Tests that _might_ crash can be executed in a separate address space.
* [Catch Timeouts](https://github.com/RailgunLabs/audition-examples/tree/master/catching-timeouts) - Abort long running or hanging tests by using a test timeout.
* [Death Testing](https://github.com/RailgunLabs/audition-examples/tree/master/death-tests) - Check expected program termination and verify the exit status code.
* [Signal Testing](https://github.com/RailgunLabs/audition-examples/tree/master/catching-signals) - Check if a specific POSIX signal was raised.
* [File-driven Testing](https://github.com/RailgunLabs/audition-examples/tree/master/file-driven) - Drive tests using files from the file system.
* [Snapshot Testing](https://github.com/RailgunLabs/audition-examples/tree/master/snapshot-testing) - Like file-driven testing but generates expected output files at runtime.
* [Static Function Testing](https://github.com/RailgunLabs/audition-examples/tree/master/static-functions) - A strategy for testing static functions.
* [Mocking with Fakes](https://github.com/RailgunLabs/audition-examples/tree/master/mocking-with-fakes) - Mock a function by redirecting calls to it to another function.
* [Mocking with Stubs](https://github.com/RailgunLabs/audition-examples/tree/master/mocking-with-stubs) - Mock a function by having it always return a hard-coded return value.
* [Mocking with Spies](https://github.com/RailgunLabs/audition-examples/tree/master/mocking-with-spies) - Intercept calls to a function without altering its behavior.
* [Selective Mocking](https://github.com/RailgunLabs/audition-examples/tree/master/selective-mocking) - Mock system functions without affecting third-party libraries.

## Building

Use [CMake](https://cmake.org/) to build and run the examples:

```
$ cmake -B build
$ cmake --build build --config Release
$ ctest --test-dir build --output-on-failure -C Release
```

or navigate to each test directory and compile the source files yourself.
I've you're running Linux and you installed Audition with a `.deb` or `.rpm`, then you can use [pkg-config](https://en.wikipedia.org/wiki/Pkg-config) to find the Audition library and header:

```
$ pkg-config audition --libs --cflags
```

## License

This work is dedicated to the public domain.
