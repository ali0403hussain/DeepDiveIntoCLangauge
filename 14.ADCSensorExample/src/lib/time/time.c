/**
 * @file time.c
 * 
 * @description Provides library for time
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
#include "time.h"
 
/**********************************************************
 * Macros
 **********************************************************/
 
/**********************************************************
 * Struct, Enums, and Typedef 
 **********************************************************/
 
/***********************************************************
 * Forward declerations and global variables
 **********************************************************/

/**********************************************************
 * INLINE function
 **********************************************************/
/**
 * @brief inline function to get current cpu cycles
 * This can be done by reading Time stamp count
 * 
 * @param void
 * 
 * @return function for cpu cycles count of type size_frequency_t
 */
static inline size_frequency_t get_countCpuCycles( void )
{
    unsigned int lowCpuCycles, highCpuCycles;
    __asm__ __volatile__ (
        "rdtsc"                                     // Reads the Time Stamp Counter (TSC)
        : "=a"(lowCpuCycles), "=d"(highCpuCycles)
    );

    return ((size_frequency_t)highCpuCycles << 32) | lowCpuCycles;
}

/***********************************************************
 * Function Prototype
 **********************************************************/
/**
 * @brief delay loop function
 * 
 * @param interations  no of iterations for loop
 * 
 * @return void
 */
static void delay_loop(size_frequency_t iterations) ;

/**
 * @brief get estimated cpu frequency Hz
 * 
 * @param object pointer to Time instance
 * @param frequencyHz pointer to variable to return frequency
 * 
 * @return @TimeStatusCode
 */
static TimeStatusCode loc_Time_getEstimateCpuFrequencyHz( Time *object, size_frequency_t *frequencyHz );

/**
 * @brief Fuction to get system tick in millisecond
 * 
 * @param object pointer to time instance
 * @param time pointer to time variable as return value
 * 
 * @return @TimeStatusCode
 */
static TimeStatusCode loc_Time_getSystemTick( Time *object, uint32_t *time );

/**
 * @brief Function to start software timer
 * 
 * @param object pointer to Time instance
 * 
 * @return @TimeStatusCode
 */
static TimeStatusCode loc_Time_startTimer( Time *object );

/**
 * @brief Function to stop software timer
 * 
 * @param object pointer to Time instance
 * 
 * @return @TimeStatusCode
 */
static TimeStatusCode loc_Time_stopTimer( Time *object );

/**
 * @brief function to delay
 * 
 * @param object pointer to Time instance
 * @param delayMilliseconds delay in millisec
 * 
 * @return @TimeStatusCode
 */
static TimeStatusCode loc_Time_delayMs( Time *object, uint32_t delayMilliseconds );

/***********************************************************
 * Function Definations
 **********************************************************/

/**
 * @brief Fuction to initialize time
 * 
 * @param object pointer to time instance
 * 
 * @return @TimeStatusCode
 */
TimeStatusCode Time_init( Time *object )
{
    TimeStatusCode retValue = TIME_STATUS_GOOD;

    if ( NULL == object )
    {
        retValue = TIME_STATUS_INSTANCE_INVALID;
    }
    else
    {
        //Initialize frequency 
        object->frequencyHz = CPU_FREQUENCY_HZ;

        //Initialize Interfaces
        object->interface.getEstimateCpuFrequency = &loc_Time_getEstimateCpuFrequencyHz;
        object->interface.startTimer = &loc_Time_startTimer;
        object->interface.stopTimer = &loc_Time_stopTimer;
        object->interface.delayMs = &loc_Time_delayMs;
    }

    return retValue;
}

/**
 * @brief get estimated cpu frequency Hz
 * 
 * @param object pointer to Time instance
 * @param frequencyHz pointer to variable to return frequency  
 * 
 * @return @TimeStatusCode
 */
TimeStatusCode loc_Time_getEstimateCpuFrequencyHz( Time *object, size_frequency_t *frequencyHz )
{
    TimeStatusCode retValue = TIME_STATUS_GOOD;

    if ( NULL == object )
    {
        retValue = TIME_STATUS_INSTANCE_INVALID;
    }
    else if ( NULL == frequencyHz )
    {
        retValue = TIME_STATUS_ARGUMENT_INVALID;
    }
    else
    {
        size_frequency_t startCpuCyclesCount = 0, 
                         endCpuCyclesCount = 0,
                         elapsedCpuCyclesCount = 0; 

        double approxElapsedTime = 0.1;  //approx time 0.1 sec

        startCpuCyclesCount = get_countCpuCycles();

        //Normally for loop each iteration will consume almost ~ 2 to 3 cycles depending on compiler optimizations and architecture.
        //waist approx 0.1 secs 
        delay_loop( CPU_CYCLES_1_8_GHZ_1_PER_10_SEC );

        endCpuCyclesCount = get_countCpuCycles();

        elapsedCpuCyclesCount = endCpuCyclesCount - startCpuCyclesCount;

        //frequency = cyclescount / elapsedtime;
        *frequencyHz = (size_frequency_t)( elapsedCpuCyclesCount / approxElapsedTime);
    }

    return retValue;
}

/**
 * @brief Fuction to get system tick in millisecond
 * 
 * @param object pointer to time instance
 * @param time pointer to time variable as return value
 * 
 * @return @TimeStatusCode
 */
TimeStatusCode loc_Time_getSystemTick( Time *object, uint32_t *time )
{
    
    TimeStatusCode retValue = TIME_STATUS_GOOD;

    if ( NULL == object )
    {
        retValue = TIME_STATUS_INSTANCE_INVALID;
    }
    else if ( NULL == time )
    {
        retValue = TIME_STATUS_ARGUMENT_INVALID;
    }
    else if ( 0 == object->frequencyHz )
    {
        retValue = TIME_STATUS_PARAMETER_OUT_OF_RANGE;
    }
    else
    {
        size_frequency_t cpuCyclesCount = 0;

        cpuCyclesCount = get_countCpuCycles();

        *time = (uint32_t)( ( cpuCyclesCount * MILLI_SEC_PER_SEC ) / object->frequencyHz );
    }

    return retValue;
}

/**
 * @brief Function to start software timer
 * 
 * @param object pointer to Time instance
 * 
 * @return @TimeStatusCode
 */
TimeStatusCode loc_Time_startTimer( Time *object )
{
    TimeStatusCode retValue = TIME_STATUS_GOOD;

    if ( NULL == object )
    {
        retValue = TIME_STATUS_INSTANCE_INVALID;
    }
    else if ( object->softTimer.isRunning == True )
    {
        retValue = TIME_STATUS_TIMER_NOT_EXPIRED;
    }
    else
    {
        loc_Time_getSystemTick( object, &object->softTimer.startTick );

        object->softTimer.isRunning = True;
    }
    return retValue;
}

/**
 * @brief Function to stop software timer
 * 
 * @param object pointer to Time instance
 * 
 * @return @TimeStatusCode
 */
TimeStatusCode loc_Time_stopTimer( Time *object )
{
    TimeStatusCode retValue = TIME_STATUS_GOOD;

    if ( NULL == object )
    {
        retValue = TIME_STATUS_INSTANCE_INVALID;
    }
    else if ( object->softTimer.isRunning == False )
    {
        retValue = TIME_STATUS_TIMER_EXPIRED;
    }
    else
    {
        uint32_t currentTick = 0;

        loc_Time_getSystemTick( object, &currentTick );

        object->softTimer.duration = currentTick - object->softTimer.startTick;

        object->softTimer.isRunning = False;
    }
    return retValue;
}

/**
 * @brief function to delay
 * 
 * @param object pointer to Time instance
 * @param delayMilliseconds delay in millisec
 * 
 * @return @TimeStatusCode
 */
TimeStatusCode loc_Time_delayMs( Time *object, uint32_t delayMilliseconds )
{
    TimeStatusCode retValue = TIME_STATUS_GOOD;

    if ( NULL == object )
    {
        retValue = TIME_STATUS_INSTANCE_INVALID;
    }
    else if ( 0 == delayMilliseconds )
    {
        retValue = TIME_STATUS_ARGUMENT_INVALID;
    }
    else if ( 0 == object->frequencyHz )
    {
        retValue = TIME_STATUS_PARAMETER_OUT_OF_RANGE;
    }
    else
    {
        size_frequency_t startCycle = get_countCpuCycles();
        size_frequency_t cyclesToWait = ((size_frequency_t)object->frequencyHz / 1000) * delayMilliseconds;

        while ((get_countCpuCycles() - startCycle) < cyclesToWait) 
        {
            // Busy wait
        }
    }

    return retValue;
}


/**
 * @brief delay loop function
 * 
 * @param interations  no of iterations for loop
 * 
 * @return void
 */
void delay_loop(size_frequency_t iterations) 
{
    for (volatile size_frequency_t i = 0; i < iterations; ++i) 
    {
        __asm__ volatile("nop");
    }
}

