cmake_minimum_required (VERSION 3.10)
project (hash_map)

set (FLAGS -Wall -Wextra -Wpedantic -Werror)
set (SRC Error.c Person.c)

add_executable (${PROJECT_NAME} main.c ${SRC})
target_compile_options (${PROJECT_NAME} PRIVATE ${FLAGS})

add_executable (${PROJECT_NAME}-error-ut test-error.cpp catch_amalgamated.cpp ${SRC})

target_compile_options (${PROJECT_NAME}-error-ut PRIVATE ${FLAGS}
                        )


enable_testing ()
add_test (NAME error-tests COMMAND ${PROJECT_NAME}-error-ut)

