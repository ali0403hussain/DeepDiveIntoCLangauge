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
/**
 * @brief Function to pop multiple values
 * 
 * @param object pointer to stack instance
 * @param count no of items to pop
 * 
 * @return void
 */
void popMultipleItems(Stack *object, size_t count);

/***********************************************************
 * Function Definations
 **********************************************************/
/**
 * @brief Function to pop multiple values
 * 
 * @param object pointer to stack instance
 * @param count no of items to pop
 * 
 * @return void
 */
void popMultipleItems(Stack *object, size_t count)
{
    StackStatusCodes retValue;

    int32_t popValue = 0;

    for(size_t alter = 0; alter < count; alter++)
    {
        //pop item
        retValue = object->interface.pop( object, &popValue );
        if ( STACK_STATUS_GOOD !=  retValue )
        {
            printf("Error: %u\n", retValue);
        }
        else
        {
            printf("Pop Value: %#X\n", popValue);
        }
    }
}

/**
 * Starting (Entry) Point of C program
 * @param -void
 * 
 * @return 0
 */
int main()
{
    StackStatusCodes retValue;

    int32_t peekValue = 0, popValue = 0;

    printf("Hello World Welcome to Stack example in C\n");

    Stack stack;
    Stack *ptrStack = &stack;

    size_t size = 8, itemsCount = 0;

    //initialize stack
    retValue = Stack_init( ptrStack, size );

    if ( STACK_STATUS_GOOD ==  retValue )
    {
        //Push item
        retValue = ptrStack->interface.push( ptrStack, 0x0D );
        if ( STACK_STATUS_GOOD !=  retValue )
        {
            printf("Error: %u\n", retValue);
        }

        //Keep track of items pushed/pop
        itemsCount++;

        //Push item
        retValue = ptrStack->interface.push( ptrStack, 0x0E );
        if ( STACK_STATUS_GOOD !=  retValue )
        {
            printf("Error: %u\n", retValue);
        }

        //Keep track of items pushed/pop
        itemsCount++;

        //Push item
        retValue = ptrStack->interface.push( ptrStack, 0x0A );
        if ( STACK_STATUS_GOOD !=  retValue )
        {
            printf("Error: %u\n", retValue);
        }

        //Keep track of items pushed/pop
        itemsCount++;

        //Push item
        retValue = ptrStack->interface.push( ptrStack, 0x0D );
        if ( STACK_STATUS_GOOD !=  retValue )
        {
            printf("Error: %u\n", retValue);
        }

        //Keep track of items pushed/pop
        itemsCount++;

        //Push item
        retValue = ptrStack->interface.push( ptrStack, 0x0B );
        if ( STACK_STATUS_GOOD !=  retValue )
        {
            printf("Error: %u\n", retValue);
        }

        //Keep track of items pushed/pop
        itemsCount++;

        //Push item
        retValue = ptrStack->interface.push( ptrStack, 0x0E );
        if ( STACK_STATUS_GOOD !=  retValue )
        {
            printf("Error: %u\n", retValue);
        }

        //Keep track of items pushed/pop
        itemsCount++;

        //Push item
        retValue = ptrStack->interface.push( ptrStack, 0x0E );
        if ( STACK_STATUS_GOOD !=  retValue )
        {
            printf("Error: %u\n", retValue);
        }

        //Keep track of items pushed/pop
        itemsCount++;

        //Last valid value pushed on stack
        retValue = ptrStack->interface.push( ptrStack, 0x0F );
        if ( STACK_STATUS_GOOD !=  retValue )
        {
            printf("Error: %u\n", retValue);
        }

        //Keep track of items pushed/pop
        itemsCount++;

        //Should throw an error because stack is full
        retValue = ptrStack->interface.push( ptrStack, 0x0D );
        if ( STACK_STATUS_GOOD !=  retValue )
        {
            printf("Error: %u\n", retValue);
        }

        //show peek item
        retValue = ptrStack->interface.peek( ptrStack, &peekValue );
        if ( STACK_STATUS_GOOD !=  retValue )
        {
            printf("Error: %u\n", retValue);
        }
        else
        {
            printf("Peek Value: %#X\n", peekValue);
        }

        //pop item
        retValue = ptrStack->interface.pop( ptrStack, &popValue );
        if ( STACK_STATUS_GOOD !=  retValue )
        {
            printf("Error: %u\n", retValue);
        }
        else
        {
            printf("Pop Value: %#X\n", popValue);
            //Keep track of items pushed/pop
            itemsCount--;
        }

        //show peek item
        retValue = ptrStack->interface.peek( ptrStack, &peekValue );
        if ( STACK_STATUS_GOOD !=  retValue )
        {
            printf("Error: %u\n", retValue);
        }
        else
        {
            printf("Peek Value: %#X\n", peekValue);
        }

        //POP All items on the stack and pass 1 additional count to force an error
        //for empty stack
        popMultipleItems(ptrStack, (itemsCount+1));
    }
    else
    {
        printf("Error: %u\n", retValue);
    }


    return 0;
}
