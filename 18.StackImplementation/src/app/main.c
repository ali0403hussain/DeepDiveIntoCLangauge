/**
 * @file main.c
 * 
 * @description Provides examples for ADC Sensors
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
#include <stdint.h>

#include "stack.h"

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
 * Starting (Entry) Point of C program
 * @param -void
 * 
 * @return 0
 */
int main()
{
    StackStatusCodes retValue;

    printf("Hello World Welcome to Stack example in C\n");

    Stack stack;
    Stack *ptrStack = &stack;

    size_t size = 8;

    retValue = Stack_init( ptrStack, size );

    if ( STACK_STATUS_GOOD ==  retValue )
    {
        retValue = ptrStack->interface.push( ptrStack, 0x0D );
        if ( STACK_STATUS_GOOD !=  retValue )
        {
            printf("Error: %u\n", retValue);
        }

        retValue = ptrStack->interface.push( ptrStack, 0x0E );
        if ( STACK_STATUS_GOOD !=  retValue )
        {
            printf("Error: %u\n", retValue);
        }

        retValue = ptrStack->interface.push( ptrStack, 0x0A );
        if ( STACK_STATUS_GOOD !=  retValue )
        {
            printf("Error: %u\n", retValue);
        }

        retValue = ptrStack->interface.push( ptrStack, 0x0D );
        if ( STACK_STATUS_GOOD !=  retValue )
        {
            printf("Error: %u\n", retValue);
        }

        retValue = ptrStack->interface.push( ptrStack, 0x0B );
        if ( STACK_STATUS_GOOD !=  retValue )
        {
            printf("Error: %u\n", retValue);
        }

        retValue = ptrStack->interface.push( ptrStack, 0x0E );
        if ( STACK_STATUS_GOOD !=  retValue )
        {
            printf("Error: %u\n", retValue);
        }

        retValue = ptrStack->interface.push( ptrStack, 0x0E );
        if ( STACK_STATUS_GOOD !=  retValue )
        {
            printf("Error: %u\n", retValue);
        }

        retValue = ptrStack->interface.push( ptrStack, 0x0F );
        if ( STACK_STATUS_GOOD !=  retValue )
        {
            printf("Error: %u\n", retValue);
        }

        retValue = ptrStack->interface.push( ptrStack, 0x0D );
        if ( STACK_STATUS_GOOD !=  retValue )
        {
            printf("Error: %u\n", retValue);
        }
    }
    else
    {
        printf("Error: %u\n", retValue);
    }


    return 0;
}
