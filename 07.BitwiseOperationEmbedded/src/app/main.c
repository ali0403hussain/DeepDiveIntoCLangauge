/**
 * @file main.c
 * 
 * @description Provides examples for Bitwise Embedded Operations
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
#include <stdint.h>
#include <bitwise.h>
#include <bool.h>

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
    uint32_t reg = 0b10101010101010101010101010101010;  //< Simulating 32 bit register

    printf("Hello World from Bitwise Embedded Example.\n");

    printf("Set 4th bit of 32 bit register\n");
    printf("Old-value-reg=");
    printf( BYTE_TO_BINARY_PATTERN , PRINT_UINT32_BINARY(reg) );
    printf("\n");

    if ( BITWISE_STATUS_GOOD == Bitwise_setBit( &reg, 4 ) )
    {
        printf("New-value-reg=");
        printf( BYTE_TO_BINARY_PATTERN , PRINT_UINT32_BINARY(reg) );
        printf("\n");
    }
    else
    {
        printf("Error\n");
    }

    printf("Clear 9th bit of 32 bit register\n");
    printf("Old-value-reg=");
    printf( BYTE_TO_BINARY_PATTERN , PRINT_UINT32_BINARY(reg) );
    printf("\n");

    if ( BITWISE_STATUS_GOOD == Bitwise_clearBit( &reg, 9 ) )
    {
        printf("New-value-reg=");
        printf( BYTE_TO_BINARY_PATTERN , PRINT_UINT32_BINARY(reg) );
        printf("\n");
    }
    else
    {
        printf("Error\n");
    }

    printf("Toggle 10th bit of 32 bit register\n");
    printf("Old-value-reg=");
    printf( BYTE_TO_BINARY_PATTERN , PRINT_UINT32_BINARY(reg) );
    printf("\n");

    if ( BITWISE_STATUS_GOOD == Bitwise_toggleBit( &reg, 10 ) )
    {
        printf("New-value-reg=");
        printf( BYTE_TO_BINARY_PATTERN , PRINT_UINT32_BINARY(reg) );
        printf("\n");
    }
    else
    {
        printf("Error\n");
    }

    bool_t bitStatus;

    printf("Checking 12th bit of 32 bit register\n");
    printf("value-reg=");
    printf( BYTE_TO_BINARY_PATTERN , PRINT_UINT32_BINARY(reg) );
    printf("\n");

    if ( BITWISE_STATUS_GOOD == Bitwise_isBitSet( &reg, 12, &bitStatus ) )
    {
        printf("%d bit = %d \n", 12, bitStatus);
    }
    else
    {
        printf("Error\n");
    }

    uint32_t maskValue;
    uint32_t bitMask = 0x3F;

    printf("Masking 1st 6 bits of 32 bit register\n");
    printf("value-reg=");
    printf( BYTE_TO_BINARY_PATTERN , PRINT_UINT32_BINARY(reg) );
    printf("\n");

    if ( BITWISE_STATUS_GOOD == Bitwise_maskBits( &reg, bitMask , &maskValue ) )
    {
        printf("Mask-Value=");
        printf( BYTE_TO_BINARY_PATTERN , PRINT_UINT32_BINARY(maskValue) );
        printf("\n");

    }
    else
    {
        printf("Error\n");
    }

    return 0;  
}

