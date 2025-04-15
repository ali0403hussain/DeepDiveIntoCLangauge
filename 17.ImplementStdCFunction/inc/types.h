/**
 * @file types.h
 * 
 * @description type library
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

#ifndef TYPES_H_INCLUDE
#define TYPES_H_INCLUDE

#define INT8_MAX            ( 127 )
#define INT8_MIN            ( -128 )
#define INT16_MAX           ( 32767 )
#define INT16_MIN           ( -32768 )
#define INT32_MAX           ( 2147483647 )
#define INT32_MIN           ( -2147483648 )
#define INT64_MAX           ( 9223372036854775807 )
#define INT64_MIN           ( -9223372036854775808 )

#define UINT8_MAX           ( 255U )
#define UINT8_MIN           ( 0U )
#define UINT16_MAX          ( 65535U )
#define UINT16_MIN          ( 0U )
#define UINT32_MAX          ( 4294967295U )
#define UINT32_MIN          ( 0U )
#define UINT64_MAX          ( 18446744073709551615U )
#define UINT64_MIN          ( 0U )

#define SIZE_MAX            ( 4294967295U )
#define SIZE_MIN            ( 0U )

/**********************************************************
 * Includes
 **********************************************************/

/**********************************************************
 * Struct, Enums, and Typedef 
 **********************************************************/

typedef enum {
    False = 0,
    True = 1
}bool;

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;
typedef unsigned int size_t;


/***********************************************************
 * Forward declerations and global variables
 **********************************************************/

/***********************************************************
 * Functions Declerations
 **********************************************************/


#endif // TYPES_H_INCLUDE
    
    