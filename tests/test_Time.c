/**
 * @file    test_Time.c
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

#include "../14.ADCSensorExample/src/lib/time/time.h"

/**********************************************************
 * Forward decleration, Global variables Placeholders
 **********************************************************/
Time time;
Time *ptrTime = &time;

size_frequency_t frequency;
uint32_t delayMilliseconds;

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

void test_Time_init(void);
void test_Time_interfacesArgs(void);
void test_Time_startTimer(void);
void test_Time_stopTimer(void);
void test_Time_softTimer_with_delay(void);

/**********************************************************
 * Test Case Definitions
 **********************************************************/

void test_Time_init(void) 
{
    CU_ASSERT(Time_init( NULL     ) == TIME_STATUS_INSTANCE_INVALID);
    CU_ASSERT(Time_init( ptrTime  ) == TIME_STATUS_GOOD);
}

void test_Time_interfacesArgs(void) 
{
    delayMilliseconds = 100;
    ptrTime->frequencyHz = 0;

    CU_ASSERT( ptrTime->interface.getEstimateCpuFrequency( NULL,    &frequency ) == TIME_STATUS_INSTANCE_INVALID );
    CU_ASSERT( ptrTime->interface.getEstimateCpuFrequency( ptrTime,       NULL ) == TIME_STATUS_ARGUMENT_INVALID );
    CU_ASSERT( ptrTime->interface.getEstimateCpuFrequency( NULL,          NULL ) == TIME_STATUS_INSTANCE_INVALID );
    CU_ASSERT( ptrTime->interface.getEstimateCpuFrequency( ptrTime, &frequency ) == TIME_STATUS_GOOD );
    CU_ASSERT( ptrTime->interface.startTimer( NULL    ) == TIME_STATUS_INSTANCE_INVALID);
    CU_ASSERT( ptrTime->interface.startTimer( ptrTime ) == TIME_STATUS_GOOD);
    CU_ASSERT( ptrTime->interface.stopTimer( NULL     ) == TIME_STATUS_INSTANCE_INVALID);
    CU_ASSERT( ptrTime->interface.stopTimer( ptrTime  ) == TIME_STATUS_GOOD);
    CU_ASSERT( ptrTime->interface.delayMs( NULL,    delayMilliseconds) == TIME_STATUS_INSTANCE_INVALID);
    CU_ASSERT( ptrTime->interface.delayMs( ptrTime,              0) == TIME_STATUS_ARGUMENT_INVALID);
    CU_ASSERT( ptrTime->interface.delayMs( NULL,                 0) == TIME_STATUS_INSTANCE_INVALID);
    CU_ASSERT( ptrTime->interface.delayMs( ptrTime, delayMilliseconds) == TIME_STATUS_PARAMETER_OUT_OF_RANGE);

    ptrTime->frequencyHz = CPU_FREQUENCY_HZ;

    CU_ASSERT( ptrTime->interface.delayMs( ptrTime, delayMilliseconds) == TIME_STATUS_GOOD);
}

void test_Time_startTimer(void)
{
    CU_ASSERT( ptrTime->softTimer.isRunning == False );
    CU_ASSERT( ptrTime->interface.startTimer( ptrTime ) == TIME_STATUS_GOOD );
    CU_ASSERT( ptrTime->softTimer.isRunning == True );
    CU_ASSERT( ptrTime->interface.startTimer( ptrTime ) == TIME_STATUS_TIMER_NOT_EXPIRED );
}

void test_Time_stopTimer(void)
{
    CU_ASSERT( ptrTime->softTimer.isRunning == True );
    CU_ASSERT( ptrTime->interface.stopTimer( ptrTime ) == TIME_STATUS_GOOD );
    CU_ASSERT( ptrTime->softTimer.isRunning == False );
    CU_ASSERT( ptrTime->interface.stopTimer( ptrTime ) == TIME_STATUS_TIMER_EXPIRED );
}

void test_Time_softTimer_with_delay(void)
{
    delayMilliseconds = 1;
    CU_ASSERT( ptrTime->interface.startTimer( ptrTime ) == TIME_STATUS_GOOD );
    CU_ASSERT( ptrTime->interface.delayMs( ptrTime, delayMilliseconds) == TIME_STATUS_GOOD);
    CU_ASSERT( ptrTime->interface.stopTimer( ptrTime ) == TIME_STATUS_GOOD );
    CU_ASSERT( ptrTime->softTimer.duration == delayMilliseconds);

    delayMilliseconds = 10;
    CU_ASSERT( ptrTime->interface.startTimer( ptrTime ) == TIME_STATUS_GOOD );
    CU_ASSERT( ptrTime->interface.delayMs( ptrTime, delayMilliseconds) == TIME_STATUS_GOOD);
    CU_ASSERT( ptrTime->interface.stopTimer( ptrTime ) == TIME_STATUS_GOOD );
    CU_ASSERT( ptrTime->softTimer.duration == delayMilliseconds);

    delayMilliseconds = 20;
    CU_ASSERT( ptrTime->interface.startTimer( ptrTime ) == TIME_STATUS_GOOD );
    CU_ASSERT( ptrTime->interface.delayMs( ptrTime, delayMilliseconds) == TIME_STATUS_GOOD);
    CU_ASSERT( ptrTime->interface.stopTimer( ptrTime ) == TIME_STATUS_GOOD );
    CU_ASSERT( ptrTime->softTimer.duration == delayMilliseconds);

    delayMilliseconds = 30;
    CU_ASSERT( ptrTime->interface.startTimer( ptrTime ) == TIME_STATUS_GOOD );
    CU_ASSERT( ptrTime->interface.delayMs( ptrTime, delayMilliseconds) == TIME_STATUS_GOOD);
    CU_ASSERT( ptrTime->interface.stopTimer( ptrTime ) == TIME_STATUS_GOOD );
    CU_ASSERT( ptrTime->softTimer.duration == delayMilliseconds);

    delayMilliseconds = 50;
    CU_ASSERT( ptrTime->interface.startTimer( ptrTime ) == TIME_STATUS_GOOD );
    CU_ASSERT( ptrTime->interface.delayMs( ptrTime, delayMilliseconds) == TIME_STATUS_GOOD);
    CU_ASSERT( ptrTime->interface.stopTimer( ptrTime ) == TIME_STATUS_GOOD );
    CU_ASSERT( ptrTime->softTimer.duration == delayMilliseconds);

    delayMilliseconds = 100;
    CU_ASSERT( ptrTime->interface.startTimer( ptrTime ) == TIME_STATUS_GOOD );
    CU_ASSERT( ptrTime->interface.delayMs( ptrTime, delayMilliseconds) == TIME_STATUS_GOOD);
    CU_ASSERT( ptrTime->interface.stopTimer( ptrTime ) == TIME_STATUS_GOOD );
    CU_ASSERT( ptrTime->softTimer.duration == delayMilliseconds);

    delayMilliseconds = 200;
    CU_ASSERT( ptrTime->interface.startTimer( ptrTime ) == TIME_STATUS_GOOD );
    CU_ASSERT( ptrTime->interface.delayMs( ptrTime, delayMilliseconds) == TIME_STATUS_GOOD);
    CU_ASSERT( ptrTime->interface.stopTimer( ptrTime ) == TIME_STATUS_GOOD );
    CU_ASSERT( ptrTime->softTimer.duration == delayMilliseconds);

    delayMilliseconds = 301;
    CU_ASSERT( ptrTime->interface.startTimer( ptrTime ) == TIME_STATUS_GOOD );
    CU_ASSERT( ptrTime->interface.delayMs( ptrTime, delayMilliseconds) == TIME_STATUS_GOOD);
    CU_ASSERT( ptrTime->interface.stopTimer( ptrTime ) == TIME_STATUS_GOOD );
    CU_ASSERT( ptrTime->softTimer.duration == delayMilliseconds);

    delayMilliseconds = 400;
    CU_ASSERT( ptrTime->interface.startTimer( ptrTime ) == TIME_STATUS_GOOD );
    CU_ASSERT( ptrTime->interface.delayMs( ptrTime, delayMilliseconds) == TIME_STATUS_GOOD);
    CU_ASSERT( ptrTime->interface.stopTimer( ptrTime ) == TIME_STATUS_GOOD );
    CU_ASSERT( ptrTime->softTimer.duration == delayMilliseconds);

    delayMilliseconds = 500;
    CU_ASSERT( ptrTime->interface.startTimer( ptrTime ) == TIME_STATUS_GOOD );
    CU_ASSERT( ptrTime->interface.delayMs( ptrTime, delayMilliseconds) == TIME_STATUS_GOOD);
    CU_ASSERT( ptrTime->interface.stopTimer( ptrTime ) == TIME_STATUS_GOOD );
    CU_ASSERT( ptrTime->softTimer.duration == delayMilliseconds);

    delayMilliseconds = 600;
    CU_ASSERT( ptrTime->interface.startTimer( ptrTime ) == TIME_STATUS_GOOD );
    CU_ASSERT( ptrTime->interface.delayMs( ptrTime, delayMilliseconds) == TIME_STATUS_GOOD);
    CU_ASSERT( ptrTime->interface.stopTimer( ptrTime ) == TIME_STATUS_GOOD );
    CU_ASSERT( ptrTime->softTimer.duration == delayMilliseconds);

    delayMilliseconds = 700;
    CU_ASSERT( ptrTime->interface.startTimer( ptrTime ) == TIME_STATUS_GOOD );
    CU_ASSERT( ptrTime->interface.delayMs( ptrTime, delayMilliseconds) == TIME_STATUS_GOOD);
    CU_ASSERT( ptrTime->interface.stopTimer( ptrTime ) == TIME_STATUS_GOOD );
    CU_ASSERT( ptrTime->softTimer.duration == delayMilliseconds);

    delayMilliseconds = 800;
    CU_ASSERT( ptrTime->interface.startTimer( ptrTime ) == TIME_STATUS_GOOD );
    CU_ASSERT( ptrTime->interface.delayMs( ptrTime, delayMilliseconds) == TIME_STATUS_GOOD);
    CU_ASSERT( ptrTime->interface.stopTimer( ptrTime ) == TIME_STATUS_GOOD );
    CU_ASSERT( ptrTime->softTimer.duration == delayMilliseconds);

    delayMilliseconds = 1000;
    CU_ASSERT( ptrTime->interface.startTimer( ptrTime ) == TIME_STATUS_GOOD );
    CU_ASSERT( ptrTime->interface.delayMs( ptrTime, delayMilliseconds) == TIME_STATUS_GOOD);
    CU_ASSERT( ptrTime->interface.stopTimer( ptrTime ) == TIME_STATUS_GOOD );
    CU_ASSERT( ptrTime->softTimer.duration == delayMilliseconds);
}

/**********************************************************
 * Test Suite Registration
 **********************************************************/

void register_Time_tests(void) 
{
    CU_pSuite suite = CU_add_suite("Time Test Suite", suite_init, suite_cleanup);
    if (suite) 
    {
        CU_add_test(suite, "Time Init:", test_Time_init);
        CU_add_test(suite, "Time Interfaces Args:", test_Time_interfacesArgs);
        CU_add_test(suite, "Time Start Timer:", test_Time_startTimer);
        CU_add_test(suite, "Time Stop Timer:", test_Time_stopTimer);
        CU_add_test(suite, "Time SoftTimer with delay :", test_Time_softTimer_with_delay);
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

    register_Time_tests();  // Register the test suite

    CU_basic_set_mode(CU_BRM_VERBOSE);  // Set output verbosity
    CU_basic_run_tests();               // Run all tests

    CU_cleanup_registry();              // Cleanup
    
    return CU_get_error();
}
