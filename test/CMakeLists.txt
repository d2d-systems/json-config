include(GoogleTest)

find_package(GTest REQUIRED)
set(TEST_TARGET_NAME ${PROJECT_NAME}_test)

add_executable(${TEST_TARGET_NAME})
target_sources(
        ${TEST_TARGET_NAME} PRIVATE
        get.h
        get-valid_key.cpp
        get-invalid_key.cpp
)
target_link_libraries(
        ${TEST_TARGET_NAME} PRIVATE
        ${PROJECT_NAME}::${PROJECT_NAME}
        GTest::GTest
        gtest_main
)

gtest_discover_tests(${TEST_TARGET_NAME} DISCOVERY_TIMEOUT 60)