/**
 * @file    test_LinearQueue.c
 * 
 * @brief   Main test runner for CUnit test suites.
 * 
 * @details Test for StackImplementation
 * 
 * @author  Ali Hussain
 * @date    15-04-2025
 * @email   ali0403hussain@gmail.com
 * 
 * @copyright (c) 2025 Ali Hussain
 */

/**********************************************************
 * Includes
 **********************************************************/
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "../19.QueueImplementation/src/lib/linearqueue/linearqueue.h"

/**********************************************************
 * Forward decleration, Global variables Placeholders
 **********************************************************/
LinearQueue linearQueue;
LinearQueue *ptrLinearQueue = &linearQueue;

linearQueue_type elementToEnqueue = 0;
linearQueue_type elementToDequeue = 0;
linearQueue_type elementToPeek = 0;

/**********************************************************
 * Setup and Teardown Placeholders
 **********************************************************/

int suite_init(void) 
{
    // Setup resources before each suite runs
    return 0;  // Return non-zero on failure
}

int suite_cleanup(void) 
{
    // Cleanup resources after each suite runs
    return 0;
}

/**********************************************************
 * Test Case Prototypes
 **********************************************************/

void test_linearQueue_init(void);
void test_linearQueue_enqueue(void);
void test_linearQueue_dequeue(void);
void test_linearQueue_peek(void);
void test_linearQueue_isFull(void);
void test_linearQueue_isEmpty(void); 
void test_linearQueue_fullOperation(void); 

/**********************************************************
 * Test Case Definitions
 **********************************************************/

void test_linearQueue_init(void) 
{
    CU_ASSERT(LinearQueue_init(NULL ) == LINEAR_QUEUE_STATUS_ERROR_INSTANCE_INVALID);
    CU_ASSERT(LinearQueue_init(ptrLinearQueue ) == LINEAR_QUEUE_STATUS_GOOD);
}

void test_linearQueue_enqueue(void) 
{
    elementToEnqueue = 100;
    CU_ASSERT( ptrLinearQueue->interface.enqueue (NULL, elementToEnqueue) == LINEAR_QUEUE_STATUS_ERROR_INSTANCE_INVALID);
    CU_ASSERT( ptrLinearQueue->interface.enqueue (ptrLinearQueue, elementToEnqueue) == LINEAR_QUEUE_STATUS_GOOD);
    CU_ASSERT( ptrLinearQueue->interface.peek (ptrLinearQueue, &elementToPeek) == LINEAR_QUEUE_STATUS_GOOD );
    CU_ASSERT( elementToPeek == elementToEnqueue );

    elementToEnqueue = 200;
    CU_ASSERT( ptrLinearQueue->interface.enqueue (ptrLinearQueue, elementToEnqueue) == LINEAR_QUEUE_STATUS_GOOD);

    elementToEnqueue = 300;
    CU_ASSERT( ptrLinearQueue->interface.enqueue (ptrLinearQueue, elementToEnqueue) == LINEAR_QUEUE_STATUS_GOOD);

    elementToEnqueue = 4004;
    CU_ASSERT( ptrLinearQueue->interface.enqueue (ptrLinearQueue, elementToEnqueue) == LINEAR_QUEUE_STATUS_GOOD);

    elementToEnqueue = 5001;
    CU_ASSERT( ptrLinearQueue->interface.enqueue (ptrLinearQueue, elementToEnqueue) == LINEAR_QUEUE_STATUS_GOOD);

    elementToEnqueue = 2656;
    CU_ASSERT( ptrLinearQueue->interface.enqueue (ptrLinearQueue, elementToEnqueue) == LINEAR_QUEUE_STATUS_ERROR_QUEUE_FULL);
}

void test_linearQueue_dequeue(void)
{
    CU_ASSERT( ptrLinearQueue->interface.dequeue (NULL, &elementToDequeue) == LINEAR_QUEUE_STATUS_ERROR_INSTANCE_INVALID);
    CU_ASSERT( ptrLinearQueue->interface.dequeue (ptrLinearQueue, NULL) == LINEAR_QUEUE_STATUS_ERROR_ARGUMENT_INVALID);
    CU_ASSERT( ptrLinearQueue->interface.dequeue (NULL, NULL) == LINEAR_QUEUE_STATUS_ERROR_INSTANCE_INVALID);
    CU_ASSERT( ptrLinearQueue->interface.dequeue (ptrLinearQueue, &elementToDequeue) == LINEAR_QUEUE_STATUS_GOOD);
    CU_ASSERT( ptrLinearQueue->interface.dequeue (ptrLinearQueue, &elementToDequeue) == LINEAR_QUEUE_STATUS_GOOD);
    CU_ASSERT( ptrLinearQueue->interface.dequeue (ptrLinearQueue, &elementToDequeue) == LINEAR_QUEUE_STATUS_GOOD);
    CU_ASSERT( ptrLinearQueue->interface.dequeue (ptrLinearQueue, &elementToDequeue) == LINEAR_QUEUE_STATUS_GOOD);
    CU_ASSERT( ptrLinearQueue->interface.dequeue (ptrLinearQueue, &elementToDequeue) == LINEAR_QUEUE_STATUS_GOOD);
    CU_ASSERT( ptrLinearQueue->interface.dequeue (ptrLinearQueue, &elementToDequeue) == LINEAR_QUEUE_STATUS_ERROR_QUEUE_EMPTY);
}

void test_linearQueue_peek(void)
{
    CU_ASSERT( ptrLinearQueue->interface.peek (NULL, &elementToPeek) == LINEAR_QUEUE_STATUS_ERROR_INSTANCE_INVALID);
    CU_ASSERT( ptrLinearQueue->interface.peek (ptrLinearQueue, NULL) == LINEAR_QUEUE_STATUS_ERROR_ARGUMENT_INVALID);
    CU_ASSERT( ptrLinearQueue->interface.peek (NULL, NULL) == LINEAR_QUEUE_STATUS_ERROR_INSTANCE_INVALID);
    CU_ASSERT( ptrLinearQueue->interface.peek (ptrLinearQueue, &elementToPeek) == LINEAR_QUEUE_STATUS_ERROR_QUEUE_EMPTY);

    elementToEnqueue = 2656;
    CU_ASSERT( ptrLinearQueue->interface.enqueue (ptrLinearQueue, elementToEnqueue) == LINEAR_QUEUE_STATUS_ERROR_QUEUE_FULL);
    CU_ASSERT( ptrLinearQueue->interface.peek (ptrLinearQueue, &elementToPeek) == LINEAR_QUEUE_STATUS_ERROR_QUEUE_EMPTY);
    CU_ASSERT( elementToPeek == 100 );
}

void test_linearQueue_isFull(void)
{
    CU_ASSERT( ptrLinearQueue->interface.isFull( NULL ) == LINEAR_QUEUE_STATUS_ERROR_INSTANCE_INVALID);
    CU_ASSERT( ptrLinearQueue->interface.isFull( ptrLinearQueue ) == LINEAR_QUEUE_STATUS_ERROR_QUEUE_FULL);
}

void test_linearQueue_isEmpty(void)
{
    CU_ASSERT( ptrLinearQueue->interface.isEmpty( NULL ) == LINEAR_QUEUE_STATUS_ERROR_INSTANCE_INVALID);
    CU_ASSERT( ptrLinearQueue->interface.isEmpty( ptrLinearQueue ) == LINEAR_QUEUE_STATUS_ERROR_QUEUE_EMPTY);
}

void test_linearQueue_fullOperation(void)
{
    uint8_t counter = 0;

    linearQueue_type elementsArray[] = {5001, 11111111, 1212, 3245, 0, 1234567};
    elementToDequeue = 0, elementToPeek = 0;

    //Initialization
    CU_ASSERT(LinearQueue_init(ptrLinearQueue ) == LINEAR_QUEUE_STATUS_GOOD);

    //Checking if queue full
    CU_ASSERT( ptrLinearQueue->interface.isFull( ptrLinearQueue ) == LINEAR_QUEUE_STATUS_GOOD);

    //Checking if queue empty
    CU_ASSERT( ptrLinearQueue->interface.isEmpty( ptrLinearQueue ) == LINEAR_QUEUE_STATUS_ERROR_QUEUE_EMPTY);

    //Try to dequeue element
    CU_ASSERT( ptrLinearQueue->interface.dequeue (ptrLinearQueue, &elementToDequeue) == LINEAR_QUEUE_STATUS_ERROR_QUEUE_EMPTY);
    CU_ASSERT( elementToDequeue == 0 );

    //Try to check peek
    CU_ASSERT( ptrLinearQueue->interface.peek (ptrLinearQueue, &elementToPeek) == LINEAR_QUEUE_STATUS_ERROR_QUEUE_EMPTY);
    CU_ASSERT( elementToPeek == 0 );

    //Enque an element
    CU_ASSERT( ptrLinearQueue->interface.enqueue (ptrLinearQueue, elementsArray[counter++]) == LINEAR_QUEUE_STATUS_GOOD);

    //Try to check peek
    CU_ASSERT( ptrLinearQueue->interface.peek (ptrLinearQueue, &elementToPeek) == LINEAR_QUEUE_STATUS_GOOD);
    CU_ASSERT( elementToPeek == elementsArray[0] );

    //Enque an element
    CU_ASSERT( ptrLinearQueue->interface.enqueue (ptrLinearQueue, elementsArray[counter++]) == LINEAR_QUEUE_STATUS_GOOD);

    //Try to check peek
    CU_ASSERT( ptrLinearQueue->interface.peek (ptrLinearQueue, &elementToPeek) == LINEAR_QUEUE_STATUS_GOOD);
    CU_ASSERT( elementToPeek == elementsArray[0] );

    //Enque an element
    CU_ASSERT( ptrLinearQueue->interface.enqueue (ptrLinearQueue, elementsArray[counter++]) == LINEAR_QUEUE_STATUS_GOOD);

    //Enque an element
    CU_ASSERT( ptrLinearQueue->interface.enqueue (ptrLinearQueue, elementsArray[counter++]) == LINEAR_QUEUE_STATUS_GOOD);

    //Enque an element
    CU_ASSERT( ptrLinearQueue->interface.enqueue (ptrLinearQueue, elementsArray[counter++]) == LINEAR_QUEUE_STATUS_GOOD);

    //Enque an element
    CU_ASSERT( ptrLinearQueue->interface.enqueue (ptrLinearQueue, elementsArray[counter++]) == LINEAR_QUEUE_STATUS_ERROR_QUEUE_FULL);

    //Try to check peek
    CU_ASSERT( ptrLinearQueue->interface.peek (ptrLinearQueue, &elementToPeek) == LINEAR_QUEUE_STATUS_GOOD);
    CU_ASSERT( elementToPeek == elementsArray[0] );

    //Try to deque element
    CU_ASSERT( ptrLinearQueue->interface.dequeue (ptrLinearQueue, &elementToDequeue) == LINEAR_QUEUE_STATUS_GOOD);
    CU_ASSERT( elementToDequeue == elementsArray[0] );

    //Try to check peek
    CU_ASSERT( ptrLinearQueue->interface.peek (ptrLinearQueue, &elementToPeek) == LINEAR_QUEUE_STATUS_GOOD);
    CU_ASSERT( elementToPeek == elementsArray[1] );

    //Try to deque element
    CU_ASSERT( ptrLinearQueue->interface.dequeue (ptrLinearQueue, &elementToDequeue) == LINEAR_QUEUE_STATUS_GOOD);
    CU_ASSERT( elementToDequeue == elementsArray[1] );

    //Try to check peek
    CU_ASSERT( ptrLinearQueue->interface.peek (ptrLinearQueue, &elementToPeek) == LINEAR_QUEUE_STATUS_GOOD);
    CU_ASSERT( elementToPeek == elementsArray[2] );

    //Try to deque element
    CU_ASSERT( ptrLinearQueue->interface.dequeue (ptrLinearQueue, &elementToDequeue) == LINEAR_QUEUE_STATUS_GOOD);
    CU_ASSERT( elementToDequeue == elementsArray[2] );
    
    //Try to check peek
    CU_ASSERT( ptrLinearQueue->interface.peek (ptrLinearQueue, &elementToPeek) == LINEAR_QUEUE_STATUS_GOOD);
    CU_ASSERT( elementToPeek == elementsArray[3] );

    //Try to deque element
    CU_ASSERT( ptrLinearQueue->interface.dequeue (ptrLinearQueue, &elementToDequeue) == LINEAR_QUEUE_STATUS_GOOD);
    CU_ASSERT( elementToDequeue == elementsArray[3] );

    //Try to check peek
    CU_ASSERT( ptrLinearQueue->interface.peek (ptrLinearQueue, &elementToPeek) == LINEAR_QUEUE_STATUS_GOOD);
    CU_ASSERT( elementToPeek == elementsArray[4] );

    //Try to deque element
    CU_ASSERT( ptrLinearQueue->interface.dequeue (ptrLinearQueue, &elementToDequeue) == LINEAR_QUEUE_STATUS_GOOD);
    CU_ASSERT( elementToDequeue == elementsArray[4] );

    //Try to check peek
    CU_ASSERT( ptrLinearQueue->interface.peek (ptrLinearQueue, &elementToPeek) == LINEAR_QUEUE_STATUS_ERROR_QUEUE_EMPTY);
    CU_ASSERT( elementToPeek == elementsArray[4] );

    //Try to deque element
    CU_ASSERT( ptrLinearQueue->interface.dequeue (ptrLinearQueue, &elementToDequeue) == LINEAR_QUEUE_STATUS_ERROR_QUEUE_EMPTY);
    CU_ASSERT( elementToDequeue == elementsArray[4] );

    //Enque an element
    CU_ASSERT( ptrLinearQueue->interface.enqueue (ptrLinearQueue, elementsArray[4]) == LINEAR_QUEUE_STATUS_ERROR_QUEUE_FULL);
}

/**********************************************************
 * Test Suite Registration
 **********************************************************/

void register_LinearQueue_tests(void) 
{
    CU_pSuite suite = CU_add_suite("LinearQueue Test Suite", suite_init, suite_cleanup);
    if (suite) 
    {
        CU_add_test(suite, "LinearQueue Init:", test_linearQueue_init);
        CU_add_test(suite, "LinearQueue enqueue:", test_linearQueue_enqueue);
        CU_add_test(suite, "LinearQueue dequeue:", test_linearQueue_dequeue);
        CU_add_test(suite, "LinearQueue peek:", test_linearQueue_peek);
        CU_add_test(suite, "LinearQueue isFull:", test_linearQueue_isFull);
        CU_add_test(suite, "LinearQueue isEmpty:", test_linearQueue_isEmpty);
        CU_add_test(suite, "LinearQueue Full Operation:", test_linearQueue_fullOperation);
    }
}

/**********************************************************
 * Main Test Runner
 **********************************************************/

int main(void) 
{
    if (CU_initialize_registry() != CUE_SUCCESS)
    {
        return CU_get_error();
    }

    register_LinearQueue_tests();  // Register the test suite

    CU_basic_set_mode(CU_BRM_VERBOSE);  // Set output verbosity
    CU_basic_run_tests();               // Run all tests

    CU_cleanup_registry();              // Cleanup
    
    return CU_get_error();
}
