/**
 * @file main.c
 * 
 * @description Provides examples related to Recursion
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
#include <stdint.h>  //<! Standard c library including types


/**********************************************************
 * Macros
 **********************************************************/
#define MIN_FACTORIAL_CONST (1U)    //<!Minumim factorial constant


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
 * Function to find factorial of a number using recursion
 * 
 * @param number - int number for factorial
 * 
 * @return factorial of number
 */
uint32_t recursion_findFactorial( uint32_t number );

/**
 * Function to find factorial of a number using NON-recursion
 * 
 * @param number - int number for factorial
 * 
 * @return factorial of number
 */
uint32_t nonrecursion_findFactorial( uint32_t number );

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
    uint32_t number = 0;
    uint32_t recursiveFactorial = 0;
    uint32_t nonrecursiveFactorial = 0;


    printf("Enter number to find factorial\n");
    scanf("%d",&number);

    recursiveFactorial = recursion_findFactorial( number );
    printf("Factorial of number using Recursion %d = %d \n", number, recursiveFactorial );

    nonrecursiveFactorial = nonrecursion_findFactorial( number );
    printf("Factorial of number using Non Recursion %d = %d \n", number, nonrecursiveFactorial );

    return 0;  
}

/**
 * Function to find factorial of a number using recursion
 * 
 * @param number - int number for factorial
 * 
 * @return factorial of number
 */
uint32_t recursion_findFactorial( uint32_t number )
{
    uint32_t factorial = 0;

    if ( 0 == number)
    {
        //Do nothing;
    }
    else if ( (uint32_t)MIN_FACTORIAL_CONST >= number )
    {
        factorial = MIN_FACTORIAL_CONST;
    }
    else
    {
        factorial = number * ( recursion_findFactorial( number - MIN_FACTORIAL_CONST) );
    }
    return factorial;
}

/**
 * Function to find factorial of a number using NON-recursion
 * 
 * @param number - int number for factorial
 * 
 * @return factorial of number
 */
uint32_t nonrecursion_findFactorial( uint32_t number )
{
    uint32_t factorial = 1;

    if ( 0 == number )
    {
        factorial = 0;
    }
    else
    {
        for ( uint32_t alter = number ; alter >= (uint32_t)MIN_FACTORIAL_CONST; alter--)
        {
            factorial *= alter;
        }
    }

    return factorial;
}