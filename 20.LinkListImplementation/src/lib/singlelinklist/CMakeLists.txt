set(SRC_FILE singlelinklist.c)
set(INC_PATH "." "../../../inc")
add_library(${LIB_SINGLE_LINKLIST} STATIC ${SRC_FILE})
target_include_directories(${LIB_SINGLE_LINKLIST} PUBLIC ${INC_PATH})
target_compile_options(${LIB_SINGLE_LINKLIST} PRIVATE -Werror -Wall -Wextra)