/**
 * @file stack.h
 * 
 * @description stack library
 * 
 * @author - Ali Hussain
 * @date   - 08-04-2025
 * @email  - ali0403hussain@gmail.com
 * 
 * @copyright (c) 2025 Ali Hussain
 */


/**********************************************************
 * Macros
 **********************************************************/

#ifndef STACK_H_INCLUDE
#define STACK_H_INCLUDE

/**********************************************************
 * Includes
 **********************************************************/
#include <stdint.h>
#include <stdbool.h>

/**********************************************************
 * Struct, Enums, and Typedef 
 **********************************************************/

typedef struct Stack Stack;

/**
 * @brief enum for Stack status codes
 *  */ 
typedef enum {
    STACK_STATUS_GOOD = 0,
    STACK_STATUS_ERROR = 1,
    STACK_STATUS_ERROR_INSTANCE_INVALID = 2,
    STACK_STATUS_ERROR_ARGUMENT_INVALID = 3,
    STACK_STATUS_ERROR_STACK_FULL = 4,
    STACK_STATUS_ERROR_STACK_EMPTY = 5
}StackStatusCodes;

/**
 * @brief Stack interface Push item
 * 
 * @param object pointer to stack object
 * @param value value to push
 * 
 * @return @StackStatusCodes
 */
typedef StackStatusCodes (*PushItem)(Stack *object, int32_t value);

/**
 * @brief Stack interface Pop item
 * 
 * @param object pointer to stack object
 * @param popValue pointer to variable to pop value
 * 
 * @return @StackStatusCodes
 */
typedef StackStatusCodes (*PopItem)(Stack *object, int32_t *popValue);

/**
 * @brief Stack interface peek item
 * 
 * @param object pointer to stack object
 * @param peekValue pointer to variable to peek value
 * 
 * @return @StackStatusCodes
 */
typedef StackStatusCodes (*Peek)(Stack *object, int32_t *peekValue);

/**
 * @brief struct for Stack interfaces
 *  */ 
typedef struct {
    PushItem push;
    PopItem pop;
    Peek peek;
}StackInterface;

/**
 * @brief struct for stack
 */
struct Stack {
    int32_t *ptrContainer;      //<! Pointer to the stack container
    int32_t top;                //<! Top of the stack
    size_t size;                //<! Size of the stack
    StackInterface interface;   //<! Interface for stack
};

/***********************************************************
 * Forward declerations and global variables
 **********************************************************/

/***********************************************************
 * Inline functions
 **********************************************************/

/**
 * @brief Stack inline function is empty
 * 
 * @param object pointer to stack object

 * 
 * @return True:False
 */
static inline bool loc_Stack_isEmpty( Stack *object )
{
    return ( object->top == -1 )? true: false;
}

/**
 * @brief Stack inline function is Full
 * 
 * @param object pointer to stack object

 * 
 * @return True:False
 */
static inline bool loc_Stack_isFull( Stack *object )
{
    return ( (size_t)object->top == (object->size - 1) )? true: false;
}

/***********************************************************
 * Functions Declerations
 **********************************************************/

/**
 * @brief Stack Init function
 * 
 * @param object pointer to stack object
 * @param size   size for stack
 * 
 * @return @StackStausCodes
 */
StackStatusCodes Stack_init( Stack *object, size_t size );

/**
 * @brief Stack Init function
 * 
 * @param object pointer to stack object
 * 
 * @return @StackStausCodes
 */
StackStatusCodes Stack_deInit( Stack *object );


#endif // STACK_H_INCLUDE
   
   