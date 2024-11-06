cmake_minimum_required(VERSION 3.14)
project(audition-examples VERSION 1.0 LANGUAGES C)

# Disable annoying Microsoft Visual Studio warnings.
if (MSVC)
    add_definitions(-D_CRT_SECURE_NO_DEPRECATE)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    add_definitions(-D_CRT_NONSTDC_NO_WARNINGS)
endif ()

enable_testing() # This allows CTest to be used.

find_package(Audition REQUIRED)

set(CMAKE_C_STANDARD 11) # Audition requires C11 or newer.
include_directories(${AUDITION_INCLUDE_DIR})
link_libraries(${AUDITION_LIBRARY})

add_subdirectory(minimal)
add_subdirectory(looped)
add_subdirectory(fixtures)
add_subdirectory(mocking-with-fakes)
add_subdirectory(mocking-with-stubs)
add_subdirectory(mocking-with-spies)
add_subdirectory(selective-mocking)
add_subdirectory(table-driven)
add_subdirectory(file-driven)
add_subdirectory(catching-crashes)
add_subdirectory(catching-timeouts)
add_subdirectory(snapshot-testing)
add_subdirectory(death-tests)
add_subdirectory(capture-standard-streams)
add_subdirectory(simulate-standard-input)
add_subdirectory(static-functions)
if (NOT WIN32) # Audition only supports catching signals on POSIX systems.
    add_subdirectory(catching-signals)
endif ()
