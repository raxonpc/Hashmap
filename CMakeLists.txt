cmake_minimum_required (VERSION 3.10)
project (hash_map)

set (FLAGS -Wall -Wextra -Wpedantic -Werror)
set (SRC Error.c Person.c Hashmap.c)

add_executable (${PROJECT_NAME} main.c ${SRC})
target_compile_options (${PROJECT_NAME} PRIVATE ${FLAGS} -g -O0)

add_executable (${PROJECT_NAME}-error-ut test-error.cpp catch_amalgamated.cpp ${SRC})
add_executable (${PROJECT_NAME}-person-ut test-person.cpp catch_amalgamated.cpp ${SRC})

target_compile_options (${PROJECT_NAME}-error-ut PRIVATE ${FLAGS}
                        ${PROJECT_NAME}-person-ut PRIVATE ${FLAGS}
                        )


enable_testing ()
add_test (NAME error-tests COMMAND ${PROJECT_NAME}-error-ut)
add_test (NAME Person-tests COMMAND ${PROJECT_NAME}-person-ut)
