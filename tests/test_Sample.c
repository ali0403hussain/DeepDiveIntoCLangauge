/**
 * @file    test_Sample.c
 * 
 * @brief   Main test runner for CUnit test suites.
 * 
 * @details This file initializes the CUnit test registry, registers 
 *          test suites (example: Addition Test Suite), and executes 
 *          all tests using the basic CUnit interface. It also includes 
 *          optional setup and teardown functions for test suites.
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
void test_addition(void);

/**********************************************************
 * Test Case Definitions
 **********************************************************/
void test_addition(void) 
{
    CU_ASSERT(2 + 2 == 4);
    CU_ASSERT(0 + 5 == 5);
    CU_ASSERT(-3 + 3 == 0);
}

/**********************************************************
 * Test Suite Registration
 **********************************************************/

void register_addition_tests(void) 
{
    CU_pSuite suite = CU_add_suite("Addition Test Suite", suite_init, suite_cleanup);
    if (suite) 
    {
        CU_add_test(suite, "Addition:", test_addition);
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

    register_addition_tests();  // Register the test suite

    CU_basic_set_mode(CU_BRM_VERBOSE);  // Set output verbosity
    CU_basic_run_tests();               // Run all tests

    CU_cleanup_registry();              // Cleanup
    
    return CU_get_error();
}
