add_executable(sample_tests test_Sample.c)

target_include_directories(sample_tests PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Link with CUnit
find_package(PkgConfig REQUIRED)
pkg_check_modules(CUNIT REQUIRED cunit)
target_include_directories(sample_tests PRIVATE ${CUNIT_INCLUDE_DIRS})
target_link_libraries(sample_tests ${CUNIT_LIBRARIES})

# Register with CTest
add_test(NAME SampleTest COMMAND sample_tests)
