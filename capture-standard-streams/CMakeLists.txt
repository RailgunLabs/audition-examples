add_executable(capture-standard-streams capture.c)
add_test(NAME test-capture-standard-streams COMMAND capture-standard-streams)
