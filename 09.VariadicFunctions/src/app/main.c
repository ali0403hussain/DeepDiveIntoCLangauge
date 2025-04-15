/**
 * @file main.c
 * 
 * @description Provides examples for Variadic Functions
 * 
 * @author - Ali Hussain
 * @date   - 11-04-2025
 * @email  - ali0403hussain@gmail.com
 * 
 * @copyright (c) 2025 Ali Hussain
 */

/**********************************************************
 * Includes
 **********************************************************/

#include <stdio.h>  //<! Standard c library including printf scanf etc
#include <stdarg.h> //<! Standard c library for variadic functions


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
 * @brief Variadic function to compute sum of n numbers
 * 
 * @param n,... variable number of inputs integers
 * @return sum
 */
int sum_ofIntegers( int n, ...);


/***********************************************************
 * Function Definations
 **********************************************************/

/**
 * @brief Variadic function to compute sum of n numbers
 * 
 * @param n,... variable number of inputs integers
 * @return sum
 */
int sum_ofIntegers( int n, ...)
{
    int sum = 0, alter = 0 ;

    va_list sumArgs;

    va_start( sumArgs, n );

    while ( alter < n )
    {
        sum += va_arg ( sumArgs, int );
        alter++;
    }

    va_end (sumArgs);

    return sum;
}

/**
 * Starting (Entry) Point of C program
 * @param -void
 * 
 * @return 0
 */
int main()
{
    int sum = sum_ofIntegers( 5, 2, 4, 8, 10, 12 );  //<! First input arg is total number of args and then args for sum
    printf("Sum = %d\n", sum );

    return 0;  
}
