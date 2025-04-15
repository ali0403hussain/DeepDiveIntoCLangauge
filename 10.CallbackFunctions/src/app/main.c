/**
 * @file main.c
 * 
 * @description Provides examples for Callback functions
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
#include "calculator.h"


/**********************************************************
 * Macros
 **********************************************************/

/**********************************************************
 * Struct, Enums, and Typedef 
 **********************************************************/

/***********************************************************
 * Forward declerations and global variables
 **********************************************************/

 Calculator calculator;
 Calculator *objectCalculator = &calculator;

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
    int sum = 0, sub = 0, product = 0;
    double div = 0.000;

    if ( CALCULATOR_STATUS_GOOD == Calculator_init ( objectCalculator ) )
    {
        if ( CALCULATOR_STATUS_GOOD ==  objectCalculator->interface.sum( 100, 10000, &sum ) )
        {
            printf("Sum of %d , %d = %d \n", 100, 10000, sum );
        }
        else
        {
            printf("Argument Invalid\n");
        }

        if ( CALCULATOR_STATUS_GOOD ==  objectCalculator->interface.subtraction( 10000, 100, &sub ) )
        {
            printf("Subtraction of %d , %d = %d \n", 10000, 100, sub );
        }
        else
        {
            printf("Argument Invalid\n");
        }

        if ( CALCULATOR_STATUS_GOOD ==  objectCalculator->interface.product( 100, 200, &product ) )
        {
            printf("Product of %d , %d = %d \n", 100, 200, product );
        }
        else
        {
            printf("Argument Invalid\n");
        }

        if ( CALCULATOR_STATUS_GOOD ==  objectCalculator->interface.div( 1024, 111, &div ) )
        {
            printf("Division of %d , %d = %lf \n", 1024, 111, div );
        }
        else
        {
            printf("Argument Invalid\n");
        }
    }
    else
    {
        printf("Instance Invalid\n");
    }

    return 0;  
}
