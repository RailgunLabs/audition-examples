# Create a library of functions that you want to test.
add_library(foo selective.c)

# Implicitly include the "_inject.h" header before every compilation unit.
if (MSVC)
    target_compile_options(foo PRIVATE "/FI ${CMAKE_CURRENT_SOURCE_DIR}/_inject.h")
else () # GCC and Clang
    target_compile_options(foo PRIVATE "-include${CMAKE_CURRENT_SOURCE_DIR}/_inject.h")
endif ()

# Create a test runner executable that links against the library being tested.
add_executable(selective selective_test.c _inject.c)
target_link_libraries(selective PRIVATE foo)

# Register the test executable with CTest.
add_test(NAME test-selective-mocking COMMAND selective)
