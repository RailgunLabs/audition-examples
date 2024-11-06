add_executable(stubs stubs.c stubs_test.c)
add_test(NAME test-stubs COMMAND stubs)
