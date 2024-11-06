add_executable(file-driven strtoupper_test.c strtoupper.c)
target_compile_definitions(file-driven PRIVATE -DINPUT_DIR="${CMAKE_CURRENT_SOURCE_DIR}/input")
target_compile_definitions(file-driven PRIVATE -DOUTPUT_DIR="${CMAKE_CURRENT_SOURCE_DIR}/output")
add_test(NAME test-file-driven COMMAND file-driven)
