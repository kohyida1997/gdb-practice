cmake_minimum_required(VERSION 3.22)

project(gdb-practice)

set(CMAKE_COLOR_MAKEFILE ON)

enable_testing()

set(SCAN_PRINT_BUG_BIN scan_print_bug)

# Scan/Print bug
add_executable(scan_print_bug
	${PROJECT_SOURCE_DIR}/scan_print_bug.cpp
)

target_compile_options(${SCAN_PRINT_BUG_BIN} PRIVATE -Wall -Wextra -pedantic -g)