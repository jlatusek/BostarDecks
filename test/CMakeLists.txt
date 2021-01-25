cmake_minimum_required(VERSION 3.19)

cmake_policy(SET CMP0048 NEW)

set(TEST_NAME boostardeck_test)

enable_testing()

add_executable(${TEST_NAME}
        main.cpp
        database_test.cpp
        )

conan_target_link_libraries(${TEST_NAME}
        CONAN_PKG::gtest_main
        )

target_link_libraries(
        ${TEST_NAME} ${LIB_NAME}
)

target_link_libraries(${TEST_NAME} ${GTEST_LDFLAGS})
target_compile_options(${TEST_NAME} PUBLIC ${GTEST_CFLAGS})

include(CTest)
add_test(test ${TEST_NAME})