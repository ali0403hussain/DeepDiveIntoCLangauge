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
 * Starting (Entry) Point of C program
 * @param -void
 * 
 * @return 0
 */
int main()
{
    printf("Hello World Welcome to Queue example in C\n");

    printf("Linear Queue Example..................\n");
    LinearQueueOperations();

    return 0;
}
