/**
 * @file linearqueue.c
 * 
 * @description Provides interfaces for linear queue
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
#include <stdio.h>
#include "linearqueue.h" 
 
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
 * @brief function for queue enqueue
 * 
 * @param object pointer to queue object
 * @param element value to Enqueue
 * 
 * @return @LinearQueueStatusCodes
 */
static LinearQueueStatusCodes loc_LinearQueue_enqueue( LinearQueue *object, linearQueue_type element );

/**
 * @brief function for queue dequeue
 * 
 * @param object pointer to queue object
 * @param ptrElement pointer to variable for dequeue
 * 
 * @return @LinearQueueStatusCodes
 */
static LinearQueueStatusCodes loc_LinearQueue_dequeue( LinearQueue *object, linearQueue_type *ptrElement );

/**
 * @brief function for queue peek
 * 
 * @param object pointer to queue object
 * @param ptrElement pointer to variable for peek
 * 
 * @return @LinearQueueStatusCodes
 */
static LinearQueueStatusCodes loc_LinearQueue_peek( LinearQueue *object, linearQueue_type *ptrElement );

/**
 * @brief function for queue IsEmpty
 * 
 * @param object pointer to queue object
 * 
 * @return @LinearQueueStatusCodes
 */
static LinearQueueStatusCodes loc_LinearQueue_isEmpty( LinearQueue *object );

/**
 * @brief function for queue IsFull
 * 
 * @param object pointer to queue object
 * 
 * @return @LinearQueueStatusCodes
 */
static LinearQueueStatusCodes loc_LinearQueue_isFull( LinearQueue *object );

/***********************************************************
 * Function Definations
 **********************************************************/
/**
 * @brief function for Linear queue initialization
 * 
 * @param object pointer to queue object
 * 
 * @return @LinearQueueStatusCodes
 */
LinearQueueStatusCodes LinearQueue_init( LinearQueue *object )
{
    LinearQueueStatusCodes retValue = LINEAR_QUEUE_STATUS_GOOD;

    if ( NULL == object )
    {
        retValue = LINEAR_QUEUE_STATUS_ERROR_INSTANCE_INVALID;
    }
    else
    {
        //Initialize front and rear with -1;
        object->queue.front = -1;
        object->queue.rear = -1;

        //Initialize interfaces
        object->interface.enqueue = &loc_LinearQueue_enqueue;
        object->interface.dequeue = &loc_LinearQueue_dequeue;
        object->interface.peek = &loc_LinearQueue_peek;
        object->interface.isEmpty = &loc_LinearQueue_isEmpty;
        object->interface.isFull = &loc_LinearQueue_isFull;
    }
    return retValue;
}

/**
 * @brief function for queue enqueue
 * 
 * @param object pointer to queue object
 * @param element value to Enqueue
 * 
 * @return @LinearQueueStatusCodes
 */
LinearQueueStatusCodes loc_LinearQueue_enqueue( LinearQueue *object, linearQueue_type element )
{
    LinearQueueStatusCodes retValue = LINEAR_QUEUE_STATUS_GOOD;

    if ( NULL == object )
    {
        retValue = LINEAR_QUEUE_STATUS_ERROR_INSTANCE_INVALID;
    }
    else
    {
        retValue = loc_LinearQueue_isFull( object );

        if ( LINEAR_QUEUE_STATUS_GOOD ==  retValue )
        {
            object->queue.data[ ++object->queue.rear ] = element;
        }
    }
    return retValue;
}

/**
 * @brief function for queue dequeue
 * 
 * @param object pointer to queue object
 * @param ptrElement pointer to variable for dequeue
 * 
 * @return @LinearQueueStatusCodes
 */
LinearQueueStatusCodes loc_LinearQueue_dequeue( LinearQueue *object, linearQueue_type *ptrElement )
{
    LinearQueueStatusCodes retValue = LINEAR_QUEUE_STATUS_GOOD;

    if ( NULL == object )
    {
        retValue = LINEAR_QUEUE_STATUS_ERROR_INSTANCE_INVALID;
    }
    else if ( NULL == ptrElement )
    {
        retValue = LINEAR_QUEUE_STATUS_ERROR_ARGUMENT_INVALID;
    }
    else
    {
        retValue = loc_LinearQueue_isEmpty( object );

        if ( LINEAR_QUEUE_STATUS_GOOD ==  retValue )
        {
            *ptrElement = object->queue.data[ ++object->queue.front ];
        }
    }
    return retValue;
}

/**
 * @brief function for queue peek
 * 
 * @param object pointer to queue object
 * @param ptrElement pointer to variable for peek
 * 
 * @return @LinearQueueStatusCodes
 */
LinearQueueStatusCodes loc_LinearQueue_peek( LinearQueue *object, linearQueue_type *ptrElement )
{
    LinearQueueStatusCodes retValue = LINEAR_QUEUE_STATUS_GOOD;

    if ( NULL == object )
    {
        retValue = LINEAR_QUEUE_STATUS_ERROR_INSTANCE_INVALID;
    }
    else if ( NULL == ptrElement )
    {
        retValue = LINEAR_QUEUE_STATUS_ERROR_ARGUMENT_INVALID;
    }
    else
    {
        retValue = loc_LinearQueue_isEmpty( object );

        if ( LINEAR_QUEUE_STATUS_GOOD ==  retValue )
        {
            *ptrElement = object->queue.data[ object->queue.front + 1];
        }
    }
    return retValue;
}

/**
 * @brief function for queue IsEmpty
 * 
 * @param object pointer to queue object
 * 
 * @return @LinearQueueStatusCodes
 */
LinearQueueStatusCodes loc_LinearQueue_isEmpty( LinearQueue *object )
{
    LinearQueueStatusCodes retValue = LINEAR_QUEUE_STATUS_GOOD;

    if ( NULL == object )
    {
        retValue = LINEAR_QUEUE_STATUS_ERROR_INSTANCE_INVALID;
    }
    else
    {
        if ( object->queue.front == object->queue.rear )
        {
            retValue = LINEAR_QUEUE_STATUS_ERROR_QUEUE_EMPTY;
        }
    }
    return retValue;
}

/**
 * @brief function for queue IsFull
 * 
 * @param object pointer to queue object
 * 
 * @return @LinearQueueStatusCodes
 */
LinearQueueStatusCodes loc_LinearQueue_isFull( LinearQueue *object )
{
    LinearQueueStatusCodes retValue = LINEAR_QUEUE_STATUS_GOOD;

    if ( NULL == object )
    {
        retValue = LINEAR_QUEUE_STATUS_ERROR_INSTANCE_INVALID;
    }
    else
    {
        if ( object->queue.rear == ( LINEAR_QUEUE_SIZE -1 ) )
        {
            retValue = LINEAR_QUEUE_STATUS_ERROR_QUEUE_FULL;
        }
    }
    return retValue;
}