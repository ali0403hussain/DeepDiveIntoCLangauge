cmake_minimum_required(VERSION 3.22)

set(PROJECT_NAME "Learn-C-Hard-Way")
set(PROJECT_VERSION 1.0.0)

project(
    ${PROJECT_NAME}
    VERSION ${PROJECT_VERSION}
    LANGUAGES C
)

enable_testing()

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(LIB_BITWISE "bitwiseLibrary")
set(LIB_CALCULATOR "CalculatorLibrary")
set(LIB_ADC "ADCLibrary")
set(LIB_TIME "TimeLibrary")
set(LIB_SENSOR "SensorLibrary")
set(LIB_STACK "StackLibrary")

add_subdirectory(01.HelloWorld)
add_subdirectory(02.Basics)
add_subdirectory(03.Recursion)
add_subdirectory(04.IntegerPromotions)
add_subdirectory(05.CreateBoolLib)
add_subdirectory(06.BitwiseOperation)
add_subdirectory(07.BitwiseOperationEmbedded)
add_subdirectory(08.CalculatorUsingSwitch)
add_subdirectory(09.VariadicFunctions)
add_subdirectory(10.CallbackFunctions)
add_subdirectory(11.InLineFunctions)
add_subdirectory(12.Pointers)
add_subdirectory(13.StructVsUnion)
add_subdirectory(14.ADCSensorExample)
add_subdirectory(15.DynamicMemory)
add_subdirectory(16.RandomNoGenerator)
add_subdirectory(17.ImplementStdCFunction)
add_subdirectory(18.StackImplementation)

add_subdirectory(tests)






