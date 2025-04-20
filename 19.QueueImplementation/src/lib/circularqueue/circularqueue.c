/**
 * @file circularqueue.c
 * 
 * @description Provides interfaces for circular queue
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
#include "circularqueue.h" 
 
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
 * @return @CircularQueueStatusCodes
 */
static CircularQueueStatusCodes loc_CircularQueue_enqueue( CircularQueue *object, circularQueue_type element );

/**
 * @brief function for queue dequeue
 * 
 * @param object pointer to queue object
 * @param ptrElement pointer to variable for dequeue
 * 
 * @return @CircularQueueStatusCodes
 */
static CircularQueueStatusCodes loc_CircularQueue_dequeue( CircularQueue *object, circularQueue_type *ptrElement );

/**
 * @brief function for queue peek
 * 
 * @param object pointer to queue object
 * @param ptrElement pointer to variable for peek
 * 
 * @return @CircularQueueStatusCodes
 */
static CircularQueueStatusCodes loc_CircularQueue_peek( CircularQueue *object, circularQueue_type *ptrElement );

/**
 * @brief function for queue IsEmpty
 * 
 * @param object pointer to queue object
 * 
 * @return @CircularQueueStatusCodes
 */
static CircularQueueStatusCodes loc_CircularQueue_isEmpty( CircularQueue *object );

/**
 * @brief function for queue IsFull
 * 
 * @param object pointer to queue object
 * 
 * @return @CircularQueueStatusCodes
 */
static CircularQueueStatusCodes loc_CircularQueue_isFull( CircularQueue *object );

/***********************************************************
 * Function Definations
 **********************************************************/
/**
 * @brief function for Circular queue initialization
 * 
 * @param object pointer to queue object
 * @param size size of queue
 * 
 * @return @CircularQueueStatusCodes
 */
CircularQueueStatusCodes CircularQueue_init( CircularQueue *object, size_t size )
{
    CircularQueueStatusCodes retValue = CIRCULAR_QUEUE_STATUS_GOOD;

    if ( NULL == object )
    {
        retValue = CIRCULAR_QUEUE_STATUS_ERROR_INSTANCE_INVALID;
    }
    else
    {
        //Initialize front and rear with -1;
        object->queue.front = -1;
        object->queue.rear = -1;
        object->queue.filledSize = 0;

        object->queue.sizeQueue = size;

        //Dynamic memory allocation
        object->queue.ptrContainer = (circularQueue_type*)malloc( size * sizeof(circularQueue_type) );

        //Initialize interfaces
        object->interface.enqueue = &loc_CircularQueue_enqueue;
        object->interface.dequeue = &loc_CircularQueue_dequeue;
        object->interface.peek = &loc_CircularQueue_peek;
        object->interface.isEmpty = &loc_CircularQueue_isEmpty;
        object->interface.isFull = &loc_CircularQueue_isFull;
    }

    return retValue;
}

/**
 * @brief function for Circular queue de initialization
 * 
 * @param object pointer to queue object
 * 
 * @return @CircularQueueStatusCodes
 */
CircularQueueStatusCodes CircularQueue_deInit( CircularQueue *object )
{
    CircularQueueStatusCodes retValue = CIRCULAR_QUEUE_STATUS_GOOD;

    if ( NULL == object )
    {
        retValue = CIRCULAR_QUEUE_STATUS_ERROR_INSTANCE_INVALID;
    }
    else
    {
        //Free Dynamic memory allocation
        free( object->queue.ptrContainer );
        
        object->queue.ptrContainer = NULL;
    }

    return retValue;
}

/**
 * @brief function for queue enqueue
 * 
 * @param object pointer to queue object
 * @param element value to Enqueue
 * 
 * @return @CircularQueueStatusCodes
 */
CircularQueueStatusCodes loc_CircularQueue_enqueue( CircularQueue *object, circularQueue_type element )
{
    CircularQueueStatusCodes retValue = CIRCULAR_QUEUE_STATUS_GOOD;

    if ( NULL == object )
    {
        retValue = CIRCULAR_QUEUE_STATUS_ERROR_INSTANCE_INVALID;
    }
    else
    {
        retValue = loc_CircularQueue_isFull( object );

        if ( CIRCULAR_QUEUE_STATUS_GOOD ==  retValue )
        {
            object->queue.rear = ( ( object->queue.rear + 1 ) % object->queue.sizeQueue);
            object->queue.ptrContainer[ object->queue.rear ] = element;
            object->queue.filledSize++;
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
 * @return @CircularQueueStatusCodes
 */
CircularQueueStatusCodes loc_CircularQueue_dequeue( CircularQueue *object, circularQueue_type *ptrElement )
{
    CircularQueueStatusCodes retValue = CIRCULAR_QUEUE_STATUS_GOOD;

    if ( NULL == object )
    {
        retValue = CIRCULAR_QUEUE_STATUS_ERROR_INSTANCE_INVALID;
    }
    else if ( NULL == ptrElement )
    {
        retValue = CIRCULAR_QUEUE_STATUS_ERROR_ARGUMENT_INVALID;
    }
    else
    {
        retValue = loc_CircularQueue_isEmpty( object );

        if ( CIRCULAR_QUEUE_STATUS_GOOD == retValue )
        {
            object->queue.front = ( ( object->queue.front + 1 ) % object->queue.sizeQueue );
            *ptrElement = object->queue.ptrContainer[ object->queue.front ];
            object->queue.filledSize--;
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
 * @return @CircularQueueStatusCodes
 */
CircularQueueStatusCodes loc_CircularQueue_peek( CircularQueue *object, circularQueue_type *ptrElement )
{
    CircularQueueStatusCodes retValue = CIRCULAR_QUEUE_STATUS_GOOD;

    if ( NULL == object )
    {
        retValue = CIRCULAR_QUEUE_STATUS_ERROR_INSTANCE_INVALID;
    }
    else if ( NULL == ptrElement )
    {
        retValue = CIRCULAR_QUEUE_STATUS_ERROR_ARGUMENT_INVALID;
    }
    else
    {
        retValue = loc_CircularQueue_isEmpty( object );

        if ( CIRCULAR_QUEUE_STATUS_GOOD == retValue )
        {
            int peekIndex = ( ( object->queue.front + 1 ) % object->queue.sizeQueue );
            *ptrElement = object->queue.ptrContainer[ peekIndex ];
        }
    }

    return retValue;
}

/**
 * @brief function for queue IsEmpty
 * 
 * @param object pointer to queue object
 * 
 * @return @CircularQueueStatusCodes
 */
CircularQueueStatusCodes loc_CircularQueue_isEmpty( CircularQueue *object )
{
    CircularQueueStatusCodes retValue = CIRCULAR_QUEUE_STATUS_GOOD;

    if ( NULL == object )
    {
        retValue = CIRCULAR_QUEUE_STATUS_ERROR_INSTANCE_INVALID;
    }
    else
    {
        if ( object->queue.filledSize == 0 )
        {
            retValue = CIRCULAR_QUEUE_STATUS_ERROR_QUEUE_EMPTY;
        }
    }

    return retValue;
}

/**
 * @brief function for queue IsFull
 * 
 * @param object pointer to queue object
 * 
 * @return @CircularQueueStatusCodes
 */
CircularQueueStatusCodes loc_CircularQueue_isFull( CircularQueue *object )
{
    CircularQueueStatusCodes retValue = CIRCULAR_QUEUE_STATUS_GOOD;

    if ( NULL == object )
    {
        retValue = CIRCULAR_QUEUE_STATUS_ERROR_INSTANCE_INVALID;
    }
    else
    {
        if ( object->queue.filledSize == object->queue.sizeQueue )
        {
            retValue = CIRCULAR_QUEUE_STATUS_ERROR_QUEUE_FULL;
        }
    }

    return retValue;
}