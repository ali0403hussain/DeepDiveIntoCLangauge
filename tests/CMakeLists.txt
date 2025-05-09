set(STACK_SRC ${CMAKE_SOURCE_DIR}/18.StackImplementation/src/lib/stack/stack.c)
set(STACK_INC ${CMAKE_SOURCE_DIR}/18.StackImplementation/src/lib/stack)

set(TIME_SRC ${CMAKE_SOURCE_DIR}/14.ADCSensorExample/src/lib/time/time.c)
set(TIME_INC ${CMAKE_SOURCE_DIR}/14.ADCSensorExample/src/lib/time)

set(LINEAR_QUEUE_SRC ${CMAKE_SOURCE_DIR}/19.QueueImplementation/src/lib/linearqueue/linearqueue.c)
set(LINEAR_QUEUE_INC ${CMAKE_SOURCE_DIR}/19.QueueImplementation/src/lib/linearqueue)
set(LINEAR_QUEUE_TYPE_INC ${CMAKE_SOURCE_DIR}/19.QueueImplementation/inc)

set(TYPE_INC ${CMAKE_SOURCE_DIR}/14.ADCSensorExample/inc)

add_executable(sample_tests test_Sample.c)
add_executable(stack_tests test_Stack.c ${STACK_SRC})
add_executable(time_tests test_Time.c ${TIME_SRC})
add_executable(linearqueue_tests test_LinearQueue.c ${LINEAR_QUEUE_SRC})

target_include_directories(stack_tests PRIVATE ${STACK_INC})
target_include_directories(time_tests PRIVATE ${TIME_INC} ${TYPE_INC})
target_include_directories(linearqueue_tests PRIVATE ${LINEAR_QUEUE_INC} ${LINEAR_QUEUE_TYPE_INC})

# Link with CUnit
find_package(PkgConfig REQUIRED)
pkg_check_modules(CUNIT REQUIRED cunit)

foreach(target 
        sample_tests 
        stack_tests
        time_tests
        linearqueue_tests)
    target_include_directories(${target} PRIVATE ${CUNIT_INCLUDE_DIRS})
endforeach()

target_link_libraries(sample_tests ${CUNIT_LIBRARIES})
target_link_libraries(stack_tests ${CUNIT_LIBRARIES})
target_link_libraries(time_tests ${CUNIT_LIBRARIES})
target_link_libraries(linearqueue_tests ${CUNIT_LIBRARIES})

# Register with CTest
foreach(target 
        sample_tests 
        stack_tests
        time_tests
        linearqueue_tests)
    add_test(NAME ${target} COMMAND ${target})
endforeach()