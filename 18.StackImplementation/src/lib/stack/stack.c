/**
 * @file stack.c
 * 
 * @description Provides interfaces for sensor
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
#include <stdlib.h>
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
 * @brief Stack loc function Push item
 * 
 * @param object pointer to stack object
 * @param value value to push
 * 
 * @return @StackStatusCodes
 */
static StackStatusCodes loc_Stack_pushItem(Stack *object, int32_t value);

/**
 * @brief Stack local function Pop item
 * 
 * @param object pointer to stack object
 * @param popValue pointer to variable to pop value
 * 
 * @return @StackStatusCodes
 */
static StackStatusCodes loc_Stack_popItem(Stack *object, int32_t *popValue);

/**
 * @brief Stack loc function peek item
 * 
 * @param object pointer to stack object
 * @param peekValue pointer to variable to pop value
 * 
 * @return @StackStatusCodes
 */
static StackStatusCodes loc_Stack_peek(Stack *object, int32_t *peekValue);
 

/***********************************************************
 * Function Definations
 **********************************************************/
/**
 * @brief Stack Init function
 * 
 * @param object pointer to stack object
 * @param size   size for stack
 * 
 * @return @StackStausCodes
 */
StackStatusCodes Stack_init( Stack *object, size_t size )
{
    StackStatusCodes retValue = STACK_STATUS_GOOD;

    if ( NULL == object )
    {
        retValue = STACK_STATUS_ERROR_INSTANCE_INVALID;
    }
    else if ( 0 == size )
    {
        retValue = STACK_STATUS_ERROR_ARGUMENT_INVALID;
    }
    else
    {
        object->size = size;
        object->top = -1;
        object->ptrContainer = (int32_t*)malloc( size * sizeof(int32_t) );

        object->interface.push = &loc_Stack_pushItem;
        object->interface.pop = &loc_Stack_popItem;
        object->interface.peek = &loc_Stack_peek;
    }
    return retValue;
}

/**
 * @brief Stack Init function
 * 
 * @param object pointer to stack object
 * 
 * @return @StackStausCodes
 */
StackStatusCodes Stack_deInit( Stack *object )
{
    StackStatusCodes retValue = STACK_STATUS_GOOD;

    if ( NULL == object )
    {
        retValue = STACK_STATUS_ERROR_INSTANCE_INVALID;
    }
    else
    {
        object->size = 0;
        object->top = -1;
        free( object->ptrContainer );
        object->ptrContainer = NULL;
    }
    return retValue;
}

/**
 * @brief Stack loc function Push item
 * 
 * @param object pointer to stack object
 * @param value value to push
 * 
 * @return @StackStatusCodes
 */
StackStatusCodes loc_Stack_pushItem(Stack *object, int32_t value)
{
    StackStatusCodes retValue = STACK_STATUS_GOOD;

    if ( NULL == object )
    {
        retValue = STACK_STATUS_ERROR_INSTANCE_INVALID;
    }
    else
    {
        if ( false == loc_Stack_isFull( object ) )
        {
            ++object->top;

            object->ptrContainer[ object->top ] = value;
        }
        else
        {
            retValue = STACK_STATUS_ERROR_STACK_FULL;
        }
    }
    return retValue;
}

/**
 * @brief Stack local function Pop item
 * 
 * @param object pointer to stack object
 * @param popValue pointer to variable to pop value
 * 
 * @return @StackStatusCodes
 */
StackStatusCodes loc_Stack_popItem(Stack *object, int32_t *popValue)
{
    StackStatusCodes retValue = STACK_STATUS_GOOD;

    if ( NULL == object )
    {
        retValue = STACK_STATUS_ERROR_INSTANCE_INVALID;
    }
    else if ( NULL == popValue )
    {
        retValue = STACK_STATUS_ERROR_ARGUMENT_INVALID;
    }
    else
    {
        if ( false == loc_Stack_isEmpty( object ) )
        {
            *popValue = object->ptrContainer[ object->top-- ];
        }
        else
        {
            retValue = STACK_STATUS_ERROR_STACK_EMPTY;
        }
    }
    return retValue;
}

/**
 * @brief Stack loc function peek item
 * 
 * @param object pointer to stack object
 * @param peekValue pointer to variable to pop value
 * 
 * @return @StackStatusCodes
 */
StackStatusCodes loc_Stack_peek(Stack *object, int32_t *peekValue)
{
    StackStatusCodes retValue = STACK_STATUS_GOOD;

    if ( NULL == object )
    {
        retValue = STACK_STATUS_ERROR_INSTANCE_INVALID;
    }
    else if ( NULL == peekValue )
    {
        retValue = STACK_STATUS_ERROR_ARGUMENT_INVALID;
    }
    else
    {
        if ( false == loc_Stack_isEmpty( object ) )
        {
            *peekValue = object->ptrContainer[ object->top ];
        }
        else
        {
            retValue = STACK_STATUS_ERROR_STACK_EMPTY;
        }
    }
    return retValue;
}
