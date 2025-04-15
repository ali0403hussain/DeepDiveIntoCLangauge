/**
 * @file main.c
 * 
 * @brief Example for random number generator
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
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

/**********************************************************
 * Macros
 **********************************************************/

/**********************************************************
 * Struct, Enums, and Typedef 
 **********************************************************/

/***********************************************************
 * Forward declerations and global variables
 **********************************************************/

/***********************************************************
 * Function Prototype
 **********************************************************/

/**
 * @brief Function to generate simple rand
 * 
 * @param noOfRandNumbers number of rand numbers to generate
 * 
 * @return void
 */
void generateSimpleRandNumbers( uint8_t noOfRandNumbers );

/**
 * @brief Function to generate rand numbers between range
 * 
 * @param noOfRandNumbers number of rand numbers to generate
 * @param lowerBound min rand number
 * @param upperBound max rand number
 * 
 * @return void
 */
void randInRange( uint8_t noOfRandNumbers , uint32_t lowerBound, uint32_t upperBound );


/***********************************************************
 * Function Definations
 **********************************************************/

/**
 * @brief Function to generate simple rand
 * 
 * @param noOfRandNumbers number of rand numbers to generate
 * 
 * @return void
 */
void generateSimpleRandNumbers( uint8_t noOfRandNumbers )
{
    uint32_t maxNumber = 0, minNumber = RAND_MAX;

    srand(time(NULL));

    for(uint8_t alter = 0; alter < noOfRandNumbers; alter++)
    {
        uint32_t randNumber = rand();
        if ( randNumber > maxNumber)
        {
            maxNumber = randNumber;
        }
        if ( randNumber < minNumber )
        {
            minNumber = randNumber;
        }
        printf("Number = %d \n", randNumber);
    }

    printf("Max Generated Number = %d \n", maxNumber);
    printf("Min Generated Number = %d \n", minNumber);
}

/**
 * @brief Function to generate rand numbers between range
 * 
 * @param noOfRandNumbers number of rand numbers to generate
 * @param lowerBound min rand number
 * @param upperBound max rand number
 * 
 * @return void
 */
void randInRange( uint8_t noOfRandNumbers , uint32_t lowerBound, uint32_t upperBound )
{
    uint32_t maxNumber = 0, minNumber = RAND_MAX;

    srand(time(NULL));
    
    for(uint8_t alter = 0; alter < noOfRandNumbers; alter++)
    {
        uint32_t randNumber = ( rand() % ( upperBound - lowerBound + 1) ) + lowerBound;
        if ( randNumber > maxNumber)
        {
            maxNumber = randNumber;
        }
        if ( randNumber < minNumber )
        {
            minNumber = randNumber;
        }
        printf("Number = %d \n", randNumber);
    }

    printf("Max Generated Number = %d \n", maxNumber);
    printf("Min Generated Number = %d \n", minNumber);
}


/**
 * Starting (Entry) Point of C program
 * @param -void
 * 
 * @return 0
 */
int main()
{
    printf("Hello World Welcome to learn Random Number Generation in C\n");

    printf("1. Basic Random Number generation\n");
    generateSimpleRandNumbers( 50 );

    printf("2. Basic Random Number generation with in range \n");
    randInRange( 50 , 50, 200 );

    return 0;
}
