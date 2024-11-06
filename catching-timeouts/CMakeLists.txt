add_executable(catching-timeouts timeouts.c)

add_test(NAME test-catching-timeouts COMMAND catching-timeouts)
set_property(TEST test-catching-timeouts PROPERTY PASS_REGULAR_EXPRESSION "Timeout")

