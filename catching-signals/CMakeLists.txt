add_executable(catching-signals signal_test.c)
add_test(NAME test-catching-signals COMMAND catching-signals)
