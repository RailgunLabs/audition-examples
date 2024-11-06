add_executable(fakes fakes.c fakes_test.c)
add_test(NAME test-fakes COMMAND fakes)
