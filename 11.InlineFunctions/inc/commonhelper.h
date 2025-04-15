/**
 * @file commonhelper.h
 * 
 * @description commonhelper library
 * 
 * @author - Ali Hussain
 * @date   - 06-04-2025
 * @email  - ali0403hussain@gmail.com
 * 
 * @copyright (c) 2025 Ali Hussain
 */

/**********************************************************
 * Includes
 **********************************************************/
#include <stdbool.h>


/**********************************************************
 * Macros
 **********************************************************/

 #ifndef COMMON_HELPER_H_INCLUDE
 #define COMMON_HELPER_H_INCLUDE
 
/**********************************************************
 * Struct, Enums, and Typedef 
 **********************************************************/

/***********************************************************
 * Forward declerations and global variables
 **********************************************************/

/***********************************************************
 * Function Prototype
 **********************************************************/ 

/***********************************************************
 * Inline Function Definitions
 ***********************************************************/

/**
 * @brief Inline function for MAX value 
 * 
 * @param num1 1st number to check
 * @param num2 2nd number to check
 * 
 * @return max value
 */
static inline int MAX(int num1, int num2)
{
    return ( num1 > num2 )? num1: num2;
}

/**
 * @brief Inline function for MIN value 
 * 
 * @param num1 1st number to check
 * @param num2 2nd number to check
 * 
 * @return min value
 */
static inline int MIN(int num1, int num2)
{
    return ( num1 < num2 )? num1: num2;
}

/**
 * @brief Inline function for checking if equal numbers  
 * 
 * @param num1 1st number to check
 * @param num2 2nd number to check
 * 
 * @return True if equal values
 */
static inline bool EQUAL(int num1, int num2)
{
    return ( num1 == num2 )? true: false;
}

/**
 * @brief Inline function for clamp   
 * 
 * @param num number to check
 * @param min min value
 * @param nax max value
 * 
 * @return clamp values
 */
static inline int CLAMP(int value, int min, int max)
{
    return ( value > min )? ( ( value < max)? value : max ) : min;
}

/**
 * @brief Inline function for abs   
 * 
 * @param num number to check
 * 
 * @return abs values
 */
static inline int ABS(int value )
{
    return ( value > 0)? value : (value * -1 );
}

/**
 * @brief Inline function for even   
 * 
 * @param num number to check
 * 
 * @return True in case of even number 
 */
static inline bool ISEVEN( int value )
{
    return ( value % 2 == 0 )? true: false;
}

/**
 * @brief Inline function for odd number   
 * 
 * @param num number to check
 * 
 * @return True in case of odd number 
 */
static inline bool ISODD( int value )
{
    return ( value % 2 != 0 )? true: false;
}

/**
 * @brief Inline function for checking if variable is zero 
 * 
 * @param num1 1st number to check
 * 
 * @return True if zero value
 */
static inline bool ISZERO(int num )
{
    return ( num == 0 )? true: false;
}
 
 #endif // COMMON_HELPER_H_INCLUDE
 
 