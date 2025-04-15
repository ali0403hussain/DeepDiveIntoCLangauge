set(EXE_NAME "StructVsUnion")
set(SRC_FILE main.c)
add_executable(${EXE_NAME} ${SRC_FILE})
target_compile_options(${EXE_NAME} PRIVATE -Werror -Wall -Wextra)