/**
 * @file bitwise.h
 * 
 * @description bitwise library
 * 
 * @author - Ali Hussain
 * @date   - 08-04-2025
 * @email  - ali0403hussain@gmail.com
 * 
 * @copyright (c) 2025 Ali Hussain
 */


/**********************************************************
 * Macros
 **********************************************************/

#ifndef BITWISE_H_INCLUDE
#define BITWISE_H_INCLUDE

/**********************************************************
 * Includes
 **********************************************************/
#include <stdint.h>
#include "bool.h"

/**********************************************************
 * Struct, Enums, and Typedef 
 **********************************************************/

/**
 * @brief Bitwise Status codes Enum */ 
typedef enum {
    BITWISE_STATUS_GOOD = 0,
    BITWISE_STATUS_ERROR = 1,
    BITWISE_STATUS_ARGUMENT_INVALID = 2
} BitwiseStatusCodes;
 

/***********************************************************
 * Forward declerations and global variables
 **********************************************************/

/***********************************************************
 * Functions Declerations
 **********************************************************/

/**
 * @brief Function to set specific bit of 32bit register
 * 
 * @param reg - pointer to 32bit register
 * @param pos - position to write
 * 
 * @return @BitwiseStatusCodes 0 incase of No error 
 *  */ 
BitwiseStatusCodes Bitwise_setBit( volatile uint32_t* reg, uint8_t pos );  

/**
 * @brief Function to clear specific bit of 32bit register
 * 
 * @param reg - pointer to 32bit register
 * @param pos - position to write
 * 
 * @return @BitwiseStatusCodes 0 incase of No error 
 *  */
BitwiseStatusCodes Bitwise_clearBit( volatile uint32_t* reg, uint8_t pos );

/**
 * @brief Function to toggle specific bit of 32bit register
 * 
 * @param reg - pointer to 32bit register
 * @param pos - position to write
 * 
 * @return @BitwiseStatusCodes 0 incase of No error 
 *  */
BitwiseStatusCodes Bitwise_toggleBit( volatile uint32_t* reg, uint8_t pos );

/**
 * @brief Function to check if specific bit of 32bit register is set
 * 
 * @param reg - pointer to 32bit register
 * @param pos - position to write
 * @param status - pointer to status variable
 * 
 * @return @BitwiseStatusCodes 0 incase of No error 
 *  */
BitwiseStatusCodes Bitwise_isBitSet( volatile uint32_t* reg, uint8_t pos, bool_t* status );

/**
 * @brief Function to mask specific bits of 32bit register
 * 
 * @param reg - pointer to 32bit register
 * @param mask - mask to read
 * @param maskValue - pointer to the variable for mask value
 * 
 * @return @BitwiseStatusCodes 0 incase of No error 
 *  */
BitwiseStatusCodes Bitwise_maskBits( volatile uint32_t* reg, uint32_t mask , uint32_t* maskValue );

#endif // BITWISE_H_INCLUDE
 
 