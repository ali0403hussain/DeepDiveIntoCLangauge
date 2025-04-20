/**
 * @file main.c
 * 
 * @description Provides examples for Queue Example
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
#include "types.h"

#include "linearqueue.h"
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
LinearQueue linearQueue;
LinearQueue *ptrLinearQueue = &linearQueue;

CircularQueue circularQueue;
CircularQueue *ptrCircularQueue = &circularQueue;

/***********************************************************
 * Function Prototype
 **********************************************************/
/**
 * @brief function to execute linear queue operations
 * 
 * @param void
 * 
 * @return void
 */
void LinearQueueOperations(void);

/**
 * @brief function to execute circular queue operations
 * 
 * @param void
 * 
 * @return void
 */
void CircularQueueOperations(void);

/**
 * @brief function to execute circular queue operations
 * 
 * @param ptrArray pointer to array
 * @param size size of array
 * 
 * @return void
 */
void CircularQueueEnqueueOpt( circularQueue_type *ptrArray, size_t size );

/**
 * @brief function to execute circular queue dequeue operations
 * 
 * @param size size of array
 * 
 * @return void
 */
void CircularQueueDequeueOpt( size_t size );

/***********************************************************
 * Function Definations
 **********************************************************/
/**
 * @brief function to execute linear queue operations
 * 
 * @param void
 * 
 * @return void
 */
void LinearQueueOperations(void)
{
    LinearQueueStatusCodes errorCode;

    linearQueue_type elementToEnqueue = 0;
    linearQueue_type elementToDequeue = 0;

    errorCode = LinearQueue_init( ptrLinearQueue );

    if ( LINEAR_QUEUE_STATUS_GOOD ==  errorCode )
    {
        elementToEnqueue = 100;
        printf("Enqueue Element: %d \n", elementToEnqueue);
        errorCode = ptrLinearQueue->interface.enqueue (ptrLinearQueue, elementToEnqueue);
        if ( LINEAR_QUEUE_STATUS_GOOD !=  errorCode)
        {
            printf("Error while enque element : %d, Error:%d \n", elementToEnqueue, errorCode);
        }

        elementToEnqueue = 200;
        printf("Enqueue Element: %d \n", elementToEnqueue);
        errorCode = ptrLinearQueue->interface.enqueue (ptrLinearQueue, elementToEnqueue);
        if ( LINEAR_QUEUE_STATUS_GOOD !=  errorCode)
        {
            printf("Error while enque element : %d, Error:%d \n", elementToEnqueue, errorCode);
        }

        elementToEnqueue = 300;
        printf("Enqueue Element: %d \n", elementToEnqueue);
        errorCode = ptrLinearQueue->interface.enqueue (ptrLinearQueue, elementToEnqueue);
        if ( LINEAR_QUEUE_STATUS_GOOD !=  errorCode)
        {
            printf("Error while enque element : %d, Error:%d \n", elementToEnqueue, errorCode);
        }

        elementToEnqueue = 400;
        printf("Enqueue Element: %d \n", elementToEnqueue);
        errorCode = ptrLinearQueue->interface.enqueue (ptrLinearQueue, elementToEnqueue);
        if ( LINEAR_QUEUE_STATUS_GOOD !=  errorCode)
        {
            printf("Error while enque element : %d, Error:%d \n", elementToEnqueue, errorCode);
        }

        elementToEnqueue = 500;
        printf("Enqueue Element: %d \n", elementToEnqueue);
        errorCode = ptrLinearQueue->interface.enqueue (ptrLinearQueue, elementToEnqueue);
        if ( LINEAR_QUEUE_STATUS_GOOD !=  errorCode)
        {
            printf("Error while enque element : %d, Error:%d \n", elementToEnqueue, errorCode);
        }

        //Force error because queue is full now
        elementToEnqueue = 600;
        printf("Enqueue Element: %d \n", elementToEnqueue);
        errorCode = ptrLinearQueue->interface.enqueue (ptrLinearQueue, elementToEnqueue);
        if ( LINEAR_QUEUE_STATUS_GOOD !=  errorCode)
        {
            printf("Error while enque element : %d, Error:%d \n", elementToEnqueue, errorCode);
        }

        /******************************************************************************** */
        //Check peek item
        errorCode = ptrLinearQueue->interface.peek (ptrLinearQueue, &elementToDequeue);
        if ( LINEAR_QUEUE_STATUS_GOOD !=  errorCode)
        {
            printf("Error while peek element Error:%d \n",errorCode);
        }
        else
        {
            printf("Peek Element: %d \n", elementToDequeue);
        }

        //Dequeue item
        errorCode = ptrLinearQueue->interface.dequeue(ptrLinearQueue, &elementToDequeue);
        if ( LINEAR_QUEUE_STATUS_GOOD !=  errorCode)
        {
            printf("Error while deque element Error:%d \n",errorCode);
        }
        else
        {
            printf("Dequeue Element: %d \n", elementToDequeue);
        }

        /******************************************************************************** */
        //Check peek item
        errorCode = ptrLinearQueue->interface.peek (ptrLinearQueue, &elementToDequeue);
        if ( LINEAR_QUEUE_STATUS_GOOD !=  errorCode)
        {
            printf("Error while peek element Error:%d \n",errorCode);
        }
        else
        {
            printf("Peek Element: %d \n", elementToDequeue);
        }

        //Dequeue item
        errorCode = ptrLinearQueue->interface.dequeue(ptrLinearQueue, &elementToDequeue);
        if ( LINEAR_QUEUE_STATUS_GOOD !=  errorCode)
        {
            printf("Error while deque element Error:%d \n",errorCode);
        }
        else
        {
            printf("Dequeue Element: %d \n", elementToDequeue);
        }

        /******************************************************************************** */
        //Check peek item
        errorCode = ptrLinearQueue->interface.peek (ptrLinearQueue, &elementToDequeue);
        if ( LINEAR_QUEUE_STATUS_GOOD !=  errorCode)
        {
            printf("Error while peek element Error:%d \n",errorCode);
        }
        else
        {
            printf("Peek Element: %d \n", elementToDequeue);
        }

        //Dequeue item
        errorCode = ptrLinearQueue->interface.dequeue(ptrLinearQueue, &elementToDequeue);
        if ( LINEAR_QUEUE_STATUS_GOOD !=  errorCode)
        {
            printf("Error while deque element Error:%d \n",errorCode);
        }
        else
        {
            printf("Dequeue Element: %d \n", elementToDequeue);
        }

        /******************************************************************************** */
        //Check peek item
        errorCode = ptrLinearQueue->interface.peek (ptrLinearQueue, &elementToDequeue);
        if ( LINEAR_QUEUE_STATUS_GOOD !=  errorCode)
        {
            printf("Error while peek element Error:%d \n",errorCode);
        }
        else
        {
            printf("Peek Element: %d \n", elementToDequeue);
        }

        //Dequeue item
        errorCode = ptrLinearQueue->interface.dequeue(ptrLinearQueue, &elementToDequeue);
        if ( LINEAR_QUEUE_STATUS_GOOD !=  errorCode)
        {
            printf("Error while deque element Error:%d \n",errorCode);
        }
        else
        {
            printf("Dequeue Element: %d \n", elementToDequeue);
        }

        /******************************************************************************** */
        //Check peek item
        errorCode = ptrLinearQueue->interface.peek (ptrLinearQueue, &elementToDequeue);
        if ( LINEAR_QUEUE_STATUS_GOOD !=  errorCode)
        {
            printf("Error while peek element Error:%d \n",errorCode);
        }
        else
        {
            printf("Peek Element: %d \n", elementToDequeue);
        }

        //Dequeue item
        errorCode = ptrLinearQueue->interface.dequeue(ptrLinearQueue, &elementToDequeue);
        if ( LINEAR_QUEUE_STATUS_GOOD !=  errorCode)
        {
            printf("Error while deque element Error:%d \n",errorCode);
        }
        else
        {
            printf("Dequeue Element: %d \n", elementToDequeue);
        }

        /****************************Forcing Error************************************** */
        //Check peek item
        errorCode = ptrLinearQueue->interface.peek (ptrLinearQueue, &elementToDequeue);
        if ( LINEAR_QUEUE_STATUS_GOOD !=  errorCode)
        {
            printf("Error while peek element Error:%d \n",errorCode);
        }
        else
        {
            printf("Peek Element: %d \n", elementToDequeue);
        }

        //Dequeue item
        errorCode = ptrLinearQueue->interface.dequeue(ptrLinearQueue, &elementToDequeue);
        if ( LINEAR_QUEUE_STATUS_GOOD !=  errorCode)
        {
            printf("Error while deque element Error:%d \n",errorCode);
        }
        else
        {
            printf("Dequeue Element: %d \n", elementToDequeue);
        }

    }
    else
    {
        printf("Error while init: %d \n", errorCode);
    }
}

/**
 * @brief function to execute circular queue operations
 * 
 * @param void
 * 
 * @return void
 */
void CircularQueueOperations(void)
{
    CircularQueueStatusCodes errorCode;

    circularQueue_type elementsToEnqueue[] = { 0x0D, 0x0E, 0x0A, 0x0D, 0x0B, 0x0E, 0x0E, 0x0F, 0x0D, 0x0E, 0x0A};

    size_t queueSize = 10;
    size_t sizeArray = sizeof( elementsToEnqueue ) / sizeof(circularQueue_type);

    errorCode = CircularQueue_init( ptrCircularQueue, queueSize );
    if ( CIRCULAR_QUEUE_STATUS_GOOD ==  errorCode )
    {
        CircularQueueEnqueueOpt( elementsToEnqueue, sizeArray);

        CircularQueueDequeueOpt( sizeArray );
    }
    else
    {
        printf("Error while init: %d \n", errorCode);
    }

    errorCode = CircularQueue_deInit( ptrCircularQueue );
    if ( CIRCULAR_QUEUE_STATUS_GOOD ==  errorCode )
    {
    }
    else
    {
        printf("Error while deinit: %d \n", errorCode);
    }
}

/**
 * @brief function to execute circular queue enqueue operations
 * 
 * @param ptrArray pointer to array
 * @param size size of array
 * 
 * @return void
 */
void CircularQueueEnqueueOpt( circularQueue_type *ptrArray, size_t size )
{
    CircularQueueStatusCodes retValue;

    for (size_t i = 0; i < size; i++)
    {
        retValue = ptrCircularQueue->interface.enqueue( ptrCircularQueue, ptrArray[i] );
        if ( CIRCULAR_QUEUE_STATUS_GOOD == retValue )
        {
            printf("Element: %#X enque successfully\n", ptrArray[i]);
        }
        else
        {
            printf("Element: %#X enque error: %d\n", ptrArray[i], retValue);
        }
    }
}

/**
 * @brief function to execute circular queue dequeue operations
 * 
 * @param size size of array
 * 
 * @return void
 */
void CircularQueueDequeueOpt( size_t size )
{
    CircularQueueStatusCodes errorCode;
    circularQueue_type elemntDequeue = 0, elementPeek = 0;

    for (size_t i = 0; i < size; i++)
    {
        errorCode = ptrCircularQueue->interface.peek( ptrCircularQueue, &elementPeek );
        if ( CIRCULAR_QUEUE_STATUS_GOOD == errorCode )
        {
            printf("Peek Element: %#X \n", elementPeek);
        }
        else
        {
            printf("Error while peek element Error:%d \n",errorCode);
        }

        errorCode = ptrCircularQueue->interface.dequeue( ptrCircularQueue, &elemntDequeue );
        if ( CIRCULAR_QUEUE_STATUS_GOOD == errorCode )
        {
            printf("Dequeue Element: %#X \n", elemntDequeue);
        }
        else
        {
            printf("Error while dequeue element Error:%d \n",errorCode);
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
    printf("Hello World Welcome to Queue example in C\n");

    printf("................................Linear Queue Example...........................\n");
    LinearQueueOperations();

    printf("................................Circular Queue Example..........................\n");
    CircularQueueOperations();

    return 0;
}
