add_executable(catching-crashes crash.c)

add_test(NAME test-catching-crashes COMMAND catching-crashes)
set_property(TEST test-catching-crashes PROPERTY PASS_REGULAR_EXPRESSION "Crash!")
