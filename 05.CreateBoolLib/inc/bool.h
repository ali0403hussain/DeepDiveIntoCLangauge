/**
 * @file bool.h
 * 
 * @description Bool library
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

/**********************************************************
 * Macros
 **********************************************************/

#ifndef BOOL_H_INCLUDE
#define BOOL_H_INCLUDE

/**********************************************************
 * Struct, Enums, and Typedef 
 **********************************************************/

 /**
  * Enum representing Bool 
  */
 enum bool_e {
    False = 0, 
    True = 1
};

/***********************************************************
 * Forward declerations and global variables
 **********************************************************/

typedef enum bool_e bool_t;  //<! Forward decleration for bool


#endif // BOOL_H_INCLUDE

