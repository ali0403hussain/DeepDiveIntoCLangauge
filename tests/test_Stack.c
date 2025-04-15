/**
 * @file    test_Stack.c
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

#include "../18.StackImplementation/src/lib/stack/stack.h"

/**********************************************************
 * Forward decleration, Global variables Placeholders
 **********************************************************/
Stack stack;
Stack *ptrStack = &stack;

int32_t popValue = 0, peekValue = 0;

/**********************************************************
 * Setup and Teardown Placeholders
 **********************************************************/

int suite_init(void) 
{
    // Setup resources before each suite runs
    return 0;  // Return non-zero on failure
}

int suite_push_pop_init(void) 
{
    Stack_init(ptrStack, 5);
    return 0;  // Return non-zero on failure
}

int suite_cleanup(void) 
{
    // Cleanup resources after each suite runs
    Stack_deInit(ptrStack);
    return 0;
}

/**********************************************************
 * Test Case Prototypes
 **********************************************************/

void test_stack_init(void);
void test_stack_push(void);
void test_stack_pop(void);
void test_stack_peek(void);

/**********************************************************
 * Test Case Definitions
 **********************************************************/

void test_stack_init(void) 
{
    CU_ASSERT(Stack_init(NULL,     10) == STACK_STATUS_ERROR_INSTANCE_INVALID);
    CU_ASSERT(Stack_init(ptrStack, 0 ) == STACK_STATUS_ERROR_ARGUMENT_INVALID);
    CU_ASSERT(Stack_init(ptrStack, 3 ) == STACK_STATUS_GOOD);
}

void test_stack_push(void) 
{
    CU_ASSERT(ptrStack->interface.push( NULL,     0x0D ) == STACK_STATUS_ERROR_INSTANCE_INVALID);
    CU_ASSERT(ptrStack->interface.push( ptrStack, 0x0D ) == STACK_STATUS_GOOD);
    CU_ASSERT(ptrStack->interface.push( ptrStack, 0x0E ) == STACK_STATUS_GOOD);
    CU_ASSERT(ptrStack->interface.push( ptrStack, 0x0A ) == STACK_STATUS_GOOD);
    CU_ASSERT(ptrStack->interface.push( ptrStack, 0x0D ) == STACK_STATUS_ERROR_STACK_FULL);
}

void test_stack_pop(void) 
{
    CU_ASSERT(ptrStack->interface.pop( NULL,     &popValue ) == STACK_STATUS_ERROR_INSTANCE_INVALID);
    CU_ASSERT(ptrStack->interface.pop( ptrStack,      NULL ) == STACK_STATUS_ERROR_ARGUMENT_INVALID);
    CU_ASSERT(ptrStack->interface.pop( ptrStack, &popValue ) == STACK_STATUS_GOOD);
    CU_ASSERT(ptrStack->interface.pop( ptrStack, &popValue ) == STACK_STATUS_GOOD);
    CU_ASSERT(ptrStack->interface.pop( ptrStack, &popValue ) == STACK_STATUS_GOOD);
    CU_ASSERT(ptrStack->interface.pop( ptrStack, &popValue ) == STACK_STATUS_ERROR_STACK_EMPTY);
}

void test_stack_peek(void)
{
    CU_ASSERT(ptrStack->interface.peek( NULL,     &peekValue ) == STACK_STATUS_ERROR_INSTANCE_INVALID);
    CU_ASSERT(ptrStack->interface.peek( ptrStack,       NULL ) == STACK_STATUS_ERROR_ARGUMENT_INVALID);
    CU_ASSERT(ptrStack->interface.peek( ptrStack, &peekValue ) == STACK_STATUS_ERROR_STACK_EMPTY);
    CU_ASSERT(ptrStack->interface.push( ptrStack,       0x0E ) == STACK_STATUS_GOOD);
    CU_ASSERT(ptrStack->interface.peek( ptrStack, &peekValue ) == STACK_STATUS_GOOD);
    CU_ASSERT(peekValue == 0x0E);
}

void test_stack_push_pop(void)
{
    CU_ASSERT(ptrStack->interface.push( ptrStack, 0x0D ) == STACK_STATUS_GOOD);
    CU_ASSERT(ptrStack->interface.pop( ptrStack, &popValue ) == STACK_STATUS_GOOD);
    CU_ASSERT(popValue == 0x0D);
    CU_ASSERT(ptrStack->interface.pop( ptrStack, &popValue ) == STACK_STATUS_ERROR_STACK_EMPTY);
    CU_ASSERT(ptrStack->interface.push( ptrStack, 0x0D ) == STACK_STATUS_GOOD);
    CU_ASSERT(ptrStack->interface.push( ptrStack, 0x0E ) == STACK_STATUS_GOOD);
    CU_ASSERT(ptrStack->interface.push( ptrStack, 0x0A ) == STACK_STATUS_GOOD);
    CU_ASSERT(ptrStack->interface.push( ptrStack, 0x0D ) == STACK_STATUS_GOOD);
    CU_ASSERT(ptrStack->interface.pop( ptrStack, &popValue ) == STACK_STATUS_GOOD);
    CU_ASSERT(popValue == 0x0D);
    CU_ASSERT(ptrStack->interface.pop( ptrStack, &popValue ) == STACK_STATUS_GOOD);
    CU_ASSERT(popValue == 0x0A);
    CU_ASSERT(ptrStack->interface.pop( ptrStack, &popValue ) == STACK_STATUS_GOOD);
    CU_ASSERT(popValue == 0x0E);
    CU_ASSERT(ptrStack->interface.pop( ptrStack, &popValue ) == STACK_STATUS_GOOD);
    CU_ASSERT(popValue == 0x0D);
}

/**********************************************************
 * Test Suite Registration
 **********************************************************/

void register_stack_tests(void) 
{
    CU_pSuite suite = CU_add_suite("Stack Test Suite", suite_init, suite_cleanup);
    if (suite) 
    {
        CU_add_test(suite, "Stack Init:", test_stack_init);
        CU_add_test(suite, "Stack Push:", test_stack_push);
        CU_add_test(suite, "Stack Pop:",  test_stack_pop);
        CU_add_test(suite, "Stack Peek:", test_stack_peek);
    }

    CU_pSuite suitePushPop = CU_add_suite("Stack Push Pop Test Suite", suite_push_pop_init, suite_cleanup);
    if (suitePushPop) 
    {
        CU_add_test(suitePushPop, "Stack Push Pop:", test_stack_push_pop);
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

    register_stack_tests();  // Register the test suite

    CU_basic_set_mode(CU_BRM_VERBOSE);  // Set output verbosity
    CU_basic_run_tests();               // Run all tests

    CU_cleanup_registry();              // Cleanup
    
    return CU_get_error();
}
