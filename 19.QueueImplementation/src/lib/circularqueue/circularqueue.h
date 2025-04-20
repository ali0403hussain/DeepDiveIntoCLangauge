/**
 * @file circularqueue.h
 * 
 * @description circular queue library
 * 
 * @author - Ali Hussain
 * @date   - 08-04-2025
 * @email  - ali0403hussain@gmail.com
 * 
 * @copyright (c) 2025 Ali Hussain
 */

#ifndef CIRCULAR_QUEUE_H_INCLUDE
#define CIRCULAR_QUEUE_H_INCLUDE

/**********************************************************
 * Includes
 **********************************************************/
#include <stdlib.h>
#include "types.h"

/**********************************************************
 * Macros
 **********************************************************/

/**********************************************************
 * Struct, Enums, and Typedef 
 **********************************************************/

typedef int circularQueue_type; //<! typedef for queue type, can be change depends upon application type

typedef struct CircularQueue CircularQueue; //<! Forward decleration for CircularQueue struct

/**
 * @brief enum for Circular Queue status codes
 *  */ 
typedef enum {
    CIRCULAR_QUEUE_STATUS_GOOD = 0,
    CIRCULAR_QUEUE_STATUS_ERROR = 1,
    CIRCULAR_QUEUE_STATUS_ERROR_INSTANCE_INVALID = 2,
    CIRCULAR_QUEUE_STATUS_ERROR_ARGUMENT_INVALID = 3,
    CIRCULAR_QUEUE_STATUS_ERROR_QUEUE_FULL = 4,
    CIRCULAR_QUEUE_STATUS_ERROR_QUEUE_EMPTY = 5
}CircularQueueStatusCodes;

/**
 * @brief interface for queue enqueue
 * 
 * @param object pointer to queue object
 * @param element value to Enqueue
 * 
 * @return @CircularQueueStatusCodes
 */
typedef CircularQueueStatusCodes (*CircularQueueEnqueue)( CircularQueue *object, circularQueue_type element );

/**
 * @brief interface for queue dequeue
 * 
 * @param object pointer to queue object
 * @param ptrElement pointer to variable for dequeue
 * 
 * @return @CircularQueueStatusCodes
 */
typedef CircularQueueStatusCodes (*CircularQueueDequeue)( CircularQueue *object, circularQueue_type *ptrElement );

/**
 * @brief interface for queue peek
 * 
 * @param object pointer to queue object
 * @param ptrElement pointer to variable for peek
 * 
 * @return @CircularQueueStatusCodes
 */
typedef CircularQueueStatusCodes (*CircularQueuePeek)( CircularQueue *object, circularQueue_type *ptrElement );

/**
 * @brief interface for queue IsEmpty
 * 
 * @param object pointer to queue object
 * 
 * @return @CircularQueueStatusCodes
 */
typedef CircularQueueStatusCodes (*CircularQueueIsEmpty)( CircularQueue *object );

/**
 * @brief interface for queue IsFull
 * 
 * @param object pointer to queue object
 * 
 * @return @CircularQueueStatusCodes
 */
typedef CircularQueueStatusCodes (*CircularQueueIsFull)( CircularQueue *object );

/**
 * @brief typedef struct for queue interface
 */
typedef struct {
    CircularQueueEnqueue enqueue;
    CircularQueueDequeue dequeue;
    CircularQueuePeek peek;
    CircularQueueIsEmpty isEmpty;
    CircularQueueIsFull isFull;
}CircularQueueInterface;

/**
 * @brief typedef struct for queue param
 */
typedef struct {
    circularQueue_type *ptrContainer;
    size_t sizeQueue;
    size_t filledSize;
    int front;
    int rear;
}CircularQueueParam;

/**
 * @brief LinearQueue struct
 */
struct CircularQueue {
    CircularQueueParam queue;
    CircularQueueInterface interface;
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
 * @brief function for Circular queue initialization
 * 
 * @param object pointer to queue object
 * @param size size of queue
 * 
 * @return @CircularQueueStatusCodes
 */
CircularQueueStatusCodes CircularQueue_init( CircularQueue *object, size_t size );

/**
 * @brief function for Circular queue de initialization
 * 
 * @param object pointer to queue object
 * 
 * @return @CircularQueueStatusCodes
 */
CircularQueueStatusCodes CircularQueue_deInit( CircularQueue *object );

#endif // CIRCULAR_QUEUE_H_INCLUDE
   
   