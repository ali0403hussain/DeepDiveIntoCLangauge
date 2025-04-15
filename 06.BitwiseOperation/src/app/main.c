/**
 * @file main.c
 * 
 * @description Provides examples for Bitwise Operations
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

#include <stdio.h>  //<! Standard c library including printf scanf etc
#include <stdint.h>   //<! Standard c library including types


/**********************************************************
 * Macros
 **********************************************************/

#define BIT(val, bit) (((val) >> (bit)) & 1 ? '1' : '0')

#define PRINT_UINT32_BINARY(val)                           \
     BIT(val, 31), BIT(val, 30), BIT(val, 29), BIT(val, 28),\
     BIT(val, 27), BIT(val, 26), BIT(val, 25), BIT(val, 24),\
     BIT(val, 23), BIT(val, 22), BIT(val, 21), BIT(val, 20),\
     BIT(val, 19), BIT(val, 18), BIT(val, 17), BIT(val, 16),\
     BIT(val, 15), BIT(val, 14), BIT(val, 13), BIT(val, 12),\
     BIT(val, 11), BIT(val, 10), BIT(val, 9),  BIT(val, 8), \
     BIT(val, 7),  BIT(val, 6),  BIT(val, 5),  BIT(val, 4), \
     BIT(val, 3),  BIT(val, 2),  BIT(val, 1),  BIT(val, 0) 

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n"

/**********************************************************
 * Struct, Enums, and Typedef 
 **********************************************************/

/***********************************************************
 * Forward declerations and global variables
 **********************************************************/

/***********************************************************
 * Function Prototype
 **********************************************************/

/**
 * Function to compute bitwise OR opeartion of two numbers
 * 
 * @param ptrNum1 - pointer to number 1
 * @param ptrNum2 - pointer to number 2
 * 
 * @return bitwise or result of 2 numbers
 */
uint32_t compute_bitwiseOR( uint32_t* ptrNum1, uint32_t* ptrNum2 );

/**
 * Function to compute bitwise AND opeartion of two numbers
 * 
 * @param ptrNum1 - pointer to number 1
 * @param ptrNum2 - pointer to number 2
 * 
 * @return bitwise AND result of 2 numbers
 */
uint32_t compute_bitwiseAND( uint32_t* ptrNum1, uint32_t* ptrNum2 );

/**
 * Function to compute bitwise XOR opeartion of two numbers
 * 
 * @param ptrNum1 - pointer to number 1
 * @param ptrNum2 - pointer to number 2
 * 
 * @return bitwise XOR result of 2 numbers
 */
uint32_t compute_bitwiseXOR( uint32_t* ptrNum1, uint32_t* ptrNum2 );

/**
 * Function to shift right a number by x
 * 
 * @param ptrNum - pointer to number 
 * @param ptrShifyBy - pointer to shifyBy value
 * 
 * @return right shifted by number x value.
 */
uint32_t shift_rightByValue( uint32_t* ptrNum, uint8_t* ptrShiftBy );

/**
 * Function to shift left a number by x
 * 
 * @param ptrNum - pointer to number 
 * @param ptrShifyBy - pointer to shifyBy value
 * 
 * @return left shifted by number x value.
 */
uint32_t shift_leftByValue( uint32_t* ptrNum, uint8_t* ptrShiftBy );



/***********************************************************
 * Function Definations
 **********************************************************/

/**
 * Starting (Entry) Point of C program
 * @param -void
 * 
 * @return 0
 */
int main()
{
    uint32_t number1 = 0, 
             number2 = 0,
             bitwiseOR = 0,
             bitwiseAND = 0,
             bitwiseXOR = 0,
             rightShift = 0,
             leftShift = 0;
    uint8_t shiftByValue = 0;

    //  Bitwise OR Example
    printf("Enter 2 Numbers to find their bitwise OR\n");
    scanf("%i \n %i", &number1, &number2 );

    bitwiseOR = compute_bitwiseOR(&number1, &number2);
    printf("Bitwise OR Results:\n");
    printf("%i = ", number1);
    printf( BYTE_TO_BINARY_PATTERN , PRINT_UINT32_BINARY(number1) );
    printf("%i = ", number2);
    printf( BYTE_TO_BINARY_PATTERN , PRINT_UINT32_BINARY(number2) );
    printf("%i = ", bitwiseOR);
    printf( BYTE_TO_BINARY_PATTERN , PRINT_UINT32_BINARY(bitwiseOR) );

    //  Bitwise AND Example
    printf("Enter 2 Numbers to find their bitwise AND\n");
    scanf("%i \n %i", &number1, &number2 );

    bitwiseAND = compute_bitwiseAND(&number1, &number2);
    printf("Bitwise AND Results:\n");
    printf("%i = ", number1);
    printf( BYTE_TO_BINARY_PATTERN , PRINT_UINT32_BINARY(number1) );
    printf("%i = ", number2);
    printf( BYTE_TO_BINARY_PATTERN , PRINT_UINT32_BINARY(number2) );
    printf("%i = ", bitwiseAND);
    printf( BYTE_TO_BINARY_PATTERN , PRINT_UINT32_BINARY(bitwiseAND) );

    //  Bitwise XOR Example
    printf("Enter 2 Numbers to find their bitwise XOR\n");
    scanf("%i \n %i", &number1, &number2 );

    bitwiseXOR = compute_bitwiseXOR(&number1, &number2);
    printf("Bitwise XOR Results:\n");
    printf("%i = ", number1);
    printf( BYTE_TO_BINARY_PATTERN , PRINT_UINT32_BINARY(number1) );
    printf("%i = ", number2);
    printf( BYTE_TO_BINARY_PATTERN , PRINT_UINT32_BINARY(number2) );
    printf("%i = ", bitwiseXOR);
    printf( BYTE_TO_BINARY_PATTERN , PRINT_UINT32_BINARY(bitwiseXOR) );

    //  Right shift Example
    printf("Enter Number and shift by value to shift right\n");
    scanf("%i \n %hhu", &number1, &shiftByValue );

    rightShift = shift_rightByValue(&number1, &shiftByValue);
    printf("Right Shift:\n");
    printf("%i = ", number1);
    printf( BYTE_TO_BINARY_PATTERN , PRINT_UINT32_BINARY(number1) );
    printf("%i => ", shiftByValue);
    printf("Shift by Value\n");
    printf("%i = ", rightShift);
    printf( BYTE_TO_BINARY_PATTERN , PRINT_UINT32_BINARY(rightShift) );

    //  left shift Example
    printf("Enter Number and shift by value to shift left\n");
    scanf("%i \n %hhu", &number1, &shiftByValue );

    leftShift = shift_leftByValue(&number1, &shiftByValue);
    printf("Left Shift:\n");
    printf("%i = ", number1);
    printf( BYTE_TO_BINARY_PATTERN , PRINT_UINT32_BINARY(number1) );
    printf("%i => ", shiftByValue);
    printf("Shift by Value\n");
    printf("%i = ", leftShift);
    printf( BYTE_TO_BINARY_PATTERN , PRINT_UINT32_BINARY(leftShift) );

    return 0;  
}

/**
 * Function to compute bitwise OR opeartion of two numbers
 * 
 * @param ptrNum1 - pointer to number 1
 * @param ptrNum2 - pointer to number 2
 * 
 * @return bitwise or result of 2 numbers
 */
uint32_t compute_bitwiseOR( uint32_t* ptrNum1, uint32_t* ptrNum2 )
{
    return ( *ptrNum1 | *ptrNum2 );
}

/**
 * Function to compute bitwise AND opeartion of two numbers
 * 
 * @param ptrNum1 - pointer to number 1
 * @param ptrNum2 - pointer to number 2
 * 
 * @return bitwise AND result of 2 numbers
 */
uint32_t compute_bitwiseAND( uint32_t* ptrNum1, uint32_t* ptrNum2 )
{
    return ( *ptrNum1 & *ptrNum2 );
}

/**
 * Function to compute bitwise XOR opeartion of two numbers
 * 
 * @param ptrNum1 - pointer to number 1
 * @param ptrNum2 - pointer to number 2
 * 
 * @return bitwise XOR result of 2 numbers
 */
uint32_t compute_bitwiseXOR( uint32_t* ptrNum1, uint32_t* ptrNum2 )
{
    return ( *ptrNum1 ^ *ptrNum2 );
}

/**
 * Function to shift right a number by x
 * 
 * @param ptrNum - pointer to number 
 * @param ptrShifyBy - pointer to shifyBy value
 * 
 * @return right shifted by number x value.
 */
uint32_t shift_rightByValue( uint32_t* ptrNum, uint8_t* ptrShiftBy )
{
    return ( *ptrNum >> *ptrShiftBy );
}

/**
 * Function to shift left a number by x
 * 
 * @param ptrNum - pointer to number 
 * @param ptrShifyBy - pointer to shifyBy value
 * 
 * @return left shifted by number x value.
 */
uint32_t shift_leftByValue( uint32_t* ptrNum, uint8_t* ptrShiftBy )
{
    return ( *ptrNum << *ptrShiftBy );
}