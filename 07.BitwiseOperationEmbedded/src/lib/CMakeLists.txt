set(LIB_SRC bitwise.c)
set(LIB_INC "../../inc")
add_library(${LIB_BITWISE} STATIC ${LIB_SRC})
target_include_directories(${LIB_BITWISE} PUBLIC ${LIB_INC})