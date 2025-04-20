/**
 * @file linearqueue.h
 * 
 * @description linearqueue library
 * 
 * @author - Ali Hussain
 * @date   - 08-04-2025
 * @email  - ali0403hussain@gmail.com
 * 
 * @copyright (c) 2025 Ali Hussain
 */

#ifndef LINEAR_QUEUE_H_INCLUDE
#define LINEAR_QUEUE_H_INCLUDE

/**********************************************************
 * Includes
 **********************************************************/
#include "types.h"

/**********************************************************
 * Macros
 **********************************************************/
#define LINEAR_QUEUE_SIZE   ( 5U )  //<!Size for linear queue

/**********************************************************
 * Struct, Enums, and Typedef 
 **********************************************************/

typedef int linearQueue_type; //<! typedef for queue type, can be change depends upon application type

typedef struct LinearQueue LinearQueue; //<! Forward decleration for LinearQueue struct

/**
 * @brief enum for Linear Queue status codes
 *  */ 
typedef enum {
    LINEAR_QUEUE_STATUS_GOOD = 0,
    LINEAR_QUEUE_STATUS_ERROR = 1,
    LINEAR_QUEUE_STATUS_ERROR_INSTANCE_INVALID = 2,
    LINEAR_QUEUE_STATUS_ERROR_ARGUMENT_INVALID = 3,
    LINEAR_QUEUE_STATUS_ERROR_QUEUE_FULL = 4,
    LINEAR_QUEUE_STATUS_ERROR_QUEUE_EMPTY = 5
}LinearQueueStatusCodes;

/**
 * @brief interface for queue enqueue
 * 
 * @param object pointer to queue object
 * @param element value to Enqueue
 * 
 * @return @LinearQueueStatusCodes
 */
typedef LinearQueueStatusCodes (*LinearQueueEnqueue)( LinearQueue *object, linearQueue_type element );

/**
 * @brief interface for queue dequeue
 * 
 * @param object pointer to queue object
 * @param ptrElement pointer to variable for dequeue
 * 
 * @return @LinearQueueStatusCodes
 */
typedef LinearQueueStatusCodes (*LinearQueueDequeue)( LinearQueue *object, linearQueue_type *ptrElement );

/**
 * @brief interface for queue peek
 * 
 * @param object pointer to queue object
 * @param ptrElement pointer to variable for peek
 * 
 * @return @LinearQueueStatusCodes
 */
typedef LinearQueueStatusCodes (*LinearQueuePeek)( LinearQueue *object, linearQueue_type *ptrElement );

/**
 * @brief interface for queue IsEmpty
 * 
 * @param object pointer to queue object
 * 
 * @return @LinearQueueStatusCodes
 */
typedef LinearQueueStatusCodes (*LinearQueueIsEmpty)( LinearQueue *object );

/**
 * @brief interface for queue IsFull
 * 
 * @param object pointer to queue object
 * 
 * @return @LinearQueueStatusCodes
 */
typedef LinearQueueStatusCodes (*LinearQueueIsFull)( LinearQueue *object );

/**
 * @brief typedef struct for queue interface
 */
typedef struct {
    LinearQueueEnqueue enqueue;
    LinearQueueDequeue dequeue;
    LinearQueuePeek peek;
    LinearQueueIsEmpty isEmpty;
    LinearQueueIsFull isFull;
}QueueInterface;

/**
 * @brief typedef struct for queue param
 */
typedef struct {
    linearQueue_type data[ LINEAR_QUEUE_SIZE ];
    int front;
    int rear;
}Queue;

/**
 * @brief LinearQueue struct
 */
struct LinearQueue {
    Queue queue;
    QueueInterface interface;
};

/***********************************************************
 * Forward declerations and global variables
 **********************************************************/

/***********************************************************
 * Inline functions
 **********************************************************/

/***********************************************************
 * Functions Declerations
 **********************************************************/

/**
 * @brief function for Linear queue initialization
 * 
 * @param object pointer to queue object
 * 
 * @return @LinearQueueStatusCodes
 */
LinearQueueStatusCodes LinearQueue_init( LinearQueue *object );

#endif // LINEAR_QUEUE_H_INCLUDE
   
   