set(EXE_NAME "QueueImplementation")
set(SRC_FILE main.c)
set(INC_PATH "../../inc" "../lib/linearqueue" "../lib/circularqueue")
add_executable(${EXE_NAME} ${SRC_FILE})
target_link_libraries(${EXE_NAME} ${LIB_QUEUE_LINEAR} ${LIB_QUEUE_CIRCULAR})
target_compile_options(${EXE_NAME} PRIVATE -Werror -Wall -Wextra)