set(EXE_NAME "StackImplementation")
set(SRC_FILE main.c)
set(INC_PATH "../../inc" "../lib/adc" "../lib/sensor")
add_executable(${EXE_NAME} ${SRC_FILE})
target_link_libraries(${EXE_NAME} ${LIB_STACK})
target_compile_options(${EXE_NAME} PRIVATE -Werror -Wall -Wextra)