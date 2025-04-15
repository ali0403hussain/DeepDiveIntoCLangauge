/**
 * @file bitwise.c
 * 
 * @description Provides interfaces for bitwise
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
#include "bitwise.h" 
 
/**********************************************************
 * Macros
 **********************************************************/
 
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
 * @brief Function to set specific bit of 32bit register
 * 
 * @param reg - pointer to 32bit register
 * @param pos - position to write
 * 
 * @return @BitwiseStatusCodes 0 incase of No error 
 *  */ 
BitwiseStatusCodes Bitwise_setBit( volatile uint32_t* reg, uint8_t pos )
{
    BitwiseStatusCodes retValue = BITWISE_STATUS_GOOD;

    if (( NULL == reg ) || ( 31U < pos ))
    {
        retValue = BITWISE_STATUS_ARGUMENT_INVALID;
    }
    else
    {
        *reg |= (1U << pos );
    }

    return retValue;
}

/**
 * @brief Function to clear specific bit of 32bit register
 * 
 * @param reg - pointer to 32bit register
 * @param pos - position to write
 * 
 * @return @BitwiseStatusCodes 0 incase of No error 
 *  */
BitwiseStatusCodes Bitwise_clearBit( volatile uint32_t* reg, uint8_t pos )
{
    BitwiseStatusCodes retValue = BITWISE_STATUS_GOOD;

    if (( NULL == reg ) || ( 31U < pos ))
    {
        retValue = BITWISE_STATUS_ARGUMENT_INVALID;
    }
    else
    {
        *reg &= ~(1U << pos );
    }

    return retValue;
}

/**
 * @brief Function to toggle specific bit of 32bit register
 * 
 * @param reg - pointer to 32bit register
 * @param pos - position to write
 * 
 * @return @BitwiseStatusCodes 0 incase of No error 
 *  */
BitwiseStatusCodes Bitwise_toggleBit( volatile uint32_t* reg, uint8_t pos )
{
    BitwiseStatusCodes retValue = BITWISE_STATUS_GOOD;

    if (( NULL == reg ) || ( 31U < pos ))
    {
        retValue = BITWISE_STATUS_ARGUMENT_INVALID;
    }
    else
    {
        *reg ^= (1U << pos );
    }

    return retValue;
}

/**
 * @brief Function to check if specific bit of 32bit register is set
 * 
 * @param reg - pointer to 32bit register
 * @param pos - position to write
 * @param status - pointer to status variable
 * 
 * @return @BitwiseStatusCodes 0 incase of No error 
 *  */
BitwiseStatusCodes Bitwise_isBitSet( volatile uint32_t* reg, uint8_t pos, bool_t* status )
{
    BitwiseStatusCodes retValue = BITWISE_STATUS_GOOD;

    if (( NULL == reg ) || ( 31U < pos ) || ( NULL == status ))
    {
        retValue = BITWISE_STATUS_ARGUMENT_INVALID;
    }
    else
    {
       *status = ( ( *reg >> pos ) & 1U ) ? True: False;
    }

    return retValue;
}

/**
 * @brief Function to mask specific bits of 32bit register
 * 
 * @param reg - pointer to 32bit register
 * @param mask - mask to read
 * @param maskValue - pointer to the variable for mask value
 * 
 * @return @BitwiseStatusCodes 0 incase of No error 
 *  */
BitwiseStatusCodes Bitwise_maskBits( volatile uint32_t* reg, uint32_t mask , uint32_t* maskValue )
{
    BitwiseStatusCodes retValue = BITWISE_STATUS_GOOD;

    if (( NULL == reg ) || ( NULL == maskValue ))
    {
        retValue = BITWISE_STATUS_ARGUMENT_INVALID;
    }
    else
    {
       *maskValue = (*reg & mask );
    }

    return retValue;
}