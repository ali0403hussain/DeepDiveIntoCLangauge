/**
 * @file main.c
 * 
 * @description Provides examples for Creating Bool Library
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
#include <stdint.h> //<! Standard c library including data types
#include "bool.h"   //<! Local created bool library


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

/**
 * Function to check if number is Even
 * 
 * @param number - number to find even 
 * 
 * @return bool -True/False
 */
bool_t is_numberEven( uint32_t number );


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
    uint32_t num = 0;

    printf("Enter number to find if even number.\n");
    scanf("%i", &num);

    if ( True == is_numberEven( num ) )
    {
        printf("Entered Number is even\n");
    }
    else
    {
        printf("Entered Number is odd\n");
    }

    return 0;  
}

/**
 * Function to check if number is Even
 * 
 * @param number - number to find even 
 * 
 * @return bool -True/False
 */
bool_t is_numberEven( uint32_t number )
{
    return ( (number % 2) == 0 ) ? True : False ;
}
