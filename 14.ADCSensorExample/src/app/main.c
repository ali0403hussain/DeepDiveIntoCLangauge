/**
 * @file main.c
 * 
 * @description Provides examples for ADC Sensors
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

#include "time.h"
#include "adc.h"
#include "sensor.h"

/**********************************************************
 * Macros
 **********************************************************/

/**********************************************************
 * Struct, Enums, and Typedef 
 **********************************************************/

/***********************************************************
 * Forward declerations and global variables
 **********************************************************/
Time time;
Time *ptrTime = &time;

/***********************************************************
 * Function Prototype
 **********************************************************/

/***********************************************************
 * Function Definations
 **********************************************************/

/**
 * Starting (Entry) Point of C program
 * @param -void
 * 
 * @return 0
 */
int main()
{
    printf("Hello World Welcome to ADC Sensor example in C\n");

    /**
     * @TODO : Temp code just for testing purpose, Later on will be removed
     */
    if ( TIME_STATUS_GOOD == Time_init( ptrTime ) )
    {

        if ( TIME_STATUS_GOOD != ptrTime->interface.startTimer( ptrTime ) )
        {
            printf("Error while starting software timer Time\n");
        }

        if( TIME_STATUS_GOOD != ptrTime->interface.delayMs(ptrTime, 1000 ) )
        {
            printf("Error while delay\n");
        }

        if ( TIME_STATUS_GOOD == ptrTime->interface.stopTimer( ptrTime ) )
        {
            printf("Elapsed Time in millisec: %u \n", ptrTime->softTimer.duration );
        }
    }
    else
    {
        printf("Error while initialization Time\n");
    }

    return 0;
}
