add_executable(snapshot-testing strtoupper_test.c strtoupper.c)
target_compile_definitions(snapshot-testing PRIVATE -DDATA_DIR="${CMAKE_CURRENT_SOURCE_DIR}/data")
add_test(NAME test-snapshot-testing COMMAND snapshot-testing)
